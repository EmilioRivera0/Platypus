// necessary includes -------->
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <iostream>
#include <regex>

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
    std::string expression;

public:
    Parser(std::map<unsigned, std::vector<std::string>> &, std::map<std::string, std::string> &, std::map<unsigned, std::map<unsigned, std::string>> &);
    bool match(std::string, bool, bool);
    bool match(std::vector<std::string>, bool);
    bool match_with_backwards(std::string);
    void expresion_parser(bool, std::string);
    void advance_token();
    void write_error(std::string);
    void analisis_parser();
    void sub_analisis_parser();
    void def_parser();
    void lib_parser();
    void declaracion_parser();
    void asignacion_parser();
    void conditional_parser();
    void loop_parser();
};