#include "calcgui.h"
#include <gtk/gtk.h>

#define WIDTH 400
#define HEIGHT 600

// Builds the Main Window for the calculator.
static void activate(GtkApplication *app) {
  GtkWidget *window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "Sam's Calc");
  gtk_window_set_default_size(GTK_WINDOW(window), WIDTH, HEIGHT);

  gtk_window_present(GTK_WINDOW(window));
}

int openWindow(int argc, char *argv[]) {
  GtkApplication *app = gtk_application_new("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
  int status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);

  return status;
}
