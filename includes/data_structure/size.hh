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

  private:
    int64 width;
    int64 height;
  };
}
