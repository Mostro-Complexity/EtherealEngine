#pragma once
/**
 * @file meta.h
 * @brief Headers for reflection
 *
 */
#include "core/meta.h"

#include "assets/asset_handle.hpp"

/**
 * @section 1 Customize Your Component
 *
 * @subsection 1 Write Your Component Code
 * The implemented cpp file of components need to be added in @link
 * engine/runtime/ecs/components @endlink.
 *
 * @subsection 2 Write RTTR Relection Setup
 * Write RTTR setup code of your component.
 * All of components setup code are located at @link /runtime/meta/ecs/components @endlink
 * @remark NOTE: hpp file should be include at the following part
 *
 * @subsection 3 Serialize the class of the objects
 * Serialize the class of the objects refered by your customize components
 *
 */
#include "ecs/components/audio_listener_component.hpp"
#include "ecs/components/audio_source_component.hpp"
#include "ecs/components/camera_component.hpp"
#include "ecs/components/component.hpp"
#include "ecs/components/light_component.hpp"
#include "ecs/components/model_component.hpp"
#include "ecs/components/reflection_probe_component.hpp"
#include "ecs/components/transform_component.hpp"
#include "ecs/components/rigidbody_component.hpp"
#include "ecs/components/box_collider_component.hpp"
#include "ecs/entity.hpp"

#include "rendering/camera.hpp"
#include "rendering/light.hpp"
#include "rendering/material.hpp"
#include "rendering/mesh.hpp"
#include "rendering/model.hpp"
#include "rendering/program.hpp"
#include "rendering/reflection_probe.hpp"
#include "rendering/standard_material.hpp"
#include "rendering/texture.hpp"

#include "animation/animation.hpp"
