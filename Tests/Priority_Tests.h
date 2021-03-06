#ifndef __PRIORITY_TESTS_H__
#define __PRIORITY_TESTS_H__

#include "gtest/gtest.h"
#include "../Headers/Priority.h"

TEST(PRIORITY, DefConstruct)
{
    Information *test_prio = new Priority();
    EXPECT_EQ(test_prio->getInfo(0), 1);
    delete test_prio;
}

TEST(PRIORITY, PassRegParam)
{
    Information *test_prio = new Priority(5);
    EXPECT_EQ(test_prio->getInfo(0), 5);
    delete test_prio;
}

TEST(PRIORITY, TestSetPrio)
{
    Information *test_prio = new Priority();
    test_prio->setInfo(5);
    EXPECT_EQ(test_prio->getInfo(0), 5);
    delete test_prio;
}

#endif
