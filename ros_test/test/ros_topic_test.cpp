#include <iostream>
#include <string>

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <gtest/gtest.h>
#include <boost/thread.hpp>

#include "ros_test/ros_topic.h"

class ROSTest : public ::testing::Test {
 protected:
  ROSTest() {}

  void SetUp() override {
    r2_.setTopicName("second_test_topic");

    r1_.configurePublisher();
    r2_.configurePublisher();
  }

  // void TearDown() override {}

  ROSTopic r0_;
  ROSTopic r1_;
  ROSTopic r2_;
};

TEST_F(ROSTest, isEmptyInitially) {
  std::string empty_str;
  EXPECT_STREQ(r0_.getString().c_str(), empty_str.c_str());
}

TEST_F(ROSTest, verifyTopicNames) {
  std::string topic_1 = "ros_topic_test", topic_2 = "second_test_topic";
  EXPECT_STREQ(r1_.getTopicName().c_str(), topic_1.c_str());
  EXPECT_STREQ(r2_.getTopicName().c_str(), topic_2.c_str());
}

TEST_F(ROSTest, verifyValues) {
  const std::string first = "first", second = "second";
  ros::Duration d = ros::Duration(10);

  r1_.setString(first);
  boost::thread t1{&ROSTopic::publishString, &r1_};

  boost::shared_ptr<const std_msgs::String> msg1 =
      ros::topic::waitForMessage<std_msgs::String>(r1_.getTopicName(), d);

  r2_.setString(second);
  boost::thread t2{&ROSTopic::publishString, &r2_};

  boost::shared_ptr<const std_msgs::String> msg2 =
      ros::topic::waitForMessage<std_msgs::String>(r2_.getTopicName(), d);

  EXPECT_STREQ(r1_.getString().c_str(), msg1->data.c_str());
  EXPECT_STREQ(r2_.getString().c_str(), msg2->data.c_str());

  ros::shutdown();

  t1.join();
  t2.join();
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  ros::init(argc, argv, "ros_test_topic");
  ros::NodeHandle n;
  return RUN_ALL_TESTS();
}