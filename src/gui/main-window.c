/**
 * @file main-window.c
 * @brief Main Window file for the 555 soil moisture sensor calibration
 * @par (C) 2025 Keith Hall
 * Read this to understand some of what is going on..
 * The GLib Object System
 * https://docs.gtk.org/gobject/concepts.html
 * 
 * Why did I start this project with cpp and then switch to C to do the GUI?
 * Because.
 */
#include "config.h"
#include "imain-window.h"
#include "main-window.h"
#include "sub-window.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

extern IMainWindow imain_window;

// This is the handle for the idle function that updates the main window 
static guint window_update_fn_source_id = 0;

typedef struct _MainWindow
{
  GtkApplicationWindow parent_instance;

  GtkWidget *col_header_sensor_raw;
  GtkWidget *col_header_sensor_pv;

  GtkWidget *data_display_label_sensor_raw0;
  GtkWidget *data_display_label_sensor_raw1;
  GtkWidget *data_display_label_sensor_raw2;
  GtkWidget *data_display_label_sensor_raw3;
  GtkWidget *data_display_label_sensor_raw4;
  GtkWidget *data_display_label_sensor_raw5;
  GtkWidget *data_display_label_sensor_raw6;
  GtkWidget *data_display_label_sensor_raw7;
  GtkWidget *data_display_label_sensor_pv0;
  GtkWidget *data_display_label_sensor_pv1;
  GtkWidget *data_display_label_sensor_pv2;
  GtkWidget *data_display_label_sensor_pv3;
  GtkWidget *data_display_label_sensor_pv4;
  GtkWidget *data_display_label_sensor_pv5;
  GtkWidget *data_display_label_sensor_pv6;
  GtkWidget *data_display_label_sensor_pv7;
  
  GtkWidget *button0; // bottom button

  GtkWidget *button_zero0;
  GtkWidget *button_zero1;
  GtkWidget *button_zero2;
  GtkWidget *button_zero3;
  GtkWidget *button_zero4;
  GtkWidget *button_zero5;
  GtkWidget *button_zero6;
  GtkWidget *button_zero7;

  GtkWidget *button_span0;
  GtkWidget *button_span1;
  GtkWidget *button_span2;
  GtkWidget *button_span3;
  GtkWidget *button_span4;
  GtkWidget *button_span5;
  GtkWidget *button_span6;
  GtkWidget *button_span7;

} MainWindow;

typedef struct _MainWindowClass
{
  GtkApplicationWindowClass parent_class;
} MainWindowClass;

// Register the MainWindow type with the GObject type system.
// This macro will actually take the string "my_app_window" and converts it to
// "main_window_app_class_init" and "main_app_window_init", and stores those
// names internally. That is how GTK knows where to find the class and init
// functions in here! Terrible for the uninitiated.
// It seems to care that MainWindowClass struct is named after MainWindow
// struct.. with "Class" appended to the end.
G_DEFINE_TYPE(MainWindow, main_window, GTK_TYPE_APPLICATION_WINDOW)
// moved this down here to make it clearer that below line is related to the
// line above.
#define MAIN_WINDOW_TYPE (main_window_get_type())

#define MAIN_WINDOW(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), MAIN_WINDOW_TYPE, MainWindow))

