#ifndef MML_JOYSTICKIMPLFREEBSD_HPP
#define MML_JOYSTICKIMPLFREEBSD_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <dev/usb/usbhid.h>
#include <usbhid.h>
#include <vector>

namespace mml {
  namespace priv {
    ////////////////////////////////////////////////////////////
    /// \brief FreeBSD implementation of joysticks
    ///
    /// This code has been tested on FreeBSD 9.1 only.
    ////////////////////////////////////////////////////////////
    class joystick_impl {
    public:
      ////////////////////////////////////////////////////////////
      /// \brief Perform the global initialization of the joystick module
      ///
      ////////////////////////////////////////////////////////////
      static void initialize();

      ////////////////////////////////////////////////////////////
      /// \brief Perform the global cleanup of the joystick module
      ///
      ////////////////////////////////////////////////////////////
      static void cleanup();

      ////////////////////////////////////////////////////////////
      /// \brief Check if a joystick is currently connected
      ///
      /// \param index Index of the joystick to check
      ///
      /// \return True if the joystick is connected, false otherwise
      ///
      ////////////////////////////////////////////////////////////
      static bool isConnected(unsigned int index);

      ////////////////////////////////////////////////////////////
      /// \brief Open the joystick
      ///
      /// \param index Index assigned to the joystick
      ///
      /// \return True on success, false on failure
      ///
      ////////////////////////////////////////////////////////////
      bool open(unsigned int index);

      ////////////////////////////////////////////////////////////
      /// \brief Close the joystick
      ///
      ////////////////////////////////////////////////////////////
      void close();

      ////////////////////////////////////////////////////////////
      /// \brief Get the joystick capabilities
      ///
      /// \return Joystick capabilities
      ///
      ////////////////////////////////////////////////////////////
      JoystickCaps get_capabilities() const;

      ////////////////////////////////////////////////////////////
      /// \brief Get the joystick identification
      ///
      /// \return Joystick identification
      ///
      ////////////////////////////////////////////////////////////
      Joystick::Identification getIdentification() const;

      ////////////////////////////////////////////////////////////
      /// \brief Update the joystick and get its new state
      ///
      /// \return Joystick state
      ///
      ////////////////////////////////////////////////////////////
      JoystickState update();

    private:
      ////////////////////////////////////////////////////////////
      // Member data
      ////////////////////////////////////////////////////////////
      int                      _file;            ///< File descriptor of the joystick
      report_desc_t            m_desc;           ///< USB report descriptor
      int                      m_id;             ///< USB id
      std::vector<char>        m_buffer;         ///< USB HID buffer
      int                      m_length;         ///< Buffer length
      Joystick::Identification _identification;  ///< Joystick identification
      JoystickState            _state;           ///< Current state of the joystick
    };

  }  // namespace priv

}  // namespace mml

#endif  // MML_JOYSTICKIMPLFREEBSD_HPP
