#include <cstdint>
#include <cstring>
#include "struct.h" // for num of sensors
#include "imain-window.h"

//extern Param_t param; // Import from struct.cpp
extern Appearance_Config_t appearance_config; // Import from struct.cpp
IMainWindow imain_window;

const char *get_channel_label(unsigned int index)
{
  if (MAX_SENSORS <= index) {
    g_printerr("imain-window get_channel_label(): Bad index [%u]\n", index);
    return "\0";
  }
  return (const char *)imain_window.channel_label[index].label_text;
}

// get imain_window.col_header_sensor_raw 
const char *get_col_header_sensor_raw(void)
{
  return (const char *)imain_window.col_header_sensor_raw.label_text;
}

// get imain_window.col_header_sensor_pv
const char *get_col_header_sensor_pv(void)
{
  return (const char *)imain_window.col_header_sensor_pv.label_text;
}

// get imain_window.data_display_label_sensor_raw0
/*const char *get_data_display_label_sensor_raw(unsigned int index)
{
  switch (index)
  {
  case 0:
    return (const char *)imain_window.data_display_label_sensor_raw0.label_text;
  case 1:
    return (const char *)imain_window.data_display_label_sensor_raw1.label_text;
  case 2:
    return (const char *)imain_window.data_display_label_sensor_raw2.label_text;
  case 3:
    return (const char *)imain_window.data_display_label_sensor_raw3.label_text;
  case 4:
    return (const char *)imain_window.data_display_label_sensor_raw4.label_text;
  case 5:
    return (const char *)imain_window.data_display_label_sensor_raw5.label_text;
  case 6:
    return (const char *)imain_window.data_display_label_sensor_raw6.label_text;
  case 7:
    return (const char *)imain_window.data_display_label_sensor_raw7.label_text;
  default:;
    g_printerr("imain-window get_data_display_label_sensor_raw(): Bad index\n");
  }
  return "\0"; // don't crash the poor guy by returning NULL..
}*/

const char *get_data_display_label_sensor_raw(unsigned int index)
{
  if (MAX_SENSORS <= index) {
    g_printerr("imain-window get_data_display_label_sensor_raw(): Bad index [%u]\n", index);
    return "\0";
  }
  return (const char *)imain_window.data_display_label_sensor_raw[index].label_text;
}

// get imain_window.data_display_label_sensor_pv
const char *get_data_display_label_sensor_pv(unsigned int index)
{
  switch (index)
  {
  case 0:
    return (const char *)imain_window.data_display_label_sensor_pv0.label_text;
  case 1:
    return (const char *)imain_window.data_display_label_sensor_pv1.label_text;
  case 2:
    return (const char *)imain_window.data_display_label_sensor_pv2.label_text;
  case 3:
    return (const char *)imain_window.data_display_label_sensor_pv3.label_text;
  case 4:
    return (const char *)imain_window.data_display_label_sensor_pv4.label_text;
  case 5:
    return (const char *)imain_window.data_display_label_sensor_pv5.label_text;
  case 6:
    return (const char *)imain_window.data_display_label_sensor_pv6.label_text;
  case 7:
    return (const char *)imain_window.data_display_label_sensor_pv7.label_text;
  default:
    g_printerr("imain-window get_data_display_label_sensor_pv(): Bad index\n");
  }
  return "\0";
}


void set_channel_label(unsigned int index, const char *text)
{
  if (MAX_SENSORS <= index) {
    g_printerr("imain-window set_channel_label(): Bad index\n");
    return;
  }
  strncpy(imain_window.channel_label[index].label_text, text, MAX_DATA_DISP_SZ);
  imain_window.channel_label[index].update_text = true;
}

// set imain_window.col_header_sensor_raw
/*void set_data_display_label_sensor_raw(unsigned int index, const char *text)
{
  switch (index)
  {
  case 0:
    strncpy(imain_window.data_display_label_sensor_raw0.label_text, text, MAX_DATA_DISP_SZ);
    imain_window.data_display_label_sensor_raw0.update_text = true;
    break;
  case 1:
    strncpy(imain_window.data_display_label_sensor_raw1.label_text, text, MAX_DATA_DISP_SZ);
    imain_window.data_display_label_sensor_raw1.update_text = true;
    break;
  case 2:
    strncpy(imain_window.data_display_label_sensor_raw2.label_text, text, MAX_DATA_DISP_SZ);
    imain_window.data_display_label_sensor_raw2.update_text = true;
    break;
  case 3:
    strncpy(imain_window.data_display_label_sensor_raw3.label_text, text, MAX_DATA_DISP_SZ);
    imain_window.data_display_label_sensor_raw3.update_text = true;
    break;
  case 4:
    strncpy(imain_window.data_display_label_sensor_raw4.label_text, text, MAX_DATA_DISP_SZ);
    imain_window.data_display_label_sensor_raw4.update_text = true;
    break;
  case 5:
    strncpy(imain_window.data_display_label_sensor_raw5.label_text, text, MAX_DATA_DISP_SZ);
    imain_window.data_display_label_sensor_raw5.update_text = true;
    break;
  case 6:
    strncpy(imain_window.data_display_label_sensor_raw6.label_text, text, MAX_DATA_DISP_SZ);
    imain_window.data_display_label_sensor_raw6.update_text = true;
    break;
  case 7:
    strncpy(imain_window.data_display_label_sensor_raw7.label_text, text, MAX_DATA_DISP_SZ);
    imain_window.data_display_label_sensor_raw7.update_text = true;
    break;
  default:
    g_printerr("imain-window set_data_display_label_sensor_raw(): Bad index\n");
    break;
  }
}*/

void set_data_display_label_sensor_raw(unsigned int index, const char *text)
{
  if (MAX_SENSORS <= index) {
    g_printerr("imain-window set_data_display_label_sensor_raw(): Bad index [%u]\n", index);
    return;
  }
  strncpy(imain_window.data_display_label_sensor_raw[index].label_text, text, MAX_DATA_DISP_SZ);
  imain_window.data_display_label_sensor_raw[index].update_text = true;
}


