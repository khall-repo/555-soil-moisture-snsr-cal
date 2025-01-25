/**
 * @file test-values.cpp
 * @brief Code to read test values from text files in lieu of actual sensor readings
 * @par (C) 2025 Keith Hall
 */
#ifndef TEST_VALUES_H
#define TEST_VALUES_H

int test_values_init(void);

int read_cal_raw_test_values(void);
double get_cal_raw_test_value(int i);
std::string get_cal_raw_test_value_str(int i);
int get_cal_raw_test_value_count(void);

int read_reading_raw_test_values(void);
double get_reading_raw_test_value(int i);
std::string get_reading_raw_test_value_str(int i);
int get_reading_raw_test_value_count(void);

#endif