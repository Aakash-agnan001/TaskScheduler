#ifndef DUEDATETESTS_H
#define DUEDATETESTS_H

#include "gtest/gtest.h"
#include "DueDate.h"

TEST(DUEDATE, May18th)
{
    Information *due_date = new DueDate("05182022");
    EXPECT_EQ(due_date->getInfo(""), "05182022");
    delete due_date;
}

TEST(DUEDATE, December25th)
{
    Information *due_date = new DueDate("12252022");
    EXPECT_EQ(due_date->getInfo(""), "12252022");
    delete due_date;
}

TEST(DUEDATE, October31st)
{
    Information *due_date = new DueDate("12252022");
    due_date->setInfo("10312022");
    EXPECT_EQ(due_date->getInfo(""), "10312022");
    delete due_date;
}

#endif
