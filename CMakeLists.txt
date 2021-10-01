# Check if this is used as part of a solo project.
if(DEFINED PROJECT_NAME)
  set(MAIN_PROJECT OFF)
else()
  set(MAIN_PROJECT ON)
endif()

cmake_minimum_required(VERSION 3.10)
project (qs
  VERSION 1.0.0
  DESCRIPTION "Simple Quicksort implementation"
  HOMEPAGE_URL "https://ssoelvsten.github.io/"
  LANGUAGES CXX
)

enable_language(CXX)

message(STATUS "CMake build configuration for QS ${PROJECT_VERSION}")
message(STATUS "  OS: ${CMAKE_SYSTEM_NAME}")
message(STATUS "  Compiler: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "    C Flags: ${CMAKE_C_FLAGS}")
message(STATUS "    CXX Flags: ${CMAKE_CXX_FLAGS}")
message(STATUS "    EXE Linker Flags: ${CMAKE_EXE_LINKER_FLAGS}")
message(STATUS "  Tests: ${MAIN_PROJECT}")
message(STATUS "")

# ============================================================================ #
# Core project
# ============================================================================ #
add_subdirectory (src)

install(DIRECTORY src/qs
        DESTINATION include
        FILES_MATCHING REGEX "\\.h$")

# ============================================================================ #
# Unit Tests
# ============================================================================ #
if (MAIN_PROJECT)
  add_subdirectory (test)
endif()
