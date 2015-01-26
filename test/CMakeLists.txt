# Gmock
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

FILE (GLOB_RECURSE TEST_SRCS test_*.cpp)

SET(TEST_EXECUTABLE run-tests)
ADD_EXECUTABLE(${TEST_EXECUTABLE} ${TEST_SRCS})
TARGET_LINK_LIBRARIES(${TEST_EXECUTABLE} gmock_main ${PROJECT_LIBRARIES})

ADD_CUSTOM_TARGET(
    test "${TEST_EXECUTABLE}"
    DEPENDS ${TEST_EXECUTABLE} # SolverTests
    COMMENT "Executing unit tests..."
    VERBATIM SOURCES ${TEST_SRCS}
)
