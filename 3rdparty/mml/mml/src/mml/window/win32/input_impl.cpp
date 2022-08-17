////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#ifdef _WIN32_WINDOWS
  #undef _WIN32_WINDOWS
#endif
#ifdef _WIN32_WINNT
  #undef _WIN32_WINNT
#endif
#define _WIN32_WINDOWS 0x0501
#define _WIN32_WINNT 0x0501
#define ATH_NUM_KEYS 256
#include <mml/window/window.hpp>
#include <mml/window/win32/input_impl.hpp>
#include <windows.h>
#include <list>

namespace mml {
  namespace priv {
    bool input_impl::is_key_pressed(keyboard::key key) {
      int vkey = 0;
      switch (key) {
      default: vkey = 0; break;
      case keyboard::key::A: vkey = 'A'; break;
      case keyboard::key::B: vkey = 'B'; break;
      case keyboard::key::C: vkey = 'C'; break;
      case keyboard::key::D: vkey = 'D'; break;
      case keyboard::key::E: vkey = 'E'; break;
      case keyboard::key::F: vkey = 'F'; break;
      case keyboard::key::G: vkey = 'G'; break;
      case keyboard::key::H: vkey = 'H'; break;
      case keyboard::key::I: vkey = 'I'; break;
      case keyboard::key::J: vkey = 'J'; break;
      case keyboard::key::K: vkey = 'K'; break;
      case keyboard::key::L: vkey = 'L'; break;
      case keyboard::key::M: vkey = 'M'; break;
      case keyboard::key::N: vkey = 'N'; break;
      case keyboard::key::O: vkey = 'O'; break;
      case keyboard::key::P: vkey = 'P'; break;
      case keyboard::key::Q: vkey = 'Q'; break;
      case keyboard::key::R: vkey = 'R'; break;
      case keyboard::key::S: vkey = 'S'; break;
      case keyboard::key::T: vkey = 'T'; break;
      case keyboard::key::U: vkey = 'U'; break;
      case keyboard::key::V: vkey = 'V'; break;
      case keyboard::key::W: vkey = 'W'; break;
      case keyboard::key::X: vkey = 'X'; break;
      case keyboard::key::Y: vkey = 'Y'; break;
      case keyboard::key::Z: vkey = 'Z'; break;
      case keyboard::key::Num0: vkey = '0'; break;
      case keyboard::key::Num1: vkey = '1'; break;
      case keyboard::key::Num2: vkey = '2'; break;
      case keyboard::key::Num3: vkey = '3'; break;
      case keyboard::key::Num4: vkey = '4'; break;
      case keyboard::key::Num5: vkey = '5'; break;
      case keyboard::key::Num6: vkey = '6'; break;
      case keyboard::key::Num7: vkey = '7'; break;
      case keyboard::key::Num8: vkey = '8'; break;
      case keyboard::key::Num9: vkey = '9'; break;
      case keyboard::key::Escape: vkey = VK_ESCAPE; break;
      case keyboard::key::LControl: vkey = VK_LCONTROL; break;
      case keyboard::key::LShift: vkey = VK_LSHIFT; break;
      case keyboard::key::LAlt: vkey = VK_LMENU; break;
      case keyboard::key::LSystem: vkey = VK_LWIN; break;
      case keyboard::key::RControl: vkey = VK_RCONTROL; break;
      case keyboard::key::RShift: vkey = VK_RSHIFT; break;
      case keyboard::key::RAlt: vkey = VK_RMENU; break;
      case keyboard::key::RSystem: vkey = VK_RWIN; break;
      case keyboard::key::Menu: vkey = VK_APPS; break;
      case keyboard::key::LBracket: vkey = VK_OEM_4; break;
      case keyboard::key::RBracket: vkey = VK_OEM_6; break;
      case keyboard::key::Semicolon: vkey = VK_OEM_1; break;
      case keyboard::key::Comma: vkey = VK_OEM_COMMA; break;
      case keyboard::key::Period: vkey = VK_OEM_PERIOD; break;
      case keyboard::key::Quote: vkey = VK_OEM_7; break;
      case keyboard::key::Slash: vkey = VK_OEM_2; break;
      case keyboard::key::Backslash: vkey = VK_OEM_5; break;
      case keyboard::key::Tilde: vkey = VK_OEM_3; break;
      case keyboard::key::Equal: vkey = VK_OEM_PLUS; break;
      case keyboard::key::Hyphen: vkey = VK_OEM_MINUS; break;
      case keyboard::key::Space: vkey = VK_SPACE; break;
      case keyboard::key::Enter: vkey = VK_RETURN; break;
      case keyboard::key::Backspace: vkey = VK_BACK; break;
      case keyboard::key::Tab: vkey = VK_TAB; break;
      case keyboard::key::PageUp: vkey = VK_PRIOR; break;
      case keyboard::key::PageDown: vkey = VK_NEXT; break;
      case keyboard::key::End: vkey = VK_END; break;
      case keyboard::key::Home: vkey = VK_HOME; break;
      case keyboard::key::Insert: vkey = VK_INSERT; break;
      case keyboard::key::Delete: vkey = VK_DELETE; break;
#ifndef IMGUI_KEYBOARD_MAPPING
      case keyboard::key::Add: vkey = VK_ADD; break;
      case keyboard::key::Subtract: vkey = VK_SUBTRACT; break;
      case keyboard::key::Multiply: vkey = VK_MULTIPLY; break;
      case keyboard::key::Divide: vkey = VK_DIVIDE; break;
#endif
      case keyboard::key::Left: vkey = VK_LEFT; break;
      case keyboard::key::Right: vkey = VK_RIGHT; break;
      case keyboard::key::Up: vkey = VK_UP; break;
      case keyboard::key::Down: vkey = VK_DOWN; break;
      case keyboard::key::Numpad0: vkey = VK_NUMPAD0; break;
      case keyboard::key::Numpad1: vkey = VK_NUMPAD1; break;
      case keyboard::key::Numpad2: vkey = VK_NUMPAD2; break;
      case keyboard::key::Numpad3: vkey = VK_NUMPAD3; break;
      case keyboard::key::Numpad4: vkey = VK_NUMPAD4; break;
      case keyboard::key::Numpad5: vkey = VK_NUMPAD5; break;
      case keyboard::key::Numpad6: vkey = VK_NUMPAD6; break;
      case keyboard::key::Numpad7: vkey = VK_NUMPAD7; break;
      case keyboard::key::Numpad8: vkey = VK_NUMPAD8; break;
      case keyboard::key::Numpad9: vkey = VK_NUMPAD9; break;
      case keyboard::key::F1: vkey = VK_F1; break;
      case keyboard::key::F2: vkey = VK_F2; break;
      case keyboard::key::F3: vkey = VK_F3; break;
      case keyboard::key::F4: vkey = VK_F4; break;
      case keyboard::key::F5: vkey = VK_F5; break;
      case keyboard::key::F6: vkey = VK_F6; break;
      case keyboard::key::F7: vkey = VK_F7; break;
      case keyboard::key::F8: vkey = VK_F8; break;
      case keyboard::key::F9: vkey = VK_F9; break;
      case keyboard::key::F10: vkey = VK_F10; break;
      case keyboard::key::F11: vkey = VK_F11; break;
      case keyboard::key::F12: vkey = VK_F12; break;
#ifndef IMGUI_KEYBOARD_MAPPING
      case keyboard::key::F13: vkey = VK_F13; break;
      case keyboard::key::F14: vkey = VK_F14; break;
      case keyboard::key::F15: vkey = VK_F15; break;
#endif
      case keyboard::key::Pause: vkey = VK_PAUSE; break;
      }

      return (GetAsyncKeyState(vkey) & 0x8000) != 0;
    }

