/**
 * @file struct.cpp
 * @brief Data structures for the 555 soil moisture sensor calibration
 * @par (C) 2025 Keith Hall
 */
#include <iostream>
#include "config.h"
#include "struct.h"
#include "config-file.h"

extern Config_File *config_file; // Import from main.cpp

Param_t param;
Analog_Input_t analog_input[MAX_SENSORS];

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

  set_param_from_config_file(); // set test values
}