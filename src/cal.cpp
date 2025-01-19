/**
 * @file cal.cpp
 * @brief Calibration functions for the 555 soil moisture sensor
 * @par (C) 2025 Keith Hall
 */
#include <iostream>
#include "config.h"
#include "struct.h"

// Import from struct.cpp
extern Param_t param;

/**
 * @brief Capture a zero calibration raw value
 * @param sensor_num - the sensor number to capture the zero for
 * @return -1 if error, 0 if success
 */
int capture_zero_raw(int sensor_num)
{
  if(NUM_SENSORS < sensor_num){
    return -1;
  }

  param.sensor_cal1_raw[sensor_num] = param.sensor_raw[sensor_num];

  return 0;
}

/**
 * @brief Capture a span calibration raw value
 * @param sensor_num - the sensor number to capture the span raw for
 * @return -1 if error, 0 if success
 */
int capture_span_raw(int sensor_num)
{
  if(NUM_SENSORS < sensor_num){
    return -1;
  }

  param.sensor_cal2_raw[sensor_num] = param.sensor_raw[sensor_num];

  return 0;
}

/**
 * @brief Capture the zero offset for a sensor
 * @param sensor_num - the sensor number to capture the zero offset for
 * @return -1 if error, 0 if success
 */
int do_zero(int sensor_num)
{
  if(NUM_SENSORS < sensor_num){
    return -1;
  }

  param.sensor_offset[sensor_num] = param.sensor_cal1_raw[sensor_num];

  return 0;
}

/**
 * @brief Calculate the calibration slope for a sensor
 * @param sensor_num - the sensor number to calculate the cal slope for
 * @return -1 if error, 0 if success
 */
int do_span(int sensor_num)
{
  if(NUM_SENSORS < sensor_num){
    return -1;
  }
//  std::cout << "Sensor num: " << sensor_num << " Cal1 raw: " << param.sensor_cal1_raw[sensor_num] << " Cal2 raw: " << param.sensor_cal2_raw[sensor_num] << '\n';
//  std::cout << "Cal1 pv: " << param.sensor_cal1_pv[sensor_num] << " Cal2 pv: " << param.sensor_cal2_pv[sensor_num] << '\n';
  param.sensor_slope[sensor_num] = (param.sensor_cal2_raw[sensor_num] - param.sensor_cal1_raw[sensor_num])/(param.sensor_cal2_pv[sensor_num] - param.sensor_cal1_pv[sensor_num]);

  return 0;
}