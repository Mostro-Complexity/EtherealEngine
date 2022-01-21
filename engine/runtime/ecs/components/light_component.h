#pragma once
/**
 * @file light_component.h
 * @author Mostro
 * @brief Source code of Light Components
 * @date 2022-01-14
 *
 */
#include "../../rendering/light.h"
#include "../ecs.h"

#include <core/common/basetypes.hpp>

/**
 * @brief Class that contains our core light data
 *
 * The class that used for rendering and other things.
 *
 * @remark NOTE: customize your component by refering @link link-engine/runtime/meta/meta.h @endlink
 *
 */
class light_component : public runtime::component_impl<light_component> {
  SERIALIZABLE(light_component)
  REFLECTABLEV(light_component, runtime::component)
public:
  /**
   * @brief Get the light
   *
   * @return const light&
   */
  inline const light& get_light() const { return light_; }

  /**
   * @brief Set the light
   *
   * @param l const light&
   */
  inline void set_light(const light& l) { light_ = l; }

  /**
   * @brief
   *
   * @param rect
   * @param light_position
   * @param light_direction
   * @param view
   * @param proj
   * @return int
   */
  int compute_projected_sphere_rect(
    irect32_t& rect, const math::vec3& light_position, const math::vec3& light_direction,
    const math::transform& view, const math::transform& proj);

private:
  /**
   * @brief The light object this component represents
   *
   */
  light light_;
};
