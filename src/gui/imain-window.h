#ifndef IMAIN_WINDOW_H
#define IMAIN_WINDOW_H

#include <stdbool.h>

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

const char *get_col_header_sensor_raw(void);
const char *get_col_header_sensor_pv(void);
const char *get_data_display_label_sensor_raw0(void);
const char *get_data_display_label_sensor_raw1(void);
const char *get_data_display_label_sensor_raw2(void);
const char *get_data_display_label_sensor_raw3(void);
const char *get_data_display_label_sensor_raw4(void);
const char *get_data_display_label_sensor_raw5(void);
const char *get_data_display_label_sensor_raw6(void);
const char *get_data_display_label_sensor_raw7(void);
const char *get_data_display_label_sensor_pv0(void);
const char *get_data_display_label_sensor_pv1(void);
const char *get_data_display_label_sensor_pv2(void);
const char *get_data_display_label_sensor_pv3(void);
const char *get_data_display_label_sensor_pv4(void);
const char *get_data_display_label_sensor_pv5(void);
const char *get_data_display_label_sensor_pv6(void);
const char *get_data_display_label_sensor_pv7(void);

void set_data_display_label_sensor_raw0(const char *text);
void set_data_display_label_sensor_raw1(const char *text);
void set_data_display_label_sensor_raw2(const char *text);
void set_data_display_label_sensor_raw3(const char *text);
void set_data_display_label_sensor_raw4(const char *text);
void set_data_display_label_sensor_raw5(const char *text);
void set_data_display_label_sensor_raw6(const char *text);
void set_data_display_label_sensor_raw7(const char *text);
void set_data_display_label_sensor_pv0(const char *text);
void set_data_display_label_sensor_pv1(const char *text);
void set_data_display_label_sensor_pv2(const char *text);
void set_data_display_label_sensor_pv3(const char *text);
void set_data_display_label_sensor_pv4(const char *text);
void set_data_display_label_sensor_pv5(const char *text);
void set_data_display_label_sensor_pv6(const char *text);
void set_data_display_label_sensor_pv7(const char *text);

bool button_zero_0_pressed(void);
bool button_zero_1_pressed(void);
bool button_zero_2_pressed(void);
bool button_zero_3_pressed(void);
bool button_zero_4_pressed(void);
bool button_zero_5_pressed(void);
bool button_zero_6_pressed(void);
bool button_zero_7_pressed(void);

bool button_span_0_pressed(void);
bool button_span_1_pressed(void);
bool button_span_2_pressed(void);
bool button_span_3_pressed(void);
bool button_span_4_pressed(void);
bool button_span_5_pressed(void);
bool button_span_6_pressed(void);
bool button_span_7_pressed(void);

bool button_zero_0_pressed_ack(void);
bool button_zero_1_pressed_ack(void);
bool button_zero_2_pressed_ack(void);
bool button_zero_3_pressed_ack(void);
bool button_zero_4_pressed_ack(void);
bool button_zero_5_pressed_ack(void);
bool button_zero_6_pressed_ack(void);
bool button_zero_7_pressed_ack(void);

bool button_span_0_pressed_ack(void);
bool button_span_1_pressed_ack(void);
bool button_span_2_pressed_ack(void);
bool button_span_3_pressed_ack(void);
bool button_span_4_pressed_ack(void);
bool button_span_5_pressed_ack(void);
bool button_span_6_pressed_ack(void);
bool button_span_7_pressed_ack(void);

#endif