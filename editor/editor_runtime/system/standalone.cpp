#include "standalone.h"
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

#include <core/filesystem/filesystem.h>
#include <core/logging/logging.h>
#include <core/audio/library.h>
#include <core/serialization/serialization.h>
#include <core/simulation/simulation.h>
#include <core/tasks/task_system.h>

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

event<void()> editor::standalone::on_application_setup;
event<void()> editor::standalone::on_application_start;
event<void()> editor::standalone::on_application_stop;
event<void()> editor::standalone::on_application_extern_quit;

event<void(delta_t)> editor::standalone::on_frame_begin;
event<void(delta_t)> editor::standalone::on_frame_update;
event<void(delta_t)> editor::standalone::on_frame_render;
event<void(delta_t)> editor::standalone::on_frame_ui_render;
event<void(delta_t)> editor::standalone::on_frame_end;

void editor::standalone::setup(cmd_line::parser& parser) {
  on_application_setup();
  on_application_extern_quit.connect(this, &editor::standalone::external_exit);
}

void editor::standalone::start(cmd_line::parser& parser) { on_application_start(); }

int editor::standalone::run(int argc, char* argv[]) {
  core::details::initialize();

  cmd_line::parser parser(argc, argv);

  setup(parser);
  if (exitcode_ != 0) {
    core::details::dispose();
    return exitcode_;
  }

  std::stringstream out, err;
  if (!parser.run(out, err)) {
    auto parse_error = out.str();
    if (parse_error.empty()) { parse_error = "Failed to parse command line."; }
    APPLOG_ERROR(parse_error);
  }
  auto parse_info = out.str();
  if (!parse_info.empty()) { APPLOG_INFO(parse_info); }

  APPLOG_INFO("Game Initializing...");
  start(parser);
  if (exitcode_ != 0) {
    core::details::dispose();
    return exitcode_;
  }

  APPLOG_INFO("Game Starting...");
  while (running_) run_one_frame();

  APPLOG_INFO("Game Deinitializing...");

  stop();

  APPLOG_INFO("Game Exiting...");

  core::details::dispose();
  return exitcode_;
}

void editor::standalone::run_one_frame() {
  using namespace std::literals;

  auto& sim = core::get_subsystem<core::simulation>();
  // auto& tasks = core::get_subsystem<core::task_system>();
  // auto& renderer = core::get_subsystem<runtime::renderer>();
  // const bool is_active = renderer.get_focused_window() != nullptr;
  // sim.run_one_frame(is_active);
  // tasks.run_on_owner_thread(5ms);

  auto dt = sim.get_delta_time();

  // renderer.process_pending_windows();

  // const auto& windows = renderer.get_windows();
  // bool should_quit = std::all_of(std::begin(windows), std::end(windows), [](const auto& window) {
  //  return !window->is_visible();
  //});
  // if (should_quit) {
  //  quit(0);
  //  return;
  //}

  on_frame_begin(dt);

  on_frame_update(dt);

  on_frame_render(dt);

  on_frame_ui_render(dt);

  on_frame_end(dt);
}

void editor::standalone::stop() { on_application_stop(); }

void editor::standalone::external_exit() { should_stop_ = true; }
