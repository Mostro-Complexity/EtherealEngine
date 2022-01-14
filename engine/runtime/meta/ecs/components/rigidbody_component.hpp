#pragma once

#include "../../../ecs/components/rigidbody_component.h"
#include <core/reflection/reflection.h>
#include <core/serialization/serialization.h>

REFLECT_EXTERN(rigidbody_component);
SAVE_EXTERN(rigidbody_component);
LOAD_EXTERN(rigidbody_component);

#include <core/serialization/associative_archive.h>
#include <core/serialization/binary_archive.h>
CEREAL_REGISTER_TYPE(rigidbody_component)
