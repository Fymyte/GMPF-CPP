//
// Created by Pierrick Guillaume on 24/09/2020.
//

#include <data_structure/global_data.hh>
#include <gtkmm.h>

namespace GMPF {
  const Glib::RefPtr<Gtk::Builder> GlobalData::getBuilder() {
    return instance().builder;
  }
  const Glib::RefPtr<Gtk::Application> GlobalData::getApp() {
    return instance().app;
  }

  void GlobalData::setBuilder(Glib::RefPtr<Gtk::Builder> newBuilder) {
    instance().builder = std::move(newBuilder);
  }
  void GlobalData::setApp(Glib::RefPtr<Gtk::Application> newApp) {
    instance().app = std::move(newApp);
  }
}  // namespace GMPF