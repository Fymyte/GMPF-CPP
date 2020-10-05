//
// Created by Pierrick on 30/09/2020.
//

#include <fstream>

#include <nlohmann/json.hpp>

#include <config/config.hh>
#include <config/logger.hh>

namespace GMPF {
  Config::Config()
          : theme("themes/main.css")
          , interface("interface.glade") {}

  Config::Config(std::string theme, std::string interface)
          : theme(std::move(theme))
          , interface(std::move(interface)) {}

  Config Config::parseConfig() {
    // Open the file
    std::ifstream file("config.json");
    if (!file) {
      log::warn("unable to open config file. Loading default config");
      return Config();
    }

    // Parse the json
    nlohmann::json jsonConfig;
    file >> jsonConfig;

    return { jsonConfig["theme"], jsonConfig["interface"] };
  }

  const std::string& Config::getTheme() const { return theme; }
  const std::string& Config::getInterface() const { return interface; }
}
