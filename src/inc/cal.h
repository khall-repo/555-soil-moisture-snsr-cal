/**
 * @file cal.cpp
 * @brief Calibration functions for the 555 soil moisture sensor
 * @par (C) 2025 Keith Hall
 */
#ifndef CAL_H
#define CAL_H

int capture_zero_raw(int sensor_num);
int capture_span_raw(int sensor_num);
int do_zero(int sensor_num);
int do_span(int sensor_num);


#endif