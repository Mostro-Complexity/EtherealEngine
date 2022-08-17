#ifndef MML_KEYBOARD_HPP
  #define MML_KEYBOARD_HPP
  #include <windows.h>
  #include <mml/window/export.hpp>

namespace mml {
  /// \brief Give access to the real-time state of the keyboard
  ///
  class MML_WINDOW_API keyboard {
  public:
  /// \brief key codes
  ///
  #ifdef IMGUI_KEYBOARD_MAPPING
    enum ImGuiKey_ {
      // Keyboard
      ImGuiKey_None = 0,
      ImGuiKey_Tab = 512,  // == ImGuiKey_NamedKey_BEGIN
      ImGuiKey_LeftArrow,
      ImGuiKey_RightArrow,
      ImGuiKey_UpArrow,
      ImGuiKey_DownArrow,
      ImGuiKey_PageUp,
      ImGuiKey_PageDown,
      ImGuiKey_Home,
      ImGuiKey_End,
      ImGuiKey_Insert,
      ImGuiKey_Delete,
      ImGuiKey_Backspace,
      ImGuiKey_Space,
      ImGuiKey_Enter,
      ImGuiKey_Escape,
      ImGuiKey_LeftCtrl,
      ImGuiKey_LeftShift,
      ImGuiKey_LeftAlt,
      ImGuiKey_LeftSuper,
      ImGuiKey_RightCtrl,
      ImGuiKey_RightShift,
      ImGuiKey_RightAlt,
      ImGuiKey_RightSuper,
      ImGuiKey_Menu,
      ImGuiKey_0,
      ImGuiKey_1,
      ImGuiKey_2,
      ImGuiKey_3,
      ImGuiKey_4,
      ImGuiKey_5,
      ImGuiKey_6,
      ImGuiKey_7,
      ImGuiKey_8,
      ImGuiKey_9,
      ImGuiKey_A,
      ImGuiKey_B,
      ImGuiKey_C,
      ImGuiKey_D,
      ImGuiKey_E,
      ImGuiKey_F,
      ImGuiKey_G,
      ImGuiKey_H,
      ImGuiKey_I,
      ImGuiKey_J,
      ImGuiKey_K,
      ImGuiKey_L,
      ImGuiKey_M,
      ImGuiKey_N,
      ImGuiKey_O,
      ImGuiKey_P,
      ImGuiKey_Q,
      ImGuiKey_R,
      ImGuiKey_S,
      ImGuiKey_T,
      ImGuiKey_U,
      ImGuiKey_V,
      ImGuiKey_W,
      ImGuiKey_X,
      ImGuiKey_Y,
      ImGuiKey_Z,
      ImGuiKey_F1,
      ImGuiKey_F2,
      ImGuiKey_F3,
      ImGuiKey_F4,
      ImGuiKey_F5,
      ImGuiKey_F6,
      ImGuiKey_F7,
      ImGuiKey_F8,
      ImGuiKey_F9,
      ImGuiKey_F10,
      ImGuiKey_F11,
      ImGuiKey_F12,
      ImGuiKey_Apostrophe,    // '
      ImGuiKey_Comma,         // ,
      ImGuiKey_Minus,         // -
      ImGuiKey_Period,        // .
      ImGuiKey_Slash,         // /
      ImGuiKey_Semicolon,     // ;
      ImGuiKey_Equal,         // =
      ImGuiKey_LeftBracket,   // [
      ImGuiKey_Backslash,     // \ (this text inhibit multiline comment caused by backslash)
      ImGuiKey_RightBracket,  // ]
      ImGuiKey_GraveAccent,   // `
      ImGuiKey_CapsLock,
      ImGuiKey_ScrollLock,
      ImGuiKey_NumLock,
      ImGuiKey_PrintScreen,
      ImGuiKey_Pause,
      ImGuiKey_Keypad0,
      ImGuiKey_Keypad1,
      ImGuiKey_Keypad2,
      ImGuiKey_Keypad3,
      ImGuiKey_Keypad4,
      ImGuiKey_Keypad5,
      ImGuiKey_Keypad6,
      ImGuiKey_Keypad7,
      ImGuiKey_Keypad8,
      ImGuiKey_Keypad9,
      ImGuiKey_KeypadDecimal,
      ImGuiKey_KeypadDivide,
      ImGuiKey_KeypadMultiply,
      ImGuiKey_KeypadSubtract,
      ImGuiKey_KeypadAdd,
      ImGuiKey_KeypadEnter,
      ImGuiKey_KeypadEqual,

