#pragma once
/**
 * @file audio_listener_component.h
 * @brief Source code of Audio Listener Components
 */
#include "../ecs.h"

#include <core/audio/listener.h>
#include <core/math/math_includes.h>

/**
 * @brief Main Class Declarations
 *
 * Class that contains core data for audio listeners.
 * There can only be one instance of it per scene.
 *
 * @remark NOTE: customize your component by refering @link engine/runtime/meta/meta.h @endlink
 *
 */
class audio_listener_component : public runtime::component_impl<audio_listener_component> {
  SERIALIZABLE(audio_listener_component)
  REFLECTABLEV(audio_listener_component, component)

public:
  /**
   * @brief Update transform of audio listeners
   *
   * @param t const math::transform&
   * @details Transform of the audio listener
   *
   */
  void update(const math::transform& t);

private:
  audio::listener listener_;
};
