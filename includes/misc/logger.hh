//
// Created by Pierrick on 30/09/2020.
//

#pragma once

#include <ostream>
#include <variant>
#include <optional>

#include <fstream>
#include <misc/singleton.hh>

namespace GMPF {
  class Logger: public Singleton<Logger> {
  public:
    Logger& operator=(const Logger& logger) = delete;
    Logger(const Logger& logger) = delete;

    static Logger& info();
    static Logger& warn();
    static Logger& error();

    static void setOutputStream(std::ostream& ostream);
    static void setOutputStream(const std::string& filename);

    friend std::ostream& operator<<(const Logger& logger, const std::string& msg);

  private:
    friend Logger& Singleton<Logger>::instance();
    Logger();
    enum logLevel {
      INFO,
      WARN,
      ERROR
    };
    logLevel logLevel_;
    std::ofstream fileStream_;
    std::ostream& ostream_;
  };

}  // namespace GMPF