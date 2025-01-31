#include "app.h"
#include "../console/console_log.h"
#include "../editing/editing_system.h"
#include "../editing/picking_system.h"
#include "../interface/docks/console_dock.h"
#include "../interface/docks/docking.h"
#include "../interface/docks/game_dock.h"
#include "../interface/docks/hierarchy_dock.h"
#include "../interface/docks/inspector_dock.h"
#include "../interface/docks/project_dock.h"
#include "../interface/docks/scene_dock.h"
#include "../interface/docks/style_dock.h"
#include "../interface/gui_system.h"
#include "../rendering/debugdraw_system.h"
#include "../system/project_manager.h"
#include "../system/standalone.h"

#include <core/filesystem/filesystem.h>
#include <core/logging/logging.h>

#include <runtime/assets/asset_manager.h>
#include <runtime/ecs/components/camera_component.h>
#include <runtime/ecs/components/light_component.h>
#include <runtime/ecs/components/model_component.h>
#include <runtime/ecs/components/reflection_probe_component.h>
#include <runtime/ecs/components/transform_component.h>
#include <runtime/ecs/constructs/scene.h>
#include <runtime/ecs/constructs/utils.h>
#include <runtime/ecs/systems/scene_graph.h>
#include <runtime/input/input.h>
#include <runtime/rendering/renderer.h>
#include <runtime/system/events.h>

#include <editor_core/nativefd/filedialog.h>

namespace editor {
  namespace {
    template <typename T> void create_window_with_dock(const std::string& dock_name) {
      auto& rend = core::get_subsystem<runtime::renderer>();
      auto& docking = core::get_subsystem<docking_system>();
      mml::video_mode desktop = mml::video_mode::get_desktop_mode();
      desktop.width = 1280;
      desktop.height = 720;
      auto window = std::make_unique<render_window>(desktop, "App", mml::style::standard);
      window->request_focus();

      auto dock = std::make_unique<T>(dock_name, true, ImVec2(200.0f, 200.0f));

      auto& dockspace = docking.get_dockspace(window->get_id());
      dockspace.dock_to(dock.get(), imguidock::slot::tab, 200, true);
      rend.register_window(std::move(window));
      docking.register_dock(std::move(dock));
    }
    std::vector<runtime::entity> gather_scene_data() {
      auto& es = core::get_subsystem<editor::editing_system>();
      auto& sg = core::get_subsystem<runtime::scene_graph>();
      const auto& roots = sg.get_roots();
      auto editor_camera = es.camera;
      std::vector<runtime::entity> entities;
      for (auto root : roots) {
        if (root.valid() && root != editor_camera) entities.push_back(root);
      }

      return entities;
    }

    void default_scene() {
      auto& am = core::get_subsystem<runtime::asset_manager>();
      auto& ecs = core::get_subsystem<runtime::entity_component_system>();

      {
        auto object = ecs.create();
        object.set_name("main camera");
        auto transf_comp = object.assign<transform_component>().lock();
        transf_comp->set_local_position({ 0.0f, 2.0f, -5.0f });
        object.assign<camera_component>();
      }
      {
        auto object = ecs.create();
        object.set_name("light");
        auto transf_comp = object.assign<transform_component>().lock();
        transf_comp->set_local_position({ 1.0f, 6.0f, -3.0f });
        transf_comp->rotate_local(50.0f, -30.0f, 0.0f);

        light light_data;
        light_data.color = math::color(255, 244, 214, 255);
        auto light_comp = object.assign<light_component>().lock();
        light_comp->set_light(light_data);
      }
      {
        auto object = ecs.create();
        object.set_name("global probe");
        auto transf_comp = object.assign<transform_component>().lock();
        transf_comp->set_local_position({ 0.0f, 0.1f, 0.0f });

        reflection_probe probe;
        probe.method = reflect_method::environment;
        probe.type = probe_type::sphere;
        probe.sphere_data.range = 1000.0f;
        auto reflect_comp = object.assign<reflection_probe_component>().lock();
        reflect_comp->set_probe(probe);
      }
      {
        auto object = ecs.create();
        object.set_name("local probe");
        auto transf_comp = object.assign<transform_component>().lock();
        transf_comp->set_local_position({ 0.0f, 0.1f, 0.0f });

        reflection_probe probe;
        probe.method = reflect_method::static_only;
        probe.type = probe_type::box;
        auto reflect_comp = object.assign<reflection_probe_component>().lock();
        reflect_comp->set_probe(probe);
      }
      {
        auto object = ecs.create();
        object.set_name("platform");
        object.assign<transform_component>();

        auto asset_future = am.load<mesh>("embedded:/plane");
        model model;
        model.set_lod(asset_future.get(), 0);

        // Add component and configure it.
        auto model_comp = object.assign<model_component>().lock();
        model_comp->set_casts_shadow(true);
        model_comp->set_casts_reflection(true);
        model_comp->set_model(model);
      }
      {
        auto object = ecs.create();
        object.set_name("object");
        auto transf_comp = object.assign<transform_component>().lock();
        transf_comp->set_local_position({ -2.0f, 0.5f, 0.0f });

        auto asset_future = am.load<mesh>("embedded:/sphere");
        model model;
        model.set_lod(asset_future.get(), 0);

        // Add component and configure it.
        auto model_comp = object.assign<model_component>().lock();
        model_comp->set_casts_shadow(true);
        model_comp->set_casts_reflection(false);
        model_comp->set_model(model);
      }

      {
        auto object = ecs.create();
        object.set_name("object_with_lods");
        auto transf_comp = object.assign<transform_component>().lock();
        transf_comp->set_local_position({ 2.0f, 1.0f, 0.0f });

        model model;
        {
          auto asset_future = am.load<mesh>("embedded:/icosphere4");
          model.set_lod(asset_future.get(), 0);
        }
        {
          auto asset_future = am.load<mesh>("embedded:/icosphere3");
          model.set_lod(asset_future.get(), 1);
        }
        {
          auto asset_future = am.load<mesh>("embedded:/icosphere2");
          model.set_lod(asset_future.get(), 2);
        }
        // Add component and configure it.
        auto model_comp = object.assign<model_component>().lock();
        model_comp->set_casts_shadow(true);
        model_comp->set_casts_reflection(false);
        model_comp->set_model(model);
      }
    }

