/**
 * @file struct.cpp
 * @brief Data structures for the 555 soil moisture sensor calibration
 * @par (C) 2025 Keith Hall
 */
#include <iostream>
#include "config.h"
#include "struct.h"

Param_t param;

/**
 * @brief Initialize the param structure
 * @param none
 * @return none
 */
void init_param()
{
  for(int i = 0; i < NUM_SENSORS; i++) {
    param.sensor_min_scale[i] = 0.0;
    param.sensor_full_scale[i] = 0.0;
    param.sensor_raw[i] = 0.0;
    param.sensor_pv[i] = 0.0;
    param.sensor_cal1_raw[i] = 0.0;
    param.sensor_cal2_raw[i] = 0.0;
    param.sensor_cal1_pv[i] = CAL1_PV;
    param.sensor_cal2_pv[i] = CAL2_PV;
    param.sensor_slope[i] = 0.0;
    param.sensor_offset[i] = 0.0;
    param.hi_alarm = 0.0;`
  }
}