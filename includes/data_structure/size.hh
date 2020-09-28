//
// Created by Pierrick on 28/09/2020.
//

#pragma once

#include <defines.hh>

namespace GMPF {
  class Size {
  public:
    Size();
    Size(int64 width, int64 height);

    Size& operator=(const Size& other);

    Size& add(const Size& other);
    Size& sub(const Size& other);

    Size& operator+=(const Size& other);
    Size& operator-=(const Size& other);

    Size operator+(const Size& other) const;
    Size operator-(const Size& other) const;

    Size operator-() const;

    bool operator==(const Size& other) const;
    bool operator!=(const Size& other) const;

    [[nodiscard]] int64 getWidth() const;
    [[nodiscard]] int64 getHeight() const;

    void setWidth(int64 width);
    void setHeight(int64 height);

  private:
    int64 width;
    int64 height;
  };
}
