#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "TuxProc::TuxProc" for configuration "Debug"
set_property(TARGET TuxProc::TuxProc APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(TuxProc::TuxProc PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib64/libtuxproc.so"
  IMPORTED_SONAME_DEBUG "libtuxproc.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS TuxProc::TuxProc )
list(APPEND _IMPORT_CHECK_FILES_FOR_TuxProc::TuxProc "${_IMPORT_PREFIX}/lib64/libtuxproc.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
