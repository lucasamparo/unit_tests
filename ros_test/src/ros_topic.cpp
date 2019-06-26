#include "ros_test/ros_topic.h"

ROSTopic::ROSTopic() {}

ROSTopic::~ROSTopic() {}

void ROSTopic::setString(std::string s) {
  s_.data = s;
}

std::string ROSTopic::getString() {
  return s_.data;
}

std_msgs::String ROSTopic::getStringMsg() {
  return s_;
}

std::string ROSTopic::getTopicName() {
  return topic_name_;
}

void ROSTopic::setTopicName(std::string topic_name) {
  topic_name_ = topic_name;
}

void ROSTopic::configurePublisher() {
  pub_ = nh_.advertise<std_msgs::String>(topic_name_, 1);
}

void ROSTopic::publishString() {
  while(ros::ok()) {
    pub_.publish(s_);
    ros::spinOnce();
  }
}