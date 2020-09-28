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
}

