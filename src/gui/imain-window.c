#include <cstring>
#include "imain-window.h"

IMainWindow imain_window;

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
const char *get_data_display_label_sensor_raw(unsigned int index)
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

// set imain_window.col_header_sensor_raw
void set_data_display_label_sensor_raw(unsigned int index, const char *text)
{
  switch (index)
  {
  case 0:
    strncpy(imain_window.data_display_label_sensor_raw0.label_text, text, MAX_SENSOR_DATA_DISP_SZ);
    imain_window.data_display_label_sensor_raw0.update_text = true;
    break;
  case 1:
    strncpy(imain_window.data_display_label_sensor_raw1.label_text, text, MAX_SENSOR_DATA_DISP_SZ);
    imain_window.data_display_label_sensor_raw1.update_text = true;
    break;
  case 2:
    strncpy(imain_window.data_display_label_sensor_raw2.label_text, text, MAX_SENSOR_DATA_DISP_SZ);
    imain_window.data_display_label_sensor_raw2.update_text = true;
    break;
  case 3:
    strncpy(imain_window.data_display_label_sensor_raw3.label_text, text, MAX_SENSOR_DATA_DISP_SZ);
    imain_window.data_display_label_sensor_raw3.update_text = true;
    break;
  case 4:
    strncpy(imain_window.data_display_label_sensor_raw4.label_text, text, MAX_SENSOR_DATA_DISP_SZ);
    imain_window.data_display_label_sensor_raw4.update_text = true;
    break;
  case 5:
    strncpy(imain_window.data_display_label_sensor_raw5.label_text, text, MAX_SENSOR_DATA_DISP_SZ);
    imain_window.data_display_label_sensor_raw5.update_text = true;
    break;
  case 6:
    strncpy(imain_window.data_display_label_sensor_raw6.label_text, text, MAX_SENSOR_DATA_DISP_SZ);
    imain_window.data_display_label_sensor_raw6.update_text = true;
    break;
  case 7:
    strncpy(imain_window.data_display_label_sensor_raw7.label_text, text, MAX_SENSOR_DATA_DISP_SZ);
    imain_window.data_display_label_sensor_raw7.update_text = true;
    break;
  default:
    g_printerr("imain-window set_data_display_label_sensor_raw(): Bad index\n");
    break;
  }
}

// set imain_window.data_display_label_sensor_pv
void set_data_display_label_sensor_pv(unsigned int index, const char *text)
{
  switch (index)
  {
  case 0:
    strncpy(imain_window.data_display_label_sensor_pv0.label_text, text, MAX_SENSOR_DATA_DISP_SZ);
    imain_window.data_display_label_sensor_pv0.update_text = true;
    break;
  case 1:
    strncpy(imain_window.data_display_label_sensor_pv1.label_text, text, MAX_SENSOR_DATA_DISP_SZ);
    imain_window.data_display_label_sensor_pv1.update_text = true;
    break;
  case 2:
    strncpy(imain_window.data_display_label_sensor_pv2.label_text, text, MAX_SENSOR_DATA_DISP_SZ);
    imain_window.data_display_label_sensor_pv2.update_text = true;
    break;
  case 3:
    strncpy(imain_window.data_display_label_sensor_pv3.label_text, text, MAX_SENSOR_DATA_DISP_SZ);
    imain_window.data_display_label_sensor_pv3.update_text = true;
    break;
  case 4:
    strncpy(imain_window.data_display_label_sensor_pv4.label_text, text, MAX_SENSOR_DATA_DISP_SZ);
    imain_window.data_display_label_sensor_pv4.update_text = true;
    break;
  case 5:
    strncpy(imain_window.data_display_label_sensor_pv5.label_text, text, MAX_SENSOR_DATA_DISP_SZ);
    imain_window.data_display_label_sensor_pv5.update_text = true;
    break;
  case 6:
    strncpy(imain_window.data_display_label_sensor_pv6.label_text, text, MAX_SENSOR_DATA_DISP_SZ);
    imain_window.data_display_label_sensor_pv6.update_text = true;
    break;
  case 7:
    strncpy(imain_window.data_display_label_sensor_pv7.label_text, text, MAX_SENSOR_DATA_DISP_SZ);
    imain_window.data_display_label_sensor_pv7.update_text = true;
    break;
  default:
    g_printerr("imain-window set_data_display_label_sensor_pv(): Bad index\n");
    break;
  }
}

void set_data_display_label_sensor_raw_fg_color(unsigned int index, guint16 red, guint16 green, guint16 blue)
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
}

void set_data_display_label_sensor_raw_bg_color(unsigned int index, guint16 red, guint16 green, guint16 blue)
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




// get the update text flag and acknowledge
bool get_update_text_raw_ack(unsigned int index)
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

bool get_update_foreground_color_raw_ack(unsigned int index)
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
}

bool get_update_background_color_raw_ack(unsigned int index)
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

/**
  End of file
*/