// necessary includes -------->
#include <regex>
#include "../headers/exceptions.h"
#include "../headers/file_operations.h"

// function definition -------->
std::ifstream open_jec_file(const char* file_name){
  // local variable declaration
  std::ifstream source_file;
  // check if source file name is correct
  if (std::regex_match(file_name,std::regex("(.*)(.jec)"))) {
    std::cout << "Correct File Name." << std::endl;
    // open file and check if operation was successful
    source_file.open(file_name);
    if (source_file.is_open()) {
      std::cout << "File Opened Successfully" << std::endl;
      return source_file;
    }
    else{
      throw exc::FileNotOpened();
    }
  }else{
    throw exc::FileName();
    //exception thrown
  }
  return source_file;
}
