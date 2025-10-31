#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "gst_pipeline_plugins_webrtc::gst_pipeline_plugins_webrtc" for configuration ""
set_property(TARGET gst_pipeline_plugins_webrtc::gst_pipeline_plugins_webrtc APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(gst_pipeline_plugins_webrtc::gst_pipeline_plugins_webrtc PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libgst_pipeline_plugins_webrtc.so"
  IMPORTED_SONAME_NOCONFIG "libgst_pipeline_plugins_webrtc.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS gst_pipeline_plugins_webrtc::gst_pipeline_plugins_webrtc )
list(APPEND _IMPORT_CHECK_FILES_FOR_gst_pipeline_plugins_webrtc::gst_pipeline_plugins_webrtc "${_IMPORT_PREFIX}/lib/libgst_pipeline_plugins_webrtc.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
