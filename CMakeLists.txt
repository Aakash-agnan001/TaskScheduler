CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

project(operations)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(unit_tests
    #ADD CPP FILES HERE 
	./Tests/unit_test.cpp
    ./Sources/Classification.cpp
    ./Sources/Description.cpp
	./Sources/Title.cpp
	./Sources/UID.cpp
    ./Sources/Priority.cpp
    ./Sources/Duration.cpp
    ./Sources/DueDate.cpp 
    ./Sources/TaskList.cpp
)

ADD_EXECUTABLE(main
    ./main.cpp
    ./Sources/Classification.cpp
    ./Sources/Description.cpp
	./Sources/Title.cpp
	./Sources/UID.cpp
    ./Sources/Priority.cpp
    ./Sources/Duration.cpp
    ./Sources/DueDate.cpp 
    ./Sources/TaskList.cpp
)

TARGET_LINK_LIBRARIES(unit_tests gtest)

TARGET_COMPILE_DEFINITIONS(unit_tests PRIVATE gtest_disable_pthreads=ON)
