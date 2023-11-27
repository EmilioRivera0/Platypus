// necessary includes -------->
#include "../headers/parser.h"

// functions definition -------->
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

bool Parser::match(std::string tag, bool starting = false, bool is_conditional = false)
{
    //? Conocer si el contador de linea ya sobrepaso las lineas de codigo
    // if (this->line_index >= this->tokens.size()) {
    //     return false;
    // }
    if (this->tokens_index < this->tokens[this->keys[this->line_index]].size())
    {
        std::cout << "\n--------\n"
                  << this->tokens[this->keys[this->line_index]][this->tokens_index] << std::endl;
        std::cout << this->symbol_table[this->tokens[this->keys[this->line_index]][this->tokens_index]] << std::endl;
        std::cout << "Tag: " << tag << std::endl;

        if (strcmp(this->symbol_table[this->tokens[this->keys[this->line_index]][this->tokens_index]].c_str(), tag.c_str()) == 0)
        {
            if (!is_conditional) {
                this->advance_token();
            }
            return true;
        }
        else
        {
            if (!starting)
            {
                std::cout << "Error" << std::endl;
                std::string error = "No se esperaba " + tokens[this->keys[this->line_index]][this->tokens_index];

                write_error(error);
                std::cout<<"match not starting"<<std::endl;
            }
            return false;
        }
    }
    else
    {
        // if (strcmp("#llavea", tag.c_str()) == 0 || strcmp("#llavec", tag.c_str()) == 0 || strcmp("#els", tag.c_str()) == 0) {
        //     this->advance_token();
        //     return this->match(tag, starting);
        // }
        // else{    
        //     std::string error = "Se esperaba " + tag;
        //     std::cout << "Nada: " << error << std::endl;

        //     write_error(error);
        //     std::cout<<"match fin"<<std::endl;
        // }
        if (!starting)
        {
            std::string error = "Se esperaba " + tag;
            std::cout << "Nada: " << error << std::endl;

            write_error(error);
            std::cout<<"match fin"<<std::endl;
        }
        // return true; //?original
        return false;
    }
}

bool Parser::match(std::vector<std::string> tags, bool starting = false)
{
    if (this->tokens_index < this->tokens[this->keys[this->line_index]].size())
    {
        for (const std::string tag : tags)
        {
            std::cout << "\n--------\n"
                      << this->tokens[this->keys[this->line_index]][this->tokens_index] << std::endl;
            std::cout << this->symbol_table[this->tokens[this->keys[this->line_index]][this->tokens_index]] << std::endl;
            std::cout << "Tag: " << tag << std::endl;

            if (strcmp(this->symbol_table[this->tokens[this->keys[this->line_index]][this->tokens_index]].c_str(), tag.c_str()) == 0)
            {
                this->advance_token();
                return true;
            }
        }
        if (!starting)
        {
            std::cout << "Error" << std::endl;
            std::string error = "No se esperaba " + tokens[this->keys[this->line_index]][this->tokens_index];

            write_error(error);
        }
        return false;
    }
    else
    {

        std::string error = "Se esperaba ";
        for (const std::string tag : tags)
        {
            error += tag + ", ";
        }

        write_error(error);

        return true;
    }
}

bool Parser::match_with_backwards(std::string tag)
{

    if (this->tokens_index < this->tokens[this->keys[this->line_index]].size())
    {
        std::cout << "\n------------------\n"
                  << "TI: " << this->tokens_index << std::endl;
        std::cout << "LI: " << this->line_index << std::endl;
        std::cout << "TsS: " << this->tokens[this->keys[this->line_index]].size() << std::endl;
        std::cout << "KS: " << this->keys.size() << std::endl;

        std::cout << "\n-------- Holaaa\n"
                  << this->tokens[this->keys[this->line_index]][this->tokens_index] << std::endl;
        std::cout << this->symbol_table[this->tokens[this->keys[this->line_index]][this->tokens_index]] << std::endl;
        std::cout << "Tag: " << tag << std::endl;

        if (strcmp(this->symbol_table[this->tokens[this->keys[this->line_index]][this->tokens_index]].c_str(), tag.c_str()) == 0)
        {
            return true;
        }
        else
        {
            this->tokens_index--;
            return false;
        }
    }
    else
    {
        return false;
    }
}

void Parser::expresion_parser(bool is_father = true, std::string final_hashtag = "#eol")
{
    unsigned int pre_token_index = this->tokens_index;
    std::cout << this->tokens_index << std::endl;
    std::cout << is_father << std::endl;

    if (this->tokens_index == this->tokens[this->keys[this->line_index]].size())
    {
        return;
    }
    else if (this->match("#group", true))
    {

        std::cout << (this->tokens_index + 2) << std::endl;
        std::cout << (this->tokens[this->keys[this->line_index]].size()) << std::endl;
        std::cout << (this->tokens_index + 2 < this->tokens[this->keys[this->line_index]].size()) << std::endl;
        this->expresion_parser((this->tokens_index + 2 < this->tokens[this->keys[this->line_index]].size()), "#group");
        std::cout << "Final de la llamda recursiva" << std::endl;

        if (this->match("#group"))
        {
            if (!is_father)
            {
                return;
            }
            else if (this->match_with_backwards(final_hashtag))
            {
                return;
            }

            this->tokens_index = pre_token_index;
        }
    }
    else if (this->match("#logic", true))
    {
        this->expresion_parser((this->tokens_index + 1 < this->tokens[this->keys[this->line_index]].size()));
    }
    else if (this->match({"#id", "#int", "#float", "#string", "#bool"}))
    {
        if (!is_father)
        {
            return;
        }
        else if (this->match_with_backwards(final_hashtag))
        {
            return;
        }
    }

    this->expresion_parser(false, final_hashtag);

    if (this->match({"#math", "#logic", ""}))
    {
        this->expresion_parser((this->tokens_index + 1 < this->tokens[this->keys[this->line_index]].size()), final_hashtag);
    }
}

