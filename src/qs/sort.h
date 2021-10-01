#ifndef QS_SORT_H
#define QS_SORT_H

#include <stdint.h>
#include <functional>
#include <algorithm>

#include <vector>

namespace qs {
  struct stats
  {
    size_t swaps;
    size_t comparisons;
    size_t max_depth;
  };

  typedef stats stats_t;

  //////////////////////////////////////////////////////////////////////////////
  /// \brief Given a vector sorts it with the Quicksort algorithm
  ///
  /// \param v  Vector to sort
  ///
  /// \return   Statistics on this run
  //////////////////////////////////////////////////////////////////////////////
  template<typename T, typename cmp_t = std::less<T>>
  stats_t sort(std::vector<T> &v, const int low_idx, const int high_idx, const cmp_t &cmp = std::less<T>())
  {
    stats_t stats = { 0, 0, 0 };
    if (low_idx < 0 || high_idx < 0 || low_idx >= high_idx) { return stats; }

    // Get pivot element
    const size_t pivot = v[low_idx];

    // Set up indices for partitioning
    size_t left_idx = low_idx - 1;
    size_t right_idx = high_idx + 1;

    // Partition step as per Tony Hoare
    while (true) {
      // skip through elements that already are, where they are supposed to be.
      do {
        left_idx++;
        stats.comparisons++;
      } while (cmp(v[left_idx], pivot));

      do {
        right_idx--;
        stats.comparisons++;
      } while (cmp(pivot, v[right_idx]));

      // break when indices cross
      if (left_idx >= right_idx) break;

      // swap elements
      stats.swaps++;

      const T left_elem = v[left_idx];
      const T right_elem = v[right_idx];

      v[left_idx] = right_elem;
      v[right_idx] = left_elem;
    }

    // Recursively solve subproblems
    const stats_t left_rec = sort(v, low_idx, right_idx, cmp);
    const stats_t right_rec = sort(v, right_idx+1, high_idx, cmp);

    return {
        stats.swaps + left_rec.swaps + right_rec.swaps,
        stats.comparisons + left_rec.comparisons + right_rec.comparisons,
        std::max(left_rec.max_depth, right_rec.max_depth) + 1,
    };
  }

  template<typename T, typename cmp_t = std::less<T>>
  stats_t sort(std::vector<T> &v, const cmp_t &cmp = std::less<T>())
  {
    return sort<T, cmp_t>(v, 0, v.size()-1, cmp);
  }
}

#endif // QS_SORT_H
