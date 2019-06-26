#include "image.h"

ImageWrap::ImageWrap() {}

ImageWrap::~ImageWrap() {}

void ImageWrap::loadImage(std::string path) {
  image_path_ = path;
  image_ = cv::imread(path, -1);
}

std::string ImageWrap::getImagePath() {
  return image_path_;
}

cv::Mat ImageWrap::getImage() {
  return image_;
}