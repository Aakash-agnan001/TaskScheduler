#ifndef TASKLIST_TESTS_H
#define TASKLIST_TESTS_H

#include "gtest/gtest.h"
#include "../Headers/TaskList.h"

TEST(TaskList, defaultConstructor)
{
	TaskList basic;
	EXPECT_EQ(basic.getSize(), 0);
}

TEST(TaskList, addTask)
{
	TaskList test;
	test.addTask("assignment 1", "first assignment", 1, 1, "12112002", 60);
	test.addTask("assignment 2", "second assignment", 2, 2, "12122002", 60);
	test.addTask("assignment 3", "third assignment", 3, 3, "12132002", 60);
	EXPECT_EQ(test.getSize(), 3);
}

TEST(TaskList, deleteTask)
{
	TaskList test;
        test.addTask("assignment 1", "first assignment", 1, 1, "12112002", 60);
        test.addTask("assignment 2", "second assignment", 2, 2, "12122002", 60);
        test.addTask("assignment 3", "third assignment", 3, 3, "12132002", 60);
	test.deleteTask("assignment 3");
        EXPECT_EQ(test.getSize(), 2);
}

TEST(TaskList, getSize2)
{
	TaskList test;
        test.addTask("assignment 1", "first assignment", 1, 1, "12112002", 60);
        test.addTask("assignment 2", "second assignment", 2, 2, "12122002", 60);
        test.addTask("assignment 3", "third assignment", 3, 3, "12132002", 60);
        test.deleteTask("assignment 3");
	test.deleteTask("assignment 2");
	test.addTask("quiz", "first quiz", 5, 5, "01023003", 90);
	test.addTask("final", "final test", 10, 10, "05054004", 180);
        EXPECT_EQ(test.getSize(), 3);
}

#endif