static void main_window_class_init(MainWindowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS(klass);
  GError *error = NULL;
  char *contents;
  gsize length;

  // Load the template from the file. Alternatively, you can compile the UI and
  // store it as a GResource, but that's a bit more complicated. See the howto
  // file I included in this project's root directory called
  // compiled-ui-resources-howto.txt.
  if (g_file_get_contents(PATH_TO_MAIN_WIN_RESOURCE, &contents, &length, &error)) {
    GBytes *template_bytes = g_bytes_new_take(contents, length);
    gtk_widget_class_set_template(widget_class, template_bytes);
    g_bytes_unref(template_bytes);

    gtk_widget_class_bind_template_child(widget_class, MainWindow, col_header_sensor_raw);
    gtk_widget_class_bind_template_child(widget_class, MainWindow, col_header_sensor_pv);

    gtk_widget_class_bind_template_child(widget_class, MainWindow, data_display_label_sensor_raw0);
    gtk_widget_class_bind_template_child(widget_class, MainWindow, data_display_label_sensor_raw1);
    gtk_widget_class_bind_template_child(widget_class, MainWindow, data_display_label_sensor_raw2);
    gtk_widget_class_bind_template_child(widget_class, MainWindow, data_display_label_sensor_raw3);
    gtk_widget_class_bind_template_child(widget_class, MainWindow, data_display_label_sensor_raw4);
    gtk_widget_class_bind_template_child(widget_class, MainWindow, data_display_label_sensor_raw5);
    gtk_widget_class_bind_template_child(widget_class, MainWindow, data_display_label_sensor_raw6);
    gtk_widget_class_bind_template_child(widget_class, MainWindow, data_display_label_sensor_raw7);
    gtk_widget_class_bind_template_child(widget_class, MainWindow, data_display_label_sensor_pv0);
    gtk_widget_class_bind_template_child(widget_class, MainWindow, data_display_label_sensor_pv1);
    gtk_widget_class_bind_template_child(widget_class, MainWindow, data_display_label_sensor_pv2);
    gtk_widget_class_bind_template_child(widget_class, MainWindow, data_display_label_sensor_pv3);
    gtk_widget_class_bind_template_child(widget_class, MainWindow, data_display_label_sensor_pv4);
    gtk_widget_class_bind_template_child(widget_class, MainWindow, data_display_label_sensor_pv5);
    gtk_widget_class_bind_template_child(widget_class, MainWindow, data_display_label_sensor_pv6);
    gtk_widget_class_bind_template_child(widget_class, MainWindow, data_display_label_sensor_pv7);

    gtk_widget_class_bind_template_child(widget_class, MainWindow, button0);

    gtk_widget_class_bind_template_child(widget_class, MainWindow, button_zero0);
    gtk_widget_class_bind_template_child(widget_class, MainWindow, button_zero1);
    gtk_widget_class_bind_template_child(widget_class, MainWindow, button_zero2);
    gtk_widget_class_bind_template_child(widget_class, MainWindow, button_zero3);
    gtk_widget_class_bind_template_child(widget_class, MainWindow, button_zero4);
    gtk_widget_class_bind_template_child(widget_class, MainWindow, button_zero5);
    gtk_widget_class_bind_template_child(widget_class, MainWindow, button_zero6);
    gtk_widget_class_bind_template_child(widget_class, MainWindow, button_zero7);
    gtk_widget_class_bind_template_child(widget_class, MainWindow, button_span0);
    gtk_widget_class_bind_template_child(widget_class, MainWindow, button_span1);
    gtk_widget_class_bind_template_child(widget_class, MainWindow, button_span2);
    gtk_widget_class_bind_template_child(widget_class, MainWindow, button_span3);
    gtk_widget_class_bind_template_child(widget_class, MainWindow, button_span4);
    gtk_widget_class_bind_template_child(widget_class, MainWindow, button_span5);
    gtk_widget_class_bind_template_child(widget_class, MainWindow, button_span6);
    gtk_widget_class_bind_template_child(widget_class, MainWindow, button_span7);
  } else {
    g_error("Failed to load MainWindow template: %s\n", error->message);
    g_error_free(error);
  }
}

static void main_window_init(MainWindow *self)
{
  gtk_widget_init_template(GTK_WIDGET(self));
}

static void main_window_destroy_cb(GtkWidget *widget, gpointer data)
{
  g_print("MainWindow has been closed.\n");
  // Remove the idle function from the main loop
  if (window_update_fn_source_id != 0) {
    g_source_remove(window_update_fn_source_id);
    window_update_fn_source_id = 0;
  }
}

