// necessary imports -------->
#include "../headers/lexical_analysis.h"
#include <regex>
#include <vector>

void lexical_analysis(std::ifstream &source_file)
{
  std::cout << "\nLexical scanning..." << std::endl;
  // local variables declaration
  char line_buffer[LINE_BUFFER_SIZE]{""};
  char *temp_c_ptr{nullptr};

  // Regular expressions
  std::vector<std::regex> regular_expressions = {
      // number
      std::regex("([-])?([0-9])+([.]([0-9])+)?"),

      // identifier
      std::regex("([_])?([a-z]|[A-Z])([_]|[a-z]|[A-Z]|[0-9])*"),

      // reserved words
      std::regex("(NUM|IF|CMT|ST(X|R)|A(ND|RR)|OR|E(IF|LS)|TOF|[$](DEF|LIB)|LUP|RTN|PTR|FUN)"),

      // logical operators
      std::regex("(([|][|])|(&&)|(==)|(!=)|(<!>)|(<->)|(<|>)(=)?)"),

      // asignation
      std::regex("(=|<-)"),

      // arithmetical operators
      std::regex("([*]|[+]|/|-|%|:(D|/|\\]|\\(|)|:\\))"),

      // symbols
      std::regex("(\\(|\\)|\\{|\\}|\\[|\\]|\\;)")};

  int i = 0;
  // get line
  while (source_file.getline(line_buffer, LINE_BUFFER_SIZE))
  {

    temp_c_ptr = strtok(line_buffer, " ");

    // get token
    while (temp_c_ptr != nullptr)
    {

      // search for subtokens inside each token pointed by temp_c_ptr
      subtokens_vec.push_back(temp_c_ptr);
      token_it = temp_c_ptr;
      while (*token_it != '\000')
      {
        token_buffer[index] = *token_it;

        token_it++;
        index++;
      }

      // lexical analyzer code ...

      temp_c_ptr = strtok(nullptr, " ");
    }
  }
}
