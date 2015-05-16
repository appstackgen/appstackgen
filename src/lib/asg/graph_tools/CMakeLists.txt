set(LIBNAME ${ASG_GRAPH_TOOLS_LIB_NAME})

set(LIBVERSION_MAJOR 1)
set(LIBVERSION_MINOR 0)
set(LIBVERSION_PATCH 0)

set(LIBSOVERSION ${LIBVERSION_MAJOR})
set(LIBVERSION ${LIBVERSION_MAJOR}.${LIBVERSION_MINOR}.${LIBVERSION_PATCH})

set(CMAKE_CXX_FLAGS "${PROJECT_COMPILER_FLAGS}")

set(GRAPHTOOLS_HEADERS
    graph_to_plain_text.h
    graph_to_dot.h
)

set(GRAPHTOOLS_SOURCES
    graph_to_plain_text.cpp
    graph_to_dot.cpp
)

set(HEADERS
    ${GRAPHTOOLS_HEADERS}
)

set(SOURCES
    ${GRAPHTOOLS_SOURCES}
)

# this dummy target ensures headers without cpp file are shown in qtcreator (eg. template files)
add_custom_target(${LIBNAME}${DUMMY_TARGET_NAME} SOURCES ${HEADERS})

add_library(${LIBNAME} SHARED ${SOURCES})

set_target_properties(${LIBNAME}
    PROPERTIES
    VERSION ${LIBVERSION}
    SOVERSION ${LIBSOVERSION}
)

target_link_libraries(${LIBNAME} ${ASG_GRAPH_LIB_NAME})
