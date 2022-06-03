#ifndef __MOCK_QT_QLIST_TESTS_H__
#define __MOCK_QT_QLIST_TESTS_H__

#include "gtest/gtest.h"
#include <list>
#include <iterator>

TEST(MOCK_QT_QLIST, PushBack)
{
    bool flag = true;
    std::list<int> l;
    int size = l.size();
    l.push_back(5);
    l.push_back(4);
    int end_size = l.size();

    if (size == end_size)
    {
        flag = false;
    }
    EXPECT_EQ(flag, true);
}

TEST(MOCK_QT_QLIST, DeleteItem)
{
    bool flag = true;
    std::list<int> l;

    l.push_back(5);
    l.pop_back();

    if (l.size() != 0)
    {
        flag = false;
    }
    EXPECT_EQ(flag, true);
}

TEST(MOCK_QT_QLIST, RemoveItem)
{
    bool flag = true;
    std::list<int> l;
    l.push_back(5);
    l.push_back(4);
    l.push_back(3);
    l.remove(4);

    if (l.size() != 2)
    {
        flag = false;
    }
    EXPECT_EQ(flag, true);
}

TEST(MOCK_QT_QLIST, ClearItems)
{
    bool flag = true;
    std::list<int> l;
    l.push_back(5);
    l.push_back(4);
    l.push_back(3);
    l.clear();

    if (l.size() != 0)
    {
        flag = false;
    }
    EXPECT_EQ(flag, true);
}

TEST(MOCK_QT_QLIST, InsertItem)
{
    bool flag = true;
    std::list<int> l;
    std::list<int>::iterator ptr = l.begin();
    l.insert(ptr, 5);
    l.insert(ptr, 6);
    l.insert(ptr, 7);

    if (l.size() != 3)
    {
        flag = false;
    }
    EXPECT_EQ(flag, true);
}

TEST(MOCK_QT_QLIST, InsertRemove)
{
    bool flag = true;
    std::list<int> l;
    std::list<int>::iterator ptr = l.begin();
    l.insert(ptr, 5);
    l.insert(ptr, 6);
    l.remove(6);
    l.insert(ptr, 7);
    l.remove(5);
    l.insert(ptr, 3);

    if (l.size() != 2)
    {
        flag = false;
    }
    EXPECT_EQ(flag, true);
}

TEST(MOCK_QT_QLIST, InsertClear)
{
    bool flag = true;
    std::list<int> l;
    std::list<int>::iterator ptr = l.begin();
    l.insert(ptr, 5);
    l.insert(ptr, 6);
    l.clear();
    l.insert(ptr, 7);
    l.remove(7);
    l.insert(ptr, 3);

    if (l.size() != 1)
    {
        flag = false;
    }
    EXPECT_EQ(flag, true);
}

#endif
