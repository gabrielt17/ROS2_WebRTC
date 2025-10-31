# Install script for directory: /home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/devuser/Workspaces/rosgsthumble_ws/install/webrtc_camera_node")
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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-build/libixwebsocket.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ixwebsocket" TYPE FILE FILES
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXBase64.h"
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXBench.h"
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXCancellationRequest.h"
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXConnectionState.h"
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXDNSLookup.h"
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXExponentialBackoff.h"
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXGetFreePort.h"
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXGzipCodec.h"
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXHttp.h"
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXHttpClient.h"
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXHttpServer.h"
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXNetSystem.h"
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXProgressCallback.h"
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXSelectInterrupt.h"
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXSelectInterruptFactory.h"
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXSelectInterruptPipe.h"
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXSelectInterruptEvent.h"
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXSetThreadName.h"
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXSocket.h"
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXSocketConnect.h"
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXSocketFactory.h"
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXSocketServer.h"
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXSocketTLSOptions.h"
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXStrCaseCompare.h"
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXUdpSocket.h"
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXUniquePtr.h"
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXUrlParser.h"
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXUuid.h"
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXUtf8Validator.h"
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXUserAgent.h"
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXWebSocket.h"
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXWebSocketCloseConstants.h"
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXWebSocketCloseInfo.h"
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXWebSocketErrorInfo.h"
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXWebSocketHandshake.h"
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXWebSocketHandshakeKeyGen.h"
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXWebSocketHttpHeaders.h"
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXWebSocketInitResult.h"
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXWebSocketMessage.h"
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXWebSocketMessageType.h"
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXWebSocketOpenInfo.h"
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXWebSocketPerMessageDeflate.h"
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXWebSocketPerMessageDeflateCodec.h"
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXWebSocketPerMessageDeflateOptions.h"
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXWebSocketProxyServer.h"
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXWebSocketSendData.h"
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXWebSocketSendInfo.h"
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXWebSocketServer.h"
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXWebSocketTransport.h"
    "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-src/ixwebsocket/IXWebSocketVersion.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/ixwebsocket/ixwebsocket-targets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/ixwebsocket/ixwebsocket-targets.cmake"
         "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-build/CMakeFiles/Export/lib/cmake/ixwebsocket/ixwebsocket-targets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/ixwebsocket/ixwebsocket-targets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/ixwebsocket/ixwebsocket-targets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/ixwebsocket" TYPE FILE FILES "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-build/CMakeFiles/Export/lib/cmake/ixwebsocket/ixwebsocket-targets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/ixwebsocket" TYPE FILE FILES "/home/devuser/Workspaces/rosgsthumble_ws/build/webrtc_camera_node/_deps/ixwebsocket-build/CMakeFiles/Export/lib/cmake/ixwebsocket/ixwebsocket-targets-noconfig.cmake")
  endif()
endif()

