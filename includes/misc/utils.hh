//
// Created by Pierrick on 22/09/2020.
//

#pragma once

#include <data_structure/global_data.hh>

namespace GMPF {
  template<typename T>
  inline T* getUiElement(const std::string& elementName) {
    T* widget;
    GlobalData::getBuilder()->get_widget(elementName, widget);
    return widget;
  }
}