    auto create_new_scene() {
      auto& es = core::get_subsystem<editor::editing_system>();
      auto& ecs = core::get_subsystem<runtime::entity_component_system>();
      es.save_editor_camera();
      ecs.dispose();
      es.load_editor_camera();
      default_scene();
      es.scene.clear();
    }

    auto open_scene() {
      auto& es = core::get_subsystem<editor::editing_system>();
      auto& am = core::get_subsystem<runtime::asset_manager>();
      es.save_editor_camera();

      std::string path;
      if (native::open_file_dialog("sgr", fs::resolve_protocol("app:/data").string(), path)) {
        auto scene_path = fs::convert_to_protocol(path);
        auto scene = am.load<::scene>(scene_path.string()).get();
        scene->instantiate(::scene::mode::standard);
        es.load_editor_camera();
        es.scene = path;
      }
    }

    auto save_scene() {
      auto& es = core::get_subsystem<editor::editing_system>();
      const auto& path = es.scene;
      if (path != "") {
        auto entities = gather_scene_data();
        ecs::utils::save_entities_to_file(path, std::move(entities));
        APPLOG_INFO("Saving scene successful.");
      }

      es.save_editor_camera();
    }

    void save_scene_as() {
      auto& es = core::get_subsystem<editor::editing_system>();

      std::string path;
      if (native::save_file_dialog("sgr", fs::resolve_protocol("app:/data").string(), path)) {
        es.scene = path;
        if (!fs::path(path).has_extension()) es.scene += ".sgr";

        save_scene();
      }

      es.save_editor_camera();
    }
  }  // namespace

