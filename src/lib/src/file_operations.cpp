// necessary includes -------->
#include "../headers/exceptions.h"
#include "../headers/file_operations.h"

// function definition -------->
std::ifstream open_jec_file(const char* file_name){
  // local variable declaration
  std::ifstream source_file;
  // open file and check if operation was successful
  source_file.open(file_name);
  if (source_file.is_open()) {
    std::cout << "File Opened Successfully" << std::endl;
  }else{
    throw exc::FileNotOpened();
  }
  return source_file;
}
