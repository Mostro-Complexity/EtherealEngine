#pragma once
#include "frame_buffer.h"
#include <string>
#include <unordered_map>
#include <vector>

namespace gfx {
  struct render_pass {
    //-----------------------------------------------------------------------------
    //  Name : render_pass ()
    /// <summary>
    ///
    ///
    ///
    /// </summary>
    //-----------------------------------------------------------------------------
    render_pass(const std::string& n);

    //-----------------------------------------------------------------------------
    //  Name : bind ()
    /// <summary>
    ///
    ///
    ///
    /// </summary>
    //-----------------------------------------------------------------------------
    void bind(const frame_buffer* fb = nullptr) const;
    void touch() const;
    //-----------------------------------------------------------------------------
    //  Name : clear ()
    /// <summary>
    ///
    ///
    ///
    /// </summary>
    //-----------------------------------------------------------------------------
    void clear(
      std::uint16_t _flags, std::uint32_t _rgba = 0x000000ff, float _depth = 1.0f,
      std::uint8_t _stencil = 0) const;

    //-----------------------------------------------------------------------------
    //  Name : clear ()
    /// <summary>
    ///
    ///
    ///
    /// </summary>
    //-----------------------------------------------------------------------------
    void clear() const;

    //-----------------------------------------------------------------------------
    //  Name : set_view_proj ()
    /// <summary>
    ///
    ///
    ///
    /// </summary>
    //-----------------------------------------------------------------------------
    void set_view_proj(const float* v, const float* p);

    //-----------------------------------------------------------------------------
    //  Name : reset ()
    /// <summary>
    ///
    ///
    ///
    /// </summary>
    //-----------------------------------------------------------------------------
    static void reset();

    //-----------------------------------------------------------------------------
    //  Name : get_pass ()
    /// <summary>
    ///
    ///
    ///
    /// </summary>
    //-----------------------------------------------------------------------------
    static gfx::view_id get_pass();
    ///
    gfx::view_id id;
  };
}  // namespace gfx
