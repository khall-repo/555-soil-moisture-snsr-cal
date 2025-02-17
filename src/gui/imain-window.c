/**
 * @file imain-window.c
 * @brief Main Window interface
 * @par (C) 2025 Keith Hall
 * Programmer interacts with the Main Window through this interface code
 */
#include <cstdint>
#include <cstring>
#include "struct.h" // for num of sensors
#include "imain-window.h"

//extern Param_t param; // Import from struct.cpp
extern Appearance_Config_t appearance_config; // Import from struct.cpp
IMainWindow imain_window;

const char *get_channel_label(unsigned int index)
{
  if (imain_window.num_sensors <= index) {
    g_printerr("imain-window get_channel_label(): Bad index [%u]\n", index);
    return "\0";
  }
  return (const char *)imain_window.channel_label[index].label_text;
}

// get imain_window.col_header_sensor_raw0.label_text
const char *get_col_header_sensor_raw0(void)
{
  return (const char *)imain_window.col_header_sensor_raw0.label_text;
}

// get imain_window.col_header_sensor_pv0.label_text
const char *get_col_header_sensor_pv0(void)
{
  return (const char *)imain_window.col_header_sensor_pv0.label_text;
}

// get imain_window.col_header_sensor_raw1.label_text
const char *get_col_header_sensor_raw1(void)
{
  return (const char *)imain_window.col_header_sensor_raw1.label_text;
}

// get imain_window.col_header_sensor_pv1.label_text
const char *get_col_header_sensor_pv1(void)
{
  return (const char *)imain_window.col_header_sensor_pv1.label_text;
}



// get imain_window.data_display_label_sensor_raw[n].label_text
const char *get_data_display_label_sensor_raw(unsigned int index)
{
  if (imain_window.num_sensors <= index) {
    g_printerr("imain-window get_data_display_label_sensor_raw(): Bad index [%u]\n", index);
    return "\0";
  }
  return (const char *)imain_window.data_display_label_sensor_raw[index].label_text;
}

// get imain_window.data_display_label_sensor_pv[n].label_text
const char *get_data_display_label_sensor_pv(unsigned int index)
{
  if (imain_window.num_sensors <= index) {
    g_printerr("imain-window get_data_display_label_sensor_pv(): Bad index [%u]\n", index);
    return "\0";
  }
  return (const char *)imain_window.data_display_label_sensor_pv[index].label_text;
}




void set_channel_label(unsigned int index, const char *text)
{
  if (imain_window.num_sensors <= index) {
    g_printerr("imain-window set_channel_label(): Bad index\n");
    return;
  }
  strncpy(imain_window.channel_label[index].label_text, text, MAX_DATA_DISP_SZ);
  imain_window.channel_label[index].update_text = true;
}

// set imain_window.data_display_label_sensor_raw[n] text
void set_data_display_label_sensor_raw(unsigned int index, const char *text)
{
  if (imain_window.num_sensors <= index) {
    g_printerr("imain-window set_data_display_label_sensor_raw(): Bad index [%u]\n", index);
    return;
  }
  strncpy(imain_window.data_display_label_sensor_raw[index].label_text, text, MAX_DATA_DISP_SZ);
  imain_window.data_display_label_sensor_raw[index].update_text = true;
}

// set imain_window.data_display_label_sensor_pv[n] text
void set_data_display_label_sensor_pv(unsigned int index, const char *text)
{
  if (imain_window.num_sensors <= index) {
    g_printerr("imain-window set_data_display_label_sensor_pv(): Bad index [%u]\n", index);
    return;
  }
  strncpy(imain_window.data_display_label_sensor_pv[index].label_text, text, MAX_DATA_DISP_SZ);
  imain_window.data_display_label_sensor_pv[index].update_text = true;
}




