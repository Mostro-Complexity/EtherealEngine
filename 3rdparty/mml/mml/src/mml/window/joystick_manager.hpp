#ifndef MML_JOYSTICKMANAGER_HPP
#define MML_JOYSTICKMANAGER_HPP

#include <mml/window/joystick.hpp>
#include <mml/window/joystick_impl.hpp>
#include <mml/system/non_copyable.hpp>

namespace mml {
  namespace priv {
    /// \brief Global joystick manager
    ///
    class joystick_manager : non_copyable {
    public:
      /// \brief Get the global unique instance of the manager
      ///
      /// \return Unique instance of the joystick manager
      static joystick_manager& get_instance();

      /// \brief Get the capabilities for an open joystick
      ///
      /// \param joystick Index of the joystick
      ///
      /// \return Capabilities of the joystick
      const joystick_caps& get_capabilities(unsigned int joystick) const;

      /// \brief Get the current state of an open joystick
      ///
      /// \param joystick Index of the joystick
      ///
      /// \return Current state of the joystick
      const joystick_state& get_state(unsigned int joystick) const;

      /// \brief Get the identification for an open joystick
      ///
      /// \param joystick Index of the joystick
      ///
      /// \return identification for the joystick
      const joystick::identification& get_identification(unsigned int joystick) const;

      /// \brief Update the state of all the joysticks
      ///
      void update();

    private:
      /// \brief Default constructor
      ///
      joystick_manager();

      /// \brief Destructor
      ///
      ~joystick_manager();

      /// \brief joystick information and state
      ///
      struct item {
        joystick_impl joystick;                   ///< joystick implementation
        joystick_state state;                     ///< The current joystick state
        joystick_caps capabilities;               ///< The joystick capabilities
        joystick::identification identification;  ///< The joystick identification
      };

      item m_joysticks[joystick::count];  ///< Joysticks information and state
    };

  }  // namespace priv

}  // namespace mml

#endif  // MML_JOYSTICKMANAGER_HPP
