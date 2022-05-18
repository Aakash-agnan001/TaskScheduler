#ifndef __CLASSIFICATION_TESTS_H__
#define __CLASSIFICATION_TESTS_H__

#include "gtest/gtest.h"
#include "Classification.h"

TEST(CLASS, DefConstruct) {
    Classification test_class = Classification(); 
    EXPECT_EQ(test_class.GetClassification(), 0);
}

TEST(CLASS, PassRegParam) {
    Classification test_class = Classification(4);
    EXPECT_EQ(test_class.GetClassification(), 4);
}

TEST(Class, TestSetClass) {
    Classification test_class = Classification();
    test_class.SetClassification(4);
    EXPECT_EQ(test_class.GetClassification(), 4);
}

#endif
