#pragma once
/**
 * @file rigidbody_component.h
 * @author Mostro
 * @brief Source code of rigidbody_component Components
 * @date 2022-01-14
 *
 */
#include "../ecs.h"

#include <core/common/basetypes.hpp>
#include <core/math/math_includes.h>
#include <core/physics/bullet_includes.h>
#include <core/physics/rigidbody.h>

enum class force_mode { acceleration, force, impulse, velocity_change };

enum class query_trigger_interaction { use_global, Ignore, Collide };

// TODO: implement it
// struct raycast_hit {
//  articulation_body ab;  // The ArticulationBody of the collider that was hit.If the collider is
//  not
//                         // attached to an articulation body then it is null.
//  barycentric_coordinate bc;  // The barycentric coordinate of the triangle we hit.
//  collider c;                 // The Collider that was hit.
//  distance d;                 // The distance from the ray's origin to the impact point.
//  lightmap_coord lc;          // The uv lightmap coordinate at the impact point.
//  normal n;                   // The normal of the surface the ray hit.
//  point p;                    // The impact point in world space where the ray hit the collider.
//  rigidbody r;  // The Rigidbody of the collider that was hit. If the collider is not attached to
//  a
//                // rigidbody then it is null.
//  texture_coord tc;    // The uv texture coordinate at the collision location.
//  texture_coord2 tc2;  // The secondary uv texture coordinate at the impact point.
//  transform t;         // The Transform of the rigidbody or collider that was hit.
//  triangle_index ti;   // The index of the triangle that was hit.
//};

//-----------------------------------------------------------------------------
/**
 * @brief Class that contains physical data for rigidbody.
 *
 * @remark NOTE: if you use rigidbody, you can't bypass physics engine
 * @remark NOTE: customize your component by refering @link link-engine/runtime/meta/meta.h @endlink
 */
class rigidbody_component : public runtime::component_impl<rigidbody_component> {
  SERIALIZABLE(rigidbody_component)
  REFLECTABLEV(rigidbody_component, runtime::component)
public:
  /**
   * @brief Construct a new rigidbody component
   *
   */
  rigidbody_component();
  virtual ~rigidbody_component();

  //-------------------------------------------------------------------------
  // Public Methods
  //-------------------------------------------------------------------------
  //-----------------------------------------------------------------------------
  //  Name : awake ()
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  // virtual void awake() override;

  //-----------------------------------------------------------------------------
  //  Name : add_force ()
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  void add_force(math::vec3 force, force_mode mode);

  //-----------------------------------------------------------------------------
  //  Name : add_explosion_force ()
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  // void add_explosion_force(
  //  float explosionForce, math::vec3 explosionPosition, float explosionRadius,
  //  float upwardsModifier = 0.0f, force_mode mode = force_mode::force);

  //-----------------------------------------------------------------------------
  //  Name : add_force_at ()
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  // void add_force_at(math::vec3 force, math::vec3 position, force_mode mode = force_mode::force);

  //-----------------------------------------------------------------------------
  //  Name : add_relative_force ()
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  // void add_relative_force(math::vec3 force, force_mode mode = force_mode::force);

  //-----------------------------------------------------------------------------
  //  Name : add_relative_torque ()
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  // void add_relative_torque(math::vec3 torque, force_mode mode = force_mode::force);

  //-----------------------------------------------------------------------------
  //  Name : add_torque ()
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  // void add_torque(math::vec3 torque, force_mode mode = force_mode::force);

  //-----------------------------------------------------------------------------
  //  Name : set_far_clip ()
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  // void closest_point_on_bounds(math::vec3 position);

  //-----------------------------------------------------------------------------
  //  Name : get_rigidbody ()
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  const physics::rigidbody& get_rigidbody() const;

  //-----------------------------------------------------------------------------
  //  Name : get_point_velocity ()
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  // void get_point_velocity(math::vec3 worldPoint);

  //-----------------------------------------------------------------------------
  //  Name : get_fov ()
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  // math::vec3 get_relative_point_velocity(math::vec3 relativePoint);

  //-----------------------------------------------------------------------------
  //  Name : get_fov ()
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  // void move_position(math::vec3 position);

  //-----------------------------------------------------------------------------
  //  Name : get_fov ()
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  // void move_rotation(math::quat rot);

  //-----------------------------------------------------------------------------
  //  Name : get_fov ()
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  // void reset_center_of_mass();

  //-----------------------------------------------------------------------------
  //  Name : get_fov ()
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  // bool is_sleeping();
  //-----------------------------------------------------------------------------
  //  Name : reset_inertia_tensor ()
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  // void reset_inertia_tensor();

  //-----------------------------------------------------------------------------
  //  Name : set_density ()
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  // void set_density(float density);

  //-----------------------------------------------------------------------------
  //  Name : sleep ()
  /// <summary>
  /// Forces a rigidbody to sleep at least one frame.
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  // void sleep();

  //-----------------------------------------------------------------------------
  //  Name : start ()
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  virtual void start() override;

  //-----------------------------------------------------------------------------
  //  Name : sweep_test ()
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  // TODO: implement it
  // bool sweep_test(
  //  math::vec3 direction, raycast_hit& hitInfo, float max_distance = INFINITY,
  //  query_trigger_interaction queryTriggerInteraction = query_trigger_interaction::use_global);

  //-----------------------------------------------------------------------------
  //  Name : sweep_test_all ()
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  // TODO: implement it
  // std::vector<raycast_hit> sweep_test_all(
  //  math::vec3 direction, float maxDistance = INFINITY,
  //  query_trigger_interaction queryTriggerInteraction = query_trigger_interaction::use_global);

  //-----------------------------------------------------------------------------
  //  Name : wake_up ()
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  // void wake_up();
  void set_gravity_validity(bool flag);

  bool get_gravity_validity() const;

  void update();

  float get_mass() const;

  void set_mass(float mass);

  void set_rigidbody(const physics::rigidbody& body);
  void set_rigidbody(physics::rigidbody&& body);

private:
  //-------------------------------------------------------------------------
  // Private Member Variables.
  //-------------------------------------------------------------------------
  float mass_;
  bool gravity_enabled_;
  std::shared_ptr<physics::rigidbody> body_;
  math::vec3 velocity_;
};
