#ifndef UIDTESTS_H
#define UIDTESTS_H

#include "gtest/gtest.h"
#include "UID.h"

TEST(UID, constructor)
{
	UID test("test");
	EXPECT_EQ(test.getInfo(), "test");
}

TEST(UID, setInfo)
{
	UID test("");
	test.setInfo("test");
	EXPECT_EQ(test.getInfo(), "test");
}

#endif 
