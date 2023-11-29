// necessary includes -------->
#include "../headers/console_output.h"

// functions definition -------->
void print_map(std::map<std::string, std::string> map)
{
    // print symbols table contents key and value pairs
    std::cout << std::left << std::setw(20) << "Key"
              << "    |    " << std::setw(10) << "Value" << std::endl;
    for (const auto &par : map)
    {
        std::cout << std::left << std::setw(20) << par.first << "    |    " << std::setw(10) << par.second << std::endl;
    }
}

void print_map(std::map<unsigned, std::map<unsigned, char>> map)
{
    // print generated errors specifying line, column and character
    std::cout << std::left << std::setw(8) << "Line"
              << "    |    " << std::setw(8) << "Column"
              << "    |    " << std::setw(8) << "Character"
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

void print_map(std::map<unsigned, std::map<unsigned, std::string>> map)
{
    // print generated errors specifying line, column and character
    std::cout << std::left << std::setw(8) << "Line"
              << "    |    " << std::setw(8) << "Token"
              << "    |    " << std::setw(20) << "Mensaje"
              << "    |    " << std::endl;
    for (const auto &par : map)
    {
        for (const auto &error : par.second)
        {
            std::cout << std::left << std::setw(8) << par.first << "    |    ";
            std::cout << std::setw(8) << error.first << "    |    ";
            std::cout << std::setw(20) << error.second << "    |    ";
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
