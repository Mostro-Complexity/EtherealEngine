#pragma once

#include "../../../ecs/components/box_collider_component.h"
#include <core/reflection/reflection.h>
#include <core/serialization/serialization.h>

REFLECT_EXTERN(box_collider_component);
SAVE_EXTERN(box_collider_component);
LOAD_EXTERN(box_collider_component);

#include <core/serialization/associative_archive.h>
#include <core/serialization/binary_archive.h>
CEREAL_REGISTER_TYPE(box_collider_component)
