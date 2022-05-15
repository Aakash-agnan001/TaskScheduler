#ifndef __DESCRIPTIONTEST_H__
#define __DESCRIPTIONTEST_H__

#include "gtest/gtest.h"
#include "Description.h"

using namespace std;

TEST(description, empty) {
	Description name("");
	EXPECT_EQ(name.getDescription(), "");
}

#endif
