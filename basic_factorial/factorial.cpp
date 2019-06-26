#include <iostream>
#include <string>

#include <gtest/gtest.h>

using namespace std;

int factorial(int n){
  return (n < 1) ? 1 : factorial(n-1) * n;
}

TEST(FactorialTest, DealWithZero) {
  EXPECT_EQ(factorial(0), 1);
}

TEST(FactorialTest, HandlesPositiveInput) {
  EXPECT_EQ(factorial(1), 1);
  EXPECT_EQ(factorial(2), 2);
  EXPECT_EQ(factorial(3), 6);
  EXPECT_EQ(factorial(8), 40320);
}

int main(int argc, char * argv[]) {
  ::testing::InitGoogleTest(&argc,argv);

  return RUN_ALL_TESTS();
}