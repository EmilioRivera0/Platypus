// necessary includes -------->
#include <vector>
#include <map>
#include <string>
#include <iostream>

// class declaration -------->
class Parser
{
private:
    std::map<unsigned, std::vector<std::string>> &tokens;
    std::vector<unsigned> keys;
    std::map<std::string, std::string> &symbol_table;
    unsigned tokens_index;
    unsigned line_index;
    std::map<unsigned, std::map<unsigned, std::string>> &parser_errors;

public:
    Parser(std::map<unsigned, std::vector<std::string>> &, std::map<std::string, std::string> &, std::map<unsigned, std::map<unsigned, std::string>> &);
    void analisis_parser();
    void def_parser();
    void lib_parser();
    void asignacion_parser();
    void expresion_parser();
    bool match(std::string, bool);
};