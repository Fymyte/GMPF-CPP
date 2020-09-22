#include <gtk/gtk.h>
#include <err.h>

#include "gtk.hh"

int main(int argc, char* argv[]) {

    /* Init the Gtk library. */
    gtk_init(&argc, &argv);

    int error = GMPF::start();

    return error;
}
