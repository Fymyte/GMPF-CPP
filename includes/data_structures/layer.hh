///
/// @file layer.hh
/// @author Pierrick Guillaume
/// @date 18/10/2020.
///

#pragma once

#include <optional>

#include <gdkmm/pixbuf.h>
#include <gtkmm/grid.h>
#include <gtkmm/flowboxchild.h>
#include <cairomm/context.h>

#include "data_structures/size.hh"
#include "data_structures/position.hh"
#include "data_structures/angle.hh"

namespace GMPF {
  class Layer {
  public:
    Layer* loadFromFile(const std::string& filename);
    bool saveToFile(const std::string& filename);

  private:
    Glib::ustring name_;

    Position position_;
    Size size_;
    Angle rotationAngle_;
    bool visible_;

    Gdk::Pixbuf* image_;

    Cairo::Surface* surface_;
    Cairo::Context* cr_;

    Gtk::Grid* UIIcon_;
    Gtk::FlowBoxChild* UIElement_;
  };
}  // namespace GMPF
