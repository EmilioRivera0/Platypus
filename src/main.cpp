// necessary includes -------->
#include "lib/headers/file_operations.h"
#include "lib/headers/parameter_engine.h"

// program entry point -------->
int main (int argc, char *argv[]) {
  // program variables
  std::ifstream source_code_file;
  try {
    source_code_file = open_jec_file(get_parameters(argc,argv));
  }
  catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
    
  }
  return 0;
}
