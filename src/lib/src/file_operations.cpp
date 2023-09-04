// necessary includes -------->
#include <iostream>
#include <fstream>
#include <ostream>
#include <regex>

// function definition -------->
void open_jec_file(const char* file_name){
  // check if source file name is correct
  if (std::regex_match(file_name,std::regex("(.*)(.jec)"))) {
    std::cout << "Correct File Name." << std::endl;
    // open file and check if operation was successful
    std::ifstream source_file(file_name);
    if (source_file.is_open()) {
      std::cout << "File Opened Successfully" << std::endl;
    }
  }
}
