// necessary imports -------->
#include "../headers/lexical_analysis.h"

void lexical_analysis(std::ifstream& source_file){
  // local variables declaration
  char line_buffer[LINE_BUFFER_SIZE]{""};
  char token_buffer[TOKEN_BUFFER_SIZE];
  short int index{0};
  char* temp_c_ptr{nullptr};
  char* token_it{nullptr};
  std::vector<const char*> subtokens_vec{};

  // initialize buffers with cstring end character
  memset(token_buffer, '\000', TOKEN_BUFFER_SIZE);
  
  // gel line
  while (source_file.getline(line_buffer, LINE_BUFFER_SIZE)) {

    temp_c_ptr = strtok(line_buffer, " ");

    // get token
    while (temp_c_ptr != nullptr) {

      // search for subtokens inside each token pointed by temp_c_ptr
      subtokens_vec.push_back(temp_c_ptr);
      token_it = temp_c_ptr;
      while (*token_it != '\000') {
        token_buffer[index] = *token_it;

        token_it++;
        index++;
      }

      // lexical analyzer code ...

      temp_c_ptr = strtok(nullptr, " ");
    }
  }
}
