#include <gtk/gtk.h>
#include "config.h"
#include "main-window.h"
#include "sub-window.h"
#include "struct.h" // for param.num_sensors
#include "gui.h"

extern Param_t param; // Import from struct.c, for param.num_sensors

// The main window text is now initialied through the imain-window interface.
// The text in the .UI file is now just a placeholder, it can be removed.
// We no longer have to worry about waiting for the window to be created
// before we start writing to the labels. 
void init_main_window_data_disp_text(void)
{
  /*set_data_display_label_sensor_raw0("Data Display 0");
  set_data_display_label_sensor_raw1("Data Display 1");
  set_data_display_label_sensor_raw2("Data Display 2");
  set_data_display_label_sensor_raw3("Data Display 3");
  set_data_display_label_sensor_raw4("Data Display 4");
  set_data_display_label_sensor_raw5("Data Display 5");
  set_data_display_label_sensor_raw6("Data Display 6");
  set_data_display_label_sensor_raw7("Data Display 7");
  set_data_display_label_sensor_pv0("Data Display 8");
  set_data_display_label_sensor_pv1("Data Display 9");
  set_data_display_label_sensor_pv2("Data Display 10");
  set_data_display_label_sensor_pv3("Data Display 11");
  set_data_display_label_sensor_pv4("Data Display 12");
  set_data_display_label_sensor_pv5("Data Display 13");
  set_data_display_label_sensor_pv6("Data Display 14");
  set_data_display_label_sensor_pv7("Data Display 15");*/
  for(unsigned int channel = 0; channel < param.num_sensors; ++channel) {
    set_data_display_label_sensor_raw(channel, "0.00");
    set_data_display_label_sensor_pv(channel, "0.00");
  }
}

int run_gui_application(int argc, char *argv[])
{
  GtkApplication *main_app;
  int status;

  init_main_window_data_disp_text();

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