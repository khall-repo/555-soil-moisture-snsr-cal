/**
 * @brief Read the configuration file and populate the config_map
 * @param none
 * @return none
 */
int read_config_file(void)
{
  std::cout << "Reading configuration file" << '\n';
  // Read the configuration file and populate the config_map
  
  try{
    config_file.open(CONFIG_INI_FILE_PATH);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    return -1;
  }
  if(!config_file.is_open()) {
    std::cerr << "Error opening file" << '\n';
    return -1;
  }

  std::cout << "End of reading configuration file" << '\n';
}