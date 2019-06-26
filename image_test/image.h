#include <iostream>

#include <opencv2/opencv.hpp>

class ImageWrap {
 public:
  ImageWrap();
  ~ImageWrap();

  void loadImage(std::string path);
  cv::Mat getImage();
  std::string getImagePath();

 private:
  std::string image_path_;
  cv::Mat image_;
};