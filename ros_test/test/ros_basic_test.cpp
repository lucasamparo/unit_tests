#include <iostream>
#include <string>

#include <ros/ros.h>
#include <gtest/gtest.h>

#include "ros_test/ros_basic.h"

class ROSTest : public ::testing::Test {
 protected:
  ROSTest() {}

  void SetUp() override {
    r1_.setString("first");
    r2_.setString("second");
    r2_.setFloat(0.123456);
  }

  // void TearDown() override {}

  ROSBasic r0_;
  ROSBasic r1_;
  ROSBasic r2_;
};

TEST_F(ROSTest, isEmptyInitially) {
  EXPECT_EQ(r0_.getFloat(), 0.0);
}

TEST_F(ROSTest, verifyValues) {
  const std::string first = "first", second = "second";
  EXPECT_STREQ(r1_.getString().c_str(), first.c_str());
  EXPECT_STREQ(r2_.getString().c_str(), first.c_str());
  EXPECT_STREQ(r2_.getString().c_str(), second.c_str());

  EXPECT_EQ(r2_.getFloat(), 0.123456);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  ros::init(argc, argv, "ros_test_basic");
  ros::NodeHandle n;
  return RUN_ALL_TESTS();
}
