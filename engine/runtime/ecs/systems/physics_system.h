#pragma once
#include "../ecs.h"

#include <core/common/basetypes.hpp>
#include <core/physics/bullet_includes.h>

namespace runtime {
  class physics_system {
  public:
    physics_system();
    ~physics_system();

    /**
     * @brief
     *
     * @param dt
     */
    void awake(delta_t dt);

   /**
     * @brief 
     * 
     * @param dt 
     */
    void frame_update(delta_t dt);

    /**
     * @brief 
     * 
     */
    void start();

  private:
    physics::default_collision_configuration collision_configuration_;
    physics::collision_dispatcher dispatcher_;
    physics::dbv_broadphase broadphase_;
    physics::sequential_impulse_constraint_solver solver_;
    physics::discrete_dynamics_world world_;
  };
}  // namespace runtime