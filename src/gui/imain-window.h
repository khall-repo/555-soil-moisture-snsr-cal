#ifndef IMAIN_WINDOW_H
#define IMAIN_WINDOW_H

#include <stdbool.h>
#include <glib.h>

#define MAX_COL_HEADER_STR_SZ   16u
#define MAX_SENSOR_DATA_DISP_SZ 16u

typedef struct _INainWindow
{
  char col_header_sensor_raw[MAX_COL_HEADER_STR_SZ];
  char col_header_sensor_pv[MAX_COL_HEADER_STR_SZ];

  char data_display_label_sensor_raw0[MAX_SENSOR_DATA_DISP_SZ];
  char data_display_label_sensor_raw1[MAX_SENSOR_DATA_DISP_SZ];
  char data_display_label_sensor_raw2[MAX_SENSOR_DATA_DISP_SZ];
  char data_display_label_sensor_raw3[MAX_SENSOR_DATA_DISP_SZ];
  char data_display_label_sensor_raw4[MAX_SENSOR_DATA_DISP_SZ];
  char data_display_label_sensor_raw5[MAX_SENSOR_DATA_DISP_SZ];
  char data_display_label_sensor_raw6[MAX_SENSOR_DATA_DISP_SZ];
  char data_display_label_sensor_raw7[MAX_SENSOR_DATA_DISP_SZ];
  char data_display_label_sensor_pv0[MAX_SENSOR_DATA_DISP_SZ];
  char data_display_label_sensor_pv1[MAX_SENSOR_DATA_DISP_SZ];
  char data_display_label_sensor_pv2[MAX_SENSOR_DATA_DISP_SZ];
  char data_display_label_sensor_pv3[MAX_SENSOR_DATA_DISP_SZ];
  char data_display_label_sensor_pv4[MAX_SENSOR_DATA_DISP_SZ];
  char data_display_label_sensor_pv5[MAX_SENSOR_DATA_DISP_SZ];
  char data_display_label_sensor_pv6[MAX_SENSOR_DATA_DISP_SZ];
  char data_display_label_sensor_pv7[MAX_SENSOR_DATA_DISP_SZ];

  struct _data_display_label_sensor_raw0_color { 
    guint16 red; guint16 green; guint16 blue;
  }data_display_label_sensor_raw0_color;
  char data_display_label_sensor_raw1[MAX_SENSOR_DATA_DISP_SZ];
  struct _data_display_label_sensor_raw1_color { 
    guint16 red; guint16 green; guint16 blue;
  }data_display_label_sensor_raw1_color;
  char data_display_label_sensor_raw2[MAX_SENSOR_DATA_DISP_SZ];
  struct _data_display_label_sensor_raw2_color { 
    guint16 red; guint16 green; guint16 blue;
  }data_display_label_sensor_raw2_color;
  
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
bool button_zero_pressed(unsigned int index);
bool button_span_pressed(unsigned int index);
bool button_zero_pressed_ack(unsigned int index);
bool button_span_pressed_ack(unsigned int index);

#endif

/**
 * End of file
 */