void set_data_display_label_sensor_raw_fg_color(unsigned int index, guint16 red,
                                                guint16 green, guint16 blue)
{
  if (imain_window.num_sensors <= index) {
    g_printerr("imain-window set_data_display_label_sensor_raw_fg_color(): Bad index [%u]\n", index);
    return;
  }
  imain_window.data_display_label_sensor_raw[index].foreground_color.red = red;
  imain_window.data_display_label_sensor_raw[index].foreground_color.green = green;
  imain_window.data_display_label_sensor_raw[index].foreground_color.blue = blue;
  imain_window.data_display_label_sensor_raw[index].update_foreground_color = true;
}

void set_data_display_label_sensor_raw_bg_color(unsigned int index, guint16 red,
                                                guint16 green, guint16 blue)
{
  if (imain_window.num_sensors <= index) {
    g_printerr("imain-window set_data_display_label_sensor_raw_bg_color(): Bad index [%u]\n", index);
    return;
  }
  imain_window.data_display_label_sensor_raw[index].background_color.red = red;
  imain_window.data_display_label_sensor_raw[index].background_color.green = green;
  imain_window.data_display_label_sensor_raw[index].background_color.blue = blue;
  imain_window.data_display_label_sensor_raw[index].update_background_color = true;
}

void set_data_display_label_sensor_raw_highlight_color(unsigned int index,
                                                       guint16 red, 
                                                       guint16 green,
                                                       guint16 blue)
{
  if (imain_window.num_sensors <= index) {
    g_printerr("imain-window set_data_display_label_sensor_raw_highlight_color(): Bad index [%u]\n", index);
    return;
  }
  imain_window.data_display_label_sensor_raw[index].text_highlight_color.red = red;
  imain_window.data_display_label_sensor_raw[index].text_highlight_color.green = green;
  imain_window.data_display_label_sensor_raw[index].text_highlight_color.blue = blue;
  imain_window.data_display_label_sensor_raw[index].update_text_highlight_color = true;
}

void set_data_display_label_sensor_pv_fg_color(unsigned int index, guint16 red,
                                               guint16 green, guint16 blue)
{
  if (imain_window.num_sensors <= index) {
    g_printerr("imain-window set_data_display_label_sensor_pv_fg_color(): Bad index [%u]\n", index);
    return;
  }
  imain_window.data_display_label_sensor_pv[index].foreground_color.red = red;
  imain_window.data_display_label_sensor_pv[index].foreground_color.green = green;
  imain_window.data_display_label_sensor_pv[index].foreground_color.blue = blue;
  imain_window.data_display_label_sensor_pv[index].update_foreground_color = true;
}

void set_data_display_label_sensor_pv_bg_color(unsigned int index, guint16 red,
                                               guint16 green, guint16 blue)
{
  if (imain_window.num_sensors <= index) {
    g_printerr("imain-window set_data_display_label_sensor_pv_bg_color(): Bad index [%u]\n", index);
    return;
  }
  imain_window.data_display_label_sensor_pv[index].background_color.red = red;
  imain_window.data_display_label_sensor_pv[index].background_color.green = green;
  imain_window.data_display_label_sensor_pv[index].background_color.blue = blue;
  imain_window.data_display_label_sensor_pv[index].update_background_color = true;
}

void set_data_display_label_sensor_pv_highlight_color(unsigned int index,
                                                      guint16 red,
                                                      guint16 green,
                                                      guint16 blue)
{
  if (imain_window.num_sensors <= index) {
    g_printerr("imain-window set_data_display_label_sensor_pv_highlight_color(): Bad index [%u]\n", index);
    return;
  }
  imain_window.data_display_label_sensor_pv[index].text_highlight_color.red = red;
  imain_window.data_display_label_sensor_pv[index].text_highlight_color.green = green;
  imain_window.data_display_label_sensor_pv[index].text_highlight_color.blue = blue;
  imain_window.data_display_label_sensor_pv[index].update_text_highlight_color = true;
}




void set_data_display_label_sensor_raw_font_family(unsigned int index,
                                                   const char *font_family)
{
  if((NULL == font_family) || 
     (NULL == imain_window.data_display_label_sensor_raw[index].font_attrib.font_family)) {
    return;
  }
  strncpy((char*)imain_window.data_display_label_sensor_raw[index].font_attrib.font_family, font_family, MAX_FONT_FAMILY_LEN);
  imain_window.data_display_label_sensor_raw[index].font_attrib.update_font_attrib = true;
}

