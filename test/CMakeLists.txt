# # Include the test libraries
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

file(GLOB test_files "test_*.cpp")
add_executable(run_tests ${test_files})
target_link_libraries(run_tests solver gtest_main)

add_custom_target(test ${CMAKE_BINARY_DIR}/test/run_tests)
