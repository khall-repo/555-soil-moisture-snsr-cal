/**
 * @file struct.cpp
 * @brief Data structures for the 555 soil moisture sensor calibration
 * @par (C) 2025 Keith Hall
 */
#include <iostream>
#include <cstring>
#include "config.h"
#include "struct.h"
#include "config-file.h"
#include "util.h"

extern Config_File *config_file; // Import from main.cpp

Param_t param;
Analog_Input_t analog_input[MAX_SENSORS];
Appearance_Config_t appearance_config;


/**
 * @brief Set raw and PV values with test values from the config file
 * @param none
 * @return none
 */
void set_param_from_config_file(void)
{
  std::string value;

  if(NULL == config_file) {
    std::cerr << "Error: Config file not initialized" << '\n';
    return;
  }

  value = config_file->get_config_value("param", "num_sensors");
  param.num_sensors = std::stoi(value);

  value = config_file->get_config_value("param", "sensor_min_scale");
  param.sensor_min_scale = std::stod(value);
  value = config_file->get_config_value("param", "sensor_full_scale");
  param.sensor_full_scale = std::stod(value);
  value = config_file->get_config_value("param", "cal1_pv");
  param.sensor_cal1_pv = std::stod(value);
  value = config_file->get_config_value("param", "cal2_pv");
  param.sensor_cal2_pv = std::stod(value);
  value = config_file->get_config_value("param", "hi_alarm");
  param.hi_alarm = std::stod(value);
  value = config_file->get_config_value("param", "mid_alarm");
  param.mid_alarm = std::stod(value);
  value = config_file->get_config_value("param", "lo_alarm");
  param.low_alarm = std::stod(value);
  value = config_file->get_config_value("param", "raw_disp_precision");
  param.raw_disp_precision = std::stoi(value);
  value = config_file->get_config_value("param", "pv_disp_precision");
  param.pv_disp_precision = std::stoi(value);
  value = config_file->get_config_value("param", "adc_num_samples");
  param.adc_num_samples = std::stoi(value);

  value = config_file->get_config_value("param", "testraw0");
  param.sensor_raw[0] = std::stod(value);
  value = config_file->get_config_value("param", "testraw1");
  param.sensor_raw[1] = std::stod(value);
  value = config_file->get_config_value("param", "testraw2");
  param.sensor_raw[2] = std::stod(value);
  value = config_file->get_config_value("param", "testraw3");
  param.sensor_raw[3] = std::stod(value);
  value = config_file->get_config_value("param", "testraw4");
  param.sensor_raw[4] = std::stod(value);
  value = config_file->get_config_value("param", "testraw5");
  param.sensor_raw[5] = std::stod(value);
  value = config_file->get_config_value("param", "testraw6");
  param.sensor_raw[6] = std::stod(value);
  value = config_file->get_config_value("param", "testraw7");
  param.sensor_raw[7] = std::stod(value);

  value = config_file->get_config_value("param", "testpv0");
  param.sensor_pv[0] = std::stod(value);
  value = config_file->get_config_value("param", "testpv1");
  param.sensor_pv[1] = std::stod(value);
  value = config_file->get_config_value("param", "testpv2");
  param.sensor_pv[2] = std::stod(value);
  value = config_file->get_config_value("param", "testpv3");
  param.sensor_pv[3] = std::stod(value);
  value = config_file->get_config_value("param", "testpv4");
  param.sensor_pv[4] = std::stod(value);
  value = config_file->get_config_value("param", "testpv5");
  param.sensor_pv[5] = std::stod(value);
  value = config_file->get_config_value("param", "testpv6");
  param.sensor_pv[6] = std::stod(value);
  value = config_file->get_config_value("param", "testpv7");
  param.sensor_pv[7] = std::stod(value);

  // Load calibration data
  for (unsigned int sensor_num = 0; sensor_num < param.num_sensors; ++sensor_num) {
    value = config_file->get_config_value("calibration", "sensor_offset_" + std::to_string(sensor_num));
    try{
      param.sensor_offset[sensor_num] = std::stod(value);
    } catch (std::exception &e) {
      std::cerr << "Error: " << e.what() << '\n';
      std::cerr << "Error reading sensor offset for sensor: " << sensor_num << '\n';
      std::cerr << "Value: " << value << '\n';
      exit(-1);
    }
    
    value = config_file->get_config_value("calibration", "sensor_slope_" + std::to_string(sensor_num));
    try{
      param.sensor_slope[sensor_num] = std::stod(value);
    } catch (std::exception &e) {
      std::cerr << "Error: " << e.what() << '\n';
      std::cerr << "Error reading sensor slope for sensor: " << sensor_num << '\n';
      std::cerr << "Value: " << value << '\n';
      exit(EXIT_FAILURE);
    }
  }

  // Load appearance data
  value = config_file->get_config_value("appearance", "data_display_font_family");
  if (!is_font_family_valid(value.c_str())) {
    std::cerr << "Error: Invalid font family: " << value << '\n';
    exit(EXIT_FAILURE);
  }
  // check value string length and copy to appearance_config.data_display_font_family if length is less than MAX_FONT_FAMILY_LEN
  if (value.length() < MAX_FONT_FAMILY_LEN) {
    strncpy(appearance_config.data_display_font_family, value.c_str(), value.length());
  } else {
    std::cerr << "Error: Font family string too long: " << value << '\n';
    exit(EXIT_FAILURE);
  }

}

/**
 * @brief Initialize the param structure
 * @param none
 * @return none
 */
void init_param()
{
  // zero out the param structure
  param.num_sensors = 0;
  param.sensor_min_scale = 0.0;
  param.sensor_full_scale = 0.0;
  param.sensor_cal1_pv = 0.0;
  param.sensor_cal2_pv = 0.0;
  param.hi_alarm = 0.0;
  param.mid_alarm = 0.0;
  param.low_alarm = 0.0;
  param.raw_disp_precision = 0;
  param.pv_disp_precision = 0;
  for(int i = 0; i < MAX_SENSORS; i++) {
    param.sensor_raw[i] = 0.0;
    param.sensor_pv[i] = 0.0;
    param.sensor_cal1_raw[i] = 0.0;
    param.sensor_cal2_raw[i] = 0.0;
    param.sensor_slope[i] = 0.0;
    param.sensor_offset[i] = 0.0;
  }

  // zero out analog input structure
  for(int i = 0; i < MAX_SENSORS; i++) {
    analog_input[i].adc_val = 0;
    analog_input[i].accum_adc = 0;
    analog_input[i].sample_num = 0;
    analog_input[i].unfiltered_mv = 0.0;
    analog_input[i].filtered_mv = 0.0;
  }

  memset(&appearance_config, 0, sizeof(Appearance_Config_t));
  strncpy(appearance_config.data_display_font_family, DEFAULT_DATA_DISP_FONT_FAMILY, std::strlen(DEFAULT_DATA_DISP_FONT_FAMILY)+1);

  set_param_from_config_file(); // set test values
}
