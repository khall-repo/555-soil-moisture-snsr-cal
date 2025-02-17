/**
 * @file config.h
 * @brief Configuration header for the 555 soil moisture sensor calibration
 * program
 * @par (C) 2025 Keith Hall
 */
#ifndef CONFIG_H
#define CONFIG_H

#include <glib.h>

// Path to window resource files. It's relative to the current working
// directory. The bin should be ran from the project root directory.
#define PATH_TO_MAIN_WIN_RESOURCE "./src/gui/resource/main-window.ui"
#define PATH_TO_SUB_WIN_RESOURCE "./src/gui/resource/sub-window.ui"

#define MAX_CONFIG_SECTIONS 64u
#define CONFIG_INI_FILE_PATH "config.ini"

#define MAX_SENSORS 16
#define TEST_CAL_RAW_VALUES_FILE_PATH     "test-cal-raw-values.txt"
#define TEST_READING_RAW_VALUES_FILE_PATH "test-reading-raw-values.txt"

#define MCP3008_PINBASE   100
#define MCP3008_0_SPI_CHAN  0

#define VREF    (double)3300.0
#define ADC_MAX (double)1024.0

#define FILTER            (double) 15.0 // normal filter
#define BIG_JUMP          (double) 50.0 // if the raw value jumps by this amount
                                        // then use this filter number (i.e.
                                        // relax the filtering for big jumps)
#define MID_JUMP          (double) 25.0
#define SMALL_JUMP        (double) 10.0
#define MAX_FILTER  (unsigned int) 25
#define MIN_FILTER  (unsigned int) 1

#define MAX_FONT_FAMILY_LEN 64u // should be more than enough
#define MAX_FONT_SIZE 32
#define DEFAULT_DATA_DISP_FONT_FAMILY "LiberationMono"
#define DEFAULT_DATA_DISP_FONT_SIZE 10
#define DEFAULT_DATA_DISP_FONT_WEIGHT PANGO_WEIGHT_NORMAL
#define DEFAULT_LABEL_CH "Channel"
#define DEFAULT_LABEL_TAB0 "Ch 0-7"
#define DEFAULT_LABEL_TAB1 "Ch 8-15"

#define DEFAULT_NO_ALARM_BG_DCOLOR_R  (double)1.0  // white
#define DEFAULT_NO_ALARM_BG_DCOLOR_G  (double)1.0
#define DEFAULT_NO_ALARM_BG_DCOLOR_B  (double)1.0
#define DEFAULT_HI_ALARM_BG_DCOLOR_R  (double)0.82 // red
#define DEFAULT_HI_ALARM_BG_DCOLOR_G  (double)0.0
#define DEFAULT_HI_ALARM_BG_DCOLOR_B  (double)0.0
#define DEFAULT_MID_ALARM_BG_DCOLOR_R (double)1.0 // orange
#define DEFAULT_MID_ALARM_BG_DCOLOR_G (double)0.7
#define DEFAULT_MID_ALARM_BG_DCOLOR_B (double)0.0
#define DEFAULT_LO_ALARM_BG_DCOLOR_R  (double)0.9  // yellow
#define DEFAULT_LO_ALARM_BG_DCOLOR_G  (double)0.9
#define DEFAULT_LO_ALARM_BG_DCOLOR_B  (double)0.0
#define DEFAULT_FLT_ALARM_BG_DCOLOR_R (double)0.82 // red
#define DEFAULT_FLT_ALARM_BG_DCOLOR_G (double)0.0
#define DEFAULT_FLT_ALARM_BG_DCOLOR_B (double)0.0

#define DEFAULT_NO_ALARM_BG_COLOR16_R  (guint16)(DEFAULT_NO_ALARM_BG_DCOLOR_R*65535)
#define DEFAULT_NO_ALARM_BG_COLOR16_G  (guint16)(DEFAULT_NO_ALARM_BG_DCOLOR_G*65535)
#define DEFAULT_NO_ALARM_BG_COLOR16_B  (guint16)(DEFAULT_NO_ALARM_BG_DCOLOR_B*65535)
#define DEFAULT_HI_ALARM_BG_COLOR16_R  (guint16)(DEFAULT_HI_ALARM_BG_DCOLOR_R*65535)
#define DEFAULT_HI_ALARM_BG_COLOR16_G  (guint16)(DEFAULT_HI_ALARM_BG_DCOLOR_G*65535)
#define DEFAULT_HI_ALARM_BG_COLOR16_B  (guint16)(DEFAULT_HI_ALARM_BG_DCOLOR_B*65535)
#define DEFAULT_MID_ALARM_BG_COLOR16_R (guint16)(DEFAULT_MID_ALARM_BG_DCOLOR_R*65535)
#define DEFAULT_MID_ALARM_BG_COLOR16_G (guint16)(DEFAULT_MID_ALARM_BG_DCOLOR_G*65535)
#define DEFAULT_MID_ALARM_BG_COLOR16_B (guint16)(DEFAULT_MID_ALARM_BG_DCOLOR_B*65535)
#define DEFAULT_LO_ALARM_BG_COLOR16_R  (guint16)(DEFAULT_LO_ALARM_BG_DCOLOR_R*65535)
#define DEFAULT_LO_ALARM_BG_COLOR16_G  (guint16)(DEFAULT_LO_ALARM_BG_DCOLOR_G*65535)
#define DEFAULT_LO_ALARM_BG_COLOR16_B  (guint16)(DEFAULT_LO_ALARM_BG_DCOLOR_B*65535)
#define DEFAULT_FLT_ALARM_BG_COLOR16_R (guint16)(DEFAULT_FLT_ALARM_BG_DCOLOR_R*65535)
#define DEFAULT_FLT_ALARM_BG_COLOR16_G (guint16)(DEFAULT_FLT_ALARM_BG_DCOLOR_G*65535)
#define DEFAULT_FLT_ALARM_BG_COLOR16_B (guint16)(DEFAULT_FLT_ALARM_BG_DCOLOR_B*65535)


