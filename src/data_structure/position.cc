//
// Created by Pierrick Guillaume on 27/09/2020.
//

#include "data_structure/position.hh"

namespace GMPF {
  Position::Position()
  : x_(0)
  , y_(0) {}
  Position::Position(int64 x, int64 y)
  : x_(x)
  , y_(y) {}
  Position::~Position() = default;
  Position& Position::add(const Position& other) {
    x_ += other.x_;
    y_ += other.y_;
    return *this;
  }
  Position& Position::sub(const Position& other) {
    x_ -= other.x_;
    y_ -= other.y_;
    return *this;
  }
  Position Position::operator+(const Position& other) const {
    return {x_ + other.x_, y_ + other.y_};
  }
  Position Position::operator-(const Position& other) const {
    return {x_ - other.x_, y_ - other.y_};
  }
  Position& Position::operator+=(const Position& other) {
    return this->add(other);
  }
  Position& Position::operator-=(const Position& other) {
    return this->sub(other);
  }

  bool Position::operator==(const Position& other) const {
    return x_ == other.x_ && y_ == other.y_;
  }
  bool Position::operator!=(const Position& other) const {
    return !(*this == other);
  }

  Position Position::operator-() const { return {-x_, -y_}; }

  int64 Position::getX() const { return x_; }
  int64 Position::getY() const { return y_; }
}