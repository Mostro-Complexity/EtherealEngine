#include "rigidbody_component.h"
#include "transform_component.h"
#include "box_collider_component.h"
#include <core/math/transform.h>
#include <core/tasks/task_system.h>
#include <cstdlib>
#include <cassert>

rigidbody_component::rigidbody_component() {}

rigidbody_component::~rigidbody_component() {}

void rigidbody_component::add_force(math::vec3 force, force_mode mode = force_mode::force) {}

void rigidbody_component::start() {}

void rigidbody_component::set_gravity_validity(bool flag) { gravity_enabled_ = flag; }

bool rigidbody_component::get_gravity_validity() const { return gravity_enabled_; }

void rigidbody_component::update() {
  physics::rigidbody* body = physics::rigidbody::upcast(body_.get());
  math::mat4          out;
  {
    btTransform trans;
    if (body && body->getMotionState()) {
      body->getMotionState()->getWorldTransform(trans);
    } else {
      trans = body_->getWorldTransform();
    }
    trans.getOpenGLMatrix(&out[0][0]);
  }
  auto trans = math::transform(out);
  auto transform_comp = entity_.get_component<transform_component>().lock();
  transform_comp->set_transform(trans);
}

float rigidbody_component::get_mass() const { return mass_; }

void rigidbody_component::set_mass(float mass) { mass_ = mass; }

void rigidbody_component::set_rigidbody(const physics::rigidbody& body) {
  body_ = std::make_shared<physics::rigidbody>(body);
}

void rigidbody_component::set_rigidbody(physics::rigidbody&& body) {
  body_ = std::make_shared<physics::rigidbody>(std::forward<physics::rigidbody>(body));
}

const physics::rigidbody& rigidbody_component::get_rigidbody() const { return *body_; }
