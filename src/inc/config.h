/**
 * @file config.h
 * @brief Configuration header for the 555 soil moisture sensor calibration
 * program
 * @par (C) 2025 Keith Hall
 */
#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <fstream>
#include <map>
#include <string>

#define MAX_CONFIG_SECTIONS 64u
#define CONFIG_INI_FILE_PATH "config.ini"

#define NUM_SENSORS 8
#define TEST_CAL_RAW_VALUES_FILE_PATH     "test-cal-raw-values.txt"
#define TEST_READING_RAW_VALUES_FILE_PATH "test-reading-raw-values.txt"

#define CAL1_PV (double)0      // PV min scale and also the zero point
#define CAL2_PV (double)100.0  // PV max scale and also the span point

class Config_Section {
  friend class Config;
  public:
    Config_Section();
    ~Config_Section();
    int read_config_section(void);
    std::string get_config_section_value(std::string key);
  private:
    
    int num_elements; // I think I only need this for debug
    std::ifstream config_section;
    std::map<std::string, std::string> config_value_map;
};

class Config {
  public:
    Config();
    ~Config();
    int read_config_file(void);
    std::string get_config_value(std::string section, std::string key);
  private:
    std::ifstream config_file;
    int num_sections; // I think I only need this for debug
    std::map<std::string, std::map<std::string, std::string>> config_section_map;
};

#endif