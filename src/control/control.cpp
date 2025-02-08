/**
 * @file control.cpp
 * @brief Control for the 555 soil moisture sensor calibration
 * @date 01-29-2025
 * @par The timebase and control code for the 555 soil moisture sensor
 * calibration project.
 */
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <signal.h>
#include <time.h>
#include <math.h>
#include <wiringPi.h>
#include <mcp3004.h>
#include "util.h"
#include "config.h"
#include "imain-window.h"
#include "gui.h"
#include "struct.h"
#include "control.h"

extern Param_t param; // Import from struct.c
extern Analog_Input_t analog_input[MAX_SENSORS]; // Import from struct.c

timer_t timebase_timerid;

/**
 * @brief Read and print raw values from all 8 channels of the MCP3008
 * @param none
 * @return none
 */
void mcp3008_read_all_print(void)
{
  for (unsigned int channel = 0; channel < param.num_sensors; ++channel) {
    int value = analogRead(MCP3008_PINBASE + channel);
    std::cout << "Ch " << channel << ": " << value << '\n';
  }
}

/**
 * @brief Read MCP3008 ADC values and convert to millivolts
 * @param none
 * @return none
 */
void mcp3008_read_raw_mv_all(void)
{
  for (unsigned int channel = 0; channel < param.num_sensors; ++channel) {
    int value = analogRead(MCP3008_PINBASE + channel);
    param.sensor_raw[channel] = VREF * (double)value / ADC_MAX;
  }
}

/**
 * @brief Print all sensor raw values
 * @param none
 * @return none
 */
void print_all_sensor_raw(void)
{
  for (unsigned int channel = 0; channel < param.num_sensors; ++channel) {
    std::cout << "Ch " << channel << ": " << param.sensor_raw[channel] << " mV" << '\n';
  }
}

/**
 * @brief Update the main window sensor raw signal display boxes
 * @param none
 * @return none
 */
void update_sensor_raw_display(void)
{
  set_data_display_label_sensor_raw0(dtos(param.sensor_raw[0], param.raw_disp_precision).c_str());
  set_data_display_label_sensor_raw1(dtos(param.sensor_raw[1], param.raw_disp_precision).c_str());
  set_data_display_label_sensor_raw2(dtos(param.sensor_raw[2], param.raw_disp_precision).c_str());
  set_data_display_label_sensor_raw3(dtos(param.sensor_raw[3], param.raw_disp_precision).c_str());
  set_data_display_label_sensor_raw4(dtos(param.sensor_raw[4], param.raw_disp_precision).c_str());
  set_data_display_label_sensor_raw5(dtos(param.sensor_raw[5], param.raw_disp_precision).c_str());
  set_data_display_label_sensor_raw6(dtos(param.sensor_raw[6], param.raw_disp_precision).c_str());
  set_data_display_label_sensor_raw7(dtos(param.sensor_raw[7], param.raw_disp_precision).c_str());
}

/**
 * @brief Update the main window sensor PV display boxes
 * @param none
 * @return none
 */
void update_pv_display(void)
{
  set_data_display_label_sensor_pv0(dtos(param.sensor_pv[0], param.pv_disp_precision).c_str());
  set_data_display_label_sensor_pv1(dtos(param.sensor_pv[1], param.pv_disp_precision).c_str());
  set_data_display_label_sensor_pv2(dtos(param.sensor_pv[2], param.pv_disp_precision).c_str());
  set_data_display_label_sensor_pv3(dtos(param.sensor_pv[3], param.pv_disp_precision).c_str());
  set_data_display_label_sensor_pv4(dtos(param.sensor_pv[4], param.pv_disp_precision).c_str());
  set_data_display_label_sensor_pv5(dtos(param.sensor_pv[5], param.pv_disp_precision).c_str());
  set_data_display_label_sensor_pv6(dtos(param.sensor_pv[6], param.pv_disp_precision).c_str());
  set_data_display_label_sensor_pv7(dtos(param.sensor_pv[7], param.pv_disp_precision).c_str());
}

/**
 * @brief Calculate millivolts from ADC value
 * @param adc_val - ADC output value
 * @return ADC output value converted to millivolts
 */
double calc_mv(int adc_val)
{
  return VREF * (double)adc_val / ADC_MAX;
}

