//
// Created by Pierrick on 01/10/2020.
//

#include <iostream>

#include "misc/logger.hh"

constexpr auto reset = "\033[0m";
constexpr auto boldRed = "\033[1m\033[31m";
constexpr auto boldMagenta = "\033[1m\033[35m";
constexpr auto boldWhite = "\033[1m\033[37m";

namespace GMPF {
  Logger::Logger()
      : logLevel_(Logger::INFO)
      , ostream_(std::clog)
      , fileStream_() {}

  Logger& Logger::debug() {
    auto& logger = instance();
    logger.logLevel_ = DEBUG;
    return logger;
  }
  Logger& Logger::info() {
    auto& logger = instance();
    logger.logLevel_ = INFO;
    return logger;
  }
  Logger& Logger::warn() {
    auto& logger = instance();
    logger.logLevel_ = WARN;
    return logger;
  }
  Logger& Logger::error() {
    auto& logger = instance();
    logger.logLevel_ = ERROR;
    return logger;
  }

  void Logger::setOutputStream(std::ostream& ostream) {
    auto& logger = instance();
    logger.ostream_.rdbuf(ostream.rdbuf());
    if (logger.fileStream_.is_open()) {
      logger.fileStream_.flush();
      logger.fileStream_.close();
    }
  }

  void Logger::setOutputStream(const std::string& filename) {
    auto& logger = instance();
    logger.fileStream_.open(filename);

    if (!logger.fileStream_.is_open())
      Logger::warn() << "unable to open config file" << std::endl;
    else
      logger.ostream_.rdbuf(logger.fileStream_.rdbuf());
  }

  std::ostream& operator<<(const Logger& logger, const std::string& msg) {
    switch (logger.logLevel_) {
    case Logger::DEBUG:
      logger.ostream_ << "[ " << boldWhite << "Debug" << reset << " ] " << msg;
      break;
    case Logger::INFO:
      logger.ostream_ << "[ " << boldWhite << "Info" << reset << " ] " << msg;
      break;
    case Logger::WARN:
      logger.ostream_ << "[ " << boldMagenta << "Warn" << reset << " ] " << msg;
      break;
    case Logger::ERROR:
      logger.ostream_ << "[ " << boldRed << "Error" << reset << " ] " << msg;
      break;
    default:
      Logger::warn() << "Unknown log level";
      logger.ostream_ << msg;
    }

    logger.ostream_.flush();
    return logger.ostream_;
  }
}  // namespace GMPF
