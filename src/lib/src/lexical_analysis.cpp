// necessary imports -------->
#include "../headers/lexical_analysis.h"

void lexical_analysis(std::ifstream &source_file)
{
    std::cout << "\nLexical scanning..." << std::endl;

    // Regular expressions
    std::vector<std::regex> regular_expressions = {
        // number
        std::regex("([-])?([0-9])+([.]([0-9])+)?"),

        // reserved words
        std::regex("(NUM|IF|CMT|ST(X|R)|A(ND|RR)|OR|E(IF|LS)|TOF|[$](DEF|LIB)|LUP|RTN|PTR|FUN)"),

        // identifier
        std::regex("([_])?([a-z]|[A-Z])([_]|[a-z]|[A-Z]|[0-9])*"),

        // logical operators
        std::regex("(([|][|])|(&&)|(<!>)|(<->)|(<|>)(=)?)"),

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
    Automata nada;

    // get line
    while (std::getline(source_file, line_buffer))
    {
        nada.run(line_buffer);
    }

    std::cout << "\nLexical done" << std::endl;
}