void set_data_display_label_sensor_pv_font_family(unsigned int index,
                                                  const char *font_family)
{
  if((NULL == font_family) || 
     (NULL == imain_window.data_display_label_sensor_pv[index].font_attrib.font_family)) {
    return;
  }
  if(imain_window.num_sensors <= index) {
    return;
  }
  strncpy((char*)imain_window.data_display_label_sensor_pv[index].font_attrib.font_family, font_family, MAX_FONT_FAMILY_LEN);
  imain_window.data_display_label_sensor_pv[index].font_attrib.update_font_attrib = true;
}

void set_data_display_label_sensor_raw_font_size(unsigned int index, int size)
{
  if(imain_window.num_sensors <= index) {
    return;
  }
  imain_window.data_display_label_sensor_raw[index].font_attrib.size = size;
  imain_window.data_display_label_sensor_raw[index].font_attrib.update_font_attrib = true;
}

void set_data_display_label_sensor_pv_font_size(unsigned int index, gint size)
{
  if(imain_window.num_sensors <= index) {
    return;
  }
  imain_window.data_display_label_sensor_pv[index].font_attrib.size = size;
  imain_window.data_display_label_sensor_pv[index].font_attrib.update_font_attrib = true;
}

void set_data_display_label_sensor_raw_font_weight(unsigned int index,
                                                   PangoWeight pango_weight)
{
  if(imain_window.num_sensors <= index) {
    return;
  }
  imain_window.data_display_label_sensor_raw[index].font_attrib.weight = pango_weight;
  imain_window.data_display_label_sensor_raw[index].font_attrib.update_font_attrib = true;
}

void set_data_display_label_sensor_pv_font_weight(unsigned int index,
                                                  PangoWeight pango_weight)
{
  if(imain_window.num_sensors <= index) {
    return;
  }
  imain_window.data_display_label_sensor_pv[index].font_attrib.weight = pango_weight;
  imain_window.data_display_label_sensor_pv[index].font_attrib.update_font_attrib = true;
}




// get the update text flag and acknowledge
bool get_update_text_raw_ack(unsigned int index)
{
  bool state = false;
  if (imain_window.num_sensors <= index) {
    g_printerr("imain-window get_update_text_raw_ack(): Bad index [%u]\n", index);
    return false;
  }
  state = imain_window.data_display_label_sensor_raw[index].update_text;
  imain_window.data_display_label_sensor_raw[index].update_text = false;
  return state;
}

// get the update text flag and acknowledge
bool get_update_text_pv_ack(unsigned int index)
{
  bool state = false;
  if (imain_window.num_sensors <= index) {
    g_printerr("imain-window get_update_text_pv_ack(): Bad index [%u]\n", index);
    return false;
  }
  state = imain_window.data_display_label_sensor_pv[index].update_text;
  imain_window.data_display_label_sensor_pv[index].update_text = false;
  return state;
}




bool get_update_foreground_color_raw_ack(unsigned int index)
{
  bool state = false;
  if (imain_window.num_sensors <= index) {
    g_printerr("imain-window get_update_foreground_color_raw_ack(): Bad index [%u]\n", index);
    return false;
  }
  state = imain_window.data_display_label_sensor_raw[index].update_foreground_color;
  imain_window.data_display_label_sensor_raw[index].update_foreground_color = false;
  return state;
}

bool get_update_background_color_raw_ack(unsigned int index)
{
  bool state = false;
  if (imain_window.num_sensors <= index) {
    g_printerr("imain-window get_update_background_color_raw_ack(): Bad index [%u]\n", index);
    return false;
  }
  state = imain_window.data_display_label_sensor_raw[index].update_background_color;
  imain_window.data_display_label_sensor_raw[index].update_background_color = false;
  return state;
}

