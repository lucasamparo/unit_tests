#include <iostream>
#include <string>

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Float64.h>

class ROSBasic {
 public:
  ROSBasic();
  ~ROSBasic();

  void setString(std::string s);
  std::string getString();
  std_msgs::String getStringMsg();

  void setFloat(double f);
  double getFloat();
  std_msgs::Float64 getFloatMsg();

 private:
  std_msgs::String s_;
  std_msgs::Float64 f_;
};