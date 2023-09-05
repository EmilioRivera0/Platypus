// necessary includes -------->
#include "lib/headers/file_operations.h"

// program entry point -------->
int main (int argc, char *argv[]) {
  // program variables
  std::ifstream source_code_file;
  try {
    source_code_file = open_jec_file(argv[1]);
  }
  catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
    
  }
  return 0;
}