  void app::draw_menubar(render_window& window) {
    auto& es = core::get_subsystem<editor::editing_system>();
    auto& pm = core::get_subsystem<editor::project_manager>();
    auto& rend = core::get_subsystem<runtime::renderer>();
    auto& input = core::get_subsystem<runtime::input>();
    const auto& current_project = pm.get_name();

    if (input.is_key_down(mml::keyboard::LControl)) {
      if (input.is_key_down(mml::keyboard::LShift)) {
        if (input.is_key_pressed(mml::keyboard::S)) { save_scene_as(); }
      } else if (input.is_key_pressed(mml::keyboard::S)) {
        save_scene();
      }

      if (input.is_key_pressed(mml::keyboard::O)) { open_scene(); }

      if (input.is_key_pressed(mml::keyboard::N)) { create_new_scene(); }
    }
    if (gui::BeginMainMenuBar()) {

      if (gui::BeginMenu("FILE")) {
        if (gui::MenuItem("NEW SCENE", "CTRL+N", false, current_project != "")) {
          create_new_scene();
        }
        if (gui::MenuItem("OPEN SCENE", "CTRL+O", false, current_project != "")) { open_scene(); }
        if (gui::MenuItem("SHOW START PAGE", "CTRL+P")) {
          show_start_page_ = true;
          rend.hide_all_secondary_windows();
          pm.close_project();
          window.restore();
          auto& io = gui::GetIO();
          io.MouseDown[0] = false;
          io.MouseDown[1] = false;
          io.MouseDown[2] = false;
        }

        if (gui::MenuItem("SAVE", "CTRL+S", false, es.scene != "" && current_project != "")) {
          save_scene();
        }
        auto& ecs = core::get_subsystem<runtime::entity_component_system>();

        if (gui::MenuItem(
              "SAVE AS..", "CTRL+SHIFT+S", false, ecs.size() > 0 && current_project != "")) {
          save_scene_as();
        }

        gui::EndMenu();
      }
      if (gui::BeginMenu("EDIT")) {
        if (gui::MenuItem("UNDO", "CTRL+Z")) {}
        if (gui::MenuItem("REDO", "CTRL+Y", false, false)) {}
        gui::Separator();
        if (gui::MenuItem("CUT", "CTRL+X")) {}
        if (gui::MenuItem("COPY", "CTRL+C")) {}
        if (gui::MenuItem("PASTE", "CTRL+V")) {}
        gui::EndMenu();
      }
      if (gui::BeginMenu("WINDOWS")) {
        if (gui::MenuItem("HIERARCHY")) { create_window_with_dock<hierarchy_dock>("HIERARCHY"); }
        if (gui::MenuItem("INSPECTOR")) { create_window_with_dock<inspector_dock>("INSPECTOR"); }
        if (gui::MenuItem("SCENE")) { create_window_with_dock<scene_dock>("SCENE"); }
        if (gui::MenuItem("GAME")) { create_window_with_dock<game_dock>("GAME"); }
        if (gui::MenuItem("PROJECT")) { create_window_with_dock<project_dock>("PROJECT"); }
        if (gui::MenuItem("STYLE")) { create_window_with_dock<style_dock>("STYLE"); }
        gui::EndMenu();
      }
      float offset = gui::GetWindowHeight();
      gui::EndMainMenuBar();
      gui::SetCursorPosY(gui::GetCursorPosY() + offset);
    }
  }

  void app::draw_toolbar() {
    auto& es = core::get_subsystem<editor::editing_system>();
    auto& icons = es.icons;

    float width = gui::GetContentRegionAvailWidth();
    if (gui::ToolbarButton(
          icons["translate"].get(), "TRANSLATE", es.operation == imguizmo::operation::translate)) {
      es.operation = imguizmo::operation::translate;
    }
    gui::SameLine(0.0f);
    if (gui::ToolbarButton(
          icons["rotate"].get(), "ROTATE", es.operation == imguizmo::operation::rotate)) {
      es.operation = imguizmo::operation::rotate;
    }
    gui::SameLine(0.0f);
    if (gui::ToolbarButton(
          icons["scale"].get(), "SCALE", es.operation == imguizmo::operation::scale)) {
      es.operation = imguizmo::operation::scale;
      es.mode = imguizmo::mode::local;
    }
    gui::SameLine(0.0f, 50.0f);

    if (gui::ToolbarButton(
          icons["local"].get(), "LOCAL COORDINATE SYSTEM", es.mode == imguizmo::mode::local)) {
      es.mode = imguizmo::mode::local;
    }
    gui::SameLine(0.0f);
    if (gui::ToolbarButton(
          icons["global"].get(),
          "GLOBAL COORDINATE SYSTEM",
          es.mode == imguizmo::mode::world,
          es.operation != imguizmo::operation::scale)) {
      es.mode = imguizmo::mode::world;
    }
    gui::SameLine(0.0f);
    if (gui::ToolbarButton(icons["grid"].get(), "SHOW GRID", es.show_grid)) {
      es.show_grid = !es.show_grid;
    }
    gui::SameLine(0.0f);
    if (gui::ToolbarButton(
          icons["wireframe"].get(), "WIREFRAME SELECTION", es.wireframe_selection)) {
      es.wireframe_selection = !es.wireframe_selection;
    }

    gui::SameLine(width / 2.0f - 36.0f);
    if (gui::ToolbarButton(icons["play"].get(), "PLAY", false)) {
      // NOTE: start game life period
      // NOTE: for temporary

      auto& ts = core::get_subsystem<core::task_system>();
      auto task = ts.push_on_worker_thread([]() {  // FIXME: 必须使用单一线程运行
        int argc = 1;
        char* argv[] = { "game" };
        editor::standalone standalone;
        int return_code = standalone.run(argc, argv);
      });
    }
    gui::SameLine(0.0f);
    if (gui::ToolbarButton(icons["pause"].get(), "PAUSE", false)) {
      editor::standalone::on_application_extern_quit();
    }
    gui::SameLine(0.0f);
    if (gui::ToolbarButton(icons["next"].get(), "STEP", false)) {}
  }

