cmake_minimum_required(VERSION 2.6)
project(unit_tests)

set (CMAKE_CXX_STANDARD 11)

# Configure executables names
set (EXEC_BASIC ${PROJECT_NAME}_basic)
set (EXEC_FIXTURE ${PROJECT_NAME}_fixture)
set (EXEC_IMAGE ${PROJECT_NAME}_image)
set (EXEC_ROS_BASIC ${PROJECT_NAME}_ros_basic)
set (EXEC_ROS_TOPIC ${PROJECT_NAME}_ros_topic)
set (EXEC_ROS_BUFFER ${PROJECT_NAME}_ros_buffer)

set (BUILD_PATH ${CATKIN_DEVEL_PREFIX}/lib/${PROJECT_NAME})

# Setup testing
enable_testing()

find_package(GTest REQUIRED)
find_package(OpenCV REQUIRED)
find_package(catkin REQUIRED COMPONENTS
  roscpp
)

catkin_package()

include_directories(
  ros_test/include
  ${catkin_INCLUDE_DIRS}
  ${GTEST_INCLUDE_DIR}
  ${OpenCV_INCLUDE_DIRS}
)

# Factorial basic test
add_executable(
    ${EXEC_BASIC}
    basic_factorial/factorial.cpp
)
target_link_libraries(${EXEC_BASIC} ${GTEST_LIBRARY} ${GTEST_MAIN_LIBRARY})
add_test(NAME ${EXEC_BASIC} COMMAND ${EXEC_BASIC})

# Factorial with Fixture test
add_executable(
    ${EXEC_FIXTURE}
    basic_fixture/factorial_test.cpp
    basic_fixture/factorial.cpp
)
target_link_libraries(${EXEC_FIXTURE} ${GTEST_LIBRARY} ${GTEST_MAIN_LIBRARY})
add_test(NAME ${EXEC_FIXTURE} COMMAND ${EXEC_FIXTURE})

# Image Test
add_executable(
    ${EXEC_IMAGE}
    image_test/image.cpp
    image_test/image_test.cpp
)
target_link_libraries(${EXEC_IMAGE} ${GTEST_LIBRARY} ${GTEST_MAIN_LIBRARY} ${OpenCV_LIBS})
add_test(NAME ${EXEC_IMAGE} COMMAND ${EXEC_IMAGE})

# ROS Basic Test
if(CATKIN_ENABLE_TESTING)
  catkin_add_gtest(
      ${EXEC_ROS_BASIC}
      ros_test/test/ros_basic_test.cpp
      ros_test/src/ros_basic.cpp
  )
  target_link_libraries(${EXEC_ROS_BASIC} ${catkin_LIBRARIES}) 
endif()

# ROS Topic Test
if(CATKIN_ENABLE_TESTING)
  catkin_add_gtest(
      ${EXEC_ROS_TOPIC}
      ros_test/test/ros_topic_test.cpp
      ros_test/src/ros_topic.cpp
  )
  target_link_libraries(${EXEC_ROS_TOPIC} ${catkin_LIBRARIES}) 
endif()

# ROS Buffer Test
if(CATKIN_ENABLE_TESTING)
  catkin_add_gtest(
      ${EXEC_ROS_BUFFER}
      ros_test/test/ros_buffer_test.cpp
      ros_test/src/ros_buffer.cpp
  )
  target_link_libraries(${EXEC_ROS_BUFFER} ${catkin_LIBRARIES}) 
endif()
