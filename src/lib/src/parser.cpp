// necessary includes -------->
#include "../headers/parser.h"

Parser::Parser(std::map<unsigned, std::vector<std::string>> &line_tokens, std::map<std::string, std::string> &symbols_table, std::map<unsigned, std::map<unsigned, std::string>> &parser_errors)
    : tokens(line_tokens), symbol_table(symbols_table), parser_errors(parser_errors)
{
    for (const auto &par : tokens)
    {
        this->keys.push_back(par.first);
    }

    this->tokens_index = 0;
    this->line_index = 0;
}

bool Parser::match(std::string tag, bool starting) {
    if (strcmp(this->symbol_table[this->tokens[this->keys[this->line_index]][this->tokens_index]].c_str(), tag.c_str()) == 0)
    {
        this->tokens_index++;
        return true;
    }
    else
    {
        if (!starting)
        {
            std::string error = "No se esperaba " + tokens[this->keys[this->line_index]][this->tokens_index];
            this->parser_errors[this->keys[this->line_index]][this->tokens_index] = "No se esperaba el token";
        }
        return false;
    }
}

bool Parser::expression_parser() {
    this->expression = "";
    std::regex regex_expression("#id | #id#logic#id | #id#math#id | #int | #int#math#int | #float | #float#math#float | #string | #string#math#string");
    while (strcmp(this->symbol_table[this->tokens[this->keys[this->line_index]][this->tokens_index]].c_str(), "#eol") != 0) {
        this->expression += this->symbol_table[this->tokens[this->keys[this->line_index]][this->tokens_index]].c_str();
        this->tokens_index++;
        if (!std::regex_match(this->expression, regex_expression)) {
            return false;
        }
    }
    return true;
}

// functions definition -------->

void Parser::analisis_parser() {
    unsigned line = this->keys[this->line_index];
    while (this->line_index < this->keys.size() && this->tokens_index < this->tokens[line].size())
    {

        if (this->match("#macro", true))
        {
            this->def_parser();
        }
        else if (this->match("#header", true))
        {
            this->lib_parser();
        }
        else if (this->match("#dtype", true))
        {
            this->asignacion_parser();
        }
        else
        {
        }

        line = this->keys[this->line_index];
    }
}

void Parser::def_parser() {
    if (this->match("#id", false)) {
        if (this->match("#int", false) || this->match("#float", false) || this->match("#string", false)) {
            if (this->match("#eol", false)) {
                return;
            }
        }
    }
    return;
}

void Parser::lib_parser() {
    return;
}

void Parser::asignacion_parser() {
    if (this->match("#id", false)) {
        if (this->match("logic", false)) {
            if (this->expression_parser()) {
                return;
            }
        }
    }
    return;
}