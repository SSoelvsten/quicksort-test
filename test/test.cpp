#include <vector>
#include <functional>

#include <bandit/bandit.h>

using namespace snowhouse;
using namespace bandit;

#include <qs/qs.h>

////////////////////////////////////////////////////////////////////////////////
#include "qs/test_sort.cpp"

////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[]) {
#ifdef NDEBUG
  std::cerr << "Warning: Internal assertions are not enabled!\n\n";
#endif

  qs::qs_init();

  const auto bandit_ret = bandit::run(argc, argv);

  qs::qs_deinit();

  return bandit_ret;
}
