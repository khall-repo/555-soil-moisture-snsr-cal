/**
 * @brief Read the configuration file and populate the config_map
 * @param none
 * @return none
 */
int read_config_file(void)
{
  std::cout << "Reading configuration file" << '\n';
  // Read the configuration file and populate the config_map
  
  try{
    config_file.open(CONFIG_INI_FILE_PATH);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    return -1;
  }
  if(!config_file.is_open()) {
    std::cerr << "Error opening file" << '\n';
    return -1;
  }

  std::cout << "End of reading configuration file" << '\n';
}

// Function to set the background color of a GtkDrawingArea in GTK4
// doens't work no snapshot event
/*static void on_snapshot_event(GtkWidget *widget, GtkSnapshot *snapshot, gpointer user_data)
{
    GdkRGBA *color = (GdkRGBA *)user_data;
    graphene_rect_t rect;
    graphene_rect_init(&rect, 0, 0, (float)gtk_widget_get_width(widget), (float)gtk_widget_get_height(widget));
    gtk_snapshot_append_color(snapshot, color, &rect);
}*/

// Function to handle the draw signal
/*static gboolean on_drawing_area_draw(GtkDrawingArea *drawing_area, 
  cairo_t *cr,
  gint width,
  gint height,
  gpointer user_data)
{
  // Set color (RGB values from 0 to 1)
  cairo_set_source_rgb(cr, 0.8, 0.8, 0.8); // Light gray

  // Draw rectangle covering whole area
  cairo_rectangle(cr, 0, 0, width, height);
  cairo_fill(cr);

  return FALSE;
}*/

// In your setup code (e.g., main_window_init or where you set up the widgets)
/*static void setup_drawing_area(MainWindow *self)
{
  GtkDrawingArea *drawing_area = GTK_DRAWING_AREA(gtk_widget_get_by_name(GTK_WIDGET(self), "drawing_area0"));

  // Set a minimum size if desired
  gtk_widget_set_size_request(GTK_WIDGET(drawing_area), 50, 20);

  // Connect the draw signal handler
  gtk_drawing_area_set_draw_func(drawing_area, 
  (GtkDrawingAreaDrawFunc)on_drawing_area_draw,
  NULL,  // user_data
  NULL); // destroy notify
}*/

//setup_drawing_area(self);
  // Set the initial color for the drawing area FAILS
   //Gtk-CRITICAL **: 19:04:16.890: Error building template class 'MainWindow' for an instance of type 'MainWindow': .:0:0 Invalid signal 'draw' for type 'GtkDrawingArea'
  // Set the initial color for the drawing area
  // Set the initial color for the drawing area
  // Set the initial color for the drawing area
  //GdkRGBA initial_color;
  //gdk_rgba_parse(&initial_color, "lightblue");
  //g_object_set_data(G_OBJECT(self->drawing_area0), "drawing-area-color", gdk_rgba_copy(&initial_color));
  //g_signal_connect(self->drawing_area0, "snapshot", G_CALLBACK(on_snapshot_event), g_object_get_data(G_OBJECT(self->drawing_area0), "drawing-area-color"));

  /*void update_drawing_area_color(GtkDrawingArea *drawing_area, const gchar *color_str)
{
    GdkRGBA color;
    gdk_rgba_parse(&color, color_str);
    g_object_set_data(G_OBJECT(drawing_area), "drawing-area-color", gdk_rgba_copy(&color));
    gtk_widget_queue_draw(GTK_WIDGET(drawing_area));
}*/
// Example usage
//update_drawing_area_color(GTK_DRAWING_AREA(window->drawing_area0), "red");/*void update_drawing_area_color(GtkDrawingArea *drawing_area, const gchar *color_str)
{
    GdkRGBA color;
    gdk_rgba_parse(&color, color_str);
    g_object_set_data(G_OBJECT(drawing_area), "drawing-area-color", gdk_rgba_copy(&color));
    gtk_widget_queue_draw(GTK_WIDGET(drawing_area));
}
// Example usage
//update_drawing_area_color(GTK_DRAWING_AREA(window->drawing_area0), "red");