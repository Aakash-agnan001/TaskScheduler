CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

project(operations)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(test
	  unit_test.cpp
    Description.cpp
	Title.cpp
	UID.cpp
	Classification.cpp
	Priority.cpp
    #ADD CPP FILES HERE
)

TARGET_LINK_LIBRARIES(test gtest)

TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
