#ifndef UIDTESTS_H
#define UIDTESTS_H

#include "gtest/gtest.h"
#include "../Headers/UID.h"

TEST(UID, constructor)
{
	Information* test = new UID("test");
	EXPECT_EQ(test->getInfo(""), "test");
    delete test;
}

TEST(UID, setInfo)
{
	Information* test = new UID("");
	test->setInfo("test");
	EXPECT_EQ(test->getInfo(""), "test");
    delete test;
}

#endif 
