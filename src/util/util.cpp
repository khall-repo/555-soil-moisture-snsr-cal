/**
 * @file util.cpp
 * @brief Utility functions for the 555 soil moisture sensor calibration
 * @date 02-06-2025 Happy birthday Dad you glorious old bastard
 * @par The utility functions for the 555 soil moisture sensor calibration
 * project.
 */
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include "config.h"
#include "util.h"

const std::vector<std::string> allowed_font_families = {
  "FreeMono",
  "FreeSans",
  "FreeSerif",
  "PibotoLT",
  "LiberationMono",
  "LiberationSans",
  "LiberationSerif",
  "NimbusMonoPS",
  "NimbusRoman"
};

// not used yet
const std::vector<std::string> allowed_font_weights = {
  "bold",
  "normal"
};

/**
 * @brief Convert double to string, with precision adjust
 * @param val - Double value to convert
 * @param precision - Number of decimal places to display
 * @return String representation of the double value
 */
std::string dtos(double val, unsigned int precision)
{
  std::ostringstream out;
  out << std::fixed << std::setprecision(precision) << val;
  return out.str();
}

/**
 * @brief Clear terminal screen
 * @param none
 * @return none
 */
void clear_terminal_screen(void)
{
    std::cout << "\033[2J\033[H";
}

/**
 * @brief Verify font family string is valid
 * @param font_family - Font family string to verify
 * @return true if font family is valid, false otherwise
 */
 bool is_font_family_valid(const char *font_family)
 {
  for (const auto &family : allowed_font_families) {
    if(0 == std::strcmp(family.c_str(), font_family)) {
      return true;
    }
  }
  return 0;
}
