#include <iostream>
#include <string>

#include <ros/ros.h>
#include <std_msgs/String.h>

class ROSTopic {
 public:
  ROSTopic();
  ~ROSTopic();

  void setString(std::string s);
  std::string getString();
  std_msgs::String getStringMsg();
  std::string getTopicName();
  void setTopicName(std::string topic_name);

  void configurePublisher();

  void publishString();

 private:
  std_msgs::String s_;
  ros::Publisher pub_;
  ros::NodeHandle nh_;
  std::string topic_name_ = "ros_topic_test";
};