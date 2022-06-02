#include "gtest/gtest.h"
#include "Description_Tests.h"
#include "Classification_Tests.h"
#include "Priority_Tests.h"
#include "TitleTests.h"
#include "DurationTests.h"
#include "DueDateTests.h"
#include "TaskList_Tests.h"
#include "Task_Tests.h"
#include "UserTests.h"

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