bool get_update_highlight_color_raw_ack(unsigned int index)
{
  bool state = false;
  if (imain_window.num_sensors <= index) {
    g_printerr("imain-window get_update_highlight_color_raw_ack(): Bad index [%u]\n", index);
    return false;
  }
  state = imain_window.data_display_label_sensor_raw[index].update_text_highlight_color;
  imain_window.data_display_label_sensor_raw[index].update_text_highlight_color = false;
  return state;
}

bool get_update_foreground_color_pv_ack(unsigned int index)
{
  bool state = false;
  if (imain_window.num_sensors <= index) {
    g_printerr("imain-window get_update_foreground_color_pv_ack(): Bad index [%u]\n", index);
    return false;
  }
  state = imain_window.data_display_label_sensor_pv[index].update_foreground_color;
  imain_window.data_display_label_sensor_pv[index].update_foreground_color = false;
  return state;
}

bool get_update_background_color_pv_ack(unsigned int index)
{
  bool state = false;
  if (imain_window.num_sensors <= index) {
    g_printerr("imain-window get_update_background_color_pv_ack(): Bad index [%u]\n", index);
    return false;
  }
  state = imain_window.data_display_label_sensor_pv[index].update_background_color;
  imain_window.data_display_label_sensor_pv[index].update_background_color = false;
  return state;
}

bool get_update_highlight_color_pv_ack(unsigned int index)
{
  bool state = false;
  if (imain_window.num_sensors <= index) {
    g_printerr("imain-window get_update_highlight_color_pv_ack(): Bad index [%u]\n", index);
    return false;
  }
  state = imain_window.data_display_label_sensor_pv[index].update_text_highlight_color;
  imain_window.data_display_label_sensor_pv[index].update_text_highlight_color = false;
  return state;
}

bool get_update_font_attrib_raw_ack(unsigned int index)
{
  bool state;
  if (imain_window.num_sensors <= index) {
    g_printerr("imain-window get_update_font_attrib_raw_ack(): Bad index [%u]\n", index);
    return false;
  }
  state = imain_window.data_display_label_sensor_raw[index].font_attrib.update_font_attrib;
  imain_window.data_display_label_sensor_raw[index].font_attrib.update_font_attrib = false;  
  return state;
}

bool get_update_font_attrib_pv_ack(unsigned int index)
{
  bool state;
  if (imain_window.num_sensors <= index) {
    g_printerr("imain-window get_update_font_attrib_pv_ack(): Bad index [%u]\n", index);
    return false;
  }
  state = imain_window.data_display_label_sensor_pv[index].font_attrib.update_font_attrib;
  imain_window.data_display_label_sensor_pv[index].font_attrib.update_font_attrib = false;  
  return state;
}




// get imain_window.button_zero_pressed[n]
bool button_zero_pressed(unsigned int index)
{
  if (imain_window.num_sensors <= index) {
    g_printerr("imain-window button_zero_pressed(): Bad index [%u]\n", index);
    return false;
  }
  return imain_window.button_zero_pressed[index];

}

// get imain_window.button_span_pressed[n]
bool button_span_pressed(unsigned int index)
{
  if (imain_window.num_sensors <= index) {
    g_printerr("imain-window button_span_pressed(): Bad index [%u]\n", index);
    return false;
  }
  return imain_window.button_span_pressed[index];

}

// get imain_window.button_zero_pressed[n] and acknowledge
bool button_zero_pressed_ack(unsigned int index)
{
  bool state = false;
  if (imain_window.num_sensors <= index) {
    g_printerr("imain-window button_zero_pressed(): Bad index [%u]\n", index);
    return false;
  }
  state = imain_window.button_zero_pressed[index];
  imain_window.button_zero_pressed[index] = false;
  return state;
}

// get imain_window.button_span_pressed[n] and acknowledge
bool button_span_pressed_ack(unsigned int index)
{
  bool state = false;
  if (imain_window.num_sensors <= index) {
    g_printerr("imain-window button_span_pressed(): Bad index [%u]\n", index);
    return false;
  }
  state = imain_window.button_span_pressed[index];
  imain_window.button_span_pressed[index] = false;
  return state;
}




