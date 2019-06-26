#include "ros_test/ros_buffer.h"
#include <sys/socket.h>
#include <unistd.h>

ROSBuffer::ROSBuffer() {}
ROSBuffer::~ROSBuffer() {}
  
uint8_t * ROSBuffer::readPacket() {
  buffer_ = static_cast<uint8_t *>(malloc(sizeof(uint8_t) * BUFFER_SIZE));
  int n = read(fdpair_, buffer_, sizeof(buffer_));
  return buffer_;
}
void ROSBuffer::writePacket(uint8_t * pkg) {
  write(fdpair_, pkg, sizeof(pkg));
}

void ROSBuffer::turnOn() {
  uint8_t b[BUFFER_SIZE] = {TURN_ON_CMD, 0x00, 0x00, 0x00, 0x00};
  writePacket(b);
}

void ROSBuffer::turnOff() {
  uint8_t b[BUFFER_SIZE] = {TURN_OFF_CMD, 0x00, 0x00, 0x00, 0x00}; 
  writePacket(b);
}

void ROSBuffer::setSocket(int fdpair) {
  fdpair_ = fdpair;
}