//
// Created by Pierrick on 07/10/2020.
//

#include <string>
#include <fstream>

#include <gtest/gtest.h>

#include <misc/logger.hh>

class LoggerTest: public ::testing::Test {
public:
  LoggerTest() {
    ::testing::internal::CaptureStderr();
  }
};

TEST_F(LoggerTest, log_info_on_console) {
  std::string message = "hello there";

  GMPF::Logger::info() << message << std::endl;
  GMPF::Logger::info() << message << std::endl;

  ASSERT_EQ("[ \x1B[1m\x1B[37mInfo\x1B[0m ] " + message +
                    "\n[ \x1B[1m\x1B[37mInfo\x1B[0m ] " + message + "\n",::testing::internal::GetCapturedStderr());
}

TEST_F(LoggerTest, log_warning_on_console) {
  std::string message = "hello there";

  GMPF::Logger::warn() << message << std::endl;
  GMPF::Logger::warn() << message << std::endl;

  ASSERT_EQ("[ \033[1m\033[35mWarn\x1B[0m ] " + message +
                    "\n[ \033[1m\033[35mWarn\x1B[0m ] " + message + "\n", ::testing::internal::GetCapturedStderr());
}

TEST_F(LoggerTest, log_error_on_console) {
  std::string message = "hello there";

  GMPF::Logger::error() << message << std::endl;
  GMPF::Logger::error() << message << std::endl;

  ASSERT_EQ("[ \033[1m\033[31mError\x1B[0m ] " + message +
                    "\n[ \033[1m\033[31mError\x1B[0m ] " + message + "\n", ::testing::internal::GetCapturedStderr());
}
