//
// Created by Pierrick on 23/09/2020.
//

#pragma once

#include <gtkmm.h>

/**
 * @brief Called when the quit button from file menu is activated.
 */
void quitMenuItem_cb();
/**
 * @brief Called when the cross button from the main window is activated.
 * @return false (constrains by signature of Gtk event callbacks)
 */
bool quitMainWindow_cb(GdkEventAny*);
