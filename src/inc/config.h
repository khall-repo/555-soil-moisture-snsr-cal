/**
 * @file config.h
 * @brief Configuration header for the 555 soil moisture sensor calibration
 * program
 * @par (C) 2025 Keith Hall
 */
#ifndef CONFIG_H
#define CONFIG_H

#define NUM_SENSORS 8
#define TEST_CAL_RAW_VALUES_FILE_PATH     "test-cal-raw-values.txt"
#define TEST_READING_RAW_VALUES_FILE_PATH "test-reading-raw-values.txt"

#define CAL1_PV (double)0      // PV min scale and also the zero point
#define CAL2_PV (double)100.0  // PV max scale and also the span point

#endif