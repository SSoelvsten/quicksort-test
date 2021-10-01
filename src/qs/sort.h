#ifndef QS_SORT_H
#define QS_SORT_H

#include <stdint.h>
#include <functional>
#include <algorithm>

#include <vector>

#include <assert.h>

namespace qs {
  struct stats
  {
    size_t swaps;
    size_t comparisons;
    size_t max_depth;
  };

  typedef stats stats_t;

  //////////////////////////////////////////////////////////////////////////////////////////////////
  /// \brief Given a vector sorts it with the Quicksort algorithm
  ///
  /// \param v        Vector to sort
  /// \param low_idx  The start index to sort from (inclusive)
  /// \param high_idx The end index to sort to (inclusive)
  /// \param cmp      Comparator to use, e.g. std::less<T>
  ///
  /// \return     Statistics on this run
  //////////////////////////////////////////////////////////////////////////////////////////////////
  template<typename T, typename cmp_t = std::less<T>>
  stats_t sort(std::vector<T> &v, const int low_idx, const int high_idx,
               const cmp_t &cmp = std::less<T>())
  {
    stats_t stats = { 0, 0, 0 };
    if (low_idx < 0 || high_idx < 0 || low_idx >= high_idx) { return stats; }

    // Get pivot element
    assert(high_idx < v.size());
    const size_t pivot = v[high_idx];

    // Partition step as per Lomuto
    size_t pivot_idx = low_idx - 1;

    for (int i = low_idx; i <= high_idx; i++) {
      stats.comparisons++;
      if (cmp(v[i], pivot) || v[i] == pivot) {
        // move pivot index forward
        pivot_idx++;

        // swap elements
        stats.swaps++;

        const T pivot_elem = v[pivot_idx];
        const T i_elem = v[i];

        v[i] = pivot_elem;
        v[pivot_idx] = i_elem;
      }
    }

    // Recursively solve subproblems
    const stats_t left_rec = sort(v, low_idx, pivot_idx-1, cmp);
    const stats_t right_rec = sort(v, pivot_idx+1, high_idx, cmp);

    return {
        stats.swaps + left_rec.swaps + right_rec.swaps,
        stats.comparisons + left_rec.comparisons + right_rec.comparisons,
        std::max(left_rec.max_depth, right_rec.max_depth) + 1,
    };
  }

  //////////////////////////////////////////////////////////////////////////////////////////////////
  /// \brief Same as calling qs::sort(v, 0, v.size()-1, cmp) above.
  //////////////////////////////////////////////////////////////////////////////////////////////////
  template<typename T, typename cmp_t = std::less<T>>
  stats_t sort(std::vector<T> &v, const cmp_t &cmp = std::less<T>())
  {
    return sort<T, cmp_t>(v, 0, v.size()-1, cmp);
  }
}

#endif // QS_SORT_H
