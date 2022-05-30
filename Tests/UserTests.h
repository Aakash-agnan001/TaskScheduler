#ifndef USERTESTS_H
#define USERTESTS_H

#include "gtest/gtest.h"
#include "../Headers/User.h"

TEST(USER, May18th)
{
    User *user = new User;
    EXPECT_EQ(user->writeCSV(), true);
    delete user;
}


#endif