// set imain_window.data_display_label_sensor_pv
void set_data_display_label_sensor_pv(unsigned int index, const char *text)
{
  switch (index)
  {
  case 0:
    strncpy(imain_window.data_display_label_sensor_pv0.label_text, text, MAX_DATA_DISP_SZ);
    imain_window.data_display_label_sensor_pv0.update_text = true;
    break;
  case 1:
    strncpy(imain_window.data_display_label_sensor_pv1.label_text, text, MAX_DATA_DISP_SZ);
    imain_window.data_display_label_sensor_pv1.update_text = true;
    break;
  case 2:
    strncpy(imain_window.data_display_label_sensor_pv2.label_text, text, MAX_DATA_DISP_SZ);
    imain_window.data_display_label_sensor_pv2.update_text = true;
    break;
  case 3:
    strncpy(imain_window.data_display_label_sensor_pv3.label_text, text, MAX_DATA_DISP_SZ);
    imain_window.data_display_label_sensor_pv3.update_text = true;
    break;
  case 4:
    strncpy(imain_window.data_display_label_sensor_pv4.label_text, text, MAX_DATA_DISP_SZ);
    imain_window.data_display_label_sensor_pv4.update_text = true;
    break;
  case 5:
    strncpy(imain_window.data_display_label_sensor_pv5.label_text, text, MAX_DATA_DISP_SZ);
    imain_window.data_display_label_sensor_pv5.update_text = true;
    break;
  case 6:
    strncpy(imain_window.data_display_label_sensor_pv6.label_text, text, MAX_DATA_DISP_SZ);
    imain_window.data_display_label_sensor_pv6.update_text = true;
    break;
  case 7:
    strncpy(imain_window.data_display_label_sensor_pv7.label_text, text, MAX_DATA_DISP_SZ);
    imain_window.data_display_label_sensor_pv7.update_text = true;
    break;
  default:
    g_printerr("imain-window set_data_display_label_sensor_pv(): Bad index\n");
    break;
  }
}

/*void set_data_display_label_sensor_raw_fg_color(unsigned int index, guint16 red, guint16 green, guint16 blue)
{
  switch (index)
  {
  case 0:
    imain_window.data_display_label_sensor_raw0.foreground_color.red = red;
    imain_window.data_display_label_sensor_raw0.foreground_color.green = green;
    imain_window.data_display_label_sensor_raw0.foreground_color.blue = blue;
    imain_window.data_display_label_sensor_raw0.update_foreground_color = true;
    break;
  case 1:
    imain_window.data_display_label_sensor_raw1.foreground_color.red = red;
    imain_window.data_display_label_sensor_raw1.foreground_color.green = green;
    imain_window.data_display_label_sensor_raw1.foreground_color.blue = blue;
    imain_window.data_display_label_sensor_raw1.update_foreground_color = true;
    break;
  case 2:
    imain_window.data_display_label_sensor_raw2.foreground_color.red = red;
    imain_window.data_display_label_sensor_raw2.foreground_color.green = green;
    imain_window.data_display_label_sensor_raw2.foreground_color.blue = blue;
    imain_window.data_display_label_sensor_raw2.update_foreground_color = true;
    break;
  case 3:
    imain_window.data_display_label_sensor_raw3.foreground_color.red = red;
    imain_window.data_display_label_sensor_raw3.foreground_color.green = green;
    imain_window.data_display_label_sensor_raw3.foreground_color.blue = blue;
    imain_window.data_display_label_sensor_raw3.update_foreground_color = true;
    break;
  case 4:
    imain_window.data_display_label_sensor_raw4.foreground_color.red = red;
    imain_window.data_display_label_sensor_raw4.foreground_color.green = green;
    imain_window.data_display_label_sensor_raw4.foreground_color.blue = blue;
    imain_window.data_display_label_sensor_raw4.update_foreground_color = true;
    break;
  case 5:
    imain_window.data_display_label_sensor_raw5.foreground_color.red = red;
    imain_window.data_display_label_sensor_raw5.foreground_color.green = green;
    imain_window.data_display_label_sensor_raw5.foreground_color.blue = blue;
    imain_window.data_display_label_sensor_raw5.update_foreground_color = true;
    break;
  case 6:
    imain_window.data_display_label_sensor_raw6.foreground_color.red = red;
    imain_window.data_display_label_sensor_raw6.foreground_color.green = green;
    imain_window.data_display_label_sensor_raw6.foreground_color.blue = blue;
    imain_window.data_display_label_sensor_raw6.update_foreground_color = true;
    break;
  case 7:
    imain_window.data_display_label_sensor_raw7.foreground_color.red = red;
    imain_window.data_display_label_sensor_raw7.foreground_color.green = green;
    imain_window.data_display_label_sensor_raw7.foreground_color.blue = blue;
    imain_window.data_display_label_sensor_raw7.update_foreground_color = true;
    break;
  default:
    g_printerr("imain-window set_data_display_label_sensor_raw_fg_color(): Bad index\n");
    break;
  }
}*/

void set_data_display_label_sensor_raw_fg_color(unsigned int index, guint16 red, guint16 green, guint16 blue)
{
  if (MAX_SENSORS <= index) {
    g_printerr("imain-window set_data_display_label_sensor_raw_fg_color(): Bad index [%u]\n", index);
    return;
  }
  imain_window.data_display_label_sensor_raw[index].foreground_color.red = red;
  imain_window.data_display_label_sensor_raw[index].foreground_color.green = green;
  imain_window.data_display_label_sensor_raw[index].foreground_color.blue = blue;
  imain_window.data_display_label_sensor_raw[index].update_foreground_color = true;
}

