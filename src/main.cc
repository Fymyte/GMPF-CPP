#include <data_structure/global_data.hh>
#include <gtk.hh>
#include <gtkmm.h>

int main(int argc, char* argv[]) {

  Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "com.gmpf.fr");
  GMPF::GlobalData::setApp(app);

  std::optional<Gtk::Window*> window = GMPF::start();

  if (window.has_value()) return app->run(*(window.value()));
  return 1;
}
