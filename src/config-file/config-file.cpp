/**
 * @file config-file.cpp
 * @brief Code to read an ini style configuration file, without using someone
 * else's library
 * @par (C) 2025 Keith Hall
 */
#include <iostream>
#include <fstream>
#include "config.h"
#include "config-file.h"

/// @brief Config_Section Constructor
Config_Section::Config_Section()
{
  num_elements = 0;
}

/// @brief Config_Section Destructor
Config_Section::~Config_Section()
{
  config_section.close();
}

/**
 * @brief Read a configuration file section, ignoring comments
 * @param none
 * @return 0 if success, -1 if error
 */
int Config_Section::read_config_section(void)
{
  std::string line;
  while (std::getline(config_section, line)) {
    // done if blank line or new line
    if(("" == line) || ("\n" == line)) {
      break;
    }
    // Ignore comments starting with '#'
    if(line[0] == '#') {
      continue;
    }
    // Remove comment text from line after ';' char
    std::string::size_type pos = line.find(";");
    if(pos != std::string::npos) {
      line = line.substr(0, pos);
    }
    
    // Split line into key and value
    std::string key;
    std::string value;

    pos = line.find("=");
    if(pos != std::string::npos) {
      key = line.substr(0, pos);
      value = line.substr(pos + 1);
      config_value_map[key] = value;
      num_elements++;
    }
  }
  return 0;
}

/// @brief Config_File constructor
Config_File::Config_File()
{
  num_sections = 0;
  config_section_map.clear();

  try{
    config_file.open(CONFIG_INI_FILE_PATH);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    return;
  }
  if(!config_file.is_open()) {
    std::cerr << "Error opening file" << '\n';
    return;
  }
  
  if(read_config_file() != 0) {
    std::cerr << "Error reading config file" << '\n';
    return;
  }

  // debug messages to follow:
  std::cout << "Config file read successfully" << '\n';
  //std::cout << "Number of sections: " << num_sections << '\n';

  //for(auto const& section : config_section_map) {
  //  std::cout << "Section: " << section.first << '\n';
  //  for(auto const& key : section.second) {
  //    std::cout << "  Key: " << key.first << " Value: " << key.second << '\n';
  //  }
  //}
  // end debug messages

  config_file.close();
}

/**
 * @brief Locate all of the sections in the configuration file
 * @param none
 * @return 0 if success, -1 if error
 */
int Config_File::read_config_file(void)
{
  std::string line;

  while (std::getline(config_file, line)) {
    // done if eof
    if(config_file.eof()) {
      break;
    }
    // Ignore comments starting with '#'
    if(line[0] == '#') {
      continue;
    }
    // Remove comment text from line after ';' char
    std::string::size_type pos = line.find(";");
    if(pos != std::string::npos) {
      line = line.substr(0, pos);
    }

    std::string section;

    // find the section name
    pos = line.find("[");
    if(pos != std::string::npos) {
      section = line.substr(pos + 1);
      pos = section.find("]");
      if(pos != std::string::npos) {
        section = section.substr(0, pos);
        
        // create a new section object, seek to current file pos with tellg(),
        // and read the section
        Config_Section *config_section = new Config_Section();
        config_section->config_section.open(CONFIG_INI_FILE_PATH);
        config_section->config_section.seekg(config_file.tellg(), std::ios::cur);

        if(config_section->read_config_section() != 0) {
          std::cerr << "Error reading config section" << '\n';
          return -1;
        }        
        config_section_map[section] = config_section->config_value_map;
        num_sections++;
      }
    }
  }
  return 0;
}

/// @brief Get a configuration value from a section
/// @param section - the section to get the value from
/// @param key - the key to get the value for
/// @return the value for the key in the section
std::string Config_File::get_config_value(std::string section, std::string key)
{
  return config_section_map[section][key];
}