/*void set_data_display_label_sensor_raw_bg_color(unsigned int index, guint16 red, guint16 green, guint16 blue)
{
  switch (index)
  {
  case 0:
    imain_window.data_display_label_sensor_raw0.background_color.red = red;
    imain_window.data_display_label_sensor_raw0.background_color.green = green;
    imain_window.data_display_label_sensor_raw0.background_color.blue = blue;
    imain_window.data_display_label_sensor_raw0.update_background_color = true;
    break;
  case 1:
    imain_window.data_display_label_sensor_raw1.background_color.red = red;
    imain_window.data_display_label_sensor_raw1.background_color.green = green;
    imain_window.data_display_label_sensor_raw1.background_color.blue = blue;
    imain_window.data_display_label_sensor_raw1.update_background_color = true;
    break;
  case 2:
    imain_window.data_display_label_sensor_raw2.background_color.red = red;
    imain_window.data_display_label_sensor_raw2.background_color.green = green;
    imain_window.data_display_label_sensor_raw2.background_color.blue = blue;
    imain_window.data_display_label_sensor_raw2.update_background_color = true;
    break;
  case 3:
    imain_window.data_display_label_sensor_raw3.background_color.red = red;
    imain_window.data_display_label_sensor_raw3.background_color.green = green;
    imain_window.data_display_label_sensor_raw3.background_color.blue = blue;
    imain_window.data_display_label_sensor_raw3.update_background_color = true;
    break;
  case 4:
    imain_window.data_display_label_sensor_raw4.background_color.red = red;
    imain_window.data_display_label_sensor_raw4.background_color.green = green;
    imain_window.data_display_label_sensor_raw4.background_color.blue = blue;
    imain_window.data_display_label_sensor_raw4.update_background_color = true;
    break;
  case 5:
    imain_window.data_display_label_sensor_raw5.background_color.red = red;
    imain_window.data_display_label_sensor_raw5.background_color.green = green;
    imain_window.data_display_label_sensor_raw5.background_color.blue = blue;
    imain_window.data_display_label_sensor_raw5.update_background_color = true;
    break;
  case 6:
    imain_window.data_display_label_sensor_raw6.background_color.red = red;
    imain_window.data_display_label_sensor_raw6.background_color.green = green;
    imain_window.data_display_label_sensor_raw6.background_color.blue = blue;
    imain_window.data_display_label_sensor_raw6.update_background_color = true;
    break;
  case 7:
    imain_window.data_display_label_sensor_raw7.background_color.red = red;
    imain_window.data_display_label_sensor_raw7.background_color.green = green;
    imain_window.data_display_label_sensor_raw7.background_color.blue = blue;
    imain_window.data_display_label_sensor_raw7.update_background_color = true;
    break;
  default:
    g_printerr("imain-window set_data_display_label_sensor_raw_bg_color(): Bad index\n");
    break;
  }
}*/

void set_data_display_label_sensor_raw_bg_color(unsigned int index, guint16 red, guint16 green, guint16 blue)
{
  if (MAX_SENSORS <= index) {
    g_printerr("imain-window set_data_display_label_sensor_raw_bg_color(): Bad index [%u]\n", index);
    return;
  }
  imain_window.data_display_label_sensor_raw[index].background_color.red = red;
  imain_window.data_display_label_sensor_raw[index].background_color.green = green;
  imain_window.data_display_label_sensor_raw[index].background_color.blue = blue;
  imain_window.data_display_label_sensor_raw[index].update_background_color = true;
}


/*void set_data_display_label_sensor_raw_highlight_color(unsigned int index, guint16 red, guint16 green, guint16 blue)
{
  switch (index)
  {
  case 0:
    imain_window.data_display_label_sensor_raw0.text_highlight_color.red = red;
    imain_window.data_display_label_sensor_raw0.text_highlight_color.green = green;
    imain_window.data_display_label_sensor_raw0.text_highlight_color.blue = blue;
    imain_window.data_display_label_sensor_raw0.update_text_highlight_color = true;
    break;
  case 1:
    imain_window.data_display_label_sensor_raw1.text_highlight_color.red = red;
    imain_window.data_display_label_sensor_raw1.text_highlight_color.green = green;
    imain_window.data_display_label_sensor_raw1.text_highlight_color.blue = blue;
    imain_window.data_display_label_sensor_raw1.update_text_highlight_color = true;
    break;
  case 2:
    imain_window.data_display_label_sensor_raw2.text_highlight_color.red = red;
    imain_window.data_display_label_sensor_raw2.text_highlight_color.green = green;
    imain_window.data_display_label_sensor_raw2.text_highlight_color.blue = blue;
    imain_window.data_display_label_sensor_raw2.update_text_highlight_color = true;
    break;
  case 3:
    imain_window.data_display_label_sensor_raw3.text_highlight_color.red = red;
    imain_window.data_display_label_sensor_raw3.text_highlight_color.green = green;
    imain_window.data_display_label_sensor_raw3.text_highlight_color.blue = blue;
    imain_window.data_display_label_sensor_raw3.update_text_highlight_color = true;
    break;
  case 4:
    imain_window.data_display_label_sensor_raw4.text_highlight_color.red = red;
    imain_window.data_display_label_sensor_raw4.text_highlight_color.green = green;
    imain_window.data_display_label_sensor_raw4.text_highlight_color.blue = blue;
    imain_window.data_display_label_sensor_raw4.update_text_highlight_color = true;
    break;
  case 5:
    imain_window.data_display_label_sensor_raw5.text_highlight_color.red = red;
    imain_window.data_display_label_sensor_raw5.text_highlight_color.green = green;
    imain_window.data_display_label_sensor_raw5.text_highlight_color.blue = blue;
    imain_window.data_display_label_sensor_raw5.update_text_highlight_color = true;
    break;
  case 6:
    imain_window.data_display_label_sensor_raw6.text_highlight_color.red = red;
    imain_window.data_display_label_sensor_raw6.text_highlight_color.green = green;
    imain_window.data_display_label_sensor_raw6.text_highlight_color.blue = blue;
    imain_window.data_display_label_sensor_raw6.update_text_highlight_color = true;
    break;
  case 7:
    imain_window.data_display_label_sensor_raw7.text_highlight_color.red = red;
    imain_window.data_display_label_sensor_raw7.text_highlight_color.green = green;
    imain_window.data_display_label_sensor_raw7.text_highlight_color.blue = blue;
    imain_window.data_display_label_sensor_raw7.update_text_highlight_color = true;
    break;
  default:
    g_printerr("imain-window set_data_display_label_sensor_raw_highlight_color(): Bad index\n");
    break;
  }
}*/

void set_data_display_label_sensor_raw_highlight_color(unsigned int index, guint16 red, guint16 green, guint16 blue)
{
  if (MAX_SENSORS <= index) {
    g_printerr("imain-window set_data_display_label_sensor_raw_highlight_color(): Bad index [%u]\n", index);
    return;
  }
  imain_window.data_display_label_sensor_raw[index].text_highlight_color.red = red;
  imain_window.data_display_label_sensor_raw[index].text_highlight_color.green = green;
  imain_window.data_display_label_sensor_raw[index].text_highlight_color.blue = blue;
  imain_window.data_display_label_sensor_raw[index].update_text_highlight_color = true;
}


