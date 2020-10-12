//
// Created by Pierrick on 30/09/2020.
//

#include <fstream>

#include <nlohmann/json.hpp>

#include <config/config.hh>
#include <misc/logger.hh>

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
      Logger::warn() << "unable to open config file. Loading default config" << "\n";
      return Config();
    }

    // Parse the json
    nlohmann::json jsonConfig;
    file >> jsonConfig;

    std::string theme;
    if (jsonConfig.find("theme") != jsonConfig.end()) theme = jsonConfig["theme"];
    else theme = "themes/main.css";

    std::string interface;
    if (jsonConfig.find("interface") != jsonConfig.end()) theme = jsonConfig["interface"];
    else interface = "interface.glade";

    if (jsonConfig.find("log-file") != jsonConfig.end())
      Logger::setOutputStream(std::make_shared<std::ofstream>(std::ofstream(jsonConfig["interface"])));

    return { theme, interface };
  }

  const std::string& Config::getTheme() const { return theme; }
  const std::string& Config::getInterface() const { return interface; }
}
