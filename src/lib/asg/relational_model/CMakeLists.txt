set(LIBNAME ${ASG_RELATIONAL_MODEL_LIB_NAME})

set(LIBVERSION_MAJOR 1)
set(LIBVERSION_MINOR 0)
set(LIBVERSION_PATCH 0)

set(LIBSOVERSION ${LIBVERSION_MAJOR})
set(LIBVERSION ${LIBVERSION_MAJOR}.${LIBVERSION_MINOR}.${LIBVERSION_PATCH})

set(CMAKE_CXX_FLAGS "${PROJECT_COMPILER_FLAGS}")

set(KERNEL_HEADERS
    model.h
    model_fragment.h
    data_type.h
    iso_data_type.h
    custom_data_type.h
    schema.h
    schema_fragment.h
    tabloid.h
    table.h
    constant.h
    iso_constant.h
    table_fragment.h
    table_column.h
    table_constraint.h
    primary_key_constraint.h
)

set(KERNEL_SOURCES
    model.cpp
    model_fragment.cpp
    data_type.cpp
    iso_data_type.cpp
    custom_data_type.cpp
    schema.cpp
    schema_fragment.cpp
    tabloid.cpp
    table.cpp
    constant.cpp
    iso_constant.cpp
    table_fragment.cpp
    table_column.cpp
    table_constraint.cpp
    primary_key_constraint.cpp
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