void set_data_display_label_sensor_pv_fg_color(unsigned int index, guint16 red, guint16 green, guint16 blue)
{
  switch (index)
  {
  case 0:
    imain_window.data_display_label_sensor_pv0.foreground_color.red = red;
    imain_window.data_display_label_sensor_pv0.foreground_color.green = green;
    imain_window.data_display_label_sensor_pv0.foreground_color.blue = blue;
    imain_window.data_display_label_sensor_pv0.update_foreground_color = true;
    break;
  case 1:
    imain_window.data_display_label_sensor_pv1.foreground_color.red = red;
    imain_window.data_display_label_sensor_pv1.foreground_color.green = green;
    imain_window.data_display_label_sensor_pv1.foreground_color.blue = blue;
    imain_window.data_display_label_sensor_pv1.update_foreground_color = true;
    break;
  case 2:
    imain_window.data_display_label_sensor_pv2.foreground_color.red = red;
    imain_window.data_display_label_sensor_pv2.foreground_color.green = green;
    imain_window.data_display_label_sensor_pv2.foreground_color.blue = blue;
    imain_window.data_display_label_sensor_pv2.update_foreground_color = true;
    break;
  case 3:
    imain_window.data_display_label_sensor_pv3.foreground_color.red = red;
    imain_window.data_display_label_sensor_pv3.foreground_color.green = green;
    imain_window.data_display_label_sensor_pv3.foreground_color.blue = blue;
    imain_window.data_display_label_sensor_pv3.update_foreground_color = true;
    break;
  case 4:
    imain_window.data_display_label_sensor_pv4.foreground_color.red = red;
    imain_window.data_display_label_sensor_pv4.foreground_color.green = green;
    imain_window.data_display_label_sensor_pv4.foreground_color.blue = blue;
    imain_window.data_display_label_sensor_pv4.update_foreground_color = true;
    break;
  case 5:
    imain_window.data_display_label_sensor_pv5.foreground_color.red = red;
    imain_window.data_display_label_sensor_pv5.foreground_color.green = green;
    imain_window.data_display_label_sensor_pv5.foreground_color.blue = blue;
    imain_window.data_display_label_sensor_pv5.update_foreground_color = true;
    break;
  case 6:
    imain_window.data_display_label_sensor_pv6.foreground_color.red = red;
    imain_window.data_display_label_sensor_pv6.foreground_color.green = green;
    imain_window.data_display_label_sensor_pv6.foreground_color.blue = blue;
    imain_window.data_display_label_sensor_pv6.update_foreground_color = true;
    break;
  case 7:
    imain_window.data_display_label_sensor_pv7.foreground_color.red = red;
    imain_window.data_display_label_sensor_pv7.foreground_color.green = green;
    imain_window.data_display_label_sensor_pv7.foreground_color.blue = blue;
    imain_window.data_display_label_sensor_pv7.update_foreground_color = true;
    break;
  default:
    g_printerr("imain-window set_data_display_label_sensor_pv_fg_color(): Bad index\n");
    break;
  }
}

void set_data_display_label_sensor_pv_bg_color(unsigned int index, guint16 red, guint16 green, guint16 blue)
{
  switch (index)
  {
  case 0:
    imain_window.data_display_label_sensor_pv0.background_color.red = red;
    imain_window.data_display_label_sensor_pv0.background_color.green = green;
    imain_window.data_display_label_sensor_pv0.background_color.blue = blue;
    imain_window.data_display_label_sensor_pv0.update_background_color = true;
    break;
  case 1:
    imain_window.data_display_label_sensor_pv1.background_color.red = red;
    imain_window.data_display_label_sensor_pv1.background_color.green = green;
    imain_window.data_display_label_sensor_pv1.background_color.blue = blue;
    imain_window.data_display_label_sensor_pv1.update_background_color = true;
    break;
  case 2:
    imain_window.data_display_label_sensor_pv2.background_color.red = red;
    imain_window.data_display_label_sensor_pv2.background_color.green = green;
    imain_window.data_display_label_sensor_pv2.background_color.blue = blue;
    imain_window.data_display_label_sensor_pv2.update_background_color = true;
    break;
  case 3:
    imain_window.data_display_label_sensor_pv3.background_color.red = red;
    imain_window.data_display_label_sensor_pv3.background_color.green = green;
    imain_window.data_display_label_sensor_pv3.background_color.blue = blue;
    imain_window.data_display_label_sensor_pv3.update_background_color = true;
    break;
  case 4:
    imain_window.data_display_label_sensor_pv4.background_color.red = red;
    imain_window.data_display_label_sensor_pv4.background_color.green = green;
    imain_window.data_display_label_sensor_pv4.background_color.blue = blue;
    imain_window.data_display_label_sensor_pv4.update_background_color = true;
    break;
  case 5:
    imain_window.data_display_label_sensor_pv5.background_color.red = red;
    imain_window.data_display_label_sensor_pv5.background_color.green = green;
    imain_window.data_display_label_sensor_pv5.background_color.blue = blue;
    imain_window.data_display_label_sensor_pv5.update_background_color = true;
    break;
  case 6:
    imain_window.data_display_label_sensor_pv6.background_color.red = red;
    imain_window.data_display_label_sensor_pv6.background_color.green = green;
    imain_window.data_display_label_sensor_pv6.background_color.blue = blue;
    imain_window.data_display_label_sensor_pv6.update_background_color = true;
    break;
  case 7:
    imain_window.data_display_label_sensor_pv7.background_color.red = red;
    imain_window.data_display_label_sensor_pv7.background_color.green = green;
    imain_window.data_display_label_sensor_pv7.background_color.blue = blue;
    imain_window.data_display_label_sensor_pv7.update_background_color = true;
    break;
  default:
    g_printerr("imain-window set_data_display_label_sensor_pv_bg_color(): Bad index\n");
    break;
  }
}

