//
// Created by Pierrick on 30/09/2020.
//

#include <exception>
#include <fstream>
#include <iostream>

#include <boost/program_options.hpp>

#include <config/config.hh>
#include <misc/logger.hh>

namespace po = boost::program_options;
namespace GMPF {
  Config::Config()
      : theme("themes/main.css")
      , interface("interface.glade") {}

  Config::Config(std::string theme, std::string interface)
      : theme(std::move(theme))
      , interface(std::move(interface)) {}

  std::optional<Config> Config::parseConfig(int argc, char* argv[]) {

    std::string config;
    std::string theme;
    std::string interface;

    po::options_description genericOpt("Generic options");
    genericOpt.add_options()
        ("help,h", "show this help message")
        ("version,v", "print program version")
        ("config,c",
            po::value<std::string>(&config)->default_value("gmpf.conf"),
            "name of a configuration file");

    po::options_description configOpt("Configuration");
    configOpt.add_options()
        ("output", po::value<std::string>(), "output file for logs")
        ("interface.theme",
            po::value<std::string>(&theme)->default_value("themes/main.css"),
            "path to a css theme file")
        ("interface.path",
            po::value<std::string>(&interface)->default_value("interface.glade"),
            "path to a glade interface file");

    po::options_description cmdOption;
    cmdOption.add(genericOpt).add(configOpt);
    po::options_description fileOption;
    fileOption.add(configOpt);

    try {
      po::variables_map vm;
      po::store(po::parse_command_line(argc, argv, cmdOption), vm);
      po::notify(vm);

      if (vm.count("help")) {
        std::cout << cmdOption << std::endl;
        return std::nullopt;
      }

      if (vm.count("version")) {
        std::cout << PROJECT_NAME << " v" << PROJECT_VERSION << std::endl;
        return std::nullopt;
      }

      std::ifstream inputStream(config);
      if (!inputStream)
        Logger::warn() << "Unable to open config file" << std::endl;
      else {
        po::store(po::parse_config_file(inputStream, fileOption), vm);
        notify(vm);
      }

      if (vm.count("output"))
        Logger::setOutputStream(vm["output"].as<std::string>());

      return { { theme, interface } };
    }
    catch (std::exception& e) {
      Logger::error() << "Unable to parse options: " << e.what() << std::endl;
      return { Config() };
    }
  }

  const std::string& Config::getTheme() const { return theme; }
  const std::string& Config::getInterface() const { return interface; }
}  // namespace GMPF
