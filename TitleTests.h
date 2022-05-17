#ifndef TITLETESTS_H
#define TITLETESTS_H

#include "gtest/gtest.h"
#include "Title.h"

TEST(TITLE, constructor)
{
	Title test("work");
	EXPECT_EQ(test.getTitle(), "work");
}

TEST(TITLE, setInfo)
{
	Title test("");
	test.setInfo("work");
	EXPECT_EQ(test.getTitle(), "work");
}

#endif
