#ifndef __MOCK_QT_DATE_TESTS_H__
#define __MOCK_QT_DATE_TESTS_H__

#include "gtest/gtest.h"

TEST(MOCK_QT_DATE, EmptyDate)
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

TEST(MOCK_QT_DATE, InvalidDate)
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

TEST(MOCK_QT_DATE, ValidDate)
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

TEST(MOCK_QT_DATE, CombinationValidInValid)
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

TEST(MOCK_QT_DATE, CheckSize)
{

    std::string str = "07AB2022";
    bool flag = true;

        if (str.size() != 8)
        {
            flag = false;
        }

    EXPECT_EQ(flag, true);
}

TEST(MOCK_QT_DATE, CheckSizeoInvalid)
{

    std::string str = "ABCDEFGH";
    bool flag = true;

        if (str.size() != 8)
        {
            flag = false;
        }

    EXPECT_EQ(flag, true);
}

TEST(MOCK_QT_DATE, CheckSizeoValid)
{

    std::string str = "07032022";
    bool flag = true;

        if (str.size() != 8)
        {
            flag = false;
        }

    EXPECT_EQ(flag, true);
}

TEST(MOCK_QT_DATE, CheckSizeInvalidShort)
{

    std::string str = "AB";
    bool flag = true;

        if (str.size() != 8)
        {
            flag = false;
        }

    EXPECT_EQ(flag, !true);
}

TEST(MOCK_QT_DATE, CheckSizeInvalidLong)
{

    std::string str = "ABABABABABABABAB";
    bool flag = true;

        if (str.size() != 8)
        {
            flag = false;
        }

    EXPECT_EQ(flag, !true);
}

TEST(MOCK_QT_DATE, CheckSizeValidShort)
{

    std::string str = "1025";
    bool flag = true;

        if (str.size() != 8)
        {
            flag = false;
        }

    EXPECT_EQ(flag, !true);
}

TEST(MOCK_QT_DATE, CheckSizeValidLong)
{

    std::string str = "1010101010101";
    bool flag = true;

        if (str.size() != 8)
        {
            flag = false;
        }

    EXPECT_EQ(flag, !true);
}

TEST(MOCK_QT_DATE, CheckValidityLengthInvalid)
{

    std::string str = "ABCDEFGH";
    bool flag = true;

        if (str.size() != 8)
        {
            flag = false;
        }

        for (char const &c : str)
    {
        if (std::isdigit(c) == 0)
        {
            flag = false;
        }
    }

    EXPECT_EQ(flag, !true);
}

TEST(MOCK_QT_DATE, CheckValidityLengthInvalidShort)
{

    std::string str = "AB";
    bool flag = true;

        if (str.size() != 8)
        {
            flag = false;
        }

        for (char const &c : str)
    {
        if (std::isdigit(c) == 0)
        {
            flag = false;
        }
    }

    EXPECT_EQ(flag, !true);
}

TEST(MOCK_QT_DATE, CheckValidityLengthInvalidLong)
{

    std::string str = "ABQWERTYUIOP";
    bool flag = true;

        if (str.size() != 8)
        {
            flag = false;
        }

        for (char const &c : str)
    {
        if (std::isdigit(c) == 0)
        {
            flag = false;
        }
    }

    EXPECT_EQ(flag, !true);
}

TEST(MOCK_QT_DATE, CheckValidityLengthValid)
{

    std::string str = "07032022";
    bool flag = true;

        if (str.size() != 8)
        {
            flag = false;
        }

        for (char const &c : str)
    {
        if (std::isdigit(c) == 0)
        {
            flag = false;
        }
    }

    EXPECT_EQ(flag, true);
}


TEST(MOCK_QT_DATE, CheckValidityLengthValidShort)
{

    std::string str = "0703";
    bool flag = true;

        if (str.size() != 8)
        {
            flag = false;
        }

        for (char const &c : str)
    {
        if (std::isdigit(c) == 0)
        {
            flag = false;
        }
    }

    EXPECT_EQ(flag, !true);
}

TEST(MOCK_QT_DATE, CheckValidityLengthValidLong)
{

    std::string str = "0703202207";
    bool flag = true;

        if (str.size() != 8)
        {
            flag = false;
        }

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
