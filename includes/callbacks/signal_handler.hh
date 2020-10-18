//
// Created by Pierrick on 24/09/2020.
//

#pragma once

#include <gtkmm/builder.h>

namespace GMPF {
  /**
   * @brief Connect each useful button and event to its corresponding callback.
   * @param builder The \a Gtk::Builder which hold the interface and from which
   * signals are raised.
   */
  void connectSignals(const Glib::RefPtr<Gtk::Builder>& builder);
}  // namespace GMPF
