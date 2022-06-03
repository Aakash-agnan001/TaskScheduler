#ifndef __MOCK_QT_DURATION_TESTS_H__
#define __MOCK_QT_DURATION_TESTS_H__

#include "gtest/gtest.h"

TEST(MOCK_QT_DURATION, EmptyDuration)
{

    std::string str = "0000000";
    bool flag = true;
    for (char const &c : str)
    {
        if (std::isdigit(c) == 0)
        {
            flag = false;
        }
    }
    EXPECT_EQ(flag, true);
}

TEST(MOCK_QT_DURATION, InvalidDuration)
{

    std::string str = "ABCDEFGH";
    bool flag = true;
    for (char const &c : str)
    {
        if (std::isdigit(c) == 0)
        {
            flag = false;
        }
    }
    EXPECT_EQ(flag, !true);
}

TEST(MOCK_QT_DURATION, ValidDuration)
{

    std::string str = "07032022";
    bool flag = true;
    for (char const &c : str)
    {
        if (std::isdigit(c) == 0)
        {
            flag = false;
        }
    }
    EXPECT_EQ(flag, true);
}

TEST(MOCK_QT_DURATION, CombinationValidInValid)
{

    std::string str = "07AB2022";
    bool flag = true;
    for (char const &c : str)
    {
        if (std::isdigit(c) == 0)
        {
            flag = false;
        }
    }
    EXPECT_EQ(flag, !true);
}

#endif
