set(LIBNAME ${ASG_SQL_LIB_NAME})

set(LIBVERSION_MAJOR 1)
set(LIBVERSION_MINOR 0)
set(LIBVERSION_PATCH 0)

set(LIBSOVERSION ${LIBVERSION_MAJOR})
set(LIBVERSION ${LIBVERSION_MAJOR}.${LIBVERSION_MINOR}.${LIBVERSION_PATCH})

set(CMAKE_CXX_FLAGS "${PROJECT_COMPILER_FLAGS}")

set(KERNEL_HEADERS
    statement.h
    script.h
    transaction_statement.h
    begin.h
    commit.h
    rollback.h
    ddl_statement.h
    create.h
    create_database.h
    create_schema.h
    create_table.h
)

set(KERNEL_SOURCES
    statement.cpp
    script.cpp
    transaction_statement.cpp
    begin.cpp
    commit.cpp
    rollback.cpp
    ddl_statement.cpp
    create_database.cpp
    create_schema.cpp
    create_table.cpp
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

target_link_libraries(${LIBNAME}
    ${ASG_RELATIONAL_MODEL_LIB_NAME}
)
