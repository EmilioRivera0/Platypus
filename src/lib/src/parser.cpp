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

bool Parser::match(std::string tag, bool starting)
{
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

void analisis_sintactico(std::map<int, std::vector<std::string>> tokens, std::map<std::string, std::string> &symbol_table)
{
    int indice = 0;
    if (strcmp(symbol_table[tokens[0][0]].c_str(), "#macro") == 0)
    {
        indice += 1;
        defSintactico(tokens, symbol_table, indice);
        if (symbol_table.size() == indice)
        {
            std::cout << "DONE";
        }
    }
    else if (strcmp(symbol_table[tokens[0][0]].c_str(), "#header") == 0)
    {
        headerSintactico();
    }
    else if (strcmp(symbol_table[tokens[0][0]].c_str(), "#rword") == 0)
    {
        asignacionSintactico(tokens, symbol_table, indice);
    }
    else
    {
        return;
    }
}

void defSintactico(std::map<int, std::vector<std::string>> tokens, std::map<std::string, std::string> &symbol_table, int indice)
{
    if (strcmp(symbol_table[tokens[indice][0]].c_str(), "#id") == 0)
    {
        indice += 1;

        if (strcmp(symbol_table[tokens[indice][0]].c_str(), "#int") == 0 || strcmp(symbol_table[tokens[indice][0]].c_str(), "#float") == 0 || strcmp(symbol_table[tokens[indice][0]].c_str(), "#string") == 0)
        {
            indice += 1;

            if (strcmp(symbol_table[tokens[indice][0]].c_str(), "#eol") == 0)
            {
                indice += 1;

                // analisis_sintactico();
            }
        }
    }
}

void headerSintactico()
{
}

void asignacionSintactico(std::map<int, std::vector<std::string>> token, std::map<std::string, std::string> &symbol_table, int indice)
{
    while (strcmp(symbol_table[token[indice][0]].c_str(), "#eol") == 0)
    {
        // match();
    }
}

bool identificador(std::string token)
{
    if (strcmp(token.c_str(), "identificador") == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void asignacion(std::string tokens[])
{
    int indice = 0;
    if (identificador(tokens[indice]))
    {
        ;
    }
}