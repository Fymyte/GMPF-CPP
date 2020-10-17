//
// Created by Pierrick on 28/09/2020.
//

#include "data_structure/size.hh"

namespace GMPF {
  Size::Size()
    : width(0)
    , height(0) {}
  Size::Size(int64 width, int64 height)
    : width(width)
    , height(height) {}
  Size::~Size() = default;

  Size& Size::add(const Size& other) {
    width += other.width;
    height += other.height;
    return *this;
  }
  Size& Size::sub(const Size& other) {
    width -= other.width;
    height -= other.height;
    return *this;
  }

  Size& Size::operator+=(const Size& other) { return this->add(other); }
  Size& Size::operator-=(const Size& other) { return this->sub(other); }

  Size Size::operator+(const Size& other) const {
    return { width + other.width, height + other.height };
  }
  Size Size::operator-(const Size& other) const {
    return { width - other.width, height - other.height };
  }
  Size Size::operator-() const { return { -width, -height }; }

  bool Size::operator==(const Size& other) const {
    return width == other.width && height == other.height;
  }
  bool Size::operator!=(const Size& other) const { return !(*this == other); }

  int64 Size::getWidth() const { return width; }
  int64 Size::getHeight() const { return height; }
}

