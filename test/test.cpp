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

  return bandit::run(argc, argv);
}
