#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "HashMap::HashMap" for configuration "Release"
set_property(TARGET HashMap::HashMap APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(HashMap::HashMap PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libhashmap.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS HashMap::HashMap )
list(APPEND _IMPORT_CHECK_FILES_FOR_HashMap::HashMap "${_IMPORT_PREFIX}/lib/libhashmap.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
