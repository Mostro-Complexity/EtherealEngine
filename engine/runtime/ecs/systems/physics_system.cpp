#include "physics_system.h"
#include "../../system/events.h"
#include "../components/box_collider_component.h"
#include "../components/rigidbody_component.h"
#include "../components/transform_component.h"

#include "../editor/editor_runtime/system/standalone.h"

#include <core/system/subsystem.h>

namespace runtime {
  void physics_system::frame_update(delta_t dt) {
    auto& ecs = core::get_subsystem<runtime::entity_component_system>();
    auto all_entities = ecs.all_entities();
    for (const auto entity : all_entities) {  // TODO:optimization
      auto rigidbody_comp = entity.get_component<rigidbody_component>().lock();
      if (rigidbody_comp) { rigidbody_comp->update(); }
    }

    world_.stepSimulation(dt.count(), 0);
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
        auto coll = collider->get_collider_shared();  // TODO: change bullet api
        auto mass = rigidbody_comp->get_mass();

        assert(coll->getShapeType() != INVALID_SHAPE_PROXYTYPE);

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
        btDefaultMotionState* myMotionState =
          new btDefaultMotionState(trans);  // TODO: delete manually

        btRigidBody::btRigidBodyConstructionInfo cInfo(
          mass, myMotionState, coll.get(), localInertia);

        auto body = new btRigidBody(cInfo);
        // body_->setContactProcessingThreshold(m_defaultContactProcessingThreshold);

#else
        btRigidBody* body = new btRigidBody(mass, 0, shape, localInertia);
        body->setWorldTransform(startTransform);
#endif  //

        body->setUserIndex(-1);
        rigidbody_comp->set_rigidbody(std::move(*body));
        rigidbody_comp->start();
        world_.addRigidBody(body);
        world_.setGravity(btVector3(0, -1, 0));
      }
    }
  }

  physics_system::physics_system()
    : dispatcher_(&collision_configuration_),
      world_(&dispatcher_, &broadphase_, &solver_, &collision_configuration_) {
    editor::standalone::on_frame_update.connect(this, &physics_system::frame_update);
    editor::standalone::on_application_start.connect(this, &physics_system::start);
  }

  physics_system::~physics_system() {
    editor::standalone::on_frame_update.disconnect(this, &physics_system::frame_update);
    editor::standalone::on_application_start.disconnect(this, &physics_system::start);
  }
}  // namespace runtime
