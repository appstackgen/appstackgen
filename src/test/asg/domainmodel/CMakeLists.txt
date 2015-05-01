set(TESTED_LIB_NAME ${ASG_DOMAINMODEL_LIB_NAME})
set(APPNAME ${TEST_PREFIX}${TESTED_LIB_NAME})

set(CMAKE_CXX_FLAGS "${PROJECT_COMPILER_FLAGS}")

set(TEST_HEADERS
    infrastructure.h
    testprojectfactory.h
    testproject.h
)

set(TEST_SOURCES
    main.cpp
    testprojectfactory.cpp
    testproject.cpp
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
    ${CPPUNIT_LIBRARY}
    ${TESTED_LIB_NAME}
)

add_test(NAME ${APPNAME} COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${APPNAME})
