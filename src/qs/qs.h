#ifndef QS_H
#define QS_H

#include <qs/sort.h>

namespace qs {

  //////////////////////////////////////////////////////////////////////////////////////////////////
  /// \brief Initialises the qs library.
  ///
  /// Call this function, before you use any other functionality of the library.
  //////////////////////////////////////////////////////////////////////////////////////////////////
  void qs_init();

  //////////////////////////////////////////////////////////////////////////////////////////////////
  /// \brief Deinitialises the qs library
  ///
  /// Call this function when you are done, such that data can be cleaned up.
  //////////////////////////////////////////////////////////////////////////////////////////////////
  void qs_deinit();
}

#endif // QS_H
