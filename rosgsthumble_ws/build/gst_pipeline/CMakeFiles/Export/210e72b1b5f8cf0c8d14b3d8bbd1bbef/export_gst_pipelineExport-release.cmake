#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "gst_pipeline::gst_pipeline" for configuration "Release"
set_property(TARGET gst_pipeline::gst_pipeline APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(gst_pipeline::gst_pipeline PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libgst_pipeline.so"
  IMPORTED_SONAME_RELEASE "libgst_pipeline.so"
  )

list(APPEND _cmake_import_check_targets gst_pipeline::gst_pipeline )
list(APPEND _cmake_import_check_files_for_gst_pipeline::gst_pipeline "${_IMPORT_PREFIX}/lib/libgst_pipeline.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
