#ifndef TASK_TESTS_H
#define TASK_TESTS_H

#include "gtest/gtest.h"
#include "../Headers/Task.h"

TEST(Task, defConstructUID)
{
	Task sampleTask;
	EXPECT_EQ(sampleTask.uid.getInfo(), "");	
}

TEST(Task, defConstructTitle)
{
	Task sampleTask;
	EXPECT_EQ(sampleTask.title.getInfo(), ""); 
}

TEST(Task, defConstructDueDate)
{
	Task sampleTask;
	EXPECT_EQ(sampleTask.date.getInfo(),0 );
}

TEST(Task, defConstructDescription)
{
	Task sampleTask;
	EXPECT_EQ(sampleTask.description.getInfo(), "");
}

TEST(Task, defConstructClassification)
{
	Task sampleTask;
	EXPECT_EQ(sampleTask.classifaction.getInfo(), 1);
}

TEST(Task, defConstructDuration)
{
	Task sampleTask;
	EXPECT_EQ(sampleTask.duration.getInfo(), 1);
}

TEST(Task, defConstructPriority)
{
	Task sampleTask:
	EXPECT_EQ(sampleTask.priority.getInfo(), 1);
}

#endif
