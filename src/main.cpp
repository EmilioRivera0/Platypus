// necessary includes -------->
#include <map>
#include <iomanip>
#include <string>

#include "lib/headers/file_operations.h"
#include "lib/headers/parameter_engine.h"
#include "lib/headers/lexical_analysis.h"
#include "lib/headers/console_output.h"
#include "lib/headers/parser.h"

// program entry point -------->
int main(int argc, char *argv[])
{
    // program variables
    std::ifstream source_code_file;
    std::map<std::string, std::string> symbols_table;
    std::map<unsigned, std::map<unsigned, char>> lexical_errors;
    std::map<unsigned, std::vector<std::string>> file_tokens;
    std::map<unsigned, std::map<unsigned, std::string>> parser_errors;

    try
    {
        // open source file
        source_code_file = open_jec_file(get_parameters(argc, argv));
        lexical_analysis(source_code_file, symbols_table, lexical_errors, file_tokens);

        if (lexical_errors.size() > 0)
        {
            print_map(lexical_errors);
        }
        // print symbols table
        print_map(symbols_table);
        std::cout << "\n\n Tokens por linea" << std::endl;
        print_map(file_tokens);

        Parser parser(file_tokens, symbols_table, parser_errors);
        parser.analisis_parser();

        std::cout << "\n\n Errores Sintacticos" << std::endl;
        print_map(parser_errors);
    }
    // output the exception message
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
