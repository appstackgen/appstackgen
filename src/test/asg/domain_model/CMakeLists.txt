set(TESTED_LIB_NAME ${ASG_DOMAIN_MODEL_LIB_NAME})
set(APPNAME ${TEST_PREFIX}${TESTED_LIB_NAME})

set(CMAKE_CXX_FLAGS "${PROJECT_COMPILER_FLAGS}")

set(TEST_HEADERS
    project_factory.h
)

set(TEST_SOURCES
    project_factory.cpp
    test_project.cpp
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
    ${TESTED_LIB_NAME}
    ${ASG_GRAPH_TOOLS_LIB_NAME}
)

add_test(NAME ${APPNAME} COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${APPNAME})
