//
// Created by Pierrick Guillaume on 24/09/2020.
//

#include "data_structures/global_data.hh"

namespace GMPF {
  GlobalData::GlobalData(SingletonToken) {}

  const Glib::RefPtr<Gtk::Builder> GlobalData::getBuilder() {
    return instance().builder_;
  }
  const Glib::RefPtr<Gtk::Application> GlobalData::getApp() {
    return instance().app_;
  }

  void GlobalData::setBuilder(Glib::RefPtr<Gtk::Builder> newBuilder) {
    instance().builder_ = std::move(newBuilder);
  }
  void GlobalData::setApp(Glib::RefPtr<Gtk::Application> newApp) {
    instance().app_ = std::move(newApp);
  }
}  // namespace GMPF
