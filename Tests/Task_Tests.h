#ifndef TASK_TESTS_H
#define TASK_TESTS_H

#include "gtest/gtest.h"
#include "../Headers/Task.h"

TEST(Task, defConstructTitle)
{
	Task sampleTask;
	EXPECT_EQ(sampleTask.title.getInfo(""), ""); 
}

TEST(Task, defConstructDueDate)
{
	Task sampleTask;
	EXPECT_EQ(sampleTask.date.getInfo(""), "00000000");
}

TEST(Task, defConstructDescription)
{
	Task sampleTask;
	EXPECT_EQ(sampleTask.description.getInfo(""), "");
}

TEST(Task, defConstructClassification)
{
	Task sampleTask;
	EXPECT_EQ(sampleTask.classification.getInfo(1), 1);
}

TEST(Task, defConstructDuration)
{
	Task sampleTask;
	EXPECT_EQ(sampleTask.duration.getInfo(1), 1);
}

TEST(Task, defConstructPriority)
{
	Task sampleTask;
	EXPECT_EQ(sampleTask.priority.getInfo(1), 1);
}

#endif