  //-----------------------------------------------------------------------------

  void app::setup(cmd_line::parser& parser) {
    runtime::app::setup(parser);

    runtime::on_frame_ui_render.connect(this, &editor::app::draw_docks);
  }

  void app::start(cmd_line::parser& parser) {
    console_log_ = std::make_shared<console_log>();

    auto logging_container = logging::get_mutable_logging_container();
    logging_container->add_sink(console_log_);

    runtime::app::start(parser);

    core::add_subsystem<gui_system>();
    core::add_subsystem<docking_system>();
    core::add_subsystem<editing_system>();
    core::add_subsystem<picking_system>();
    core::add_subsystem<debugdraw_system>();
    core::add_subsystem<project_manager>();

    create_docks();
    register_console_commands();
  }

  void app::create_docks() {
    auto& rend = core::get_subsystem<runtime::renderer>();
    auto& main_window = rend.get_main_window();

    main_window->set_title("ETHEREAL EDITOR");

    console_dock_name_ = "CONSOLE";
    auto scene = std::make_unique<scene_dock>("SCENE", true, ImVec2(200.0f, 200.0f));
    auto game = std::make_unique<game_dock>("GAME", true, ImVec2(300.0f, 200.0f));
    auto hierarchy = std::make_unique<hierarchy_dock>("HIERARCHY", true, ImVec2(300.0f, 200.0f));
    auto inspector = std::make_unique<inspector_dock>("INSPECTOR", true, ImVec2(300.0f, 200.0f));
    auto project = std::make_unique<project_dock>("PROJECT", true, ImVec2(200.0f, 200.0f));
    auto console =
      std::make_unique<console_dock>("CONSOLE", true, ImVec2(200.0f, 200.0f), console_log_);
    auto style = std::make_unique<style_dock>("STYLE", true, ImVec2(300.0f, 200.0f));

    auto& docking = core::get_subsystem<docking_system>();
    auto& dockspace = docking.get_dockspace(main_window->get_id());
    dockspace.dock_to(scene.get(), imguidock::slot::tab, 200, true);
    dockspace.dock_with(game.get(), scene.get(), imguidock::slot::tab, 300, false);
    dockspace.dock_with(inspector.get(), scene.get(), imguidock::slot::right, 400, true);
    dockspace.dock_with(hierarchy.get(), scene.get(), imguidock::slot::left, 300, true);
    dockspace.dock_to(console.get(), imguidock::slot::bottom, 300, true);
    dockspace.dock_with(project.get(), console.get(), imguidock::slot::tab, 250, true);
    dockspace.dock_with(style.get(), project.get(), imguidock::slot::right, 400, true);

    docking.register_dock(std::move(scene));
    docking.register_dock(std::move(game));
    docking.register_dock(std::move(inspector));
    docking.register_dock(std::move(hierarchy));
    docking.register_dock(std::move(console));
    docking.register_dock(std::move(project));
    docking.register_dock(std::move(style));
  }

  void app::register_console_commands() {
    std::function<void()> log_version = []() { APPLOG_INFO("Version 1.0"); };
    console_log_->register_command(
      "version", "Returns the current version of the Editor.", {}, {}, log_version);
  }

  void app::stop() {
    runtime::on_frame_ui_render.disconnect(this, &editor::app::draw_docks);

    runtime::app::stop();
  }

  void app::draw_docks(delta_t dt) {
    auto& gui = core::get_subsystem<gui_system>();
    auto& docking = core::get_subsystem<docking_system>();
    auto& renderer = core::get_subsystem<runtime::renderer>();
    const auto& windows = renderer.get_windows();

    for (std::size_t i = 0; i < windows.size(); ++i) {
      const auto& window = windows[i];
      window->begin_present_pass();

      const auto id = window->get_id();
      auto& dockspace = docking.get_dockspace(id);
      gui.push_context(id);
      gui.draw_begin(*window, dt);

      gui::PushFont("standard");

      if (show_start_page_) {
        draw_start_page(*window);
      } else {
        draw_dockspace(i == 0, *window, dockspace);
      }

      handle_drag_and_drop();

      gui::PopFont();
      gui.draw_end();
      gui.pop_context();
    }
  }

  void app::draw_header(render_window& window) {
    draw_menubar(window);
    draw_toolbar();
  }

