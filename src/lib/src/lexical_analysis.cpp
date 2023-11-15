// necessary imports -------->
#include "../headers/lexical_analysis.h"

void lexical_analysis(std::ifstream &source_file, std::map<std::string, std::string> &symbols_table, std::map<unsigned, std::map<unsigned, char>> &lexical_errors, std::map<unsigned, std::vector<std::string>> &file_tokens)
{
    std::cout << "\nLexical scanning..." << std::endl;

    // Regular expressions
    std::vector<std::regex> regular_expressions = {
        // number
        std::regex("([-])?([0-9])+([.]([0-9])+)?"),
        // reserved words
        std::regex("(NUM|IF|CMT|ST(X|R)|ARR|E(IF|LS)|TOF|[$](DEF|LIB)|LUP|RTN|PTR|FUN)"),
        // identifier
        std::regex("([_])?([a-z]|[A-Z])([_]|[a-z]|[A-Z]|[0-9])*"),
        // logical operators
        std::regex("(([|][|])|(&&)|(<!>)|(<->)|(<|>)(=)?|\\!|NOT|AND|OR)"),
        // assignation
        std::regex("(<-)"),
        // arithmetical operators
        std::regex("([*]|[+]|/|-|%)"),
        // strings
        std::regex("((\\'.\\')|(\u0022.\u0022))"),
        // symbols
        std::regex("(\\(|\\)|\\{|\\}|\\[|\\]|\\;)"),
    };

    // local variables declaration
    std::string line_buffer;
    unsigned line_index = 0;
    std::vector<unsigned> line_errors;
    std::vector<std::string> line_tokens;
    Automata worker;

    // get line
    while (std::getline(source_file, line_buffer))
    {
        // update line index
        line_index++;

        worker.run(line_buffer, symbols_table, line_errors, line_tokens);

        if (line_errors.size() > 0)
        {
            std::map<unsigned, char> temp_array;

            for (unsigned error : line_errors)
            {
                temp_array[error] = line_buffer[error];
            }
            lexical_errors[line_index] = temp_array;
            line_errors.clear();
        }

        if (line_tokens.size() > 0)
        {
            file_tokens[line_index] = line_tokens;

            line_tokens.clear();
        }
    }
    std::cout << "\nLexical done\n\n";
}
