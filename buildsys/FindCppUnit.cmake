#
# This module finds an installed CppUnit package.
#
# CPPUNIT_FOUND - Set to true if CppUnit is found. Otherwise False or undefined
# CPPUNIT_INCLUDE_DIR - Where CppUnit Header files are located
# CPPUNIT_LIBRARY - The CppUnit Library
#

FIND_PATH(CPPUNIT_INCLUDE_DIR cppunit/TestSuite.h)
FIND_LIBRARY(CPPUNIT_LIBRARY NAMES cppunit)

IF (CPPUNIT_INCLUDE_DIR)
    MESSAGE(STATUS "CppUnit include files found: ${CPPUNIT_INCLUDE_DIR}")
ELSE (CPPUNIT_INCLUDE_DIR)
    MESSAGE(FATAL_ERROR "CppUnit include files NOT found.")
ENDIF (CPPUNIT_INCLUDE_DIR)
    
IF (CPPUNIT_LIBRARY)
    MESSAGE(STATUS "CppUnit library found: ${CPPUNIT_LIBRARY}")
ELSE (CPPUNIT_LIBRARY)
    MESSAGE(FATAL_ERROR "CppUnit library NOT found.")
ENDIF (CPPUNIT_LIBRARY)
                                                 
IF (CPPUNIT_INCLUDE_DIR AND CPPUNIT_LIBRARY)
    SET(CPPUNIT_FOUND TRUE)
ENDIF (CPPUNIT_INCLUDE_DIR AND CPPUNIT_LIBRARY)