void set_data_display_label_sensor_pv_highlight_color(unsigned int index, guint16 red, guint16 green, guint16 blue)
{
  switch (index)
  {
  case 0:
    imain_window.data_display_label_sensor_pv0.text_highlight_color.red = red;
    imain_window.data_display_label_sensor_pv0.text_highlight_color.green = green;
    imain_window.data_display_label_sensor_pv0.text_highlight_color.blue = blue;
    imain_window.data_display_label_sensor_pv0.update_text_highlight_color = true;
    break;
  case 1:
    imain_window.data_display_label_sensor_pv1.text_highlight_color.red = red;
    imain_window.data_display_label_sensor_pv1.text_highlight_color.green = green;
    imain_window.data_display_label_sensor_pv1.text_highlight_color.blue = blue;
    imain_window.data_display_label_sensor_pv1.update_text_highlight_color = true;
    break;
  case 2:
    imain_window.data_display_label_sensor_pv2.text_highlight_color.red = red;
    imain_window.data_display_label_sensor_pv2.text_highlight_color.green = green;
    imain_window.data_display_label_sensor_pv2.text_highlight_color.blue = blue;
    imain_window.data_display_label_sensor_pv2.update_text_highlight_color = true;
    break;
  case 3:
    imain_window.data_display_label_sensor_pv3.text_highlight_color.red = red;
    imain_window.data_display_label_sensor_pv3.text_highlight_color.green = green;
    imain_window.data_display_label_sensor_pv3.text_highlight_color.blue = blue;
    imain_window.data_display_label_sensor_pv3.update_text_highlight_color = true;
    break;
  case 4:
    imain_window.data_display_label_sensor_pv4.text_highlight_color.red = red;
    imain_window.data_display_label_sensor_pv4.text_highlight_color.green = green;
    imain_window.data_display_label_sensor_pv4.text_highlight_color.blue = blue;
    imain_window.data_display_label_sensor_pv4.update_text_highlight_color = true;
    break;
  case 5:
    imain_window.data_display_label_sensor_pv5.text_highlight_color.red = red;
    imain_window.data_display_label_sensor_pv5.text_highlight_color.green = green;
    imain_window.data_display_label_sensor_pv5.text_highlight_color.blue = blue;
    imain_window.data_display_label_sensor_pv5.update_text_highlight_color = true;
    break;
  case 6:
    imain_window.data_display_label_sensor_pv6.text_highlight_color.red = red;
    imain_window.data_display_label_sensor_pv6.text_highlight_color.green = green;
    imain_window.data_display_label_sensor_pv6.text_highlight_color.blue = blue;
    imain_window.data_display_label_sensor_pv6.update_text_highlight_color = true;
    break;
  case 7:
    imain_window.data_display_label_sensor_pv7.text_highlight_color.red = red;
    imain_window.data_display_label_sensor_pv7.text_highlight_color.green = green;
    imain_window.data_display_label_sensor_pv7.text_highlight_color.blue = blue;
    imain_window.data_display_label_sensor_pv7.update_text_highlight_color = true;
    break;
  default:
    g_printerr("imain-window set_data_display_label_sensor_pv_highlight_color(): Bad index\n");
    break;
  }
}

// behold the power of c!
void set_data_display_label_sensor_raw_font_family(unsigned int index, const char *font_family)
{
  Font_Attrib_t *p_font_attrib = (Font_Attrib_t *)((char *)&imain_window.data_display_label_sensor_raw[0].font_attrib + index * sizeof(Data_Display_Label_t));
  if(NULL == font_family) {
    return;
  }
  strncpy((char*)p_font_attrib->font_family, font_family, MAX_FONT_FAMILY_LEN);
  p_font_attrib->update_font_attrib = true;
}

void set_data_display_label_sensor_pv_font_family(unsigned int index, const char *font_family)
{
  Font_Attrib_t *p_font_attrib = (Font_Attrib_t *)((char *)&imain_window.data_display_label_sensor_pv0.font_attrib + index * sizeof(Data_Display_Label_t));
  if(NULL == font_family) {
    return;
  }
  strncpy((char*)p_font_attrib->font_family, font_family, MAX_FONT_FAMILY_LEN);
  p_font_attrib->update_font_attrib = true;
}

void set_data_display_label_sensor_raw_font_size(unsigned int index, int size)
{
  Font_Attrib_t *p_font_attrib = (Font_Attrib_t *)((char *)&imain_window.data_display_label_sensor_raw[0].font_attrib + index * sizeof(Data_Display_Label_t));
  p_font_attrib->size = size;
  p_font_attrib->update_font_attrib = true;
}

void set_data_display_label_sensor_pv_font_size(unsigned int index, gint size)
{
  Font_Attrib_t *p_font_attrib = (Font_Attrib_t *)((char *)&imain_window.data_display_label_sensor_pv0.font_attrib + index * sizeof(Data_Display_Label_t));
  p_font_attrib->size = size;
  p_font_attrib->update_font_attrib = true;
}

void set_data_display_label_sensor_raw_font_weight(unsigned int index, PangoWeight pango_weight)
{
  Font_Attrib_t *p_font_attrib = (Font_Attrib_t *)((char *)&imain_window.data_display_label_sensor_raw[0].font_attrib + index * sizeof(Data_Display_Label_t));
  p_font_attrib->weight = pango_weight;
  p_font_attrib->update_font_attrib = true;
}

void set_data_display_label_sensor_pv_font_weight(unsigned int index, PangoWeight pango_weight)
{
  Font_Attrib_t *p_font_attrib = (Font_Attrib_t *)((char *)&imain_window.data_display_label_sensor_pv0.font_attrib + index * sizeof(Data_Display_Label_t));
  p_font_attrib->weight = pango_weight;
  p_font_attrib->update_font_attrib = true;
}

// get the update text flag and acknowledge
/*bool get_update_text_raw_ack(unsigned int index)
{
  bool state = false;
  switch(index)
  {
  case 0:
    state = imain_window.data_display_label_sensor_raw0.update_text;
    imain_window.data_display_label_sensor_raw0.update_text = false;
    break;
  case 1:
    state = imain_window.data_display_label_sensor_raw1.update_text;
    imain_window.data_display_label_sensor_raw1.update_text = false;
    break;
  case 2:
    state = imain_window.data_display_label_sensor_raw2.update_text;
    imain_window.data_display_label_sensor_raw2.update_text = false;
    break;
  case 3:
    state = imain_window.data_display_label_sensor_raw3.update_text;
    imain_window.data_display_label_sensor_raw3.update_text = false;
    break;
  case 4:
    state = imain_window.data_display_label_sensor_raw4.update_text;
    imain_window.data_display_label_sensor_raw4.update_text = false;
    break;
  case 5:
    state = imain_window.data_display_label_sensor_raw5.update_text;
    imain_window.data_display_label_sensor_raw5.update_text = false;
    break;
  case 6:
    state = imain_window.data_display_label_sensor_raw6.update_text;
    imain_window.data_display_label_sensor_raw6.update_text = false;
    break;
  case 7:
    state = imain_window.data_display_label_sensor_raw7.update_text;
    imain_window.data_display_label_sensor_raw7.update_text = false;
    break;
  default:
    g_printerr("imain-window get_update_text_raw_ack(): Bad index\n");
    break;
  }
  return state;
}*/

