#ifndef DESCRIPTION_TESTS_H
#define DESCRIPTION_TESTS_H

#include "gtest/gtest.h"
#include "../Headers/Description.h"

TEST(DESCRIPTION, EMPTY) {
	Information* name = new Description("");
	EXPECT_EQ(name->getInfo(""), "");
    delete name;
}

TEST(DESCRIPTION, ONE_WORD) {
	Information* name = new Description("");
	name->setInfo("Hello");
	EXPECT_EQ(name->getInfo(""), "Hello");
    delete name;
}

TEST(DESCRIPTION, MANY_WORDS) {
	Information* name = new Description("");
	name->setInfo("Hello Aakash, hi");
	EXPECT_EQ(name->getInfo(""), "Hello Aakash, hi");
    delete name;
}

TEST(DESCRIPTION, SPECIAL_CHARACTERS) {
	Information* name = new Description("");
	name->setInfo("@@k@$h! ! !");
	EXPECT_EQ(name->getInfo(""), "@@k@$h! ! !");
    delete name;
}

#endif
