#ifndef IMAIN_WINDOW_H
#define IMAIN_WINDOW_H

#include <stdbool.h>
#include <glib.h>

#define MAX_COL_HEADER_STR_SZ   16u
#define MAX_SENSOR_DATA_DISP_SZ 16u

typedef struct _Color_t
{
  guint16 red;
  guint16 green;
  guint16 blue;
}Color_t;

typedef struct _Data_Display_Label_t
{
  char label_text[MAX_SENSOR_DATA_DISP_SZ] = {0};
  bool update_text = false;
  Color_t foreground_color = {0,0,0};
  bool update_foreground_color = false;
  Color_t background_color = {0,0,0};
  bool update_background_color = false;
}Data_Display_Label_t;

typedef struct _IMainWindow
{
  Data_Display_Label_t col_header_sensor_raw;
  Data_Display_Label_t col_header_sensor_pv;
  Data_Display_Label_t data_display_label_sensor_raw0;
  Data_Display_Label_t data_display_label_sensor_raw1;
  Data_Display_Label_t data_display_label_sensor_raw2;
  Data_Display_Label_t data_display_label_sensor_raw3;
  Data_Display_Label_t data_display_label_sensor_raw4;
  Data_Display_Label_t data_display_label_sensor_raw5;
  Data_Display_Label_t data_display_label_sensor_raw6;
  Data_Display_Label_t data_display_label_sensor_raw7;
  Data_Display_Label_t data_display_label_sensor_pv0;
  Data_Display_Label_t data_display_label_sensor_pv1;
  Data_Display_Label_t data_display_label_sensor_pv2;
  Data_Display_Label_t data_display_label_sensor_pv3;
  Data_Display_Label_t data_display_label_sensor_pv4;
  Data_Display_Label_t data_display_label_sensor_pv5;
  Data_Display_Label_t data_display_label_sensor_pv6;
  Data_Display_Label_t data_display_label_sensor_pv7;
  
  bool button0; // bottom button

  bool button_zero_0_pressed; // first column of buttons
  bool button_zero_1_pressed;
  bool button_zero_2_pressed;
  bool button_zero_3_pressed;
  bool button_zero_4_pressed;
  bool button_zero_5_pressed;
  bool button_zero_6_pressed;
  bool button_zero_7_pressed;

  bool button_span_0_pressed; // second column of buttons
  bool button_span_1_pressed;
  bool button_span_2_pressed;
  bool button_span_3_pressed;
  bool button_span_4_pressed;
  bool button_span_5_pressed;
  bool button_span_6_pressed;
  bool button_span_7_pressed;

} IMainWindow;

const char *get_data_display_label_sensor_raw(unsigned int index);
const char *get_data_display_label_sensor_pv(unsigned int index);

void set_data_display_label_sensor_raw(unsigned int index, const char *text);
void set_data_display_label_sensor_pv(unsigned int index, const char *text);

void set_data_display_label_sensor_raw_fg_color(unsigned int index, guint16 red, guint16 green, guint16 blue);
void set_data_display_label_sensor_raw_bg_color(unsigned int index, guint16 red, guint16 green, guint16 blue);
void set_data_display_label_sensor_pv_fg_color(unsigned int index, guint16 red, guint16 green, guint16 blue);
void set_data_display_label_sensor_pv_bg_color(unsigned int index, guint16 red, guint16 green, guint16 blue);

bool get_update_text_raw_ack(unsigned int index);
bool get_update_text_pv_ack(unsigned int index);
bool get_update_foreground_color_raw_ack(unsigned int index);
bool get_update_background_color_raw_ack(unsigned int index);
bool get_update_foreground_color_pv_ack(unsigned int index);
bool get_update_background_color_pv_ack(unsigned int index);

bool button_zero_pressed(unsigned int index);
bool button_span_pressed(unsigned int index);
bool button_zero_pressed_ack(unsigned int index);
bool button_span_pressed_ack(unsigned int index);

#endif

/**
 * End of file
 */