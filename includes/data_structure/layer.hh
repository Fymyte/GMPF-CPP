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

#include "data_structure/size.hh"
#include "data_structure/position.hh"
#include "data_structure/angle.hh"

namespace GMPF {
  class Layer {
  public:
    Layer* loadFromFile(const std::string& filename);
    bool saveToFile(const std::string& filename);

  private:
    Glib::ustring name;

    Position position;
    Size size;
    Angle rotationAngle;
    bool visible;

    Gdk::Pixbuf* image;

    Cairo::Surface* surface;
    Cairo::Context* cr;

    Gtk::Grid* UIIcon;
    Gtk::FlowBoxChild* UIElement;
  };
}  // namespace GMPF
