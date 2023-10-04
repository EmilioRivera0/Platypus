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
    i++;
    temp_c_ptr = strtok(line_buffer, " ");

    // get token
    while (temp_c_ptr != nullptr)
    {
      // Buscar los inicios de subtokens

      // lexical analyzer code ...
      // regex_match(input, e)
      std::cout << "line: " << i << " : " << temp_c_ptr << std::endl;

      temp_c_ptr = strtok(nullptr, " ");
    }
  }

  std::cout << "Done" << std::endl;
}
