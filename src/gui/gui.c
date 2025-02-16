#include <gtk/gtk.h>
#include "config.h"
#include "main-window.h"
#include "sub-window.h"
#include "struct.h" // for param.num_sensors
#include "gui.h"

extern Param_t param; // Import from struct.c, for param.num_sensors

// TODO: Move this to imain-window.c init_imain_window()
// The main window text is now initialied through the imain-window interface.
// The text in the .UI file is now just a placeholder, it can be removed.
// We no longer have to worry about waiting for the window to be created
// before we start writing to the labels. 
void init_main_window_data_disp_text(void)
{
  for(unsigned int channel = 0; channel < param.num_sensors; ++channel) {
    set_data_display_label_sensor_raw(channel, "0.00");
    set_data_display_label_sensor_pv(channel, "0.00");
  }
}

int run_gui_application(int argc, char *argv[])
{
  GtkApplication *main_app;
  int status;

  init_main_window_data_disp_text(); // TODO: get rid of

  // Disable accessibility so we don't get a bunch of warnings about it.
  g_setenv("GTK_A11Y", "none", TRUE);

  // On the RPi OS, it complains that G_APPLICATION_FLAGS_NONE is deprecated,
  // and that we should use instead use G_APPLICATION_DEFAULT_FLAGS.
  // But on Linux mint AMD64, that doesn't even exist.
  main_app = gtk_application_new("com.makeithappen.sensorcal", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect(main_app, "activate", G_CALLBACK(activate_main_window_cb), NULL);
  status = g_application_run(G_APPLICATION(main_app), argc, argv);

  g_object_unref(main_app);
  return status;
}
