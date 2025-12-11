# CMake generated Testfile for 
# Source directory: /root/Workspaces/rosgsthumble_ws/src/ros-gst-bridge/gst_bridge
# Build directory: /root/Workspaces/rosgsthumble_ws/build/gst_bridge
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(clang_format "/usr/bin/python3" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/root/Workspaces/rosgsthumble_ws/build/gst_bridge/test_results/gst_bridge/clang_format.xunit.xml" "--package-name" "gst_bridge" "--output-file" "/root/Workspaces/rosgsthumble_ws/build/gst_bridge/ament_clang_format/clang_format.txt" "--command" "/opt/ros/humble/bin/ament_clang_format" "--xunit-file" "/root/Workspaces/rosgsthumble_ws/build/gst_bridge/test_results/gst_bridge/clang_format.xunit.xml" "--config" "/root/Workspaces/rosgsthumble_ws/src/ros-gst-bridge/gst_bridge/.clang-format")
set_tests_properties(clang_format PROPERTIES  LABELS "clang_format;linter" TIMEOUT "60" WORKING_DIRECTORY "/root/Workspaces/rosgsthumble_ws/src/ros-gst-bridge/gst_bridge" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_clang_format/cmake/ament_clang_format.cmake;57;ament_add_test;/root/Workspaces/rosgsthumble_ws/src/ros-gst-bridge/gst_bridge/CMakeLists.txt;133;ament_clang_format;/root/Workspaces/rosgsthumble_ws/src/ros-gst-bridge/gst_bridge/CMakeLists.txt;0;")
