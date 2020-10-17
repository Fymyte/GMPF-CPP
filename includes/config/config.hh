///
/// @file config.hh
/// @author Pierrick Guillaume
/// @date 30/09/2020.
///

#pragma once

#include <string>
#include <optional>

namespace GMPF {
  /**
   * @class Config
   * @brief A configuration class.
   *
   * This class use the \a boost::program_option to parse command line options
   * and allow usage of a config file
   */
  class Config {
  public:
    /**
     * @brief Parse config using command line and config file.
     *
     * Command line arguments overloads config file settings.
     * @param argc The number of command line arguments.
     * @param argv The list of command line arguments.
     * @return An instance of \a Config, or an empty option if something went
     * wrong.
     */
    static std::optional<Config> parseConfig(int argc, char* argv[]);

    /// @name Getters.
    /// @{
    /** Retrieve theme filename. */
    [[nodiscard]] const std::string& getTheme() const;
    /** Retrieve interface filename. */
    [[nodiscard]] const std::string& getInterface() const;
    /// @}
  private:
    Config(std::string theme, std::string interface);
    Config();

    const std::string theme;
    const std::string interface;
  };
}