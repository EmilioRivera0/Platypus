// necessary includes -------->
#include "lib/headers/file_operations.h"
#include "lib/headers/parameter_engine.h"
#include "lib/headers/lexical_analysis.h"
#include <map>
#include <iomanip>
#include <string>

void print_map(std::map<std::string, std::string> map)
{
    std::cout << std::left << std::setw(20) << "Clave"
              << "    |    " << std::setw(10) << "Valor" << std::endl;
    for (const auto &par : map)
    {
        std::cout << std::left << std::setw(20) << par.first << "    |    " << std::setw(10) << par.second << std::endl;
    }
}

void print_map(std::map<unsigned, std::vector<char>> map)
{
    std::cout << std::left << std::setw(8) << "Linea"
              << "    |    " << std::setw(8) << "Caracteres" << std::endl;
    for (const auto &par : map)
    {
        std::cout << std::left << std::setw(8) << par.first << "    |    " << std::setw(8);

        for (char c : par.second)
        {
            std::cout << c;
        }
        std::cout << std::endl;
    }

    std::cout << "\n\n";
}

// program entry point -------->
int main(int argc, char *argv[])
{
    // program variables
    std::ifstream source_code_file;
    std::map<std::string, std::string> symbols_table;
    std::map<unsigned, std::vector<char>> lexical_errors;

    try
    {
        source_code_file = open_jec_file(get_parameters(argc, argv));
        lexical_analysis(source_code_file, symbols_table, lexical_errors);

        if (lexical_errors.size() > 0)
        {
            print_map(lexical_errors);
        }

        print_map(symbols_table);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
