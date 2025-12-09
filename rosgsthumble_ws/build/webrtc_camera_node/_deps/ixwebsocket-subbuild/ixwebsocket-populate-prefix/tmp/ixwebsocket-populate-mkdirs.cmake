# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/root/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src"
  "/root/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-build"
  "/root/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-subbuild/ixwebsocket-populate-prefix"
  "/root/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-subbuild/ixwebsocket-populate-prefix/tmp"
  "/root/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-subbuild/ixwebsocket-populate-prefix/src/ixwebsocket-populate-stamp"
  "/root/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-subbuild/ixwebsocket-populate-prefix/src"
  "/root/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-subbuild/ixwebsocket-populate-prefix/src/ixwebsocket-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/root/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-subbuild/ixwebsocket-populate-prefix/src/ixwebsocket-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/root/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-subbuild/ixwebsocket-populate-prefix/src/ixwebsocket-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
