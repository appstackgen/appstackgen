set(LIBNAME ${ASG_DOMAINMODEL_LIB_NAME})

set(LIBVERSION_MAJOR 1)
set(LIBVERSION_MINOR 0)
set(LIBVERSION_PATCH 0)

set(LIBSOVERSION ${LIBVERSION_MAJOR})
set(LIBVERSION ${LIBVERSION_MAJOR}.${LIBVERSION_MINOR}.${LIBVERSION_PATCH})

set(CMAKE_CXX_FLAGS "${PROJECT_COMPILER_FLAGS}")

set(KERNEL_HEADERS
    model.h
    model_fragment.h
    bounded_context.h
    primitive_data_type.h
    bounded_context_fragment.h
    domain.h
    domain_fragment.h
    domain_object.h
    domain_object_fragment.h
    value.h
    system_value.h
    persistence_value.h
    id_value.h
    concurrency_control_value.h
    last_changed_timestamp_value.h
    object_version.h
)

set(KERNEL_SOURCES
    model.cpp
    model_fragment.cpp
    bounded_context.cpp
    primitive_data_type.cpp
    bounded_context_fragment.cpp
    domain.cpp
    domain_fragment.cpp
    domain_object.cpp
    domain_object_fragment.cpp
    value.cpp
    system_value.cpp
    persistence_value.cpp
    id_value.cpp
    concurrency_control_value.cpp
    last_changed_timestamp_value.cpp
    object_version.cpp
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

target_link_libraries(${LIBNAME} ${ASG_GRAPH_LIB_NAME})
