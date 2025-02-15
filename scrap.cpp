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

  //free(imain_window.data_display_label_sensor_raw0.font_attrib.font_family);
  //imain_window.data_display_label_sensor_raw0.font_attrib.font_family = NULL;
  //char *p_free = (char*)&imain_window.data_display_label_sensor_raw0.font_attrib.font_family;
  char *p_free;
  size_t str_len = 0;
  g_print("str %s\r\n", (const char*)&imain_window.data_display_label_sensor_raw0.font_attrib.font_family[0]);
  //str_len = strlen(imain_window.data_display_label_sensor_raw0.font_attrib.font_family);
  //g_print("str_len1 %lu\r\n", str_len);
  //str_len = strlen((const char*) (imain_window.data_display_label_sensor_raw0.font_attrib.font_family +
  //                               sizeof(Data_Display_Label_t)));
  //g_print("str_len2 %lu\r\n", str_len);
  /*for(unsigned int i = 0; i < param.num_sensors; i++) {
    //str_len = strlen((const char*)&imain_window.data_display_label_sensor_raw0.font_attrib.font_family[0] + (i * (sizeof(Data_Display_Label_t))));
    //g_print("addr 0: 0x%016lX\t str_len: %lu\r\n", (uint64_t)&imain_window.data_display_label_sensor_raw0.font_attrib.font_family[0],
    //                                           str_len);
    g_print("addr 0: 0x%016lX\r\n", (uint64_t)&imain_window.data_display_label_sensor_raw0.font_attrib.font_family + (i * (sizeof(Data_Display_Label_t))));
  }*/
  
  /*for(unsigned int i = 0; i < param.num_sensors; i++) {
    p_free = (char*)&(&imain_window.data_display_label_sensor_raw0.font_attrib.font_family[0] + (i * sizeof(Data_Display_Label_t) ));
    //str_len = MAX_FONT_FAMILY_LEN
    //g_print("\tfree %d len %lu\r\n", i, str_len);
    free((void*)p_free);
    //p_free += sizeof(Data_Display_Label_t);
  }*/

void set_data_display_label_sensor_pv_font_family(unsigned int index, const char *font_family)
{
  /*char **p_font_family = (char **)((char *)&imain_window.data_display_label_sensor_pv0.font_attrib.font_family + index * sizeof(Data_Display_Label_t));
  bool *p_update_font_attrib = (bool *)&imain_window.data_display_label_sensor_pv0.font_attrib.update_font_attrib + index * sizeof(Data_Display_Label_t);
  *p_font_family = (char*)font_family;
  *p_update_font_attrib = true;*/
  char **p_font_family = (char **)((char *)&imain_window.data_display_label_sensor_pv0.font_attrib.font_family + index * sizeof(Data_Display_Label_t));
  Font_Attrib_t *p_font_attrib = (Font_Attrib_t *)((char *)&imain_window.data_display_label_sensor_pv0.font_attrib + index * sizeof(Data_Display_Label_t));
  *p_font_family = (char*)font_family;
  p_font_attrib->update_font_attrib = true;
}

void set_data_display_label_sensor_raw_font_size(unsigned int index, int size)
{
  /*int *p_size =               (int *)&imain_window.data_display_label_sensor_raw0.font_attrib.size + index * sizeof(Data_Display_Label_t);
  bool *p_update_font_attrib = (bool *)&imain_window.data_display_label_sensor_raw0.font_attrib.update_font_attrib + index * sizeof(Data_Display_Label_t);
  *p_size = size;
  *p_update_font_attrib = true;*/
  Font_Attrib_t *p_font_attrib = (Font_Attrib_t *)((char *)&imain_window.data_display_label_sensor_raw0.font_attrib + index * sizeof(Data_Display_Label_t));
  p_font_attrib->size = size;
  p_font_attrib->update_font_attrib = true;
}

