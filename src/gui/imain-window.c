#include <cstring>
#include "imain-window.h"

IMainWindow imain_window;

// get imain_window.col_header_sensor_raw
const char *get_col_header_sensor_raw(void)
{
  return (const char *)imain_window.col_header_sensor_raw;
}

// get imain_window.col_header_sensor_pv
const char *get_col_header_sensor_pv(void)
{
  return (const char *)imain_window.col_header_sensor_pv;
}

// get imain_window.data_display_label_sensor_raw0
const char *get_data_display_label_sensor_raw(unsigned int index)
{
  switch (index)
  {
  case 0:
    return (const char *)imain_window.data_display_label_sensor_raw0;
  case 1:
    return (const char *)imain_window.data_display_label_sensor_raw1;
  case 2:
    return (const char *)imain_window.data_display_label_sensor_raw2;
  case 3:
    return (const char *)imain_window.data_display_label_sensor_raw3;
  case 4:
    return (const char *)imain_window.data_display_label_sensor_raw4;
  case 5:
    return (const char *)imain_window.data_display_label_sensor_raw5;
  case 6:
    return (const char *)imain_window.data_display_label_sensor_raw6;
  case 7:
    return (const char *)imain_window.data_display_label_sensor_raw7;
  default:
    return (const char *)imain_window.data_display_label_sensor_raw0;
  }
}

// get imain_window.data_display_label_sensor_pv
const char *get_data_display_label_sensor_pv(unsigned int index)
{
  switch (index)
  {
  case 0:
    return (const char *)imain_window.data_display_label_sensor_pv0;
  case 1:
    return (const char *)imain_window.data_display_label_sensor_pv1;
  case 2:
    return (const char *)imain_window.data_display_label_sensor_pv2;
  case 3:
    return (const char *)imain_window.data_display_label_sensor_pv3;
  case 4:
    return (const char *)imain_window.data_display_label_sensor_pv4;
  case 5:
    return (const char *)imain_window.data_display_label_sensor_pv5;
  case 6:
    return (const char *)imain_window.data_display_label_sensor_pv6;
  case 7:
    return (const char *)imain_window.data_display_label_sensor_pv7;
  default:
    return (const char *)imain_window.data_display_label_sensor_pv0;
  }
}

// set imain_window.col_header_sensor_raw
void set_data_display_label_sensor_raw(unsigned int index, const char *text)
{
  switch (index)
  {
  case 0:
    strncpy(imain_window.data_display_label_sensor_raw0, text, MAX_SENSOR_DATA_DISP_SZ);
    break;
  case 1:
    strncpy(imain_window.data_display_label_sensor_raw1, text, MAX_SENSOR_DATA_DISP_SZ);
    break;
  case 2:
    strncpy(imain_window.data_display_label_sensor_raw2, text, MAX_SENSOR_DATA_DISP_SZ);
    break;
  case 3:
    strncpy(imain_window.data_display_label_sensor_raw3, text, MAX_SENSOR_DATA_DISP_SZ);
    break;
  case 4:
    strncpy(imain_window.data_display_label_sensor_raw4, text, MAX_SENSOR_DATA_DISP_SZ);
    break;
  case 5:
    strncpy(imain_window.data_display_label_sensor_raw5, text, MAX_SENSOR_DATA_DISP_SZ);
    break;
  case 6:
    strncpy(imain_window.data_display_label_sensor_raw6, text, MAX_SENSOR_DATA_DISP_SZ);
    break;
  case 7:
    strncpy(imain_window.data_display_label_sensor_raw7, text, MAX_SENSOR_DATA_DISP_SZ);
    break;
  default:
    strncpy(imain_window.data_display_label_sensor_raw0, text, MAX_SENSOR_DATA_DISP_SZ);
    break;
  }
}

// set imain_window.data_display_label_sensor_pv
void set_data_display_label_sensor_pv(unsigned int index, const char *text)
{
  switch (index)
  {
  case 0:
    strncpy(imain_window.data_display_label_sensor_pv0, text, MAX_SENSOR_DATA_DISP_SZ);
    break;
  case 1:
    strncpy(imain_window.data_display_label_sensor_pv1, text, MAX_SENSOR_DATA_DISP_SZ);
    break;
  case 2:
    strncpy(imain_window.data_display_label_sensor_pv2, text, MAX_SENSOR_DATA_DISP_SZ);
    break;
  case 3:
    strncpy(imain_window.data_display_label_sensor_pv3, text, MAX_SENSOR_DATA_DISP_SZ);
    break;
  case 4:
    strncpy(imain_window.data_display_label_sensor_pv4, text, MAX_SENSOR_DATA_DISP_SZ);
    break;
  case 5:
    strncpy(imain_window.data_display_label_sensor_pv5, text, MAX_SENSOR_DATA_DISP_SZ);
    break;
  case 6:
    strncpy(imain_window.data_display_label_sensor_pv6, text, MAX_SENSOR_DATA_DISP_SZ);
    break;
  case 7:
    strncpy(imain_window.data_display_label_sensor_pv7, text, MAX_SENSOR_DATA_DISP_SZ);
    break;
  default:
    strncpy(imain_window.data_display_label_sensor_pv0, text, MAX_SENSOR_DATA_DISP_SZ);
    break;
  }
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