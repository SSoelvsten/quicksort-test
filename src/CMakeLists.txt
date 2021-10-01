add_subdirectory (qs)

# ============================================================================ #
# Setup MAIN target
add_executable (qs_main main.cpp)
target_link_libraries(qs_main qs)
