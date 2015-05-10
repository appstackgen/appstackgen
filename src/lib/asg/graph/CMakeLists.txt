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
    abstract_graph_fragment.h
    graph_fragment.h
    abstract_node.h
    node.h
    abstract_edge.h
    edge.h
    system_node.h
    system_edge.h
    index_node.h
    index_edge.h
    user_node.h
    user_edge.h
    owns.h
)

set(KERNEL_SOURCES
    abstract_graph.cpp
    default_graph.cpp
    abstract_graph_fragment.cpp
    graph_fragment.cpp
    abstract_node.cpp
    node.cpp
    abstract_edge.cpp
    edge.cpp
    system_node.cpp
    index_node.cpp
    system_edge.cpp
    index_edge.cpp
    user_node.cpp
    user_edge.cpp
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