  void app::draw_dockspace(bool is_main, render_window& window, imguidock::dockspace& dockspace) {
    float offset = 0.0f;

    if (is_main) {
      draw_header(window);
      offset = gui::GetFrameHeightWithSpacing();
    }

    dockspace.update_and_draw(
      ImVec2(gui::GetContentRegionAvail().x, gui::GetContentRegionAvail().y - offset));

    if (is_main) { draw_footer(window, dockspace); }
  }

  void app::draw_footer(render_window&, imguidock::dockspace& dockspace) {
    if (!console_log_) return;

    auto& ts = core::get_subsystem<core::task_system>();
    const auto tasks_info = ts.get_info();
    const auto items = console_log_->get_items();

    const auto total_width = gui::GetContentRegionAvailWidth();
    gui::BeginColumns("footer", 2, ImGuiColumnsFlags_NoBorder | ImGuiColumnsFlags_NoResize);
    gui::SetColumnWidth(0, total_width * 0.8f);

    if (items.size() > 0) {
      const auto& last_item = items.back();
      const auto& colorization = console_log_->get_level_colorization(last_item.second);
      ImVec4 col = { colorization[0], colorization[1], colorization[2], colorization[3] };

      gui::SetCursorPosY(ImGui::GetCursorPosY());
      gui::PushStyleColor(ImGuiCol_Text, col);
      gui::AlignTextToFramePadding();
      if (gui::Selectable(last_item.first.c_str(), false, 0, ImVec2(0, gui::GetTextLineHeight()))) {
        dockspace.activate_dock(console_dock_name_);
      }
      gui::PopStyleColor();
    }
    gui::NextColumn();
    if (tasks_info.pending_tasks > 0) {
      gui::PushFont("icons");
      gui::AlignTextToFramePadding();
      gui::Text(ICON_FA_TASKS " Queued tasks : (%u)", unsigned(tasks_info.pending_tasks));
      auto& g = *gui::GetCurrentContext();
      if (!g.DragDropActive && gui::IsItemHovered()) {
        gui::BeginTooltip();
        int idx = 0;
        for (const auto& info : tasks_info.queue_infos) {
          gui::Separator();
          gui::AlignTextToFramePadding();
          gui::Text("QUEUE %d : %u", idx++, unsigned(info.pending_tasks));
        }

        gui::EndTooltip();
      }

      gui::PopFont();
    }
    gui::EndColumns();
  }

  void app::draw_start_page(render_window& window) {
    auto& pm = core::get_subsystem<editor::project_manager>();

    auto on_create_project = [&](const std::string& p) {
      auto& rend = core::get_subsystem<runtime::renderer>();
      auto path = fs::path(p).make_preferred();
      pm.create_project(path);
      window.maximize();
      rend.show_all_secondary_windows();
      show_start_page_ = false;
    };
    auto on_open_project = [&](const std::string& p) {
      auto& rend = core::get_subsystem<runtime::renderer>();
      auto path = fs::path(p).make_preferred();
      pm.open_project(path);
      window.maximize();
      rend.show_all_secondary_windows();
      show_start_page_ = false;
    };

    gui::PushFont("standard_big");
    ImGuiWindowFlags flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove
                             | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_HorizontalScrollbar
                             | ImGuiWindowFlags_NoSavedSettings;

    gui::AlignTextToFramePadding();
    gui::TextUnformatted("RECENT PROJECTS");
    gui::Separator();
    gui::BeginGroup();
    {
      if (gui::BeginChild(
            "projects_content",
            ImVec2(gui::GetContentRegionAvail().x * 0.7f, gui::GetContentRegionAvail().y),
            false,
            flags)) {

        const auto& rencent_projects = pm.get_options().recent_project_paths;
        for (const auto& path : rencent_projects) {
          if (gui::Selectable(path.c_str())) { on_open_project(path); }
        }
      }
      gui::EndChild();
    }
    gui::EndGroup();

    gui::SameLine();

    gui::BeginGroup();
    {
      if (gui::Button("NEW PROJECT", ImVec2(gui::GetContentRegionAvailWidth(), 0.0f))) {
        std::string path;
        if (native::pick_folder_dialog("", path)) { on_create_project(path); }
      }

      if (gui::Button("OPEN OTHER", ImVec2(gui::GetContentRegionAvailWidth(), 0.0f))) {
        std::string path;
        if (native::pick_folder_dialog("", path)) { on_open_project(path); }
      }
    }
    gui::EndGroup();
    gui::PopFont();
  }

  void app::handle_drag_and_drop() {
    auto& es = core::get_subsystem<editing_system>();

    if (!gui::IsAnyItemActive() && !gui::IsAnyItemHovered()) {
      if (gui::IsMouseDoubleClicked(0) && !imguizmo::is_over()) { es.unselect(); }
    }
  }
}  // namespace editor
