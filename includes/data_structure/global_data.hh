//
// Created by Pierrick on 22/09/2020.
//

#pragma once

#include <gtkmm.h>

namespace GMPF {
  struct GlobalData {
  private:
    Glib::RefPtr<Gtk::Builder> builder;
    Glib::RefPtr<Gtk::Application> app;

  public:
    static const Glib::RefPtr<Gtk::Builder> getBuilder();
    static const Glib::RefPtr<Gtk::Application> getApp();

    static void setBuilder(Glib::RefPtr<Gtk::Builder> builder);
    static void setApp(Glib::RefPtr<Gtk::Application> app);
  };
}  // namespace GMPF
