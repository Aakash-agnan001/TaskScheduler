#ifndef TITLETESTS_H
#define TITLETESTS_H

#include "gtest/gtest.h"
#include "../Headers/Title.h"

TEST(TITLE, constructor)
{
	Information* test = new Title("work");
	EXPECT_EQ(test->getInfo(""), "work");
    delete test;
}

TEST(TITLE, setInfo)
{
	Information* test = new Title("");
	test->setInfo("work");
	EXPECT_EQ(test->getInfo(""), "work");
    delete test;
}

#endif
