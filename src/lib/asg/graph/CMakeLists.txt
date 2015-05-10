set(LIBNAME ${ASG_GRAPH_LIB_NAME})

set(LIBVERSION_MAJOR 1)
set(LIBVERSION_MINOR 0)
set(LIBVERSION_PATCH 0)

set(LIBSOVERSION ${LIBVERSION_MAJOR})
set(LIBVERSION ${LIBVERSION_MAJOR}.${LIBVERSION_MINOR}.${LIBVERSION_PATCH})

set(CMAKE_CXX_FLAGS "${PROJECT_COMPILER_FLAGS}")

set(KERNEL_HEADERS
    abstract_graph.h
    default_graph.h
    abstractgraphfragment.h
    graphfragment.h
    abstractnode.h
    node.h
    abstractedge.h
    edge.h
    systemnode.h
    systemedge.h
    indexnode.h
    indexedge.h
    usernode.h
    useredge.h
    owns.h
)

set(KERNEL_SOURCES
    abstract_graph.cpp
    default_graph.cpp
    abstractgraphfragment.cpp
    graphfragment.cpp
    abstractnode.cpp
    node.cpp
    abstractedge.cpp
    edge.cpp
    systemnode.cpp
    indexnode.cpp
    systemedge.cpp
    indexedge.cpp
    usernode.cpp
    useredge.cpp
    owns.cpp
)

set(HEADERS
    ${KERNEL_HEADERS}
)

set(SOURCES
    ${KERNEL_SOURCES}
)

# this dummy target ensures headers without cpp file are shown in qtcreator (eg. template files)
add_custom_target(${LIBNAME}${DUMMY_TARGET_NAME} SOURCES ${HEADERS})

add_library(${LIBNAME} SHARED ${SOURCES})

set_target_properties(${LIBNAME}
    PROPERTIES
    VERSION ${LIBVERSION}
    SOVERSION ${LIBSOVERSION}
)

target_link_libraries(${LIBNAME} ${ASG_KERNEL_LIB_NAME})
