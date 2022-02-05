#pragma once

#include "../ecs.h"
#include <fstream>
#include <memory>

struct scene {
  enum class mode {
    standard,
    additive,
  };
  std::vector<runtime::entity> instantiate(mode mod);
  std::shared_ptr<std::istream> data;

  struct id_t {
    id_t() : id_(0) {}

    explicit id_t(std::uint64_t id) : id_(id) {}
    id_t(std::uint32_t index, std::uint32_t version)
      : id_(std::uint64_t(index) | std::uint64_t(version) << 32UL) {}

    std::uint64_t id() const { return id_; }

    bool operator==(const id_t& other) const { return id_ == other.id_; }
    bool operator!=(const id_t& other) const { return id_ != other.id_; }
    bool operator<(const id_t& other) const { return id_ < other.id_; }

    std::uint32_t index() const { return id_ & 0xffffffffUL; }
    std::uint32_t version() const { return id_ >> 32; }

  private:
    std::uint64_t id_ = 0;
  };

  scene() = default;
  scene(id_t id) : id_(id) {}

  scene::id_t id() const { return id_; }

private:
  scene::id_t id_;
};
