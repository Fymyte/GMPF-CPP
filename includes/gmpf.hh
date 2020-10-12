//
// Created by Pierrick on 22/09/2020.
//

#pragma once

#include <optional>

#include <gtkmm.h>

namespace GMPF {
  std::optional<Gtk::Window*> start();
  void quit();
}  // namespace GMPF