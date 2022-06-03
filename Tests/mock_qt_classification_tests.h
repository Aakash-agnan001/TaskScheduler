#ifndef __MOCK_QT_CLASSIFICATION_TESTS_H__
#define __MOCK_QT_CLASSIFICATION_TESTS_H__

#include "gtest/gtest.h"

TEST(MOCK_QT_CLASSIFICATION, LowEdgeValidP)
{

    unsigned int classification = 1;
    bool flag = true;
    if (classification < 1 || classification > 4)
    {
        flag = false;
    }
    EXPECT_EQ(flag, true);
}

TEST(MOCK_QT_CLASSIFICATION, HighEdgeValidP)
{

    unsigned int classification = 4;
    bool flag = true;
    if (classification < 1 || classification > 4)
    {
        flag = false;
    }
    EXPECT_EQ(flag, true);
}

TEST(MOCK_QT_CLASSIFICATION, ValidP)
{

    unsigned int classification = 3;
    bool flag = true;
    if (classification < 1 || classification > 4)
    {
        flag = false;
    }
    EXPECT_EQ(flag, true);
}

TEST(MOCK_QT_CLASSIFICATION, NegInvalidP)
{

    unsigned int classification = -1;
    bool flag = true;
    if (classification < 1 || classification > 4)
    {
        flag = false;
    }
    EXPECT_EQ(flag, !true);
}

TEST(MOCK_QT_CLASSIFICATION, PosInvalidP)
{

    unsigned int classification = 100;
    bool flag = true;
    if (classification < 1 || classification > 4)
    {
        flag = false;
    }
    EXPECT_EQ(flag, !true);
}

#endif
