#include "physics_system.h"
#include "../../system/events.h"
#include "../components/box_collider_component.h"
#include "../components/rigidbody_component.h"
#include "../components/transform_component.h"

#include <core/system/subsystem.h>

namespace runtime {
  void physics_system::frame_update(delta_t) {
    auto& ecs = core::get_subsystem<runtime::entity_component_system>();
    auto all_entities = ecs.all_entities();
    for (const auto entity : all_entities) {  // TODO:optimization
      auto rigidbody_comp = entity.get_component<rigidbody_component>().lock();

      if (rigidbody_comp) { rigidbody_comp->update(); }
    }
  }

  void physics_system::awake(delta_t) {}

  void physics_system::start() {
    auto& ecs = core::get_subsystem<runtime::entity_component_system>();
    auto all_entities = ecs.all_entities();
    for (const auto entity : all_entities) {  // TODO: optimization
      auto rigidbody_comp = entity.get_component<rigidbody_component>().lock();
      auto transform_comp = entity.get_component<transform_component>().lock();
      auto collider = entity.get_component<box_collider_component>().lock();

      if (rigidbody_comp) {
        auto coll = collider->get_collider();  // TODO: change bullet api
        auto mass = rigidbody_comp->get_mass();

        assert(coll.getShapeType() != INVALID_SHAPE_PROXYTYPE);

        // rigidbody is dynamic if and only if mass is non zero, otherwise static
        bool isDynamic = (mass != 0.f);

        btVector3 localInertia(0, 0, 0);
        if (isDynamic)
          collider->calculate_local_inertia(
            mass, math::vec3(localInertia.x(), localInertia.y(), localInertia.z()));

          // using motionstate is recommended, it provides interpolation capabilities, and only
          // synchronizes 'active' objects
#define USE_MOTIONSTATE 1
#ifdef USE_MOTIONSTATE
        btTransform trans;  // TODO: change bullet api
        trans.setFromOpenGLMatrix(&transform_comp->get_transform().get_matrix()[0][0]);
        btDefaultMotionState* myMotionState = new btDefaultMotionState(trans);

        btRigidBody::btRigidBodyConstructionInfo cInfo(mass, myMotionState, &coll, localInertia);

        auto body = new btRigidBody(cInfo);
        // body_->setContactProcessingThreshold(m_defaultContactProcessingThreshold);

#else
        btRigidBody* body = new btRigidBody(mass, 0, shape, localInertia);
        body->setWorldTransform(startTransform);
#endif  //

        body->setUserIndex(-1);
        rigidbody_comp->set_rigidbody(std::move(*body));
        world_.addRigidBody(body);
      }
    }
  }

  physics_system::physics_system()
    : dispatcher_(&collision_configuration_),
      world_(&dispatcher_, &broadphase_, &solver_, &collision_configuration_) {
    on_application_start.connect(this, &physics_system::start);
    on_frame_update.connect(this, &physics_system::frame_update);
  }

  physics_system::~physics_system() {
    on_application_start.disconnect(this, &physics_system::start);
    on_frame_update.disconnect(this, &physics_system::frame_update);
  }
}  // namespace runtime
