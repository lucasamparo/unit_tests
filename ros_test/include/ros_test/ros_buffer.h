#include <iostream>

class ROSBuffer {
 public:
  static const int BUFFER_SIZE = 5;
  static const int BROADCAST_ADDRESS = 0x52;
  static const int TURN_OFF_CMD = 0x80;
  static const int TURN_ON_CMD = 0x20;
  
  ROSBuffer();
  ~ROSBuffer();
  
  uint8_t * readPacket();
  void writePacket(uint8_t * pkg);

  void turnOn();
  void turnOff();

  void setSocket(int fdpair);

 private:
  uint8_t * buffer_;
  int fdpair_;
};