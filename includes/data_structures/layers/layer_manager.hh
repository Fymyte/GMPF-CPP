///
/// @file layer_manager.hh
/// @author Pierrick Guillaume
/// @date 18/10/2020.
///

#pragma once

#include "data_structures/layers/layer.hh"

#include <gtkmm/flowbox.h>
#include <vector>

namespace GMPF {
  class LayerManager {
  public:
  private:
    std::vector<Layer> layers_;
    Gtk::FlowBox* UIElement_;
  };
}
