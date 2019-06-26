#include "image.h"
#include <fstream>
#include <gtest/gtest.h>
#include <opencv2/opencv.hpp>

class ImageTest : public ::testing::Test {
 public:
  ImageTest() {}

  void SetUp() {
    std::string path = "/home/lucasamparo/bir_tests/unit_tests/image_test/test.jpg";

    img1_.loadImage(path);
  }

  void TearDown() {}

  ImageWrap img0_;
  ImageWrap img1_;
};

TEST_F(ImageTest, isEmptyInitial) {
  cv::Mat i = img0_.getImage();

  EXPECT_EQ(i.cols, 0);
  EXPECT_EQ(i.rows, 0);
}

TEST_F(ImageTest, isValidPath) {
  std::string path_0 = img0_.getImagePath();
  std::string path_1 = img1_.getImagePath();

  std::ifstream f(path_1);

  EXPECT_EQ(path_0.size(), 0);
  EXPECT_GT(path_1.size(), 0);
  EXPECT_TRUE(f.good());
}

TEST_F(ImageTest, isValidImageL2) {
  cv::Mat groundtruth =
      cv::imread("/home/lucasamparo/bir_tests/unit_tests/image_test/test.jpg");

  cv::Mat img = img1_.getImage();

  double size_prod = (double)(groundtruth.rows * groundtruth.cols);
  double error = cv::norm(groundtruth, img, CV_L2) / size_prod;

  EXPECT_EQ(error, 0);
}

TEST_F(ImageTest, notValidImageL2) {
  cv::Mat groundtruth =
      cv::imread("/home/lucasamparo/bir_tests/unit_tests/image_test/wrong_test.jpg");

  cv::Mat img = img1_.getImage();

  double size_prod = (double)(groundtruth.rows * groundtruth.cols);
  double error = cv::norm(groundtruth, img, CV_L2) / size_prod;

  EXPECT_GT(error, 0);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}