void Parser::advance_token()
{
    std::cout<<this->tokens_index<<std::endl;
    if (this->tokens_index+1 == this->tokens[this->keys[this->line_index]].size() && this->line_index < this->keys.size())
    {
        std::cout << "Final de Linea de tokens" << std::endl;
        this->line_index++;
        this->tokens_index = 0;
    }
    else
    {
        this->tokens_index++;
    }
}

void Parser::write_error(std::string error)
{
    if (this->parser_errors[this->keys[this->line_index]][this->tokens_index].size() > 0)
    {
        std::cout << "Error que hay: " << this->parser_errors[this->keys[this->line_index]][this->tokens_index] << std::endl;
        this->parser_errors[this->keys[this->line_index]][this->tokens_index + 1] = error;
        return;
    }
    this->parser_errors[this->keys[this->line_index]][this->tokens_index] = error;
}

void Parser::analisis_parser()
{
    while ((this->line_index < this->keys.size()) || (this->tokens_index < this->tokens[this->keys[this->line_index]].size()))
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
            this->declaracion_parser();
        }
        else if (this->match("#id", true))
        {
            this->asignacion_parser();
        }
        else if (this->match("#if", true))
        {
            this->conditional_parser();
        }
        else if (this->match("#lup", true))
        {
            this->loop_parser();
        }
        else
        {
            // std::cout << "Error" << std::endl;
            // std::string error = "No se esperaba " + tokens[this->keys[this->line_index]][this->tokens_index];

            // write_error(error);
            this->advance_token();
        }

        std::cout << "\n------------------\n"
                  << "TI: " << this->tokens_index << std::endl;
        std::cout << "LI: " << this->line_index << std::endl;
        std::cout << "TsS: " << this->tokens[this->keys[this->line_index]].size() << std::endl;
        std::cout << "KS: " << this->keys.size() << std::endl;
        std::cout << "L: " << this->keys[this->line_index] << std::endl;
        std::cout << "LI < KS: " << (this->line_index < this->keys.size()) << std::endl;
        std::cout << "TI < TsS: " << (this->tokens_index == this->tokens[this->keys[this->line_index]].size()) << std::endl;

        
        // if (this->tokens_index >= this->tokens[this->keys[this->line_index]].size() && this->line_index < this->keys.size())
        // {
        //     std::cout << "Final de Linea de tokens" << std::endl;
        //     this->line_index++;
        //     this->tokens_index = 0;
        // }
    }
}

void Parser::sub_analisis_parser()
{
    while ((this->line_index < this->keys.size()) || (this->tokens_index < this->tokens[this->keys[this->line_index]].size()))
    {
        if (this->match("#dtype", true))
        {
            this->declaracion_parser();
        }
        else if (this->match("#id", true))
        {
            this->asignacion_parser();
        }
        else if (this->match("#if", true))
        {
            this->conditional_parser();
        }
        else if (this->match("#lup", true))
        {
            this->loop_parser();
        }
        else if (this->match("#llavec", true, true)) {
            break;
        }
        else
        {
            this->advance_token();
        }
    }
}

void Parser::def_parser()
{
    if (this->match("#id"))
    {
        if (this->match({"#int", "#float", "#string"}))
        {
            if (this->match("#eol"))
            {
                return;
            }
        }
    }
    return;
}

void Parser::lib_parser()
{
    if (this->match("#string"))
    {
        if (this->match("#eol"))
        {
            return;
        }
    }
}

void Parser::declaracion_parser() 
{
    if (this->match("#id", false)) 
    {
        if (!this->match("#eol", true)) 
        {
            this->asignacion_parser();
        }
    }
}

void Parser::asignacion_parser()
{
    if (this->match("#assign"))
    {
        this->expresion_parser();
        this->advance_token();
        // std::cout << "Esperando eol" << std::endl;
        // if (this->match("#eol"))
        // {
        //     return;
        // }
    }
}

void Parser::conditional_parser()
{
    if (this->match("#group")) // (
    {
        this->expresion_parser(true, "#group"); 
        if (this->match("#group")) // )
        {
            if (this->match("#llavea")) //{
            {
                /* MAS CODIGO */
                this->sub_analisis_parser(); 
                if (this->match("#llavec")) //}
                {
                    if (this->match("#els", true))
                    {
                        if (this->match("#llavea")) // {
                        {
                            this->advance_token();
                            /* MAS CODIGO */
                            this->sub_analisis_parser(); 
                            if (this->match("#llavec")) //}
                            {
                                return;
                            }
                        }
                    }
                }
            }
        }
    }
}

void Parser::loop_parser()
{
    if (this->match("#group")) //(
    {
        this->expresion_parser(true, "#group");
        if (this->match("#group"))  // )
        {
            if (this->match("#llavea")) //{
            {
                /* MAS CODIGO */
                this->sub_analisis_parser();
                if (this->match("#llavec")) //}
                {
                    return;
                }
            }
        }
    }
}