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
const char *get_data_display_label_sensor_raw0(void)
{
  return (const char *)imain_window.data_display_label_sensor_raw0;
}

// get imain_window.data_display_label_sensor_raw1
const char *get_data_display_label_sensor_raw1(void)
{
  return (const char *)imain_window.data_display_label_sensor_raw1;
}

// get imain_window.data_display_label_sensor_raw2
const char *get_data_display_label_sensor_raw2(void)
{
  return (const char *)imain_window.data_display_label_sensor_raw2;
}

// get imain_window.data_display_label_sensor_raw3
const char *get_data_display_label_sensor_raw3(void)
{
  return (const char *)imain_window.data_display_label_sensor_raw3;
}

// get imain_window.data_display_label_sensor_raw4
const char *get_data_display_label_sensor_raw4(void)
{
  return (const char *)imain_window.data_display_label_sensor_raw4;
}

// get imain_window.data_display_label_sensor_raw5
const char *get_data_display_label_sensor_raw5(void)
{
  return (const char *)imain_window.data_display_label_sensor_raw5;
}

// get imain_window.data_display_label_sensor_raw6
const char *get_data_display_label_sensor_raw6(void)
{
  return (const char *)imain_window.data_display_label_sensor_raw6;
}

// get imain_window.data_display_label_sensor_raw7
const char *get_data_display_label_sensor_raw7(void)
{
  return (const char *)imain_window.data_display_label_sensor_raw7;
}

// get imain_window.data_display_label_sensor_pv0
const char *get_data_display_label_sensor_pv0(void)
{
  return (const char *)imain_window.data_display_label_sensor_pv0;
}

// get imain_window.data_display_label_sensor_pv1
const char *get_data_display_label_sensor_pv1(void)
{
  return (const char *)imain_window.data_display_label_sensor_pv1;
}

// get imain_window.data_display_label_sensor_pv2
const char *get_data_display_label_sensor_pv2(void)
{
  return (const char *)imain_window.data_display_label_sensor_pv2;
}

// get imain_window.data_display_label_sensor_pv3
const char *get_data_display_label_sensor_pv3(void)
{
  return (const char *)imain_window.data_display_label_sensor_pv3;
}

// get imain_window.data_display_label_sensor_pv4
const char *get_data_display_label_sensor_pv4(void)
{
  return imain_window.data_display_label_sensor_pv4;
}

// get imain_window.data_display_label_sensor_pv5
const char *get_data_display_label_sensor_pv5(void)
{
  return imain_window.data_display_label_sensor_pv5;
}

// get imain_window.data_display_label_sensor_pv6
const char *get_data_display_label_sensor_pv6(void)
{
  return imain_window.data_display_label_sensor_pv6;
}

// get imain_window.data_display_label_sensor_pv7 
const char *get_data_display_label_sensor_pv7(void)
{
  return imain_window.data_display_label_sensor_pv7;
}

// set imain_window.data_display_label_sensor_raw0
void set_data_display_label_sensor_raw0(const char *text)
{
  strncpy(imain_window.data_display_label_sensor_raw0, text, MAX_SENSOR_DATA_DISP_SZ);
}

// set imain_window.data_display_label_sensor_raw1
void set_data_display_label_sensor_raw1(const char *text)
{
  strncpy(imain_window.data_display_label_sensor_raw1, text, MAX_SENSOR_DATA_DISP_SZ);
}

// set imain_window.data_display_label_sensor_raw2
void set_data_display_label_sensor_raw2(const char *text)
{
  strncpy(imain_window.data_display_label_sensor_raw2, text, MAX_SENSOR_DATA_DISP_SZ);
}

// set imain_window.data_display_label_sensor_raw3
void set_data_display_label_sensor_raw3(const char *text)
{
  strncpy(imain_window.data_display_label_sensor_raw3, text, MAX_SENSOR_DATA_DISP_SZ);
}

// set imain_window.data_display_label_sensor_raw4
void set_data_display_label_sensor_raw4(const char *text)
{
  strncpy(imain_window.data_display_label_sensor_raw4, text, MAX_SENSOR_DATA_DISP_SZ);
}

// set imain_window.data_display_label_sensor_raw5
void set_data_display_label_sensor_raw5(const char *text)
{
  strncpy(imain_window.data_display_label_sensor_raw5, text, MAX_SENSOR_DATA_DISP_SZ);
}

