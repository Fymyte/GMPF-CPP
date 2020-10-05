//
// Created by Pierrick on 01/10/2020.
//

#include <config/logger.hh>

#include <iostream>

constexpr auto RESET = "\033[0m";
constexpr auto BOLDRED = "\033[1m\033[31m";     /* Bold Red */
constexpr auto BOLDGREEN = "\033[1m\033[32m";   /* Bold Green */
constexpr auto BOLDMAGENTA = "\033[1m\033[35m"; /* Bold Magenta */
constexpr auto BOLDWHITE = "\033[1m\033[37m";   /* Bold White */

namespace GMPF::log {
  void trace(std::string msg) { std::clog << "[ " << BOLDWHITE   << "Trace" << RESET << " ] " << msg; }
  void debug(std::string msg) { std::clog << "[ " << BOLDWHITE   << "Debug" << RESET << " ] " << msg; }
  void info(std::string msg)  { std::clog << "[ " << BOLDGREEN   << "Info"  << RESET << " ] " << msg; }
  void warn(std::string msg)  { std::clog << "[ " << BOLDMAGENTA << "Warn"  << RESET << " ] " << msg; }
  void error(std::string msg) { std::clog << "[ " << BOLDRED     << "Error" << RESET << " ] " << msg; }
}  // namespace GMPF::log
