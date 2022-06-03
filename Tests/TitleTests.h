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

TEST(TITLE, EmptysetInfo)
{
        Information* test = new Title("");
        test->setInfo("");
        EXPECT_EQ(test->getInfo(""), "");
    delete test;
}

TEST(TITLE, EmptyConstructor)
{
        Information* test = new Title("");
        //test->setInfo("work");
        EXPECT_EQ(test->getInfo(""), "");
    delete test;
}

TEST(TITLE, stringNumbers)
{
        Information* test = new Title("");
        test->setInfo("work123");
        EXPECT_EQ(test->getInfo(""), "work123");
    delete test;
}

#endif
