/**
 * @file main.cpp
 * @brief Main program file for the 555 soil moisture sensor calibration
 * @par (C) 2025 Keith Hall
 * Output PV (Present Value) scale is 0 to 100 of arbitrary units we made up,
 * we've decided on calling them ST units (IYKYK).
 */
#include <iostream>
#include <wiringPi.h>
#include <mcp3004.h>
#include "config.h"
#include "config-file.h"
#include "struct.h"
#include "cal.h"
#include "gui.h"
#include "control.h"

#define MCP3008_PINBASE   100
#define MCP3008_0_SPI_CHAN  0

extern Param_t param; // Import from struct.cpp

Config_File *config_file = NULL;

/**
 * @brief Pretend to capture a bunch of zero and span readings, then calculate
 * the offsets and slopes
 * @param none
 * @return none
 */
void cal_test(void)
{
  std::cout << "Calibration test" << '\n';
  for(int i = 0; i < MAX_SENSORS; i++) {
    do_zero(i);
    do_span(i);
    std::cout << "sensor_offset[" << i << "] = " << param.sensor_offset[i] << '\n';
    std::cout << "sensor_slope[" << i << "] = " << param.sensor_slope[i] << '\n';
  }
  std::cout << '\n';
}

/**
 * @brief Calculate the present value of passed sensor number
 * @param sensor_num - the sensor number to calculate the present value for
 * @return the present value reading of the sensor
 */
double pv_calc(int sensor_num)
{
  return (param.sensor_raw[sensor_num] - param.sensor_offset[sensor_num]) / param.sensor_slope[sensor_num];
}

void pv_test(void)
{
  std::cout << "Present value calc test" << '\n';
  for(int i = 0; i < MAX_SENSORS; i++) {
    std::cout << "sensor_raw[" << i << "] = " << param.sensor_raw[i] << '\n';
    std::cout << "sensor_pv[" << i << "] = " << pv_calc(i) << '\n';
  }
}

/**
 * @brief Main program entry point
 * @return 0 if success, -1 if error
 */
int main(int argc, char *argv[])
{
  (void)argc; // not used yet
  (void)argv; // not used yet

  // Read the config file
  config_file = new Config_File();
  if(config_file->read_config_file() != 0) {
    std::cerr << "Error reading config file" << '\n';
    return -1;
  }
  init_param();

  if (wiringPiSetup() == -1) {
    std::cerr << "Failed to initialize WiringPi" << '\n';
    return -1;
  }

  if (mcp3004Setup(MCP3008_PINBASE, MCP3008_0_SPI_CHAN) == -1) {
    std::cerr << "Failed to initialize MCP3008" << '\n';
    return -1;
  }
  //cal_test();
  //pv_test();
  
  if(0 != timebase_start()) {
    return -1;
  }

  int status = run_gui_application(argc, argv);
  return status;
}