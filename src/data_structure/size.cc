//
// Created by Pierrick on 28/09/2020.
//

#include "data_structure/size.hh"

namespace GMPF {
  Size::Size()
    : width_(0)
    , height_(0) {}
  Size::Size(int64 width, int64 height)
    : width_(width)
    , height_(height) {}
  Size::~Size() = default;

  Size& Size::add(const Size& other) {
    width_ += other.width_;
    height_ += other.height_;
    return *this;
  }
  Size& Size::sub(const Size& other) {
    width_ -= other.width_;
    height_ -= other.height_;
    return *this;
  }

  Size& Size::operator+=(const Size& other) { return this->add(other); }
  Size& Size::operator-=(const Size& other) { return this->sub(other); }

  Size Size::operator+(const Size& other) const {
    return { width_ + other.width_, height_ + other.height_ };
  }
  Size Size::operator-(const Size& other) const {
    return { width_ - other.width_, height_ - other.height_ };
  }
  Size Size::operator-() const { return { -width_, -height_ }; }

  bool Size::operator==(const Size& other) const {
    return width_ == other.width_ && height_ == other.height_;
  }
  bool Size::operator!=(const Size& other) const { return !(*this == other); }

  int64 Size::getWidth() const { return width_; }
  int64 Size::getHeight() const { return height_; }
}

