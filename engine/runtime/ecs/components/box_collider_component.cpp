#include "box_collider_component.h"

box_collider_component::box_collider_component()
  : collider_(std::make_shared<physics::box_collider>(btVector3(1, 1, 1))) {}

box_collider_component::~box_collider_component() {}

void box_collider_component::calculate_local_inertia(float mass, math::vec3 local_inertia) {
  btVector3 _local_inertia;
  _local_inertia.setX(local_inertia.x);
  _local_inertia.setY(local_inertia.y);
  _local_inertia.setZ(local_inertia.z);
  collider_->calculateLocalInertia(mass, _local_inertia);
}

const physics::box_collider& box_collider_component::get_collider() { return *collider_; }

std::shared_ptr<physics::box_collider> box_collider_component::get_collider_shared() {
  return collider_;
}
