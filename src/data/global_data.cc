//
// Created by Pierrick on 24/09/2020.
//

#include <data/global_data.hh>
#include <utility>

namespace GMPF {
  namespace {
    GlobalData data;
  }  // namespace

  const Glib::RefPtr<Gtk::Builder> GlobalData::getBuilder() { return data.builder; }
  const Glib::RefPtr<Gtk::Application> GlobalData::getApp() { return data.app; }

  void GlobalData::setBuilder(Glib::RefPtr<Gtk::Builder> newBuilder) { data.builder = std::move(newBuilder); }
  void GlobalData::setApp(Glib::RefPtr<Gtk::Application> newApp) { data.app = std::move(newApp); }
}  // namespace GMPF