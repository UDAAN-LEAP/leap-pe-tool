#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "QuaZip::QuaZip" for configuration "Release"
set_property(TARGET QuaZip::QuaZip APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(QuaZip::QuaZip PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libquazip1-qt5.1.4.dylib"
  IMPORTED_SONAME_RELEASE "@rpath/libquazip1-qt5.1.4.0.dylib"
  )

list(APPEND _cmake_import_check_targets QuaZip::QuaZip )
list(APPEND _cmake_import_check_files_for_QuaZip::QuaZip "${_IMPORT_PREFIX}/lib/libquazip1-qt5.1.4.dylib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
