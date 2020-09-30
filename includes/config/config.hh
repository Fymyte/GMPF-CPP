//
// Created by Pierrick on 30/09/2020.
//

#pragma once

#include <string>

namespace GMPF {
  class Config {
  public:
    static Config parseConfig();

    [[nodiscard]] const std::string& getTheme() const;
    [[nodiscard]] const std::string& getInterface() const;
  private:
    Config(std::string theme, std::string interface);
    Config();

    const std::string theme;
    const std::string interface;
  };
}