int init_imain_window(unsigned int num_sensor_ch)
{
  Color16_t text_color;
  Color16_t text_highlight_color;
  Color16_t background_color;
  char str_buf[MAX_DATA_DISP_SZ] = {0};
  // Set number of sensors for mass data update
  imain_window.num_sensors = num_sensor_ch;
  // Initial text color black
  text_color.red = 0;
  text_color.green = 0;
  text_color.blue = 0;
  // Initial text highlight color white
  text_highlight_color.red = 0xffff;
  text_highlight_color.green = 0xffff;
  text_highlight_color.blue = 0xffff;
  // Initial background color white
  background_color.red = 0xffff;
  background_color.green = 0xffff;
  background_color.blue = 0xffff;

  // Set data label text foreground, highlight, and background color
  for(unsigned int i = 0; i < imain_window.num_sensors; i++) {
    set_data_display_label_sensor_raw_fg_color(i, text_color.red, text_color.green, text_color.blue);
    set_data_display_label_sensor_raw_highlight_color(i, text_highlight_color.red, text_highlight_color.green, text_highlight_color.blue);
    set_data_display_label_sensor_raw_bg_color(i, background_color.red, background_color.green, background_color.blue);
    
    set_data_display_label_sensor_pv_fg_color(i, text_color.red, text_color.green, text_color.blue);
    set_data_display_label_sensor_pv_highlight_color(i, text_highlight_color.red, text_highlight_color.green, text_highlight_color.blue);
    set_data_display_label_sensor_pv_bg_color(i, background_color.red, background_color.green, background_color.blue);
  }
  
  // Set the initial font family, size, and weight for each sensor data label
  for(unsigned int i = 0; i < imain_window.num_sensors; i++) {
    char *dest = (char *)g_malloc0(MAX_FONT_FAMILY_LEN);
    if (NULL == dest) {
      g_printerr("init_imain_window(): 0737 Failed to allocate memory for destination %d\n", i);
      return -1;
    }
    memcpy(dest, (const void*)&appearance_config.data_display_font_family[0], MAX_FONT_FAMILY_LEN);
    
    imain_window.data_display_label_sensor_raw[i].font_attrib.font_family = dest;

    set_data_display_label_sensor_raw_font_size(i, appearance_config.data_display_font_size);
    set_data_display_label_sensor_raw_font_weight(i, DEFAULT_DATA_DISP_FONT_WEIGHT);
  }
  for(unsigned int i = 0; i < imain_window.num_sensors; i++) {
    char *dest = (char *)g_malloc0(MAX_FONT_FAMILY_LEN);
    if (NULL == dest) {
      g_printerr("init_imain_window(): 0738 Failed to allocate memory for destination %d\n", i);
      return -1;
    }
    memcpy(dest, (const void*)&appearance_config.data_display_font_family[0], MAX_FONT_FAMILY_LEN);

    imain_window.data_display_label_sensor_pv[i].font_attrib.font_family = dest;
    
    set_data_display_label_sensor_pv_font_size(i, appearance_config.data_display_font_size);
    set_data_display_label_sensor_pv_font_weight(i, DEFAULT_DATA_DISP_FONT_WEIGHT);
  }
  
  // Set the channel labels text
  for(unsigned int i = 0; i < imain_window.num_sensors; i++) {
    sprintf(str_buf, "%s %u", DEFAULT_LABEL_CH, i);
    set_channel_label(i, (const char*)str_buf);
  }
  
  return 0;
}

void cleanup_imain_window(void)
{
  for(unsigned int i = 0; i < imain_window.num_sensors; i++) {
    if(NULL != imain_window.data_display_label_sensor_raw[i].font_attrib.font_family) {
      g_free((void*)imain_window.data_display_label_sensor_raw[i].font_attrib.font_family);
    }
    if(NULL != imain_window.data_display_label_sensor_pv[i].font_attrib.font_family) {
      g_free((void*)imain_window.data_display_label_sensor_pv[i].font_attrib.font_family);
    }
  }
}
/**
  End of file
*/