      // Gamepad (some of those are analog values, 0.0f to 1.0f)                              //
      // NAVIGATION action
      ImGuiKey_GamepadStart,        // Menu (Xbox)          + (Switch)   Start/Options (PS) // --
      ImGuiKey_GamepadBack,         // View (Xbox)          - (Switch)   Share (PS)         // --
      ImGuiKey_GamepadFaceUp,       // Y (Xbox)             X (Switch)   Triangle (PS)      // ->
                                    // ImGuiNavInput_Input
      ImGuiKey_GamepadFaceDown,     // A (Xbox)             B (Switch)   Cross (PS)         // ->
                                    // ImGuiNavInput_Activate
      ImGuiKey_GamepadFaceLeft,     // X (Xbox)             Y (Switch)   Square (PS)        // ->
                                    // ImGuiNavInput_Menu
      ImGuiKey_GamepadFaceRight,    // B (Xbox)             A (Switch)   Circle (PS)        // ->
                                    // ImGuiNavInput_Cancel
      ImGuiKey_GamepadDpadUp,       // D-pad Up                                             // ->
                                    // ImGuiNavInput_DpadUp
      ImGuiKey_GamepadDpadDown,     // D-pad Down                                           // ->
                                    // ImGuiNavInput_DpadDown
      ImGuiKey_GamepadDpadLeft,     // D-pad Left                                           // ->
                                    // ImGuiNavInput_DpadLeft
      ImGuiKey_GamepadDpadRight,    // D-pad Right                                          // ->
                                    // ImGuiNavInput_DpadRight
      ImGuiKey_GamepadL1,           // L Bumper (Xbox)      L (Switch)   L1 (PS)            // ->
                                    // ImGuiNavInput_FocusPrev + ImGuiNavInput_TweakSlow
      ImGuiKey_GamepadR1,           // R Bumper (Xbox)      R (Switch)   R1 (PS)            // ->
                                    // ImGuiNavInput_FocusNext + ImGuiNavInput_TweakFast
      ImGuiKey_GamepadL2,           // L Trigger (Xbox)     ZL (Switch)  L2 (PS) [Analog]
      ImGuiKey_GamepadR2,           // R Trigger (Xbox)     ZR (Switch)  R2 (PS) [Analog]
      ImGuiKey_GamepadL3,           // L Thumbstick (Xbox)  L3 (Switch)  L3 (PS)
      ImGuiKey_GamepadR3,           // R Thumbstick (Xbox)  R3 (Switch)  R3 (PS)
      ImGuiKey_GamepadLStickUp,     // [Analog]                                             // ->
                                    // ImGuiNavInput_LStickUp
      ImGuiKey_GamepadLStickDown,   // [Analog]                                             // ->
                                    // ImGuiNavInput_LStickDown
      ImGuiKey_GamepadLStickLeft,   // [Analog]                                             // ->
                                    // ImGuiNavInput_LStickLeft
      ImGuiKey_GamepadLStickRight,  // [Analog]                                             // ->
                                    // ImGuiNavInput_LStickRight
      ImGuiKey_GamepadRStickUp,     // [Analog]
      ImGuiKey_GamepadRStickDown,   // [Analog]
      ImGuiKey_GamepadRStickLeft,   // [Analog]
      ImGuiKey_GamepadRStickRight,  // [Analog]

