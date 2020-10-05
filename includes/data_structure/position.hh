//
// Created by Pierrick Guillaume on 27/09/2020.
//

#pragma once

#include <misc/type.hh>

namespace GMPF {
  class Position {
  public:
    Position();
    Position(int64 x, int64 y);
    virtual ~Position();

    Position& operator=(const Position& other);

    Position& add(const Position& other);
    Position& sub(const Position& other);

    Position operator+(const Position& other) const;
    Position operator-(const Position& other) const;

    Position& operator+=(const Position& other);
    Position& operator-=(const Position& other);

    Position operator-() const;

    bool operator==(const Position& other) const;
    bool operator!=(const Position& other) const;

    [[nodiscard]] int64 getX() const;
    [[nodiscard]] int64 getY() const;

  private:
    int64  x;
    int64  y;
  };
}
