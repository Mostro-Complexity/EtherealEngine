#pragma once
/**
 * @file transform_component.h
 * @brief Source code of Transform Components
 * 
 */
#include "../ecs.h"

#include <core/math/math_includes.h>

/**
 * @brief Class that contains and calculates spatial information of entities
 * 
 * @remark NOTE: customize your component by refering @link link-engine/runtime/meta/meta.h @endlink
 * 
 */
class transform_component : public runtime::component_impl<transform_component> {
  SERIALIZABLE(transform_component)
  REFLECTABLEV(transform_component, runtime::component)

public:
  /**
   * @brief Construct a new transform component 
   * 
   */
  transform_component() = default;

  //-----------------------------------------------------------------------------
  //  Name : ~transform_component ()
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  ~transform_component() override;

  //-------------------------------------------------------------------------
  // Public Static Methods
  //-------------------------------------------------------------------------
  //-----------------------------------------------------------------------------
  //  Name : resolve ()
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  void resolve(bool force = false);

  //-----------------------------------------------------------------------------
  //  Name : is_dirty (virtual )
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  void set_dirty(bool dirty);
  bool is_dirty() const;
  //-----------------------------------------------------------------------------
  //  Name : on_entity_set (virtual )
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  virtual void on_entity_set() override;

  //-----------------------------------------------------------------------------
  //  Name : get_local_transform ()
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  const math::transform& get_local_transform() const;

  //-----------------------------------------------------------------------------
  //  Name : get_transform ()
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  const math::transform& get_transform();

  //-----------------------------------------------------------------------------
  //  Name : get_position ()
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  const math::vec3& get_position();

  //-----------------------------------------------------------------------------
  //  Name : get_rotation ()
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  math::quat get_rotation();

  //-----------------------------------------------------------------------------
  //  Name : get_x_axis ()
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  math::vec3 get_x_axis();

  //-----------------------------------------------------------------------------
  //  Name : get_y_axis ()
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  math::vec3 get_y_axis();

  //-----------------------------------------------------------------------------
  //  Name : get_z_axis ()
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  math::vec3 get_z_axis();

  //-----------------------------------------------------------------------------
  //  Name : get_scale()
  /// <summary>
  /// Retrieve the current scale of the node along its world space axes.
  /// </summary>
  //-----------------------------------------------------------------------------
  math::vec3 get_scale();

  //-----------------------------------------------------------------------------
  //  Name : get_local_position ()
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  const math::vec3& get_local_position();

  //-----------------------------------------------------------------------------
  //  Name : get_local_rotation ()
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  math::quat get_local_rotation();

  //-----------------------------------------------------------------------------
  //  Name : get_local_x_axis ()
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  math::vec3 get_local_x_axis();

  //-----------------------------------------------------------------------------
  //  Name : get_local_y_axis ()
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  math::vec3 get_local_y_axis();

  //-----------------------------------------------------------------------------
  //  Name : get_local_z_axis ()
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  math::vec3 get_local_z_axis();

  //-----------------------------------------------------------------------------
  //  Name : get_local_scale ()
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  math::vec3 get_local_scale();

  //-----------------------------------------------------------------------------
  //  Name : look_at (virtual )
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  void look_at(float x, float y, float z);

  //-----------------------------------------------------------------------------
  //  Name : look_at (virtual )
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  void look_at(const math::vec3& point);

  //-----------------------------------------------------------------------------
  //  Name : look_at ( )
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  void look_at(const math::vec3& eye, const math::vec3& at, const math::vec3& up);
  //-----------------------------------------------------------------------------
  //  Name : set_position()
  /// <summary>
  /// Set the current world space position of the node.
  /// Note : This bypasses the physics system, so should really only be used
  /// for initialization purposes.
  /// </summary>
  //-----------------------------------------------------------------------------
  void set_position(const math::vec3& position);

  //-----------------------------------------------------------------------------
  //  Name : set_local_position()
  /// <summary>
  /// Set the current local space position of the node.
  /// Note : This bypasses the physics system, so should really only be used
  /// for initialization purposes.
  /// </summary>
  //-----------------------------------------------------------------------------
  void set_local_position(const math::vec3& position);

