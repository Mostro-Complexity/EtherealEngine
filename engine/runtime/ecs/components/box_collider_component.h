#pragma once
//-----------------------------------------------------------------------------
// rigidbody_component Header Includes
//-----------------------------------------------------------------------------
// NOTE: basic headers
#include "../ecs.h"

#include <core/common/basetypes.hpp>
#include <core/math/math_includes.h>
#include <core/physics/bullet_includes.h>
#include <core/physics/collider.h>

//-----------------------------------------------------------------------------
// Forward Declarations
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// Main Class Declarations
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//  Name : box_collider_component (Class)
/// <summary>
///
///
/// </summary>
//-----------------------------------------------------------------------------
class box_collider_component : public runtime::component_impl<box_collider_component> {
  SERIALIZABLE(box_collider_component)
  REFLECTABLEV(box_collider_component, runtime::component)
public:
  //-------------------------------------------------------------------------
  // Constructors & Destructors
  //-------------------------------------------------------------------------
  box_collider_component();
  virtual ~box_collider_component();

  void calculate_local_inertia(float mass, math::vec3 local_inertia);

  physics::box_collider get_collider();

private:
  //-------------------------------------------------------------------------
  // Private Member Variables.
  //-------------------------------------------------------------------------
  physics::box_collider collider_;
};