#define DEFAULT_NO_ALARM_FG_DCOLOR_R  (double)0.0  // black
#define DEFAULT_NO_ALARM_FG_DCOLOR_G  (double)0.0
#define DEFAULT_NO_ALARM_FG_DCOLOR_B  (double)0.0
#define DEFAULT_HI_ALARM_FG_DCOLOR_R  (double)1.0 // white
#define DEFAULT_HI_ALARM_FG_DCOLOR_G  (double)1.0
#define DEFAULT_HI_ALARM_FG_DCOLOR_B  (double)1.0
#define DEFAULT_MID_ALARM_FG_DCOLOR_R (double)0.0 // black
#define DEFAULT_MID_ALARM_FG_DCOLOR_G (double)0.0
#define DEFAULT_MID_ALARM_FG_DCOLOR_B (double)0.0
#define DEFAULT_LO_ALARM_FG_DCOLOR_R  (double)0.0  // black
#define DEFAULT_LO_ALARM_FG_DCOLOR_G  (double)0.0
#define DEFAULT_LO_ALARM_FG_DCOLOR_B  (double)0.0
#define DEFAULT_FLT_ALARM_FG_DCOLOR_R (double)0.0 // black
#define DEFAULT_FLT_ALARM_FG_DCOLOR_G (double)0.0
#define DEFAULT_FLT_ALARM_FG_DCOLOR_B (double)0.0
#define DEFAULT_NO_ALARM_FG_COLOR16_R  (guint16)(DEFAULT_NO_ALARM_FG_DCOLOR_R*65535)
#define DEFAULT_NO_ALARM_FG_COLOR16_G  (guint16)(DEFAULT_NO_ALARM_FG_DCOLOR_G*65535)
#define DEFAULT_NO_ALARM_FG_COLOR16_B  (guint16)(DEFAULT_NO_ALARM_FG_DCOLOR_B*65535)
#define DEFAULT_HI_ALARM_FG_COLOR16_R  (guint16)(DEFAULT_HI_ALARM_FG_DCOLOR_R*65535)
#define DEFAULT_HI_ALARM_FG_COLOR16_G  (guint16)(DEFAULT_HI_ALARM_FG_DCOLOR_G*65535)
#define DEFAULT_HI_ALARM_FG_COLOR16_B  (guint16)(DEFAULT_HI_ALARM_FG_DCOLOR_B*65535)
#define DEFAULT_MID_ALARM_FG_COLOR16_R (guint16)(DEFAULT_MID_ALARM_FG_DCOLOR_R*65535)
#define DEFAULT_MID_ALARM_FG_COLOR16_G (guint16)(DEFAULT_MID_ALARM_FG_DCOLOR_G*65535)
#define DEFAULT_MID_ALARM_FG_COLOR16_B (guint16)(DEFAULT_MID_ALARM_FG_DCOLOR_B*65535)
#define DEFAULT_LO_ALARM_FG_COLOR16_R  (guint16)(DEFAULT_LO_ALARM_FG_DCOLOR_R*65535)
#define DEFAULT_LO_ALARM_FG_COLOR16_G  (guint16)(DEFAULT_LO_ALARM_FG_DCOLOR_G*65535)
#define DEFAULT_LO_ALARM_FG_COLOR16_B  (guint16)(DEFAULT_LO_ALARM_FG_DCOLOR_B*65535)
#define DEFAULT_FLT_ALARM_FG_COLOR16_R (guint16)(DEFAULT_FLT_ALARM_FG_DCOLOR_R*65535)
#define DEFAULT_FLT_ALARM_FG_COLOR16_G (guint16)(DEFAULT_FLT_ALARM_FG_DCOLOR_G*65535)
#define DEFAULT_FLT_ALARM_FG_COLOR16_B (guint16)(DEFAULT_FLT_ALARM_FG_DCOLOR_B*65535)

#endif
