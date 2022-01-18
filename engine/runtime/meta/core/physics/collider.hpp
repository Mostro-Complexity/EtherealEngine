#pragma once
#include <core/physics/bullet_includes.h>
#include <core/serialization/serialization.h>

// namespace cereal {
//   template <typename Archive>
//   inline void SERIALIZE_FUNCTION_NAME(Archive& ar, physics::rigidbody& obj) {

//     auto pos = obj.get_position();
//     auto rot = obj.get_rotation();
//     auto scale = obj.get_scale();

//     try_serialize(ar, cereal::make_nvp("position", pos));
//     try_serialize(ar, cereal::make_nvp("rotation", rot));
//     try_serialize(ar, cereal::make_nvp("scale", scale));

//     obj.set_position(pos);
//     obj.set_rotation(rot);
//     obj.set_scale(scale);
//   }

// }  // namespace cereal