double calc_filtered_mv(double unfiltered_mv, double last_filtered_mv)
{
  double jump;
  double filtera;
  jump = fabs(last_filtered_mv - unfiltered_mv); // calculate difference between filter in and out

	if (jump > BIG_JUMP)  // set filter based on jump - for big jumps the filter is relaxed 
		filtera = (double) param.ewma_filter / 8.0;

	else if (jump > MID_JUMP)  // for middle jumps the filter is less relaxed than for big jumps
		filtera = (double) param.ewma_filter / 4.0;

	else if (jump > SMALL_JUMP)	// for small jumps the filter is less relaxed than for middle jumps
		filtera = (double) param.ewma_filter / 1.5;

	else
		filtera = (double) param.ewma_filter;

	if (filtera < 1.0)		// dFilterA CANNOT BE LESS THAN 1 TO AVOID GETTING A NEGATIVE FILTER VALUE
		filtera = 1.0;

	filtera = (filtera - 1.0) / filtera; // get filter ready for use

	return filtera * last_filtered_mv  + (1.0-filtera) * unfiltered_mv;	// apply the EWMA filter
}

/**
 * @brief Read and average ADC output values and update the analog input 
 * structure
 * @param none
 * @return none 
 */
void update_analog_input(void)
{
  for (unsigned int channel = 0; channel < param.num_sensors; ++channel) {
    analog_input[channel].adc_val = analogRead(MCP3008_PINBASE + channel);
    analog_input[channel].accum_adc += analog_input[channel].adc_val;
    if(param.adc_num_samples == ++analog_input[channel].sample_num) {
      analog_input[channel].unfiltered_mv = 
        calc_mv(analog_input[channel].accum_adc / param.adc_num_samples);
      analog_input[channel].filtered_mv = 
        calc_filtered_mv(analog_input[channel].unfiltered_mv, analog_input[channel].filtered_mv);
      analog_input[channel].accum_adc = 0.0;
      analog_input[channel].sample_num = 0;
    }
  }
}

/**
 * @brief Update param structure live data
 * @param none
 * @return none 
 */
void update_param(void)
{
  for (unsigned int channel = 0; channel < param.num_sensors; ++channel) {
    param.sensor_raw[channel] = analog_input[channel].filtered_mv;
  }
}

/**
 * @brief Program timebase handler
 * @param signum - Signal number
 * @param *info - Signal information
 * @param *context - Signal context
 * @return none
 * @note This function is called every 100 milliseconds
 */
void timebase_handler(int signum, siginfo_t *info, void *context)
{
  static int count = 0;

  // .1 second tasks
  update_analog_input();

  // 1 second tasks
  if (10 == count) {
    // Terminal update
    clear_terminal_screen();
    update_param();
    print_all_sensor_raw();
    // Main window update
    update_sensor_raw_display();
    update_pv_display();
    count = 0;
  }
  ++count;
}

/**
 * @brief Start program timebase timer
 * @param val - none
 * @return 0 if success, -1 if error
 * @note To delete timer:
 *   if (timer_delete(timebase_timerid) == -1) {
 *    perror("timer_delete error");
 *    exit(EXIT_FAILURE);
 *   }
 */
int timebase_start(void)
{
  struct sigaction sa;
  struct sigevent sev;
  struct itimerspec its;

  // Install timebase_handler as the signal handler for SIGALRM
  sa.sa_flags = SA_SIGINFO;
  sa.sa_sigaction = timebase_handler;
  sigemptyset(&sa.sa_mask);
  if (sigaction(SIGALRM, &sa, NULL) == -1) {
    std::cerr << "sigaction error" << '\n';
    return -1;
  }

  // Create the timer
  sev.sigev_notify = SIGEV_SIGNAL;
  sev.sigev_signo = SIGALRM;
  sev.sigev_value.sival_ptr = &timebase_timerid;
  if (timer_create(CLOCK_REALTIME, &sev, &timebase_timerid) == -1) {
    std::cerr << "timer_create error" << '\n';
    return -1;
  }

  // Start the timer with a period of 100 milliseconds
  its.it_value.tv_sec = 0;
  its.it_value.tv_nsec = 100000000; // 100 milliseconds
  its.it_interval.tv_sec = 0;
  its.it_interval.tv_nsec = 100000000; // 100 milliseconds
  if (timer_settime(timebase_timerid, 0, &its, NULL) == -1) {
    std::cerr << "timer_settime error" << '\n';
    return -1;
  }
  return 0;
}