  //-----------------------------------------------------------------------------
  //  Name : move()
  /// <summary>
  /// Move the current position of the node by the specified amount.
  /// </summary>
  //-----------------------------------------------------------------------------
  void move(const math::vec3& amount);

  //-----------------------------------------------------------------------------
  //  Name : move_local()
  /// <summary>
  /// Move the current position of the node by the specified amount relative to
  /// its own local axes.
  /// </summary>
  //-----------------------------------------------------------------------------
  void move_local(const math::vec3& amount);

  //-----------------------------------------------------------------------------
  //  Name : rotate ( )
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  void rotate(float x, float y, float z);

  //-----------------------------------------------------------------------------
  //  Name : rotate_local ( )
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  void rotate_local(float x, float y, float z);

  //-----------------------------------------------------------------------------
  //  Name : rotate_axis ( )
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  void rotate_axis(float degrees, const math::vec3& axis);

  //-----------------------------------------------------------------------------
  //  Name : set_scale ( )
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  void set_scale(const math::vec3& s);

  //-----------------------------------------------------------------------------
  //  Name : set_local_scale ( )
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  void set_local_scale(const math::vec3& scale);

  //-----------------------------------------------------------------------------
  //  Name : set_rotation ( )
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  void set_rotation(const math::quat& rotation);

  //-----------------------------------------------------------------------------
  //  Name : set_local_rotation ( )
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  void set_local_rotation(const math::quat& rotation);

  //-----------------------------------------------------------------------------
  //  Name : reset_rotation ( )
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  void reset_rotation();

  //-----------------------------------------------------------------------------
  //  Name : reset_scale ( )
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  void reset_scale();

  //-----------------------------------------------------------------------------
  //  Name : reset_local_rotation ( )
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  void reset_local_rotation();

  //-----------------------------------------------------------------------------
  //  Name : reset_local_scale ( )
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  void reset_local_scale();

  //-----------------------------------------------------------------------------
  //  Name : reset_pivot ( )
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  void reset_pivot();

  //-----------------------------------------------------------------------------
  //  Name : set_local_transform ( )
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  void set_local_transform(const math::transform& trans);

  //-----------------------------------------------------------------------------
  //  Name : set_transform ( )
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  void set_transform(const math::transform& trans);

  //-----------------------------------------------------------------------------
  //  Name : can_adjust_pivot ( )
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  bool can_adjust_pivot() const;

  //-----------------------------------------------------------------------------
  //  Name : can_scale ( )
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  bool can_scale() const;

  //-----------------------------------------------------------------------------
  //  Name : can_rotate ( )
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  bool can_rotate() const;

  //-----------------------------------------------------------------------------
  //  Name : set_parent ( )
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  void set_parent(runtime::entity parent, bool world_position_stays, bool local_position_stays);

  //-----------------------------------------------------------------------------
  //  Name : set_parent ( )
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  void set_parent(runtime::entity parent);

  //-----------------------------------------------------------------------------
  //  Name : get_parent ()
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  const runtime::entity& get_parent() const;

  //-----------------------------------------------------------------------------
  //  Name : get_children ()
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  const std::vector<runtime::entity>& get_children() const;

  //-----------------------------------------------------------------------------
  //  Name : attach_child ()
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  void attach_child(const runtime::entity& child);

  //-----------------------------------------------------------------------------
  //  Name : remove_child ()
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  void remove_child(const runtime::entity& child);

  //-----------------------------------------------------------------------------
  //  Name : cleanup_dead_children ()
  /// <summary>
  ///
  ///
  ///
  /// </summary>
  //-----------------------------------------------------------------------------
  void cleanup_dead_children();

protected:
  void apply_transform(math::transform& trans);
  void apply_local_transform(const math::transform& trans);

  //-------------------------------------------------------------------------
  // Protected Member Variables
  //-------------------------------------------------------------------------
  /// Parent object.
  runtime::entity parent_;
  /// Children objects.
  std::vector<runtime::entity> children_;
  /// Local transformation relative to the parent
  math::transform local_transform_;
  /// Cached world transformation at pivot point.
  math::transform world_transform_;
  /// Should recalc world transform.
  bool dirty_ = true;
};
