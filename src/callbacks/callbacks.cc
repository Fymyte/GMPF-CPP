//
// Created by Pierrick on 24/09/2020.
//

#include "callbacks/callbacks.hh"

#include "gmpf.hh"

void quitMenuItem_cb() { GMPF::quit(); }
bool quitMainWindow_cb(GdkEventAny*) {
  GMPF::quit();
  return false;
}