// This is where you would update data display labels in the main window
// based on the data in the IMainWindow struct.
static gboolean update_main_window(MainWindow *self)
{
  // I could update the column headers and button text, but the window elements
  // intended to be static should be set in the .ui file, not here. No sense in
  // wasting resources to update things that never change on every frame.
  //gtk_label_set_text(GTK_LABEL(self->col_header_sensor_raw), imain_window.col_header_sensor_raw);
  //gtk_label_set_text(GTK_LABEL(self->col_header_sensor_pv), imain_window.col_header_sensor_pv);
  
  gtk_label_set_text(GTK_LABEL(self->data_display_label_sensor_raw0), imain_window.data_display_label_sensor_raw0);
  gtk_label_set_text(GTK_LABEL(self->data_display_label_sensor_raw1), imain_window.data_display_label_sensor_raw1);
  gtk_label_set_text(GTK_LABEL(self->data_display_label_sensor_raw2), imain_window.data_display_label_sensor_raw2);
  gtk_label_set_text(GTK_LABEL(self->data_display_label_sensor_raw3), imain_window.data_display_label_sensor_raw3);
  gtk_label_set_text(GTK_LABEL(self->data_display_label_sensor_raw4), imain_window.data_display_label_sensor_raw4);
  gtk_label_set_text(GTK_LABEL(self->data_display_label_sensor_raw5), imain_window.data_display_label_sensor_raw5);
  gtk_label_set_text(GTK_LABEL(self->data_display_label_sensor_raw6), imain_window.data_display_label_sensor_raw6);
  gtk_label_set_text(GTK_LABEL(self->data_display_label_sensor_raw7), imain_window.data_display_label_sensor_raw7);
  gtk_label_set_text(GTK_LABEL(self->data_display_label_sensor_pv0), imain_window.data_display_label_sensor_pv0);
  gtk_label_set_text(GTK_LABEL(self->data_display_label_sensor_pv1), imain_window.data_display_label_sensor_pv1);
  gtk_label_set_text(GTK_LABEL(self->data_display_label_sensor_pv2), imain_window.data_display_label_sensor_pv2);
  gtk_label_set_text(GTK_LABEL(self->data_display_label_sensor_pv3), imain_window.data_display_label_sensor_pv3);
  gtk_label_set_text(GTK_LABEL(self->data_display_label_sensor_pv4), imain_window.data_display_label_sensor_pv4);
  gtk_label_set_text(GTK_LABEL(self->data_display_label_sensor_pv5), imain_window.data_display_label_sensor_pv5);
  gtk_label_set_text(GTK_LABEL(self->data_display_label_sensor_pv6), imain_window.data_display_label_sensor_pv6);
  gtk_label_set_text(GTK_LABEL(self->data_display_label_sensor_pv7), imain_window.data_display_label_sensor_pv7);

  // Return TRUE to keep the idle function running
  return TRUE;
  // Or return FALSE to stop the idle function
  //return FALSE;
}

static void button0_clicked_cb(GtkButton *button, MainWindow *self)
{
  GtkWidget *sub_window;

  // Create a new SubWindow
  sub_window = sub_window_new();
  if (sub_window == NULL) {
      g_printerr("Failed to create SubWindow\n");
      return;
  }

  // Show all widgets in the SubWindow
  gtk_widget_show(sub_window);

  gtk_label_set_text(GTK_LABEL(self->data_display_label_sensor_raw0), "Button0 was clicked!");
}

static void button_zero0_clicked_cb(GtkButton *button, MainWindow *self)
{
  imain_window.button_zero_0_pressed = true;
}

static void button_zero1_clicked_cb(GtkButton *button, MainWindow *self)
{
  imain_window.button_zero_1_pressed = true;
}

static void button_zero2_clicked_cb(GtkButton *button, MainWindow *self)
{
  imain_window.button_zero_2_pressed = true;
}

static void button_zero3_clicked_cb(GtkButton *button, MainWindow *self)
{
  imain_window.button_zero_3_pressed = true;
}

static void button_zero4_clicked_cb(GtkButton *button, MainWindow *self)
{
  imain_window.button_zero_4_pressed = true;
}

static void button_zero5_clicked_cb(GtkButton *button, MainWindow *self)
{
  imain_window.button_zero_5_pressed = true;
}

static void button_zero6_clicked_cb(GtkButton *button, MainWindow *self)
{
  imain_window.button_zero_6_pressed = true;
}

static void button_zero7_clicked_cb(GtkButton *button, MainWindow *self)
{
  imain_window.button_zero_7_pressed = true;
}

static void button_span0_clicked_cb(GtkButton *button, MainWindow *self)
{
  imain_window.button_span_0_pressed = true;
}

static void button_span1_clicked_cb(GtkButton *button, MainWindow *self)
{
  imain_window.button_span_1_pressed = true;
}

static void button_span2_clicked_cb(GtkButton *button, MainWindow *self)
{
  imain_window.button_span_2_pressed = true;
}

static void button_span3_clicked_cb(GtkButton *button, MainWindow *self)
{
  imain_window.button_span_3_pressed = true;
}

static void button_span4_clicked_cb(GtkButton *button, MainWindow *self)
{
  imain_window.button_span_4_pressed = true;
}

static void button_span5_clicked_cb(GtkButton *button, MainWindow *self)
{
  imain_window.button_span_5_pressed = true;
}

static void button_span6_clicked_cb(GtkButton *button, MainWindow *self)
{
  imain_window.button_span_6_pressed = true;
}

