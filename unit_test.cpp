#include "gtest/gtest.h"
#include "Description_Tests.h"
#include "Classification_Tests.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
