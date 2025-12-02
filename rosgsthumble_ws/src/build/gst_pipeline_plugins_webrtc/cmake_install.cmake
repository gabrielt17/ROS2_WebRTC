# Install script for directory: /home/devuser/Workspaces/rosgsthumble_ws/src/ros-gst-bridge/gst_pipeline_plugins_webrtc

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/devuser/Workspaces/rosgsthumble_ws/src/install/gst_pipeline_plugins_webrtc")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  include("/home/devuser/Workspaces/rosgsthumble_ws/src/build/gst_pipeline_plugins_webrtc/ament_cmake_symlink_install/ament_cmake_symlink_install.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libgst_pipeline_plugins_webrtc.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libgst_pipeline_plugins_webrtc.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libgst_pipeline_plugins_webrtc.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/devuser/Workspaces/rosgsthumble_ws/src/build/gst_pipeline_plugins_webrtc/libgst_pipeline_plugins_webrtc.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libgst_pipeline_plugins_webrtc.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libgst_pipeline_plugins_webrtc.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libgst_pipeline_plugins_webrtc.so"
         OLD_RPATH "/home/devuser/Workspaces/rosgsthumble_ws/src/install/gst_pipeline/lib:/opt/ros/humble/lib:/home/devuser/Workspaces/rosgsthumble_ws/src/install/gst_msgs/lib:/home/devuser/Workspaces/rosgsthumble_ws/src/install/gst_bridge/lib:/home/devuser/Workspaces/rosgsthumble_ws/src/install/audio_msgs/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libgst_pipeline_plugins_webrtc.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/gst_pipeline_plugins_webrtc/cmake/export_gst_pipeline_plugins_webrtcExport.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/gst_pipeline_plugins_webrtc/cmake/export_gst_pipeline_plugins_webrtcExport.cmake"
         "/home/devuser/Workspaces/rosgsthumble_ws/src/build/gst_pipeline_plugins_webrtc/CMakeFiles/Export/share/gst_pipeline_plugins_webrtc/cmake/export_gst_pipeline_plugins_webrtcExport.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/gst_pipeline_plugins_webrtc/cmake/export_gst_pipeline_plugins_webrtcExport-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/gst_pipeline_plugins_webrtc/cmake/export_gst_pipeline_plugins_webrtcExport.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gst_pipeline_plugins_webrtc/cmake" TYPE FILE FILES "/home/devuser/Workspaces/rosgsthumble_ws/src/build/gst_pipeline_plugins_webrtc/CMakeFiles/Export/share/gst_pipeline_plugins_webrtc/cmake/export_gst_pipeline_plugins_webrtcExport.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gst_pipeline_plugins_webrtc/cmake" TYPE FILE FILES "/home/devuser/Workspaces/rosgsthumble_ws/src/build/gst_pipeline_plugins_webrtc/CMakeFiles/Export/share/gst_pipeline_plugins_webrtc/cmake/export_gst_pipeline_plugins_webrtcExport-noconfig.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/devuser/Workspaces/rosgsthumble_ws/src/build/gst_pipeline_plugins_webrtc/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