    void input_impl::set_virtual_keyboard_visible(bool visible) {
      // Not applicable
    }

    ////////////////////////////////////////////////////////////
    bool input_impl::is_mouse_button_pressed(mouse::button button) {
      int vkey = 0;
      switch (button) {
      case mouse::left: vkey = GetSystemMetrics(SM_SWAPBUTTON) ? VK_RBUTTON : VK_LBUTTON; break;
      case mouse::right: vkey = GetSystemMetrics(SM_SWAPBUTTON) ? VK_LBUTTON : VK_RBUTTON; break;
      case mouse::middle: vkey = VK_MBUTTON; break;
      case mouse::x_button1: vkey = VK_XBUTTON1; break;
      case mouse::x_button2: vkey = VK_XBUTTON2; break;
      default: vkey = 0; break;
      }

      return (GetAsyncKeyState(vkey) & 0x8000) != 0;
    }

    ////////////////////////////////////////////////////////////
    std::array<std::int32_t, 2> input_impl::get_mouse_position() {
      POINT point;
      GetCursorPos(&point);
      return std::array<std::int32_t, 2>({ point.x, point.y });
    }

    ////////////////////////////////////////////////////////////
    std::array<std::int32_t, 2> input_impl::get_mouse_position(const window& relativeTo) {
      window_handle handle = relativeTo.native_handle();
      if (handle) {
        POINT point;
        GetCursorPos(&point);
        ScreenToClient(handle, &point);
        return std::array<std::int32_t, 2>({ point.x, point.y });
      } else {
        return std::array<std::int32_t, 2>({ 0, 0 });
      }
    }

    ////////////////////////////////////////////////////////////
    void input_impl::set_mouse_position(const std::array<std::int32_t, 2>& position) {
      SetCursorPos(position[0], position[1]);
    }

    ////////////////////////////////////////////////////////////
    void input_impl::set_mouse_position(
      const std::array<std::int32_t, 2>& position, const window& relativeTo) {
      window_handle handle = relativeTo.native_handle();
      if (handle) {
        POINT point = { position[0], position[1] };
        ClientToScreen(handle, &point);
        SetCursorPos(point.x, point.y);
      }
    }

    ////////////////////////////////////////////////////////////
    bool input_impl::is_touch_down(unsigned int /*finger*/) {
      // Not applicable
      return false;
    }

    ////////////////////////////////////////////////////////////
    std::array<std::int32_t, 2> input_impl::get_touch_position(unsigned int /*finger*/) {
      // Not applicable
      return std::array<std::int32_t, 2>({ 0, 0 });
    }

    ////////////////////////////////////////////////////////////
    std::array<std::int32_t, 2>
    input_impl::get_touch_position(unsigned int /*finger*/, const window& /*relativeTo*/) {
      // Not applicable
      return std::array<std::int32_t, 2>({ 0, 0 });
    }

  }  // namespace priv

}  // namespace mml
