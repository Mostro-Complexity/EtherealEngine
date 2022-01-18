#pragma once

#include <core/signals/event.hpp>
#include <runtime/system/app.h>

#include <string>

namespace editor {
  class standalone : public runtime::app {
  public:
    virtual ~standalone() = default;

    virtual void setup(cmd_line::parser& parser);

    virtual void start(cmd_line::parser& parser);

    virtual int run(int argc, char* argv[]);

    virtual void run_one_frame();

    virtual void stop();

    /**
     * @brief  platform events
     *
     */
    static event<void()> on_application_setup;
    static event<void()> on_application_start;
    static event<void()> on_application_stop;
    static event<void()> on_application_extern_quit;

    static event<void(delta_t)> on_frame_begin;
    static event<void(delta_t)> on_frame_update;
    static event<void(delta_t)> on_frame_render;
    static event<void(delta_t)> on_frame_ui_render;
    static event<void(delta_t)> on_frame_end;

  private:
    bool should_stop_ = false;
    void external_exit();
  };
}  // namespace editor
