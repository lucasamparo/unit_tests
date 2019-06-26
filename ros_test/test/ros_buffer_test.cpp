#include "ros_test/ros_buffer.h"
#include <ros/ros.h>
#include <gtest/gtest.h>
#include <sys/socket.h>

#define CMD_LEN 5
#define BUF_SIZE 5

class ROSTest : public ::testing::Test {
 public:
  ROSTest() {}

  void SetUp() {
    int fdpair[2];

    socketpair(PF_LOCAL, SOCK_STREAM, 0, fdpair);
    rosbuf_.setSocket(fdpair[0]);

    sockfd = fdpair[1];
  }

  void TearDown() {
    close(sockfd);
  }

  ROSBuffer rosbuf_;
  int sockfd;
  uint8_t buf[BUF_SIZE];
};

TEST_F(ROSTest, turnOnTest) {
  uint8_t correct[CMD_LEN] = {ROSBuffer::TURN_ON_CMD, 0x00, 0x00, 0x00, 0x00};
  rosbuf_.turnOn();

  ASSERT_EQ(read(sockfd, buf, BUF_SIZE), CMD_LEN);
  ASSERT_EQ(memcmp(buf, correct, CMD_LEN), 0);
}

TEST_F(ROSTest, turnOffTest) {
  uint8_t correct[CMD_LEN] = {ROSBuffer::TURN_OFF_CMD, 0x00, 0x00, 0x00, 0x00};
  rosbuf_.turnOff();

  ASSERT_EQ(read(sockfd, buf, BUF_SIZE), CMD_LEN);
  ASSERT_EQ(memcmp(buf, correct, CMD_LEN), 0);
}

TEST_F(ROSTest, writeTest) {
  uint8_t correct[CMD_LEN] = {0x35, 0x00, 0x25, 0x00, 0x15};
  rosbuf_.writePacket(correct);

  ASSERT_EQ(read(sockfd, buf, BUF_SIZE), CMD_LEN);
  ASSERT_EQ(memcmp(buf, correct, CMD_LEN), 0);
}

TEST_F(ROSTest, readTest) {
  uint8_t correct[CMD_LEN] = {0xAA, 0x00, 0x88, 0x00, 0x55};
  write(sockfd, correct, CMD_LEN);

  uint8_t * pkg_read = rosbuf_.readPacket();

  ASSERT_EQ(memcmp(pkg_read, correct, CMD_LEN), 0);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  ros::init(argc, argv, "ros_buffer_test");
  ros::NodeHandle n;
  return RUN_ALL_TESTS();
}