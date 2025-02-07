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
#include "util.h"
#include "config.h"
#include "imain-window.h"
#include "gui.h"
#include "struct.h"
#include "control.h"

extern Param_t param; // Import from struct.c

timer_t timebase_timerid;

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

  if (10 == count) { // One second (10 * 100ms) has passed
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