// set imain_window.data_display_label_sensor_raw6
void set_data_display_label_sensor_raw6(const char *text)
{
  strncpy(imain_window.data_display_label_sensor_raw6, text, MAX_SENSOR_DATA_DISP_SZ);
}

// set imain_window.data_display_label_sensor_raw7
void set_data_display_label_sensor_raw7(const char *text)
{
  strncpy(imain_window.data_display_label_sensor_raw7, text, MAX_SENSOR_DATA_DISP_SZ);
}

// set imain_window.data_display_label_sensor_pv0
void set_data_display_label_sensor_pv0(const char *text)
{
  strncpy(imain_window.data_display_label_sensor_pv0, text, MAX_SENSOR_DATA_DISP_SZ);
}

// set imain_window.data_display_label_sensor_pv1
void set_data_display_label_sensor_pv1(const char *text)
{
  strncpy(imain_window.data_display_label_sensor_pv1, text, MAX_SENSOR_DATA_DISP_SZ);
}

// set imain_window.data_display_label_sensor_pv2
void set_data_display_label_sensor_pv2(const char *text)
{
  strncpy(imain_window.data_display_label_sensor_pv2, text, MAX_SENSOR_DATA_DISP_SZ);
}

// set imain_window.data_display_label_sensor_pv3
void set_data_display_label_sensor_pv3(const char *text)
{
  strncpy(imain_window.data_display_label_sensor_pv3, text, MAX_SENSOR_DATA_DISP_SZ);
}

// set imain_window.data_display_label_sensor_pv4
void set_data_display_label_sensor_pv4(const char *text)
{
  strncpy(imain_window.data_display_label_sensor_pv4, text, MAX_SENSOR_DATA_DISP_SZ);
}

// set imain_window.data_display_label_sensor_pv5
void set_data_display_label_sensor_pv5(const char *text)
{
  strncpy(imain_window.data_display_label_sensor_pv5, text, MAX_SENSOR_DATA_DISP_SZ);
}

// set imain_window.data_display_label_sensor_pv6
void set_data_display_label_sensor_pv6(const char *text)
{
  strncpy(imain_window.data_display_label_sensor_pv6, text, MAX_SENSOR_DATA_DISP_SZ);
}

// set imain_window.data_display_label_sensor_pv7
void set_data_display_label_sensor_pv7(const char *text)
{
  strncpy(imain_window.data_display_label_sensor_pv7, text, MAX_SENSOR_DATA_DISP_SZ);
}

// get imain_window.button_zero_0_pressed
bool button_zero_0_pressed(void)
{
  return imain_window.button_zero_0_pressed;
}

// get imain_window.button_zero_1_pressed
bool button_zero_1_pressed(void)
{
  return imain_window.button_zero_1_pressed;
}

// get imain_window.button_zero_2_pressed
bool button_zero_2_pressed(void)
{
  return imain_window.button_zero_2_pressed;
}

// get imain_window.button_zero_3_pressed
bool button_zero_3_pressed(void)
{
  return imain_window.button_zero_3_pressed;
}

// get imain_window.button_zero_4_pressed
bool button_zero_4_pressed(void)
{
  return imain_window.button_zero_4_pressed;
}

// get imain_window.button_zero_5_pressed
bool button_zero_5_pressed(void)
{
  return imain_window.button_zero_5_pressed;
}

// get imain_window.button_zero_6_pressed
bool button_zero_6_pressed(void)
{
  return imain_window.button_zero_6_pressed;
}

// get imain_window.button_zero_7_pressed
bool button_zero_7_pressed(void)
{
  return imain_window.button_zero_7_pressed;
}

// get imain_window.button_span_0_pressed
bool button_span_0_pressed(void)
{
  return imain_window.button_span_0_pressed;
}

// get imain_window.button_span_1_pressed
bool button_span_1_pressed(void)
{
  return imain_window.button_span_1_pressed;
}

// get imain_window.button_span_2_pressed
bool button_span_2_pressed(void)
{
  return imain_window.button_span_2_pressed;
}

// get imain_window.button_span_3_pressed
bool button_span_3_pressed(void)
{
  return imain_window.button_span_3_pressed;
}

