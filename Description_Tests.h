#ifndef DESCRIPTION_TESTS_H
#define DESCRIPTION_TESTS_H

#include "gtest/gtest.h"
#include "Description.h"

TEST(DESCRIPTION, EMPTY) {
	Description name("");
	EXPECT_EQ(name.getInfo(), "");
}

TEST(DESCRIPTION, ONE_WORD) {
	Description name("");
	name.setInfo("Hello");
	EXPECT_EQ(name.getInfo(), "Hello");
}

TEST(DESCRIPTION, MANY_WORDS) {
	Description name("");
	name.setInfo("Hello Aakash, hi");
	EXPECT_EQ(name.getInfo(), "Hello Aakash, hi");
}

TEST(DESCRIPTION, SPECIAL_CHARACTERS) {
	Description name("");
	name.setInfo("@@k@$h! ! !");
	EXPECT_EQ(name.getInfo(), "@@k@$h! ! !");
}

#endif
