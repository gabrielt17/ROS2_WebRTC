# CMake generated Testfile for 
# Source directory: /root/Workspaces/rosgsthumble_ws/src/xacro/test
# Build directory: /root/Workspaces/rosgsthumble_ws/build/xacro/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(pytest "/usr/bin/python3.6" "-u" "/opt/ros/humble/install/share/ament_cmake_test/cmake/run_test.py" "/root/Workspaces/rosgsthumble_ws/build/xacro/test_results/xacro/pytest.xunit.xml" "--package-name" "xacro" "--output-file" "/root/Workspaces/rosgsthumble_ws/build/xacro/ament_cmake_pytest/pytest.txt" "--env" "AMENT_PREFIX_PATH=/root/Workspaces/rosgsthumble_ws/build/xacro/test/test_ament_index:/opt/ros/humble/install" "--command" "/usr/bin/python3.6" "-u" "-m" "pytest" "/root/Workspaces/rosgsthumble_ws/src/xacro/test/." "-o" "cache_dir=/root/Workspaces/rosgsthumble_ws/build/xacro/test/ament_cmake_pytest/pytest/.cache" "--junit-xml=/root/Workspaces/rosgsthumble_ws/build/xacro/test_results/xacro/pytest.xunit.xml" "--junit-prefix=xacro")
set_tests_properties(pytest PROPERTIES  LABELS "pytest" TIMEOUT "60" WORKING_DIRECTORY "/root/Workspaces/rosgsthumble_ws/src/xacro/test" _BACKTRACE_TRIPLES "/opt/ros/humble/install/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/install/share/ament_cmake_pytest/cmake/ament_add_pytest_test.cmake;169;ament_add_test;/root/Workspaces/rosgsthumble_ws/src/xacro/test/CMakeLists.txt;10;ament_add_pytest_test;/root/Workspaces/rosgsthumble_ws/src/xacro/test/CMakeLists.txt;0;")
add_test(xacro_cmake "/root/Workspaces/rosgsthumble_ws/src/xacro/test/test-cmake.sh" "/root/Workspaces/rosgsthumble_ws/src/xacro/test/test-xacro-cmake")
set_tests_properties(xacro_cmake PROPERTIES  _BACKTRACE_TRIPLES "/root/Workspaces/rosgsthumble_ws/src/xacro/test/CMakeLists.txt;15;add_test;/root/Workspaces/rosgsthumble_ws/src/xacro/test/CMakeLists.txt;0;")
