#include "rigidbody_component.hpp"
#include "component.hpp"

#include "../../core/physics/rigidbody.hpp"

#include <core/serialization/types/vector.hpp>

REFLECT(rigidbody_component) {
  rttr::registration::class_<rigidbody_component>("rigidbody_component")(
    rttr::metadata("category", "RENDERING"), rttr::metadata("pretty_name", "Rigidbody"))
    .constructor<>()(rttr::policy::ctor::as_std_shared_ptr)
    .property("mass", &rigidbody_component::get_mass, &rigidbody_component::set_mass)(
      rttr::metadata("pretty_name", "Mass"),
      rttr::metadata("tooltip", "This is the mass of the entity.\n"))
    .property(
      "gravity",
      &rigidbody_component::get_gravity_validity,
      &rigidbody_component::set_gravity_validity)(
      rttr::metadata("pretty_name", "Gravity"),
      rttr::metadata("tooltip", "This is the gravity of the entity.\n"));
}

SAVE(rigidbody_component) {
  try_save(ar, cereal::make_nvp("base_type", cereal::base_class<runtime::component>(&obj)));
  try_save(ar, cereal::make_nvp("mass", obj.mass_));
  try_save(ar, cereal::make_nvp("enable_gravity", obj.gravity_enabled_));
}
SAVE_INSTANTIATE(rigidbody_component, cereal::oarchive_associative_t);
SAVE_INSTANTIATE(rigidbody_component, cereal::oarchive_binary_t);

LOAD(rigidbody_component) {
  try_load(ar, cereal::make_nvp("base_type", cereal::base_class<runtime::component>(&obj)));
  try_load(ar, cereal::make_nvp("mass", obj.mass_));
  try_load(ar, cereal::make_nvp("enable_gravity", obj.gravity_enabled_));
}
LOAD_INSTANTIATE(rigidbody_component, cereal::iarchive_associative_t);
LOAD_INSTANTIATE(rigidbody_component, cereal::iarchive_binary_t);
