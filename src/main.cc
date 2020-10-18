//
// Created by Pierrick on 22/09/2020.
//

#include <optional>

#include <gtkmm.h>

#include "config/config.hh"
#include "data_structures/global_data.hh"
#include "gmpf.hh"
#include "misc/logger.hh"

int main(int argc, char* argv[]) {
  auto config = GMPF::Config::parseConfig(argc, argv);
  if (!config) return 0;

  Glib::RefPtr<Gtk::Application> app =
      Gtk::Application::create(argc, argv, "com.gmpf.fr");
  GMPF::GlobalData::setApp(app);

  std::optional<Gtk::Window*> window =
      GMPF::configure(config->getTheme(), config->getInterface());

  if (window.has_value()) return app->run(*(window.value()));
  return 1;
}
