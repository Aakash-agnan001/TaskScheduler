CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

project(operations)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(unit_tests
    #ADD CPP FILES HERE 
	unit_test.cpp
    Classification.cpp
    Description.cpp
	Title.cpp
	UID.cpp
    Priority.cpp
    Duration.cpp
    UID.cpp
    DueDate.cpp 
)

TARGET_LINK_LIBRARIES(unit_tests gtest)

TARGET_COMPILE_DEFINITIONS(unit_tests PRIVATE gtest_disable_pthreads=ON)
