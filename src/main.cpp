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

void print_map(std::map<unsigned, std::map<unsigned, char>> map)
{
    std::cout << std::left << std::setw(8) << "Linea"
              << "    |    " << std::setw(8) << "Columna"
              << "    |    " << std::setw(8) << "Caracter"
              << "    |    " << std::endl;
    for (const auto &par : map)
    {
        for (const auto &error : par.second)
        {
            std::cout << std::left << std::setw(8) << par.first << "    |    ";
            std::cout << std::setw(8) << error.first << "    |    ";
            std::cout << std::setw(8) << error.second << "    |    ";
            std::cout << std::endl;
        }
    }

    std::cout << "\n\n";
}

void print_map(std::map<unsigned, std::vector<std::string>> map)
{
    std::cout << std::left << std::setw(6) << "Linea"
              << " | "
              << "Valor" << std::endl;
    for (const auto &par : map)
    {
        std::cout << std::left << std::setw(6) << par.first << " | [";

        for (const std::string &token : par.second)
        {
            std::cout << token;

            if (token != par.second.back())
            {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }
}

// program entry point -------->
int main(int argc, char *argv[])
{
    // program variables
    std::ifstream source_code_file;
    std::map<std::string, std::string> symbols_table;
    std::map<unsigned, std::map<unsigned, char>> lexical_errors;
    std::map<unsigned, std::vector<std::string>> file_tokens;

    try
    {
        source_code_file = open_jec_file(get_parameters(argc, argv));
        lexical_analysis(source_code_file, symbols_table, lexical_errors, file_tokens);

        if (lexical_errors.size() > 0)
        {
            print_map(lexical_errors);
        }

        print_map(symbols_table);
        std::cout << "\n\n Tokens por linea" << std::endl;
        print_map(file_tokens);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
