#pragma once
/**
 * @file audio_source_component.h
 * @brief Source code of Audio Listener Components
 */
#include "../../assets/asset_handle.h"
#include "../ecs.h"

#include <core/audio/source.h>
#include <core/common/basetypes.hpp>
#include <core/math/math_includes.h>

/**
 * @brief Main Class Declarations
 * Class that contains core data for audio listeners.
 * There can only be one instance of it per scene.
 *
 * @remark NOTE: customize your component by refering @link link-engine/runtime/meta/meta.h @endlink
 *
 */
class audio_source_component : public runtime::component_impl<audio_source_component> {
  SERIALIZABLE(audio_source_component)
  REFLECTABLEV(audio_source_component, component)

public:
  /**
   * @brief Update the transform of this audio source component
   *
   * @param t const math::transform&
   */
  void update(const math::transform& t);
  
  /**
   * @brief Set the loop to enable/disable loop play mode
   *
   * @param on bool
   */
  void set_loop(bool on);

  /**
   * @brief Set the volume
   *
   * @param volume float
   */
  void set_volume(float volume);

  /**
   * @brief Set the pitch
   *
   * @param pitch float
   */
  void set_pitch(float pitch);

  /**
   * @brief Set the volume rolloff
   *
   * @param rolloff float
   */
  void set_volume_rolloff(float rolloff);

  /**
   * @brief Set the range
   *
   * @param range frange_t
   */
  void set_range(const frange_t& range);

  /**
   * @brief Set the autoplay to enable/disable autoplay mode
   *
   * @param on bool
   */
  void set_autoplay(bool on);

  /**
   * @brief Get the autoplay mode
   *
   * @return true
   * @return false
   */
  bool get_autoplay() const;

  /**
   * @brief Get the volume
   *
   * @return float
   */
  float get_volume() const;

  /**
   * @brief Get the pitch
   *
   * @return float
   */
  float get_pitch() const;

  /**
   * @brief Get the volume rolloff
   *
   * @return float
   */
  float get_volume_rolloff() const;

  /**
   * @brief Get the range object
   *
   * @return const frange_t&
   */
  const frange_t& get_range() const;

  /**
   * @brief Set the playing offset
   *
   * @param offset audio::sound_info::duration_t
   */
  void set_playing_offset(audio::sound_info::duration_t offset);

  /**
   * @brief Get the playing offset
   *
   * @return audio::sound_info::duration_t
   */
  audio::sound_info::duration_t get_playing_offset() const;

  /**
   * @brief Get the playing duration
   *
   * @return audio::sound_info::duration_t
   */
  audio::sound_info::duration_t get_playing_duration() const;

  void play();
  void stop();
  void pause();
  bool is_playing() const;
  bool is_paused() const;

  bool is_looping() const;

  void set_sound(asset_handle<audio::sound> sound);
  asset_handle<audio::sound> get_sound() const;

  bool has_binded_sound() const;

private:
  void apply_all();
  bool is_sound_valid() const;

  bool auto_play_ = true;
  bool loop_ = true;
  float volume_ = 1.0f;
  float pitch_ = 1.0f;
  float volume_rolloff_ = 1.0f;
  frange_t range_ = { 1.0f, 20.0f };
  audio::source source_;
  asset_handle<audio::sound> sound_;
};
