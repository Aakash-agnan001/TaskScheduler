#ifndef CLASSIFICATION_TESTS_H
#define CLASSIFICATION_TESTS_H

#include "gtest/gtest.h"
#include "../Headers/Classification.h"

TEST(Classification, DefConstruct)
{
    Information *test_class = new Classification();
    EXPECT_EQ(test_class->getInfo(0), 1);
    delete test_class;
}

TEST(Classification, PassRegParam)
{
    Information *test_class = new Classification(4);
    EXPECT_EQ(test_class->getInfo(0), 4);
    delete test_class;
}

TEST(Classification, TestSetClass)
{
    Information *test_class = new Classification(1);
    test_class->setInfo(4);
    EXPECT_EQ(test_class->getInfo(0), 4);
    delete test_class;
}

#endif