      // Keyboard Modifiers
      // - This is mirroring the data also written to io.KeyCtrl, io.KeyShift, io.KeyAlt,
      // io.KeySuper, in a format allowing
      //   them to be accessed via standard key API, allowing calls such as IsKeyPressed(),
      //   IsKeyReleased(), querying duration etc.
      // - Code polling every keys (e.g. an interface to detect a key press for input mapping) might
      // want to ignore those
      //   and prefer using the real keys (e.g. ImGuiKey_LeftCtrl, ImGuiKey_RightCtrl instead of
      //   ImGuiKey_ModCtrl).
      // - In theory the value of keyboard modifiers should be roughly equivalent to a logical or of
      // the equivalent left/right keys.
      //   In practice: it's complicated; mods are often provided from different sources. Keyboard
      //   layout, IME, sticky keys and backends tend to interfere and break that equivalence. The
      //   safer decision is to relay that ambiguity down to the end-user...
      ImGuiKey_ModCtrl,
      ImGuiKey_ModShift,
      ImGuiKey_ModAlt,
      ImGuiKey_ModSuper,

      ImGuiKey_COUNT,  // No valid ImGuiKey is ever greater than this value

      // [Internal] Prior to 1.87 we required user to fill io.KeysDown[512] using their own native
      // index + a io.KeyMap[] array. We are ditching this method but keeping a legacy path for user
      // code doing e.g. IsKeyPressed(MY_NATIVE_KEY_CODE)
      ImGuiKey_NamedKey_BEGIN = 512,
      ImGuiKey_NamedKey_END = ImGuiKey_COUNT,
      ImGuiKey_NamedKey_COUNT = ImGuiKey_NamedKey_END - ImGuiKey_NamedKey_BEGIN,
    #ifdef IMGUI_DISABLE_OBSOLETE_KEYIO
      ImGuiKey_KeysData_SIZE = ImGuiKey_NamedKey_COUNT,  // Size of KeysData[]: only hold named keys
      ImGuiKey_KeysData_OFFSET = ImGuiKey_NamedKey_BEGIN  // First key stored in KeysData[0]
    #else
      ImGuiKey_KeysData_SIZE =
        ImGuiKey_COUNT,             // Size of KeysData[]: hold legacy 0..512 keycodes + named keys
      ImGuiKey_KeysData_OFFSET = 0  // First key stored in KeysData[0]
    #endif

    #ifndef IMGUI_DISABLE_OBSOLETE_FUNCTIONS
      ,
      ImGuiKey_KeyPadEnter = ImGuiKey_KeypadEnter  // Renamed in 1.87
    #endif
    };

