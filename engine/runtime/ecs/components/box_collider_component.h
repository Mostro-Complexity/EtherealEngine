#pragma once
/**
 * @file box_collider_component.h
 * @author Mostro
 * @brief Source code of Box Collider Components
 * @date 2022-01-14
 *
 */
#include "../ecs.h"

#include <core/common/basetypes.hpp>
#include <core/math/math_includes.h>
#include <core/physics/bullet_includes.h>
#include <core/physics/collider.h>

/**
 * @brief Class that contains collider shape for rigidbodies
 *
 * There can only be one instance of it per entity.
 *
 * @remark NOTE: customize your component by refering @link link-engine/runtime/meta/meta.h @endlink
 *
 */
class box_collider_component : public runtime::component_impl<box_collider_component> {
  SERIALIZABLE(box_collider_component)
  REFLECTABLEV(box_collider_component, runtime::component)
public:
  /**
   * @brief Construct a new box collider component
   *
   */
  box_collider_component();
  virtual ~box_collider_component();

  /**
   * @brief Calculate local inertia
   *
   * @param mass float
   * @param local_inertia math::vec3
   */
  void calculate_local_inertia(float mass, math::vec3 local_inertia);

  const physics::box_collider& get_collider();

  std::shared_ptr<physics::box_collider> get_collider_shared();

private:
  std::shared_ptr<physics::box_collider> collider_;  // TODO: use shared_ptr for temporary
};