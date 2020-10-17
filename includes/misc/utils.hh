///
/// @file utils.hh
/// @author Pierrick Guillaume.
/// @date 22/09/2020.
///

#pragma once

#include <data_structure/global_data.hh>

namespace GMPF {
  /**
   * @brief Retrieve a Gtk::Widget from the interface and cast it to type T
   * @tparam T The type of the element to retrieve
   * @param elementName The unique name of the element in the interface
   * @return The widget from the interface
   */
  template<typename T>
  inline T* getUiElement(const std::string& elementName) {
    T* widget;
    GlobalData::getBuilder()->get_widget(elementName, widget);
    return widget;
  }
}