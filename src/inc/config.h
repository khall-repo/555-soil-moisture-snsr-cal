/**
 * @file config.h
 * @brief Configuration header for the 555 soil moisture sensor calibration
 * program
 * @par (C) 2025 Keith Hall
 */
#ifndef CONFIG_H
#define CONFIG_H

/*#include <iostream>
#include <fstream>
#include <map>
#include <string>*/

// Path to window resource files. It's relative to the current working
// directory. The bin should be ran from the project root directory.
#define PATH_TO_MAIN_WIN_RESOURCE "./src/gui/resource/main-window.ui"
#define PATH_TO_SUB_WIN_RESOURCE "./src/gui/resource/sub-window.ui"

#define MAX_CONFIG_SECTIONS 64u
#define CONFIG_INI_FILE_PATH "config.ini"

#define MAX_SENSORS 8
#define TEST_CAL_RAW_VALUES_FILE_PATH     "test-cal-raw-values.txt"
#define TEST_READING_RAW_VALUES_FILE_PATH "test-reading-raw-values.txt"

#endif