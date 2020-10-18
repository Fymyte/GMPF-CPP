//
// Created by Pierrick on 22/09/2020.
//

#pragma once

#include <optional>

#include <gtkmm/window.h>

namespace GMPF {
  /**
   * @brief Load the interface and apply a theme on it.
   *
   * It also connect signals from interface to callbacks.
   * @param themeFile The filename of the css theme file.
   * @param interface The filename of the xml interface file.
   * @return The root window of the interface.
   */
  std::optional<Gtk::Window*> configure(const std::string& themeFile,
                                        const std::string& interface);

  /**
   * @brief Quit the application.
   */
  void quit();
}  // namespace GMPF