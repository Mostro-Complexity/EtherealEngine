#include "box_collider_component.hpp"
#include "component.hpp"

#include "../../core/physics/collider.hpp"
#include "../../core/math/vector.hpp"  //TODO: delete

#include <core/serialization/types/vector.hpp>

REFLECT(box_collider_component) {
  rttr::registration::class_<box_collider_component>("box_collider_component")(
    rttr::metadata("category", "RENDERING"), rttr::metadata("pretty_name", "BoxCollider"))
    .constructor<>()(rttr::policy::ctor::as_std_shared_ptr);
}

SAVE(box_collider_component) {
  try_save(ar, cereal::make_nvp("base_type", cereal::base_class<runtime::component>(&obj)));
}
SAVE_INSTANTIATE(box_collider_component, cereal::oarchive_associative_t);
SAVE_INSTANTIATE(box_collider_component, cereal::oarchive_binary_t);

LOAD(box_collider_component) {
  try_load(ar, cereal::make_nvp("base_type", cereal::base_class<runtime::component>(&obj)));
}
LOAD_INSTANTIATE(box_collider_component, cereal::iarchive_associative_t);
LOAD_INSTANTIATE(box_collider_component, cereal::iarchive_binary_t);
