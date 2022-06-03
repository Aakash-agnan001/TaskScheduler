#ifndef DURATIONTESTS_H
#define DURATIONTESTS_H

#include "gtest/gtest.h"
#include "../Headers/Duration.h"

TEST(DURATION, Zero)
{
    Information *duration = new Duration(0);
    EXPECT_EQ(duration->getInfo(0), 0);
    delete duration;
}

TEST(DURATION, NonZero)
{
    Information *duration = new Duration(24);
    EXPECT_EQ(duration->getInfo(0), 24);
    delete duration;
}

TEST(DURATION, SetInfo)
{
    Information *duration = new Duration(0);
    duration->setInfo(89);
    EXPECT_EQ(duration->getInfo(0), 89);
    delete duration;
}

TEST(DURATION, Constructor)
{
    Information *duration = new Duration(10);
    EXPECT_EQ(duration->getInfo(0), 10);
    delete duration;
}

TEST(DURATION, large)
{
    Information *duration = new Duration(0);
    duration->setInfo(1234);
    EXPECT_EQ(duration->getInfo(0), 1234);
    delete duration;
}

#endif
