#include "events.h"

namespace runtime {
  /// engine loop events
  event<void(delta_t)> on_frame_begin;
  event<void(delta_t)> on_frame_update;
  event<void(delta_t)> on_frame_render;
  event<void(delta_t)> on_frame_ui_render;
  event<void(delta_t)> on_frame_end;

  /// platform events
  event<void(const std::pair<std::uint32_t, bool>&, const std::vector<mml::platform_event>&)>
    on_platform_events;
}  // namespace runtime
