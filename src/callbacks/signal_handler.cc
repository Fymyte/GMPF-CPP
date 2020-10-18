//
// Created by Pierrick on 24/09/2020.
//

#include "callback/signal_handler.hh"

#include <gtkmm/widget.h>
#include <gtkmm/menuitem.h>

#include "callback/callbacks.hh"

#define CONNECT_SIGNAL(_type, _name, _signal, _function, _builder)             \
  _type* _name;                                                                \
  _builder->get_widget(#_name, _name);                                         \
  _name->signal_##_signal().connect(sigc::ptr_fun(&_function));

namespace GMPF {
  void connectSignals(const Glib::RefPtr<Gtk::Builder>& builder) {
    CONNECT_SIGNAL(Gtk::MenuItem, Quit, activate, quitMenuItem_cb, builder);
    CONNECT_SIGNAL(Gtk::Widget, MainWindow, delete_event, quitMainWindow_cb,
                   builder);
  }
}  // namespace GMPF