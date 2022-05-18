#ifndef __PRIORITY_TESTS_H__
#define __PRIORITY_TESTS_H__

#include "gtest/gtest.h"
#include "Priority.h"

TEST(PRIORITY, DefConstruct) {
     Priority test_prio = Priority();
     EXPECT_EQ(test_prio.getPriority(), 0);
}

TEST(PRIORITY, PassRegParam) {
    Priority test_prio = Priority(5);
    EXPECT_EQ(test_prio.getPriority(), 5);  
}

TEST(PRIORITY, TestSetPrio) {
    Priority test_prio = Priority();
    test_prio.setPriority(5);
    EXPECT_EQ(test_prio.getPriority(), 5);
}

#endif
