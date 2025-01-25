/**
 * @file struct.cpp
 * @brief Data structures for the 555 soil moisture sensor calibration
 * @par (C) 2025 Keith Hall
 */
#ifndef STRUCT_H
#define STRUCT_H

struct Param_t {
    double sensor_min_scale[NUM_SENSORS];
    double sensor_full_scale[NUM_SENSORS];
    double sensor_raw[NUM_SENSORS];
    double sensor_pv[NUM_SENSORS];
    double sensor_cal1_raw[NUM_SENSORS];
    double sensor_cal2_raw[NUM_SENSORS];
    double sensor_cal1_pv[NUM_SENSORS];
    double sensor_cal2_pv[NUM_SENSORS];
    double sensor_slope[NUM_SENSORS];
    double sensor_offset[NUM_SENSORS];
    double hi_alarm;
    double mid_alarm;
    double low_alarm;
};

void init_param();

#endif