bool get_update_text_raw_ack(unsigned int index)
{
  bool state = false;
  if (MAX_SENSORS <= index) {
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
  switch(index)
  {
  case 0:
    state = imain_window.data_display_label_sensor_pv0.update_text;
    imain_window.data_display_label_sensor_pv0.update_text = false;
    break;
  case 1:
    state = imain_window.data_display_label_sensor_pv1.update_text;
    imain_window.data_display_label_sensor_pv1.update_text = false;
    break;
  case 2:
    state = imain_window.data_display_label_sensor_pv2.update_text;
    imain_window.data_display_label_sensor_pv2.update_text = false;
    break;
  case 3:
    state = imain_window.data_display_label_sensor_pv3.update_text;
    imain_window.data_display_label_sensor_pv3.update_text = false;
    break;
  case 4:
    state = imain_window.data_display_label_sensor_pv4.update_text;
    imain_window.data_display_label_sensor_pv4.update_text = false;
    break;
  case 5:
    state = imain_window.data_display_label_sensor_pv5.update_text;
    imain_window.data_display_label_sensor_pv5.update_text = false;
    break;
  case 6:
    state = imain_window.data_display_label_sensor_pv6.update_text;
    imain_window.data_display_label_sensor_pv6.update_text = false;
    break;
  case 7:
    state = imain_window.data_display_label_sensor_pv7.update_text;
    imain_window.data_display_label_sensor_pv7.update_text = false;
    break;
  default:
    g_printerr("imain-window get_update_text_pv_ack(): Bad index\n");
    break;
  }
  return state;
}

/*bool get_update_foreground_color_raw_ack(unsigned int index)
{
  bool state = false;
  switch(index)
  {
  case 0:
    state = imain_window.data_display_label_sensor_raw0.update_foreground_color;
    imain_window.data_display_label_sensor_raw0.update_foreground_color = false;
    break;
  case 1:
    state = imain_window.data_display_label_sensor_raw1.update_foreground_color;
    imain_window.data_display_label_sensor_raw1.update_foreground_color = false;
    break;
  case 2:
    state = imain_window.data_display_label_sensor_raw2.update_foreground_color;
    imain_window.data_display_label_sensor_raw2.update_foreground_color = false;
    break;
  case 3:
    state = imain_window.data_display_label_sensor_raw3.update_foreground_color;
    imain_window.data_display_label_sensor_raw3.update_foreground_color = false;
    break;
  case 4:
    state = imain_window.data_display_label_sensor_raw4.update_foreground_color;
    imain_window.data_display_label_sensor_raw4.update_foreground_color = false;
    break;
  case 5:
    state = imain_window.data_display_label_sensor_raw5.update_foreground_color;
    imain_window.data_display_label_sensor_raw5.update_foreground_color = false;
    break;
  case 6:
    state = imain_window.data_display_label_sensor_raw6.update_foreground_color;
    imain_window.data_display_label_sensor_raw6.update_foreground_color = false;
    break;
  case 7:
    state = imain_window.data_display_label_sensor_raw7.update_foreground_color;
    imain_window.data_display_label_sensor_raw7.update_foreground_color = false;
    break;
  default:
    g_printerr("imain-window get_update_foreground_color_raw_ack(): Bad index\n");
    break;
  }
  return state;
}*/

bool get_update_foreground_color_raw_ack(unsigned int index)
{
  bool state = false;
  if (MAX_SENSORS <= index) {
    g_printerr("imain-window get_update_foreground_color_raw_ack(): Bad index [%u]\n", index);
    return false;
  }
  state = imain_window.data_display_label_sensor_raw[index].update_foreground_color;
  imain_window.data_display_label_sensor_raw[index].update_foreground_color = false;
  return state;
}

/*bool get_update_background_color_raw_ack(unsigned int index)
{
  bool state = false;
  switch(index)
  {
  case 0:
    state = imain_window.data_display_label_sensor_raw0.update_background_color;
    imain_window.data_display_label_sensor_raw0.update_background_color = false;
    break;
  case 1:
    state = imain_window.data_display_label_sensor_raw1.update_background_color;
    imain_window.data_display_label_sensor_raw1.update_background_color = false;
    break;
  case 2:
    state = imain_window.data_display_label_sensor_raw2.update_background_color;
    imain_window.data_display_label_sensor_raw2.update_background_color = false;
    break;
  case 3:
    state = imain_window.data_display_label_sensor_raw3.update_background_color;
    imain_window.data_display_label_sensor_raw3.update_background_color = false;
    break;
  case 4:
    state = imain_window.data_display_label_sensor_raw4.update_background_color;
    imain_window.data_display_label_sensor_raw4.update_background_color = false;
    break;
  case 5:
    state = imain_window.data_display_label_sensor_raw5.update_background_color;
    imain_window.data_display_label_sensor_raw5.update_background_color = false;
    break;
  case 6:
    state = imain_window.data_display_label_sensor_raw6.update_background_color;
    imain_window.data_display_label_sensor_raw6.update_background_color = false;
    break;
  case 7:
    state = imain_window.data_display_label_sensor_raw7.update_background_color;
    imain_window.data_display_label_sensor_raw7.update_background_color = false;
    break;
  default:
    g_printerr("imain-window get_update_background_color_raw_ack(): Bad index\n");
    break;
  }
  return state;
}*/

bool get_update_background_color_raw_ack(unsigned int index)
{
  bool state = false;
  if (MAX_SENSORS <= index) {
    g_printerr("imain-window get_update_background_color_raw_ack(): Bad index [%u]\n", index);
    return false;
  }
  state = imain_window.data_display_label_sensor_raw[index].update_background_color;
  imain_window.data_display_label_sensor_raw[index].update_background_color = false;
  return state;
}

/*bool get_update_highlight_color_raw_ack(unsigned int index)
{
  bool state = false;
  switch(index)
  {
  case 0:
    state = imain_window.data_display_label_sensor_raw0.update_text_highlight_color;
    imain_window.data_display_label_sensor_raw0.update_text_highlight_color = false;
    break;
  case 1:
    state = imain_window.data_display_label_sensor_raw1.update_text_highlight_color;
    imain_window.data_display_label_sensor_raw1.update_text_highlight_color = false;
    break;
  case 2:
    state = imain_window.data_display_label_sensor_raw2.update_text_highlight_color;
    imain_window.data_display_label_sensor_raw2.update_text_highlight_color = false;
    break;
  case 3:
    state = imain_window.data_display_label_sensor_raw3.update_text_highlight_color;
    imain_window.data_display_label_sensor_raw3.update_text_highlight_color = false;
    break;
  case 4:
    state = imain_window.data_display_label_sensor_raw4.update_text_highlight_color;
    imain_window.data_display_label_sensor_raw4.update_text_highlight_color = false;
    break;
  case 5:
    state = imain_window.data_display_label_sensor_raw5.update_text_highlight_color;
    imain_window.data_display_label_sensor_raw5.update_text_highlight_color = false;
    break;
  case 6:
    state = imain_window.data_display_label_sensor_raw6.update_text_highlight_color;
    imain_window.data_display_label_sensor_raw6.update_text_highlight_color = false;
    break;
  case 7:
    state = imain_window.data_display_label_sensor_raw7.update_text_highlight_color;
    imain_window.data_display_label_sensor_raw7.update_text_highlight_color = false;
    break;
  default:
    g_printerr("imain-window get_update_highlight_color_raw_ack(): Bad index\n");
    break;
  }
  return state;
}*/

bool get_update_highlight_color_raw_ack(unsigned int index)
{
  bool state = false;
  if (MAX_SENSORS <= index) {
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
  switch(index)
  {
  case 0:
    state = imain_window.data_display_label_sensor_pv0.update_foreground_color;
    imain_window.data_display_label_sensor_pv0.update_foreground_color = false;
    break;
  case 1:
    state = imain_window.data_display_label_sensor_pv1.update_foreground_color;
    imain_window.data_display_label_sensor_pv1.update_foreground_color = false;
    break;
  case 2:
    state = imain_window.data_display_label_sensor_pv2.update_foreground_color;
    imain_window.data_display_label_sensor_pv2.update_foreground_color = false;
    break;
  case 3:
    state = imain_window.data_display_label_sensor_pv3.update_foreground_color;
    imain_window.data_display_label_sensor_pv3.update_foreground_color = false;
    break;
  case 4:
    state = imain_window.data_display_label_sensor_pv4.update_foreground_color;
    imain_window.data_display_label_sensor_pv4.update_foreground_color = false;
    break;
  case 5:
    state = imain_window.data_display_label_sensor_pv5.update_foreground_color;
    imain_window.data_display_label_sensor_pv5.update_foreground_color = false;
    break;
  case 6:
    state = imain_window.data_display_label_sensor_pv6.update_foreground_color;
    imain_window.data_display_label_sensor_pv6.update_foreground_color = false;
    break;
  case 7:
    state = imain_window.data_display_label_sensor_pv7.update_foreground_color;
    imain_window.data_display_label_sensor_pv7.update_foreground_color = false;
    break;
  default:
    g_printerr("imain-window get_update_foreground_color_pv_ack(): Bad index\n");
    break;
  }
  return state;
}

bool get_update_background_color_pv_ack(unsigned int index)
{
  bool state = false;
  switch(index)
  {
  case 0:
    state = imain_window.data_display_label_sensor_pv0.update_background_color;
    imain_window.data_display_label_sensor_pv0.update_background_color = false;
    break;
  case 1:
    state = imain_window.data_display_label_sensor_pv1.update_background_color;
    imain_window.data_display_label_sensor_pv1.update_background_color = false;
    break;
  case 2:
    state = imain_window.data_display_label_sensor_pv2.update_background_color;
    imain_window.data_display_label_sensor_pv2.update_background_color = false;
    break;
  case 3:
    state = imain_window.data_display_label_sensor_pv3.update_background_color;
    imain_window.data_display_label_sensor_pv3.update_background_color = false;
    break;
  case 4:
    state = imain_window.data_display_label_sensor_pv4.update_background_color;
    imain_window.data_display_label_sensor_pv4.update_background_color = false;
    break;
  case 5:
    state = imain_window.data_display_label_sensor_pv5.update_background_color;
    imain_window.data_display_label_sensor_pv5.update_background_color = false;
    break;
  case 6:
    state = imain_window.data_display_label_sensor_pv6.update_background_color;
    imain_window.data_display_label_sensor_pv6.update_background_color = false;
    break;
  case 7:
    state = imain_window.data_display_label_sensor_pv7.update_background_color;
    imain_window.data_display_label_sensor_pv7.update_background_color = false;
    break;
  default:
    g_printerr("imain-window get_update_background_color_pv_ack(): Bad index\n");
    break;
  }
  return state;
}

bool get_update_highlight_color_pv_ack(unsigned int index)
{
  bool state = false;
  switch(index)
  {
  case 0:
    state = imain_window.data_display_label_sensor_pv0.update_text_highlight_color;
    imain_window.data_display_label_sensor_pv0.update_text_highlight_color = false;
    break;
  case 1:
    state = imain_window.data_display_label_sensor_pv1.update_text_highlight_color;
    imain_window.data_display_label_sensor_pv1.update_text_highlight_color = false;
    break;
  case 2:
    state = imain_window.data_display_label_sensor_pv2.update_text_highlight_color;
    imain_window.data_display_label_sensor_pv2.update_text_highlight_color = false;
    break;
  case 3:
    state = imain_window.data_display_label_sensor_pv3.update_text_highlight_color;
    imain_window.data_display_label_sensor_pv3.update_text_highlight_color = false;
    break;
  case 4:
    state = imain_window.data_display_label_sensor_pv4.update_text_highlight_color;
    imain_window.data_display_label_sensor_pv4.update_text_highlight_color = false;
    break;
  case 5:
    state = imain_window.data_display_label_sensor_pv5.update_text_highlight_color;
    imain_window.data_display_label_sensor_pv5.update_text_highlight_color = false;
    break;
  case 6:
    state = imain_window.data_display_label_sensor_pv6.update_text_highlight_color;
    imain_window.data_display_label_sensor_pv6.update_text_highlight_color = false;
    break;
  case 7:
    state = imain_window.data_display_label_sensor_pv7.update_text_highlight_color;
    imain_window.data_display_label_sensor_pv7.update_text_highlight_color = false;
    break;
  default:
    g_printerr("imain-window get_update_highlight_color_pv_ack(): Bad index\n");
    break;
  }
  return state;
}

bool get_update_font_attrib_raw_ack(unsigned int index)
{
  bool state;
  bool *p_update_font_attrib = (bool *)&imain_window.data_display_label_sensor_raw[0].font_attrib.update_font_attrib + index * sizeof(Data_Display_Label_t);
  state = *p_update_font_attrib;
  *p_update_font_attrib = false;
  return state;
}

bool get_update_font_attrib_pv_ack(unsigned int index)
{
  bool state;
  bool *p_update_font_attrib = (bool *)&imain_window.data_display_label_sensor_pv0.font_attrib.update_font_attrib + index * sizeof(Data_Display_Label_t);
  state = *p_update_font_attrib;
  *p_update_font_attrib = false;
  return state;
}

// get imain_window.button_zero_pressed
bool button_zero_pressed(unsigned int index)
{
  switch (index)
  {
  case 0:
    return imain_window.button_zero_0_pressed;
  case 1:
    return imain_window.button_zero_1_pressed;
  case 2:
    return imain_window.button_zero_2_pressed;
  case 3:
    return imain_window.button_zero_3_pressed;
  case 4:
    return imain_window.button_zero_4_pressed;
  case 5:
    return imain_window.button_zero_5_pressed;
  case 6:
    return imain_window.button_zero_6_pressed;
  case 7:
    return imain_window.button_zero_7_pressed;
  default:
    return imain_window.button_zero_0_pressed;
  }
}

// get imain_window.button_span_pressed
bool button_span_pressed(unsigned int index)
{
  switch (index)
  {
  case 0:
    return imain_window.button_span_0_pressed;
  case 1:
    return imain_window.button_span_1_pressed;
  case 2:
    return imain_window.button_span_2_pressed;
  case 3:
    return imain_window.button_span_3_pressed;
  case 4:
    return imain_window.button_span_4_pressed;
  case 5:
    return imain_window.button_span_5_pressed;
  case 6:
    return imain_window.button_span_6_pressed;
  case 7:
    return imain_window.button_span_7_pressed;
  default:
    return imain_window.button_span_0_pressed;
  }
}

// get imain_window.button_zero_n_pressed and acknowledge
bool button_zero_pressed_ack(unsigned int index)
{
  bool state = false;
  switch (index)
  {
  case 0:
    state = imain_window.button_zero_0_pressed;
    imain_window.button_zero_0_pressed = false;
    return state;
  case 1:
    state = imain_window.button_zero_1_pressed;
    imain_window.button_zero_1_pressed = false;
    return state;
  case 2:
    state = imain_window.button_zero_2_pressed;
    imain_window.button_zero_2_pressed = false;
    return state;
  case 3:
    state = imain_window.button_zero_3_pressed;
    imain_window.button_zero_3_pressed = false;
    return state;
  case 4:
    state = imain_window.button_zero_4_pressed;
    imain_window.button_zero_4_pressed = false;
    return state;
  case 5:
    state = imain_window.button_zero_5_pressed;
    imain_window.button_zero_5_pressed = false;
    return state;
  case 6:
    state = imain_window.button_zero_6_pressed;
    imain_window.button_zero_6_pressed = false;
    return state;
  case 7:
    state = imain_window.button_zero_7_pressed;
    imain_window.button_zero_7_pressed = false;
    return state;
  default:
    state = imain_window.button_zero_0_pressed;
    imain_window.button_zero_0_pressed = false;
    return state;
  }
}

// get imain_window.button_span_n_pressed and acknowledge
bool button_span_pressed_ack(unsigned int index)
{
  bool state = false;
  switch (index)
  {
  case 0:
    state = imain_window.button_span_0_pressed;
    imain_window.button_span_0_pressed = false;
    return state;
  case 1:
    state = imain_window.button_span_1_pressed;
    imain_window.button_span_1_pressed = false;
    return state;
  case 2:
    state = imain_window.button_span_2_pressed;
    imain_window.button_span_2_pressed = false;
    return state;
  case 3:
    state = imain_window.button_span_3_pressed;
    imain_window.button_span_3_pressed = false;
    return state;
  case 4:
    state = imain_window.button_span_4_pressed;
    imain_window.button_span_4_pressed = false;
    return state;
  case 5:
    state = imain_window.button_span_5_pressed;
    imain_window.button_span_5_pressed = false;
    return state;
  case 6:
    state = imain_window.button_span_6_pressed;
    imain_window.button_span_6_pressed = false;
    return state;
  case 7:
    state = imain_window.button_span_7_pressed;
    imain_window.button_span_7_pressed = false;
    return state;
  default:
    state = imain_window.button_span_0_pressed;
    imain_window.button_span_0_pressed = false;
    return state;
  }
}

int init_imain_window(unsigned int num_sensor_ch)
{
  Color_t text_color;
  Color_t text_highlight_color;
  Color_t background_color;
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
  
  // Set the font family for each sensor data label
  for(unsigned int i = 0; i < imain_window.num_sensors; i++) {
    char *dest = (char *)g_malloc0(MAX_FONT_FAMILY_LEN);
    if (NULL == dest) {
      g_printerr("init_imain_window(): 0737 Failed to allocate memory for destination %d\n", i);
      return -1;
    }
    memcpy(dest, (const void*)&appearance_config.data_display_font_family[0], MAX_FONT_FAMILY_LEN);

    char **font_family_ptr = (char **)((char *)&imain_window.data_display_label_sensor_raw[0].font_attrib.font_family + i * sizeof(Data_Display_Label_t));
    *font_family_ptr = dest;

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

    char **font_family_ptr = (char **)((char *)&imain_window.data_display_label_sensor_pv0.font_attrib.font_family + i * sizeof(Data_Display_Label_t));
    *font_family_ptr = dest;

    set_data_display_label_sensor_pv_font_size(i, appearance_config.data_display_font_size);
    set_data_display_label_sensor_pv_font_weight(i, DEFAULT_DATA_DISP_FONT_WEIGHT);
  }
  
  // Set the channel labels text
  for(unsigned int i = 0; i < imain_window.num_sensors; i++) {
    sprintf(str_buf, "%s %u", DEFAULT_CH_LABEL, i);
    set_channel_label(i, (const char*)str_buf);
  }
  
  return 0;
}

void cleanup_imain_window(void)
{
  for(unsigned int i = 0; i < imain_window.num_sensors; i++) {
    char **font_family_ptr = (char **)((char *)&imain_window.data_display_label_sensor_raw[0].font_attrib.font_family + i * sizeof(Data_Display_Label_t));
    if (*font_family_ptr != NULL) {
      g_free(*font_family_ptr);
      *font_family_ptr = NULL;
    }
  }
  for(unsigned int i = 0; i < imain_window.num_sensors; i++) {
    char **font_family_ptr = (char **)((char *)&imain_window.data_display_label_sensor_pv0.font_attrib.font_family + i * sizeof(Data_Display_Label_t));
    if (*font_family_ptr != NULL) {
      g_free(*font_family_ptr);
      *font_family_ptr = NULL;
    }
  }
  g_print("imain-window cleanup\r\n");
}
/**
  End of file
*/
