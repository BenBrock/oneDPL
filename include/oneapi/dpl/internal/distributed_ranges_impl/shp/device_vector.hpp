// SPDX-FileCopyrightText: Intel Corporation
//
// SPDX-License-Identifier: BSD-3-Clause

#pragma once

#include <oneapi/dpl/internal/distributed_ranges_impl/shp/allocators.hpp>
#include <oneapi/dpl/internal/distributed_ranges_impl/shp/vector.hpp>

namespace experimental::shp {

template <typename T, typename Allocator>
class device_vector : public dr::shp::vector<T, Allocator> {
public:
  constexpr device_vector() noexcept {}

  using base = dr::shp::vector<T, Allocator>;

  using value_type = T;
  using size_type = std::size_t;
  using difference_type = std::size_t;

  constexpr device_vector(size_type count, const Allocator &alloc,
                          size_type rank)
      : base(count, alloc), rank_(rank) {}

  constexpr std::size_t rank() const noexcept { return rank_; }

private:
  std::size_t rank_ = 0;
};

template <class Alloc>
device_vector(std::size_t, const Alloc, std::size_t)
    -> device_vector<typename Alloc::value_type, Alloc>;

} // namespace experimental::shp
