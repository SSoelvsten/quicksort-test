set_property(GLOBAL PROPERTY USE_FOLDERS On)

# ============================================================================ #
# Link up files for the library

set(HEADERS
  # core files
  qs.h
  sort.h
)

set(SOURCES
)

add_library(qs STATIC ${HEADERS} ${SOURCES})

include(GenerateExportHeader)
generate_export_header(qs
  EXPORT_MACRO_NAME QS_API
)

# ============================================================================ #
# Setup as library

target_include_directories(qs PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/..
                                        ${CMAKE_CURRENT_SOURCE_DIR}/..)

set_target_properties(qs PROPERTIES
  # Language settings
  LINKER_LANGUAGE CXX
  C_STANDARD 17
  C_STANDARD_REQUIRED ON
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
  CXX_VISIBILITY_PRESET hidden

  # Linkage?
  FOLDER qs

  # Other
  VERSION ${PROJECT_VERSION}
  POSITION_INDEPENDENT_CODE ON
)

target_compile_features(qs PUBLIC cxx_std_17)

install(TARGETS qs
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        INCLUDES DESTINATION ${LIBLEGACY_INCLUDE_DIRS}
)
