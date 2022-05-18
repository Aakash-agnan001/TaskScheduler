#ifndef DURATIONTESTS_H
#define DURATIONTESTS_H

#include "gtest/gtest.h"
#include "Duration.h"

TEST(DURATION, EMPTY) {
	Information* duration = new Duration(10);
	EXPECT_EQ(duration->getInfo(0), 10);
    delete duration;
}

TEST(DURATION, ONE_WORD) {
	Information* duration = new Duration(15);
	duration->setInfo(20);
	EXPECT_EQ(duration->getInfo(0), 20);
    delete duration;
}

TEST(DURATION, MANY_WORDS) {
	Information* duration = new Duration(0);
	duration->setInfo(34);
	EXPECT_EQ(duration->getInfo(0), 34);
    delete duration;
}

#endif