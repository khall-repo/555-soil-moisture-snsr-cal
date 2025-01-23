/**
 * @file test-values.cpp
 * @brief Code to read test values from text files in lieu of actual sensor readings
 * @par (C) 2025 Keith Hall
 */
#include <iostream>
#include <fstream>
#include <string>
#include "config.h"
#include "test-values.h"

/// @brief Structure to hold a test value and its string representation
typedef struct {
  std::string value_str;
  double value;
} test_value;

test_value test_cal_raw_values[32];
int test_cal_raw_value_count = 0;

test_value test_reading_raw_values[32];
int test_reading_raw_value_count = 0;

/**
 * @brief Init the test values
 * @param none
 * @return -1 if error, 0 if success
 */
int test_values_init(void)
{
  if(read_cal_raw_test_values()){
    return -1;
  }
  if(read_reading_raw_test_values()){
    return -1;
  }
  return 0;
}

/**
 * @brief Read the reading raw test values from a file
 * @param none
 * @return -1 if error, 0 if success
 */
int read_reading_raw_test_values(void)
{
  std::ifstream file;
  try{
    file.open(TEST_READING_RAW_VALUES_FILE_PATH);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    return -1;
  }
  if(!file.is_open()) {
    std::cerr << "Error opening file" << '\n';
    return -1;
  }
  std::string line;
  int i = 0;

  while (std::getline(file, line)) {
    if(("" == line) || ("\n" == line)) {
      break;
    }
    test_reading_raw_values[i].value_str = line;
      i++;
    }
    std::cout << "Test reading raw values count " << i << '\n';
    for(int j = 0; j < i; j++) {
      try{
        test_reading_raw_values[j].value = std::stod(test_reading_raw_values[j].value_str);
      } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        std::cout << "Error converting value " << test_reading_raw_values[j].value_str << " to double" << '\n';
        return -1;
    }
  }
  test_reading_raw_value_count = i;
  return 0;
}

/**
 * @brief Read the calibration raw test values from a file
 * @param none
 * @return -1 if error, 0 if success
 */
int read_cal_raw_test_values(void)
{
  std::ifstream file;
  try{
    file.open(TEST_CAL_RAW_VALUES_FILE_PATH);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    return -1;
  }
  if(!file.is_open()) {
    std::cerr << "Error opening file" << '\n';
    return -1;
  }
  std::string line;
  int i = 0;

  while (std::getline(file, line)) {
    if(("" == line) || ("\n" == line)) {
      break;
    }
    test_cal_raw_values[i].value_str = line;
      i++;
    }
    std::cout << "Test cal raw values count " << i << '\n';
    for(int j = 0; j < i; j++) {
      try{
        test_cal_raw_values[j].value = std::stod(test_cal_raw_values[j].value_str);
      } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        std::cout << "Error converting value " << test_cal_raw_values[j].value_str << " to double" << '\n';
        return -1;
    }
  }
    test_cal_raw_value_count = i;
    return 0;
}

/**
 * @brief Get a stored calibration raw test value
 * @param i - the index of the value to get
 * @return The stored calibration raw test value at index i
 * @par Should only be called after successful read_cal_raw_test_values
 */
double get_cal_raw_test_value(int i)
{
  return test_cal_raw_values[i].value;
}

/**
 * @brief Get a stored calibration raw test value string
 * @param i - the index of the value to get
 * @return The stored calibration raw test value string at index i
 * @par Should only be called after successful read_cal_raw_test_values
 */
std::string get_cal_raw_test_value_str(int i)
{
  return test_cal_raw_values[i].value_str;
}

/**
 * @brief Get count of stored calibration raw test values
 * @param none
 * @return The count of stored calibration raw test values
 */
int get_cal_raw_test_value_count(void)
{
  return test_cal_raw_value_count;
}

/**
 * @brief Get a stored reading raw test value
 * @param i - the index of the value to get
 * @return The stored reading raw test value at index i
 * @par Should only be called after successful read_reading_raw_test_values
 */
double get_reading_raw_test_value(int i)
{
  return test_reading_raw_values[i].value;
}

/**
 * @brief Get a stored reading raw test value string
 * @param i - the index of the value to get
 * @return The stored reading raw test value string at index i
 * @par Should only be called after successful read_reading_raw_test_values
 */
std::string get_reading_raw_test_value_str(int i)
{
  return test_reading_raw_values[i].value_str;
}

/**
 * @brief Get count of stored reading raw test values
 * @param none
 * @return The count of stored reading raw test values
 */
int get_reading_raw_test_value_count(void)
{
  return test_reading_raw_value_count;
}