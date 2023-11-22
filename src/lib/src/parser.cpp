// necessary includes -------->
#include "../headers/parser.h"
#include "parser.h"

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

bool Parser::match(std::string tag, bool starting = false)
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

void Parser::expresion_parser()
{
    if (this->match("#id") || this->match("#int") || this->match("#float") || this->match("#string") || this->match("#bool"))
    {
    }
    else if (this->match("#group"))
    {
        this->expresion_parser();

        if (this->match("#group"))
        {
        }
    }
    else if (this->match("#logic"))
    {
        this->expresion_parser();
    }
    else
    {
        this->expresion_parser();
        if (this->match("#math") || this->match("#logic"))
        {
            this->expresion_parser();
        }
    }
}

// functions definition -------->

void Parser::analisis_parser()
{
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
            if (this->match("#id", false))
            {
                if (this->match("#eol", false))
                {
                    this->analisis_parser();
                }
                else
                {
                    this->asignacion_parser();
                }
            }
        }
        else if (this->match("#id", true))
        {
            this->asignacion_parser();
        }
        else if (this->match("#if", true))
        {
            this->conditional_parser();
        }

        line = this->keys[this->line_index];
    }
}

void Parser::def_parser()
{
    if (this->match("#id", false))
    {
        if (this->match("#int", false) || this->match("#float", false) || this->match("#string", false))
        {
            if (this->match("#eol", false))
            {
                return;
            }
        }
    }
    return;
}

void Parser::lib_parser()
{
    if (this->match("#string", false))
    {
        if (this->match("#eol", false))
        {
            return;
        }
    }
}

void Parser::asignacion_parser()
{
    if (this->match("#assign", false))
    {
        this->expresion_parser();
        if (this->match("#eol", false))
        {
            return;
        }
    }
}

void Parser::conditional_parser()
{
    if (strcmp(this->symbol_table[this->tokens[this->keys[this->line_index]][this->tokens_index]].c_str(), "(") == 0)
    {
        this->tokens_index += 1;
        // if (this->expresion_parser())
        // {
        if (strcmp(this->symbol_table[this->tokens[this->keys[this->line_index]][this->tokens_index]].c_str(), ")") == 0)
        {
            this->tokens_index += 1;
            if (strcmp(this->symbol_table[this->tokens[this->keys[this->line_index]][this->tokens_index]].c_str(), "{") == 0)
            {
                this->tokens_index += 1;
                /* Implementar las comprobaciones
                / para el analisis de la estructura
                / dentro de un if */
                if (strcmp(this->symbol_table[this->tokens[this->keys[this->line_index]][this->tokens_index]].c_str(), "}") == 0)
                {
                    this->tokens_index += 1;

                    if (this->match("#els", true))
                    {
                        if (strcmp(this->symbol_table[this->tokens[this->keys[this->line_index]][this->tokens_index]].c_str(), "{") == 0)
                        {
                            this->tokens_index += 1;
                            /* Implementar las comprobaciones
                            / para el analisis de la estructura
                            / dentro de un if */
                            if (strcmp(this->symbol_table[this->tokens[this->keys[this->line_index]][this->tokens_index]].c_str(), "}") == 0)
                            {
                                this->tokens_index += 1;
                                // IF () {} ELS {}
                                return;
                            }
                        }
                    }
                    // IF () {}
                    return;
                }
            }
        }
        // }
    }
}