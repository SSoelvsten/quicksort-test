#include "qs.h"

#include <ostream>
#include <iostream>

namespace qs {
  void qs_init() {
    std::cout << "qs initialized" << std::endl;
  }

  void qs_deinit() {
    std::cout << "qs deinitialized" << std::endl;
  }
}