void set_data_display_label_sensor_pv_font_size(unsigned int index, gint size)
{
  /*gint *p_size =               (gint *)&imain_window.data_display_label_sensor_pv0.font_attrib.size + index * sizeof(Data_Display_Label_t);
  bool *p_update_font_attrib = (bool *)&imain_window.data_display_label_sensor_pv0.font_attrib.update_font_attrib + index * sizeof(Data_Display_Label_t);
  *p_size = size;
  *p_update_font_attrib = true;*/
  Font_Attrib_t *p_font_attrib = (Font_Attrib_t *)((char *)&imain_window.data_display_label_sensor_pv0.font_attrib + index * sizeof(Data_Display_Label_t));
  p_font_attrib->size = size;
  p_font_attrib->update_font_attrib = true;
}

void set_data_display_label_sensor_raw_font_weight(unsigned int index, PangoWeight pango_weight)
{
  /*PangoWeight *p_weight = (PangoWeight *)&imain_window.data_display_label_sensor_raw0.font_attrib.weight + index * sizeof(Data_Display_Label_t);
  bool *p_update_font_attrib = (bool *)&imain_window.data_display_label_sensor_raw0.font_attrib.update_font_attrib + index * sizeof(Data_Display_Label_t);
  *p_weight = pango_weight;
  *p_update_font_attrib = true;*/
  Font_Attrib_t *p_font_attrib = (Font_Attrib_t *)((char *)&imain_window.data_display_label_sensor_raw0.font_attrib + index * sizeof(Data_Display_Label_t));
  p_font_attrib->weight = pango_weight;
  p_font_attrib->update_font_attrib = true;
}

/*for(unsigned int i = 0; i < param.num_sensors; i++) {
    set_data_display_label_sensor_raw_font_size(i, DEFAULT_DATA_DISP_FONT_SIZE);
  }*/
  
  /*for(unsigned int i = 0; i < param.num_sensors; i++) {
    char *dest = (char *)g_malloc0(MAX_FONT_FAMILY_LEN);
    if (NULL == dest) {
      g_printerr("0738 Failed to allocate memory for destination %d\n", i);
      return -1;
    }
    memcpy(dest, (const void*)&appearance_config.data_display_font_family[0], MAX_FONT_FAMILY_LEN);

    set_data_display_label_sensor_pv_font_family(i, dest);
    set_data_display_label_sensor_pv_font_size(i, DEFAULT_DATA_DISP_FONT_SIZE);
    //set_data_display_label_sensor_pv_font_weight(i, DEFAULT_DATA_DISP_FONT_WEIGHT);
    //g_free(dest);
  }*/

  /*for(unsigned int i = 0; i < param.num_sensors; i++) {
    char *dest = (char *)malloc(MAX_FONT_FAMILY_LEN);
    if (NULL == dest) {
      g_printerr("Failed to allocate memory for font family data_display_label_sensor_raw[%d]\n", i);
      exit(EXIT_FAILURE);
    }
    memcpy(dest, (const void*)&appearance_config.data_display_font_family[0], MAX_FONT_FAMILY_LEN);
    g_print("Font fam %d: %s\r\n", i, dest);

    // Calculate the address of the font_family member for the current sensor
    char **font_family_ptr = (char **)((char *)&imain_window.data_display_label_sensor_raw0.font_attrib.font_family + i * sizeof(Data_Display_Label_t));
    *font_family_ptr = dest;

  }*/

//test
  for(unsigned int i = 0; i < param.num_sensors; i++) {
    set_data_display_label_sensor_raw_font_family(i, "test");
  }

  /*g_print("1st raw ff str = %s, update = %d\r\n", (const char*)&imain_window.data_display_label_sensor_raw0.font_attrib.font_family[0],
                                                  imain_window.data_display_label_sensor_raw0.font_attrib.update_font_attrib);
  g_print("1st pv ff str %s, update = %d\r\n", (const char*)&imain_window.data_display_label_sensor_pv0.font_attrib.font_family[0],
                                               imain_window.data_display_label_sensor_pv0.font_attrib.update_font_attrib);
  if(get_update_font_attrib_raw_ack(0)) {
    g_print("1st raw fa update was 1, new state = %d\r\n", imain_window.data_display_label_sensor_raw0.font_attrib.update_font_attrib);
  }
  if(get_update_font_attrib_pv_ack(0)) {
    g_print("1st pv fa update was 1, new state = %d\r\n", imain_window.data_display_label_sensor_pv0.font_attrib.update_font_attrib);
  }*/