    enum class key {
      Unknown = ImGuiKey_None,           ///< Unhandled key
      A = ImGuiKey_A,                    ///< The A key
      B = ImGuiKey_B,                    ///< The B key
      C = ImGuiKey_C,                    ///< The C key
      D = ImGuiKey_D,                    ///< The D key
      E = ImGuiKey_E,                    ///< The E key
      F = ImGuiKey_F,                    ///< The F key
      G = ImGuiKey_G,                    ///< The G key
      H = ImGuiKey_H,                    ///< The H key
      I = ImGuiKey_I,                    ///< The I key
      J = ImGuiKey_J,                    ///< The J key
      K = ImGuiKey_K,                    ///< The K key
      L = ImGuiKey_L,                    ///< The L key
      M = ImGuiKey_M,                    ///< The M key
      N = ImGuiKey_N,                    ///< The N key
      O = ImGuiKey_O,                    ///< The O key
      P = ImGuiKey_P,                    ///< The P key
      Q = ImGuiKey_Q,                    ///< The Q key
      R = ImGuiKey_R,                    ///< The R key
      S = ImGuiKey_S,                    ///< The S key
      T = ImGuiKey_T,                    ///< The T key
      U = ImGuiKey_U,                    ///< The U key
      V = ImGuiKey_V,                    ///< The V key
      W = ImGuiKey_W,                    ///< The W key
      X = ImGuiKey_X,                    ///< The X key
      Y = ImGuiKey_Y,                    ///< The Y key
      Z = ImGuiKey_Z,                    ///< The Z key
      Num0 = ImGuiKey_0,                 ///< The 0 key
      Num1 = ImGuiKey_1,                 ///< The 1 key
      Num2 = ImGuiKey_2,                 ///< The 2 key
      Num3 = ImGuiKey_3,                 ///< The 3 key
      Num4 = ImGuiKey_4,                 ///< The 4 key
      Num5 = ImGuiKey_5,                 ///< The 5 key
      Num6 = ImGuiKey_6,                 ///< The 6 key
      Num7 = ImGuiKey_7,                 ///< The 7 key
      Num8 = ImGuiKey_8,                 ///< The 8 key
      Num9 = ImGuiKey_9,                 ///< The 9 key
      Escape = ImGuiKey_Escape,          ///< The Escape key
      LControl = ImGuiKey_LeftCtrl,      ///< The left Control key
      LShift = ImGuiKey_LeftShift,       ///< The left Shift key
      LAlt = ImGuiKey_LeftAlt,           ///< The left Alt key
      LSystem = ImGuiKey_LeftSuper,      ///< The left OS specific key: window (Windows and Linux),
                                         ///< apple (MacOS X), ...
      RControl = ImGuiKey_RightCtrl,     ///< The right Control key
      RShift = ImGuiKey_RightShift,      ///< The right Shift key
      RAlt = ImGuiKey_RightAlt,          ///< The right Alt key
      RSystem = ImGuiKey_RightSuper,     ///< The right OS specific key: window (Windows and Linux),
                                         ///< apple (MacOS X), ...
      Menu = ImGuiKey_Menu,              ///< The Menu key
      LBracket = ImGuiKey_LeftBracket,   ///< The [ key
      RBracket = ImGuiKey_RightBracket,  ///< The ] key
      Semicolon = ImGuiKey_Semicolon,    ///< The ; key
      Comma = ImGuiKey_Comma,            ///< The , key
      Period = ImGuiKey_Period,          ///< The . key
      Quote = ImGuiKey_Apostrophe,       ///< The ' key
      Slash = ImGuiKey_Slash,            ///< The / key
      Backslash = ImGuiKey_Backslash,    ///< The \ key
      Tilde = ImGuiKey_GraveAccent,      ///< The ~ key
      Equal = ImGuiKey_Equal,            ///< The = key
      Hyphen = ImGuiKey_Minus,           ///< The - key (hyphen)
      Space = ImGuiKey_Space,            ///< The Space key
      Enter = ImGuiKey_Enter,            ///< The Enter/Return key
      Backspace = ImGuiKey_Backspace,    ///< The Backspace key
      Tab = ImGuiKey_Tab,                ///< The Tabulation key
      PageUp = ImGuiKey_PageUp,          ///< The Page up key
      PageDown = ImGuiKey_PageDown,      ///< The Page down key
      End = ImGuiKey_End,                ///< The End key
      Home = ImGuiKey_Home,              ///< The Home key
      Insert = ImGuiKey_Insert,          ///< The Insert key
      Delete = ImGuiKey_Delete,          ///< The Delete key
      Add = ImGuiKey_Equal,              ///< The + key
      Subtract = ImGuiKey_Minus,         ///< The - key (minus, usually from numpad)
      Multiply = ImGuiKey_8,             ///< The * key
      Divide = ImGuiKey_Slash,           ///< The / key
      Left = ImGuiKey_LeftArrow,         ///< Left arrow
      Right = ImGuiKey_RightArrow,       ///< Right arrow
      Up = ImGuiKey_UpArrow,             ///< Up arrow
      Down = ImGuiKey_DownArrow,         ///< Down arrow
      Numpad0 = ImGuiKey_Keypad0,        ///< The numpad 0 key
      Numpad1 = ImGuiKey_Keypad1,        ///< The numpad 1 key
      Numpad2 = ImGuiKey_Keypad2,        ///< The numpad 2 key
      Numpad3 = ImGuiKey_Keypad3,        ///< The numpad 3 key
      Numpad4 = ImGuiKey_Keypad4,        ///< The numpad 4 key
      Numpad5 = ImGuiKey_Keypad5,        ///< The numpad 5 key
      Numpad6 = ImGuiKey_Keypad6,        ///< The numpad 6 key
      Numpad7 = ImGuiKey_Keypad7,        ///< The numpad 7 key
      Numpad8 = ImGuiKey_Keypad8,        ///< The numpad 8 key
      Numpad9 = ImGuiKey_Keypad9,        ///< The numpad 9 key
      F1 = ImGuiKey_F1,                  ///< The F1 key
      F2 = ImGuiKey_F2,                  ///< The F2 key
      F3 = ImGuiKey_F3,                  ///< The F3 key
      F4 = ImGuiKey_F4,                  ///< The F4 key
      F5 = ImGuiKey_F5,                  ///< The F5 key
      F6 = ImGuiKey_F6,                  ///< The F6 key
      F7 = ImGuiKey_F7,                  ///< The F7 key
      F8 = ImGuiKey_F8,                  ///< The F8 key
      F9 = ImGuiKey_F9,                  ///< The F9 key
      F10 = ImGuiKey_F10,                ///< The F10 key
      F11 = ImGuiKey_F11,                ///< The F11 key
      F12 = ImGuiKey_F12,                ///< The F12 key
      Pause = ImGuiKey_Pause,            ///< The Pause key

