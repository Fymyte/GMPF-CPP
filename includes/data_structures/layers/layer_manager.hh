///
/// @file layer_manager.hh
/// @author Pierrick Guillaume
/// @date 18/10/2020.
///

#pragma once

#include "data_structures/layers/layer.hh"

#include <vector>
#include <functional>

#include <gtkmm/flowbox.h>

#include "misc/singleton.hh"

namespace GMPF {
  class LayerManager: Singleton<LayerManager> {
  public:
    static bool addLayer(Layer* layer, Uint16 index = 0);
    static bool dropSelectedLayer();
    static Uint16 dropSelectedLayers();

    static std::vector<Layer*> getLayers();
    static Layer* getSelectedLayer();
    static std::vector<Layer*> getSelectedLayers();

    static void forEatchSeletedLayer(std::function<void(Layer*)> function);

  private:
//    std::vector<Layer*> layers_;
    Gtk::FlowBox* UIElement_;
  };
}
