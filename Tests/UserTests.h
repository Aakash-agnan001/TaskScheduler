#ifndef USERTESTS_H
#define USERTESTS_H

#include "gtest/gtest.h"
#include "../Headers/User.h"

TEST(USER, constructorUser)
{
	User test;
	EXPECT_EQ(test.getName(), "");
}

TEST(USER, constructorPass)
{
        User test;
        EXPECT_EQ(test.getPassword(), "");
}

TEST(USER, constructorTask)
{
        User test;
        EXPECT_EQ(test.getTaskList().getSize(), 0);
}

TEST(USER, constructorLoggedIn)
{
        User test;
        EXPECT_EQ(test.getLoggedin(), false);
}

TEST(USER, setPass)
{
	User test;
	test.setPassword("password");
	EXPECT_EQ(test.getPassword(), "password");
}

TEST(USER, setName)
{
	User test;
	test.setName("name");
	EXPECT_EQ(test.getName(), "name");
}

TEST(USER, setLog)
{
	User test;
	test.setLoggedin(true);
	EXPECT_EQ(test.getLoggedin(), true);
}

TEST(USER, encrypt_decrypt)
{
	User test;
	test.setPassword("password"); 
	EXPECT_EQ(test.decrypt(test.encrypt(test.getPassword(), 5, 1649)), "password");
}

#endif
