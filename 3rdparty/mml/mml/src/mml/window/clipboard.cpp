#include <mml/window/clipboard.hpp>
#include <mml/window/clipboard_impl.hpp>

namespace mml {
  std::string clipboard::get_string() { return priv::clipboard_impl::get_string(); }

  void clipboard::set_string(const std::string& text) {
    return priv::clipboard_impl::set_string(text);
  }

}  // namespace mml
