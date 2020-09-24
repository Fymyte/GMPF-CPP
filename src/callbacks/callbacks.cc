//
// Created by Pierrick on 24/09/2020.
//

#include <data/global_data.hh>
#include <gtkmm.h>

void quitMenuItemActivate_cb() { GMPF::GlobalData::getApp()->quit(); }
bool quitMainWindow_cb(GdkEventAny*) {
  GMPF::GlobalData::getApp()->quit();
  return false;
}