static void button_span7_clicked_cb(GtkButton *button, MainWindow *self)
{
  imain_window.button_span_7_pressed = true;
}

// was named activate_cb and was static
void activate_main_window_cb(GtkApplication *app, gpointer user_data)
{
  MainWindow *window = (MainWindow*)g_object_new(main_window_get_type(), "application", app, NULL);

  // Store the MainWindow instance in the GtkApplicationWindow
  // Then you can use it for something later on. Look at the commented out
  // code at the bottom of this file.
  g_object_set_data(G_OBJECT(window), "main-window-instance", window);

  // Connect the button0 signal its the callback function
  g_signal_connect(window->button0, "clicked", G_CALLBACK(button0_clicked_cb), window);

  g_signal_connect(window->button0, "clicked", G_CALLBACK(button_zero0_clicked_cb), window);
  g_signal_connect(window->button0, "clicked", G_CALLBACK(button_zero1_clicked_cb), window);
  g_signal_connect(window->button0, "clicked", G_CALLBACK(button_zero2_clicked_cb), window);
  g_signal_connect(window->button0, "clicked", G_CALLBACK(button_zero3_clicked_cb), window);
  g_signal_connect(window->button0, "clicked", G_CALLBACK(button_zero4_clicked_cb), window);
  g_signal_connect(window->button0, "clicked", G_CALLBACK(button_zero5_clicked_cb), window);
  g_signal_connect(window->button0, "clicked", G_CALLBACK(button_zero6_clicked_cb), window);
  g_signal_connect(window->button0, "clicked", G_CALLBACK(button_zero7_clicked_cb), window);
  g_signal_connect(window->button0, "clicked", G_CALLBACK(button_span0_clicked_cb), window);
  g_signal_connect(window->button0, "clicked", G_CALLBACK(button_span1_clicked_cb), window);
  g_signal_connect(window->button0, "clicked", G_CALLBACK(button_span2_clicked_cb), window);
  g_signal_connect(window->button0, "clicked", G_CALLBACK(button_span3_clicked_cb), window);
  g_signal_connect(window->button0, "clicked", G_CALLBACK(button_span4_clicked_cb), window);
  g_signal_connect(window->button0, "clicked", G_CALLBACK(button_span5_clicked_cb), window);
  g_signal_connect(window->button0, "clicked", G_CALLBACK(button_span6_clicked_cb), window);
  g_signal_connect(window->button0, "clicked", G_CALLBACK(button_span7_clicked_cb), window);

  // Connect the destroy signal to detect when the window is closed
  g_signal_connect(window, "destroy", G_CALLBACK(main_window_destroy_cb), NULL);

  gtk_window_present(GTK_WINDOW(window));

  // Add idle function to the main loop
  window_update_fn_source_id = g_idle_add((GSourceFunc)update_main_window, window);
  // Alternatively, you could use g_timeout_add() to update the window at a
  // regular interval. The function would be called every 1000 milliseconds.
  //window_update_fn_source_id = g_timeout_add(1000, (GSourceFunc)update_main_window, window);
}

#pragma GCC diagnostic pop

// Here is some scrap code.. It works so I'm leaving it here for my own
// reference.
/*MainWindow *_get_main_window_instance(void)
{
  GtkApplicationWindow *window = GTK_APPLICATION_WINDOW(gtk_application_get_active_window(main_app));
  return MAIN_WINDOW(g_object_get_data(G_OBJECT(window), "main-window-instance"));
}

// Function to retrieve the text from data_display_label_sensor_raw0
const char *_get_data_display_label0_text(MainWindow *window)
{
  return gtk_label_get_text(GTK_LABEL(window->data_display_label_sensor_raw0));
}

// Example usage of get_data_display_label0_text
const char *get_data_display_label0_text(void)
{
  MainWindow *window = _get_main_window_instance();
  if (window) {
    const char *text = _get_data_display_label0_text(window);
    return text;
  } else {
    g_print("Failed to retrieve MainWindow instance\n");
  }
  return "\0";
}

int set_data_display_label0_text(const char *text)
{
  MainWindow *window = _get_main_window_instance();
  if (window) {
    gtk_label_set_text(GTK_LABEL(window->data_display_label_sensor_raw0), text);
    return 0;
  } else {
    g_print("Failed to retrieve MainWindow instance\n");
  }
  return -1;
}

// Function to retrieve the text from a GtkLabel
const char *_get_main_window_gtklabel_text(GtkWidget *label)
{
  return gtk_label_get_text(GTK_LABEL(label));
}
*/