// get imain_window.button_span_4_pressed
bool button_span_4_pressed(void)
{
  return imain_window.button_span_4_pressed;
}

// get imain_window.button_span_5_pressed
bool button_span_5_pressed(void)
{
  return imain_window.button_span_5_pressed;
}

// get imain_window.button_span_6_pressed
bool button_span_6_pressed(void)
{
  return imain_window.button_span_6_pressed;
}

// get imain_window.button_span_7_pressed
bool button_span_7_pressed(void)
{
  return imain_window.button_span_7_pressed;
}

// get imain_window.button_zero_0_pressed and acknowledge
bool button_zero_0_pressed_ack(void)
{
  bool state = imain_window.button_zero_0_pressed;
  imain_window.button_zero_0_pressed = false;
  return state;
}

// get imain_window.button_zero_1_pressed and acknowledge
bool button_zero_1_pressed_ack(void)
{
  bool state = imain_window.button_zero_1_pressed;
  imain_window.button_zero_1_pressed = false;
  return state;
}

// get imain_window.button_zero_2_pressed and acknowledge
bool button_zero_2_pressed_ack(void)
{
  bool state = imain_window.button_zero_2_pressed;
  imain_window.button_zero_2_pressed = false;
  return state;
}

// get imain_window.button_zero_3_pressed and acknowledge
bool button_zero_3_pressed_ack(void)
{
  bool state = imain_window.button_zero_3_pressed;
  imain_window.button_zero_3_pressed = false;
  return state;
}

// get imain_window.button_zero_4_pressed and acknowledge
bool button_zero_4_pressed_ack(void)
{
  bool state = imain_window.button_zero_4_pressed;
  imain_window.button_zero_4_pressed = false;
  return state;
}

// get imain_window.button_zero_5_pressed and acknowledge
bool button_zero_5_pressed_ack(void)
{
  bool state = imain_window.button_zero_5_pressed;
  imain_window.button_zero_5_pressed = false;
  return state;
}

// get imain_window.button_zero_6_pressed and acknowledge
bool button_zero_6_pressed_ack(void)
{
  bool state = imain_window.button_zero_6_pressed;
  imain_window.button_zero_6_pressed = false;
  return state;
}

// get imain_window.button_zero_7_pressed and acknowledge
bool button_zero_7_pressed_ack(void)
{
  bool state = imain_window.button_zero_7_pressed;
  imain_window.button_zero_7_pressed = false;
  return state;
}

// get imain_window.button_span_0_pressed and acknowledge
bool button_span_0_pressed_ack(void)
{
  bool state = imain_window.button_span_0_pressed;
  imain_window.button_span_0_pressed = false;
  return state;
}

// get imain_window.button_span_1_pressed and acknowledge
bool button_span_1_pressed_ack(void)
{
  bool state = imain_window.button_span_1_pressed;
  imain_window.button_span_1_pressed = false;
  return state;
}

// get imain_window.button_span_2_pressed and acknowledge
bool button_span_2_pressed_ack(void)
{
  bool state = imain_window.button_span_2_pressed;
  imain_window.button_span_2_pressed = false;
  return state;
}

// get imain_window.button_span_3_pressed and acknowledge
bool button_span_3_pressed_ack(void)
{
  bool state = imain_window.button_span_3_pressed;
  imain_window.button_span_3_pressed = false;
  return state;
}

// get imain_window.button_span_4_pressed and acknowledge
bool button_span_4_pressed_ack(void)
{
  bool state = imain_window.button_span_4_pressed;
  imain_window.button_span_4_pressed = false;
  return state;
}

// get imain_window.button_span_5_pressed and acknowledge
bool button_span_5_pressed_ack(void)
{
  bool state = imain_window.button_span_5_pressed;
  imain_window.button_span_5_pressed = false;
  return state;
}

// get imain_window.button_span_6_pressed and acknowledge
bool button_span_6_pressed_ack(void)
{
  bool state = imain_window.button_span_6_pressed;
  imain_window.button_span_6_pressed = false;
  return state;
}

// get imain_window.button_span_7_pressed and acknowledge
bool button_span_7_pressed_ack(void)
{
  bool state = imain_window.button_span_7_pressed;
  imain_window.button_span_7_pressed = false;
  return state;
}