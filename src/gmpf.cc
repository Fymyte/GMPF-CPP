//
// Created by Pierrick on 22/09/2020.
//

#include "gmpf.hh"

#include <iostream>
#include <optional>

#include <gtkmm/builder.h>
#include <gtkmm/cssprovider.h>
#include <giomm.h>

#include "callbacks/signal_handler.hh"
#include "data_structures/global_data.hh"
#include "misc/utils.hh"

namespace GMPF {
  std::optional<Gtk::Window*> configure(const std::string& themeFile,
                                        const std::string& interface) {

    gchar* filename = g_build_filename(interface.c_str(), nullptr);
    Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create();
    try {
      builder->add_from_file(filename);
    } catch (const Glib::FileError& ex) {
      std::cerr << "FileError: " << ex.what() << std::endl;
      return std::nullopt;
    } catch (const Glib::MarkupError& ex) {
      std::cerr << "MarkupError: " << ex.what() << std::endl;
      return std::nullopt;
    } catch (const Gtk::BuilderError& ex) {
      std::cerr << "BuilderError: " << ex.what() << std::endl;
      return std::nullopt;
    }
    g_free(filename);
    GlobalData::setBuilder(builder);

    // Connect signals to handlers
    connectSignals(builder);

    // Set accepted events for drawingArea
    auto drawingArea = getUiElement<Gtk::Widget>("drawingArea");
    Gdk::EventMask mask = Gdk::EventMask::BUTTON_PRESS_MASK |
                          Gdk::EventMask::POINTER_MOTION_MASK |
                          Gdk::EventMask::BUTTON_RELEASE_MASK |
                          Gdk::EventMask::ENTER_NOTIFY_MASK |
                          Gdk::EventMask::LEAVE_NOTIFY_MASK;
    drawingArea->set_events(drawingArea->get_events() | mask);

    // Set theme from css
    auto mainWindow = getUiElement<Gtk::Window>("MainWindow");
    Glib::RefPtr<Gdk::Screen> screen = mainWindow->get_screen();
    Glib::RefPtr<Gtk::CssProvider> provider = Gtk::CssProvider::create();
    provider->load_from_file(Gio::File::create_for_path(themeFile));
    Gtk::StyleContext::add_provider_for_screen(
        screen, provider, GTK_STYLE_PROVIDER_PRIORITY_USER);

    // Display all widget
    mainWindow->show_all();

    // Uncompress events from the drawing area
    Glib::RefPtr<Gdk::Window> gdkWindow = drawingArea->get_window();
    gdkWindow->set_event_compression(false);

    return mainWindow;
  }

  void quit() {
    GlobalData::getApp()->quit();
  }
}  // namespace GMPF
