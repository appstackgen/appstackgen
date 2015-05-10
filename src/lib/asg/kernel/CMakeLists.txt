set(LIBNAME ${ASG_KERNEL_LIB_NAME})

set(LIBVERSION_MAJOR 1)
set(LIBVERSION_MINOR 0)
set(LIBVERSION_PATCH 0)

set(LIBSOVERSION ${LIBVERSION_MAJOR})
set(LIBVERSION ${LIBVERSION_MAJOR}.${LIBVERSION_MINOR}.${LIBVERSION_PATCH})

set(CMAKE_CXX_FLAGS "${PROJECT_COMPILER_FLAGS}")

set(KERNEL_HEADERS
    objectidgenerator.h
    types.h
    objectname.h
    objectid.h
    stringtools.h
)

set(KERNEL_SOURCES
    objectidgenerator.cpp
    objectname.cpp
    objectid.cpp
    stringtools.cpp
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

#target_link_libraries(${APPNAME})
