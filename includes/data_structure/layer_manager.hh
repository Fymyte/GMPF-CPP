///
/// @file layer_manager.hh
/// @author Pierrick Guillaume
/// @date 18/10/2020.
///

#pragma once

#include <vector>

#include <gtkmm/flowbox.h>

#include "data_structure/layer.hh"

namespace GMPF {
  class LayerManager {
  public:
  private:
    std::vector<Layer> layers;
    Gtk::FlowBox* UIElement;
  };
}
