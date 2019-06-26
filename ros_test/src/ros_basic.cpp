#include "ros_test/ros_basic.h"

ROSBasic::ROSBasic() {
  f_.data = 0.0;
}

ROSBasic::~ROSBasic() {}

void ROSBasic::setString(std::string s) {
  s_.data = s;
}

std::string ROSBasic::getString() {
  return s_.data;
}

std_msgs::String ROSBasic::getStringMsg() {
  return s_;
}

void ROSBasic::setFloat(double f) {
  f_.data = f;
}

double ROSBasic::getFloat() {
  return f_.data;
}

std_msgs::Float64 ROSBasic::getFloatMsg() {
  return f_;
}