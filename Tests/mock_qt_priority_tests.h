#ifndef __MOCK_QT_PRIORITY_TESTS_H__
#define __MOCK_QT_PRIORITY_TESTS_H__

#include "gtest/gtest.h"
#include <list>
#include <iterator>

TEST(MOCK_QT_PRIORITY, LowEdgeValidP)
{

    unsigned int priority = 1;
    bool flag = true;
    if (priority < 1 || priority > 9)
    {
        flag = false;
    }
    EXPECT_EQ(flag, true);
}

TEST(MOCK_QT_PRIORITY, HighEdgeValidP)
{

    unsigned int priority = 9;
    bool flag = true;
    if (priority < 1 || priority > 9)
    {
        flag = false;
    }
    EXPECT_EQ(flag, true);
}

TEST(MOCK_QT_PRIORITY, ValidP)
{

    unsigned int priority = 5;
    bool flag = true;
    if (priority < 1 || priority > 9)
    {
        flag = false;
    }
    EXPECT_EQ(flag, true);
}

TEST(MOCK_QT_PRIORITY, NegInvalidP)
{

    unsigned int priority = -1;
    bool flag = true;
    if (priority < 1 || priority > 9)
    {
        flag = false;
    }
    EXPECT_EQ(flag, !true);
}

TEST(MOCK_QT_PRIORITY, PosInvalidP)
{

    unsigned int priority = 100;
    bool flag = true;
    if (priority < 1 || priority > 9)
    {
        flag = false;
    }
    EXPECT_EQ(flag, !true);
}

#endif
