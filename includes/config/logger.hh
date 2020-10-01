//
// Created by Pierrick on 30/09/2020.
//

#pragma once

#include <ostream>

namespace GMPF::log {
  void trace(std::string msg);
  void debug(std::string msg);
  void info(std::string msg);
  void warn(std::string msg);
  void error(std::string msg);
}  // namespace GMPF::log