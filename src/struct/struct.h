/**
 * @file struct.h
 * @brief Data structures for the 555 soil moisture sensor calibration
 * @par (C) 2025 Keith Hall
 */
#ifndef STRUCT_H
#define STRUCT_H

#include "config.h"

/// @brief Sensor parameter structure typedef
typedef struct _Param_t {
  unsigned int num_sensors;
  double sensor_min_scale;
  double sensor_full_scale;
  double sensor_cal1_pv;
  double sensor_cal2_pv;
  double hi_alarm;
  double mid_alarm;
  double low_alarm;
  unsigned int raw_disp_precision;
  unsigned int pv_disp_precision;
  unsigned int adc_num_samples; // number of samples to average
  unsigned int ewma_filter;     // exponential weighted moving average filter val
  double sensor_raw[MAX_SENSORS];
  double sensor_pv[MAX_SENSORS];
  double sensor_cal1_raw[MAX_SENSORS];
  double sensor_cal2_raw[MAX_SENSORS];
  double sensor_slope[MAX_SENSORS];
  double sensor_offset[MAX_SENSORS];
}Param_t;

/// @brief Analog input structure typedef
typedef struct _Analog_Input_t {
  int adc_val;
  int accum_adc;
  unsigned int sample_num;
  double unfiltered_mv;
  double filtered_mv;
}Analog_Input_t;

typedef struct _Appearance_Config_t {
  char data_display_font_family[MAX_FONT_FAMILY_LEN];
  int data_display_font_size;
}Appearance_Config_t;

int init_param();

#endif
