//
// Created by Pierrick on 24/09/2020.
//

#include <gtkmm.h>

#include <callback/callbacks.hh>
#include <callback/signal_handler.hh>
#include <macro.hh>

namespace GMPF {
  void connectSignals(Glib::RefPtr<Gtk::Builder> builder) {
    CONNECT_SIGNAL(Gtk::MenuItem, Quit, activate, quitMenuItemActivate_cb, builder);
    CONNECT_SIGNAL(Gtk::Widget, MainWindow, delete_event, quitMainWindow_cb, builder);

    //    Gtk::Widget* MainWindow;
    //    builder->get_widget("MainWindow", MainWindow);
    //    MainWindow->signal_delete_event().connect(sigc::ptr_fun(&quitMenuItemActivate_cb));
  }
}  // namespace GMPF