#pragma once
/**
 * @file model_component.h
 * @brief Source code of Model Components
s *
 */
#include "../../rendering/model.h"
#include "../ecs.h"

class material;

/**
 * @brief Class that contains core data for meshes
 *
 */
class model_component : public runtime::component_impl<model_component> {
  SERIALIZABLE(model_component)
  REFLECTABLEV(model_component, component)

public:
  /**
   * @brief Set the casts shadow validity
   *
   * @param cast_shadow bool
   */
  void set_casts_shadow(bool cast_shadow);

  /**
   * @brief Set the casts reflection validity
   *
   * @param casts_reflection
   */
  void set_casts_reflection(bool casts_reflection);

  /**
   * @brief Set the static mode validity
   *
   * @param is_static
   */
  void set_static(bool is_static);

  /**
   * @brief
   *
   * @return true
   * @return false
   */
  bool casts_shadow() const;

  /**
   * @brief
   *
   * @return true
   * @return false
   */
  bool casts_reflection() const;

  /**
   * @brief
   *
   * @return true
   * @return false
   */
  bool is_static() const;

  /**
   * @brief Get the model
   *
   * @return const model&
   */
  const model& get_model() const;

  /**
   * @brief Set the model
   *
   * @param model
   */
  void set_model(const model& model);

  /**
   * @brief Set the bone entities
   *
   * @param bone_entities
   */
  void set_bone_entities(const std::vector<runtime::entity>& bone_entities);

  /**
   * @brief Get the bone entities
   *
   * @return const std::vector<runtime::entity>&
   */
  const std::vector<runtime::entity>& get_bone_entities() const;

  /**
   * @brief Set the bone transforms object
   *
   * @param bone_transforms
   */
  void set_bone_transforms(const std::vector<math::transform>& bone_transforms);

  /**
   * @brief Get the bone transforms object
   *
   * @return const std::vector<math::transform>&
   */
  const std::vector<math::transform>& get_bone_transforms() const;

private:
  /**
   * @brief
   *
   */
  bool static_ = true;
  ///
  bool casts_shadow_ = true;
  ///
  bool casts_reflection_ = true;
  ///
  model model_;
  ///
  std::vector<runtime::entity> bone_entities_;
  std::vector<math::transform> bone_transforms_;
};
