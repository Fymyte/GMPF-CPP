//
// Created by Pierrick on 30/09/2020.
//

#pragma once

#include <exception>

class ParsingException: public std::exception {
public:
  explicit ParsingException(const char* msg);
  [[nodiscard]] const char* what() const noexcept override;
private:
  const char* msg;
};
