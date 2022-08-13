#include <mml/window/keyboard.hpp>
#include <mml/window/input_impl.hpp>

namespace mml {
  bool keyboard::is_key_pressed(key k) { return priv::input_impl::is_key_pressed(k); }

  void keyboard::set_virtual_keyboard_visible(bool visible) {
    priv::input_impl::set_virtual_keyboard_visible(visible);
  }
}  // namespace mml