      KeyCount  ///< Keep last -- the total number of keyboard keys
    };
  #else
    enum class key {
      Unknown = -1,  ///< Unhandled key
      A = 0,         ///< The A key
      B,             ///< The B key
      C,             ///< The C key
      D,             ///< The D key
      E,             ///< The E key
      F,             ///< The F key
      G,             ///< The G key
      H,             ///< The H key
      I,             ///< The I key
      J,             ///< The J key
      K,             ///< The K key
      L,             ///< The L key
      M,             ///< The M key
      N,             ///< The N key
      O,             ///< The O key
      P,             ///< The P key
      Q,             ///< The Q key
      R,             ///< The R key
      S,             ///< The S key
      T,             ///< The T key
      U,             ///< The U key
      V,             ///< The V key
      W,             ///< The W key
      X,             ///< The X key
      Y,             ///< The Y key
      Z,             ///< The Z key
      Num0,          ///< The 0 key
      Num1,          ///< The 1 key
      Num2,          ///< The 2 key
      Num3,          ///< The 3 key
      Num4,          ///< The 4 key
      Num5,          ///< The 5 key
      Num6,          ///< The 6 key
      Num7,          ///< The 7 key
      Num8,          ///< The 8 key
      Num9,          ///< The 9 key
      Escape,        ///< The Escape key
      LControl,      ///< The left Control key
      LShift,        ///< The left Shift key
      LAlt,          ///< The left Alt key
      LSystem,       ///< The left OS specific key: window (Windows and Linux), apple (MacOS X), ...
      RControl,      ///< The right Control key
      RShift,        ///< The right Shift key
      RAlt,          ///< The right Alt key
      RSystem,    ///< The right OS specific key: window (Windows and Linux), apple (MacOS X), ...
      Menu,       ///< The Menu key
      LBracket,   ///< The [ key
      RBracket,   ///< The ] key
      Semicolon,  ///< The ; key
      Comma,      ///< The , key
      Period,     ///< The . key
      Quote,      ///< The ' key
      Slash,      ///< The / key
      Backslash,  ///< The \ key
      Tilde,      ///< The ~ key
      Equal,      ///< The = key
      Hyphen,     ///< The - key (hyphen)
      Space,      ///< The Space key
      Enter,      ///< The Enter/Return key
      Backspace,  ///< The Backspace key
      Tab,        ///< The Tabulation key
      PageUp,     ///< The Page up key
      PageDown,   ///< The Page down key
      End,        ///< The End key
      Home,       ///< The Home key
      Insert,     ///< The Insert key
      Delete,     ///< The Delete key
      Add,        ///< The + key
      Subtract,   ///< The - key (minus, usually from numpad)
      Multiply,   ///< The * key
      Divide,     ///< The / key
      Left,       ///< Left arrow
      Right,      ///< Right arrow
      Up,         ///< Up arrow
      Down,       ///< Down arrow
      Numpad0,    ///< The numpad 0 key
      Numpad1,    ///< The numpad 1 key
      Numpad2,    ///< The numpad 2 key
      Numpad3,    ///< The numpad 3 key
      Numpad4,    ///< The numpad 4 key
      Numpad5,    ///< The numpad 5 key
      Numpad6,    ///< The numpad 6 key
      Numpad7,    ///< The numpad 7 key
      Numpad8,    ///< The numpad 8 key
      Numpad9,    ///< The numpad 9 key
      F1,         ///< The F1 key
      F2,         ///< The F2 key
      F3,         ///< The F3 key
      F4,         ///< The F4 key
      F5,         ///< The F5 key
      F6,         ///< The F6 key
      F7,         ///< The F7 key
      F8,         ///< The F8 key
      F9,         ///< The F9 key
      F10,        ///< The F10 key
      F11,        ///< The F11 key
      F12,        ///< The F12 key
      F13,        ///< The F13 key
      F14,        ///< The F14 key
      F15,        ///< The F15 key
      Pause,      ///< The Pause key

