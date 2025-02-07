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
#include "config.h"
#include "util.h"

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