// Set the font family for each sensor data label
  for(unsigned int i = 0; i < param.num_sensors; i++) {
    char *dest = (char *)g_malloc0(MAX_FONT_FAMILY_LEN);
    if (NULL == dest) {
      g_printerr("0737 Failed to allocate memory for destination %d\n", i);
      return -1;
    }
    memcpy(dest, (const void*)&appearance_config.data_display_font_family[0], MAX_FONT_FAMILY_LEN);

    char **font_family_ptr = (char **)((char *)&imain_window.data_display_label_sensor_raw0.font_attrib.font_family + i * sizeof(Data_Display_Label_t));
    *font_family_ptr = dest;

    set_data_display_label_sensor_raw_font_size(i, DEFAULT_DATA_DISP_FONT_SIZE);
    set_data_display_label_sensor_raw_font_weight(i, DEFAULT_DATA_DISP_FONT_WEIGHT);
  }
  for(unsigned int i = 0; i < param.num_sensors; i++) {
    char *dest = (char *)g_malloc0(MAX_FONT_FAMILY_LEN);
    if (NULL == dest) {
      g_printerr("0738 Failed to allocate memory for destination %d\n", i);
      return -1;
    }
    memcpy(dest, (const void*)&appearance_config.data_display_font_family[0], MAX_FONT_FAMILY_LEN);

    char **font_family_ptr = (char **)((char *)&imain_window.data_display_label_sensor_pv0.font_attrib.font_family + i * sizeof(Data_Display_Label_t));
    *font_family_ptr = dest;

    set_data_display_label_sensor_pv_font_size(i, DEFAULT_DATA_DISP_FONT_SIZE);
    set_data_display_label_sensor_pv_font_weight(i, DEFAULT_DATA_DISP_FONT_WEIGHT);
  }

testpv0=1.11    
testpv1=2.22
testpv2=3.33
testpv3=4.44
testpv4=5.55
testpv5=6.66
testpv6=7.77
testpv7=8.88
testraw0=10.01  
testraw1=20.02
testraw2=30.03
testraw3=40.04
testraw4=50.05
testraw5=60.06
testraw6=70.07
testraw7=80.08
value = config_file->get_config_value("param", "testraw0");
  param.sensor_raw[0] = std::stod(value);
  value = config_file->get_config_value("param", "testraw1");
  param.sensor_raw[1] = std::stod(value);
  value = config_file->get_config_value("param", "testraw2");
  param.sensor_raw[2] = std::stod(value);
  value = config_file->get_config_value("param", "testraw3");
  param.sensor_raw[3] = std::stod(value);
  value = config_file->get_config_value("param", "testraw4");
  param.sensor_raw[4] = std::stod(value);
  value = config_file->get_config_value("param", "testraw5");
  param.sensor_raw[5] = std::stod(value);
  value = config_file->get_config_value("param", "testraw6");
  param.sensor_raw[6] = std::stod(value);
  value = config_file->get_config_value("param", "testraw7");
  param.sensor_raw[7] = std::stod(value);

  value = config_file->get_config_value("param", "testpv0");
  param.sensor_pv[0] = std::stod(value);
  value = config_file->get_config_value("param", "testpv1");
  param.sensor_pv[1] = std::stod(value);
  value = config_file->get_config_value("param", "testpv2");
  param.sensor_pv[2] = std::stod(value);
  value = config_file->get_config_value("param", "testpv3");
  param.sensor_pv[3] = std::stod(value);
  value = config_file->get_config_value("param", "testpv4");
  param.sensor_pv[4] = std::stod(value);
  value = config_file->get_config_value("param", "testpv5");
  param.sensor_pv[5] = std::stod(value);
  value = config_file->get_config_value("param", "testpv6");
  param.sensor_pv[6] = std::stod(value);
  value = config_file->get_config_value("param", "testpv7");
  param.sensor_pv[7] = std::stod(value);