      KeyCount  ///< Keep last -- the total number of keyboard keys
    };
  #endif
    /// \brief Check if a key is pressed
    ///
    /// \param key key to check
    ///
    /// \return True if the key is pressed, false otherwise
    static bool is_key_pressed(key k);

    /// \brief Show or hide the virtual keyboard
    ///
    /// Warning: the virtual keyboard is not supported on all
    /// systems. It will typically be implemented on mobile OSes
    /// (Android, iOS) but not on desktop OSes (Windows, Linux, ...).
    ///
    /// If the virtual keyboard is not available, this function does
    /// nothing.
    ///
    /// \param visible True to show, false to hide
    static void set_virtual_keyboard_visible(bool visible);
  };

}  // namespace mml

#endif  // MML_KEYBOARD_HPP

////////////////////////////////////////////////////////////
/// \class mml::keyboard
/// \ingroup window
///
/// mml::keyboard provides an interface to the state of the
/// keyboard. It only contains static functions (a single
/// keyboard is assumed), so it's not meant to be instantiated.
///
/// This class allows users to query the keyboard state at any
/// time and directly, without having to deal with a window and
/// its events. Compared to the key_pressed and key_released events,
/// mml::keyboard can retrieve the state of a key at any time
/// (you don't need to store and update a boolean on your side
/// in order to know if a key is pressed or released), and you
/// always get the real state of the keyboard, even if keys are
/// pressed or released when your window is out of focus and no
/// event is triggered.
///
/// Usage example:
/// \code
/// if (mml::keyboard::is_key_pressed(mml::keyboard::Left))
/// {
///     // move left...
/// }
/// else if (mml::keyboard::is_key_pressed(mml::keyboard::Right))
/// {
///     // move right...
/// }
/// else if (mml::keyboard::is_key_pressed(mml::keyboard::Escape))
/// {
///     // quit...
/// }
/// \endcode
///
/// \see mml::joystick, mml::mouse, mml::touch
///
////////////////////////////////////////////////////////////
