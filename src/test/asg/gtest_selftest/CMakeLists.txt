set(APPNAME ${TEST_PREFIX}gtest_selftest)

set(CMAKE_CXX_FLAGS "${PROJECT_COMPILER_FLAGS}")

set(TEST_HEADERS
)

set(TEST_SOURCES
    gtest_selftest.cpp
)

set(HEADERS
    ${TEST_HEADERS}
)

set(SOURCES
    ${TEST_SOURCES}
)

# this dummy target ensures headers without cpp file are shown in qtcreator (eg. template files)
add_custom_target(${APPNAME}${DUMMY_TARGET_NAME} SOURCES ${HEADERS})

add_executable(${APPNAME} ${SOURCES})

target_link_libraries(${APPNAME}
    ${GTEST_LIBRARIES}
)

add_test(NAME ${APPNAME} COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${APPNAME})
