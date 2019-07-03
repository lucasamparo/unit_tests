# Unit tests using Google Test Framework

Simple samples using gtest for c++ codes. This repository includes samples for ROS too.

## Examples
- [Simple example (Factorial)](basic_factorial/factorial.cpp)
- [Fixture Class (Factorial)](basic_fixture/factorial_test.cpp)
- [Basic ROS Test](ros_test/test/ros_basic_test.cpp)
- [Basic ROS Topics Test](ros_test/test/ros_topic_test.cpp)
- [Embed Simple Test](ros_test/test/ros_buffer_test.cpp)
- [Simple "out-of-scope" Test (Images)](image_test/image_test.cpp)

## Prerequisites
- [ROS](http://wiki.ros.org/ROS/Installation)
- [GTest](https://github.com/google/googletest) (if you have some trouble, [see this link](https://www.eriksmistad.no/getting-started-with-google-test-on-ubuntu/))
- [CMake](https://cgold.readthedocs.io/en/latest/first-step/installation.html)
 
## Compiling
Tests excluding ROS
```
mkdir build && cd build
cmake ..
make all
```
For each ROS test
```
make unit_tests_ros_basic
make unit_tests_ros_topic
make unit_tests_ros_buffer
```

## Running
Using the "devel" folder from ROS structure
```
cd devel/lib/unit_tests
./your_test
```
To run all available tests
```
ctest -v
```

## Contribuitions
Feel free to open an [Issue](https://github.com/lucasamparo/unit_tests/issues).

## Media
- [Presentation](https://docs.google.com/presentation/d/1lMtk-4C3U3mjAnuYhOP25-pU1MlAOL5bnnADVrPnem8/edit?usp=sharing)
 
## Changelog
- 26/06/2019: First version of repository
- 03/07/2019: README creation
