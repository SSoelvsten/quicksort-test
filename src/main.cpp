// std imports
#include <iostream>
#include <vector>
#include <functional>

// quicksort import
#include <qs/qs.h>

template<typename T>
void print_vector(const std::vector<T> &v)
{
  std::cout << "vector: { ";
  for (const T &t : v) { std::cout << t << " "; }
  std::cout << "}" << std::endl << std::endl;
}

int main(int argc, char* argv[]) {
  qs::qs_init();

  {
    // ===== Your code starts here =====

    std::vector<int> v = {0, 1, 2, 3, 4, 5};

    print_vector(v);

    const qs::stats_t stats = qs::sort(v, std::less<int>());

    print_vector(v);

    // print statistics
    std::cout << "Statistics:" << std::endl
              << "  swaps:        " << stats.swaps << std::endl
              << "  comparisons:  " << stats.comparisons << std::endl
              << "  max depth:    " << stats.max_depth << std::endl;

    // =====  Your code ends here  =====
  }

  qs::qs_deinit();

  return 0;
}

