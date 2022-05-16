#ifndef DESCRIPTION_TESTS_H
#define DESCRIPTION_TESTS_H

#include "gtest/gtest.h"
#include "Description.h"

TEST(DESCRIPTION, EMPTY) {
	Description name("");
	EXPECT_EQ(name.getDescription(), "");
}

#endif
