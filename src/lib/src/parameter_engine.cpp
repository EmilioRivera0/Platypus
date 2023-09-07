// necessary imports -------->
#include "../headers/exceptions.h"
#include "../headers/parameter_engine.h"

// function declaration -------->
const char* get_parameters(int argc, char *argv[]){
  // local variables declaration
  const char* file_name = NULL;
  // iterate through all parameters searching for the filename
  for (size_t it = 1; it < argc; it++) {
    // check if source file name is correct
    if (std::regex_match(argv[it],std::regex("(.*)(.jec)"))) {
      file_name = argv[it];
      std::cout << "Correct File Name." << std::endl;
    }
  }
  if (file_name == NULL) {
    throw exc::FileName();
  }
  return file_name;
}
