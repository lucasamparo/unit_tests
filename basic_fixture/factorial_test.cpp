#include <gtest/gtest.h>
#include <iostream>
#include "factorial.h"

class FactorialTest : public ::testing::Test {
 protected:
  void SetUp() override {
    std::cout << "This function will be triggered ";
    std::cout << "on the start of the test" << std::endl;
  }

  void TearDown() override {
    std::cout << "This function will be triggered ";
    std::cout << "on the end of the test" << std::endl;
  }

  Factorial fac;
};

TEST_F(FactorialTest, DealWithZero) {
  EXPECT_EQ(fac.computeFactorial(0), 1);
}

TEST_F(FactorialTest, HandlesPositiveInput) {
  EXPECT_EQ(fac.computeFactorial(1), 1);
  EXPECT_EQ(fac.computeFactorial(2), 2);
  EXPECT_EQ(fac.computeFactorial(3), 6);
  EXPECT_EQ(fac.computeFactorial(8), 40320);
}

int main(int argc, char * argv[]) {
  ::testing::InitGoogleTest(&argc,argv);

  return RUN_ALL_TESTS();
}