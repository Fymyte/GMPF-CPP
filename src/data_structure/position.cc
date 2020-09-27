//
// Created by Pierrick Guillaume on 27/09/2020.
//

#include <defines.hh>
#include <data_structure/position.hh>

namespace GMPF {
  Position::Position()
  : x(0)
  , y(0) {}
  Position::Position(int64 x, int64 y)
  : x(x)
  , y(y) {}

  Position Position::operator=(const Position& other) const { return {x, y} ; }
  Position& Position::add(const Position& other) {
    x += other.x;
    y += other.y;
    return *this;
  }
  Position& Position::sub(const Position& other) {
    x -= other.x;
    y -= other.y;
    return *this;
  }
  Position Position::operator+(const Position& other) const {
    return {x + other.x, y + other.y};
  }
  Position Position::operator-(const Position& other) const {
    return {x - other.x, y - other.y};
  }
  Position& Position::operator+=(const Position& other) {
    return this->add(other);
  }
  Position& Position::operator-=(const Position& other) {
    return this->sub(other);
  }

  bool Position::operator==(const Position& other) const {
    return x == other.x && y == other.y;
  }
  bool Position::operator!=(const Position& other) const {
    return !(*this == other);
  }

  Position Position::operator-() const { return {-x, -y}; }

  int64 Position::getX() const { return x; }
  int64 Position::getY() const { return y; }
}