// necessary imports -------->
#include "../headers/lexical_analysis.h"

void lexical_analysis(std::ifstream& source_file){
  // local variables declaration
  char line_buffer[LINE_BUFFER_SIZE]{""};
  char* temp_c_ptr{nullptr};
  
  // gel line
  while (source_file.getline(line_buffer, LINE_BUFFER_SIZE)) {

    temp_c_ptr = strtok(line_buffer, " ");

    // get token
    while (temp_c_ptr != nullptr) {

      // lexical analyzer code ...

      temp_c_ptr = strtok(nullptr, " ");
    }
  }
}
