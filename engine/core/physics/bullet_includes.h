#pragma once
#include <btBulletDynamicsCommon.h>
namespace physics {
  using default_collision_configuration = btDefaultCollisionConfiguration;
  using collision_dispatcher = btCollisionDispatcher;
  using dbv_broadphase = btDbvtBroadphase;
  using sequential_impulse_constraint_solver = btSequentialImpulseConstraintSolver;
  using discrete_dynamics_world = btDiscreteDynamicsWorld;
}  // namespace physics