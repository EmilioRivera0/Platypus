// necessary includes -------->
#include "../headers/parser.h"

// functions definition -------->
Parser::Parser(std::map<unsigned, std::vector<std::string>> line_tokens, std::map<std::string, std::string> &symbols_table, std::map<unsigned, std::map<unsigned, std::string>> &parser_errors)
    : tokens(line_tokens), symbol_table(symbols_table), parser_errors(parser_errors)
{
    for (const auto &par : tokens)
    {
        this->keys.push_back(par.first);
    }

    this->tokens_index = 0;
    this->line_index = 0;
}

/**
 * @brief Match a the current tag with a given tag and writes an error if they does not match
 *
 * @param tag Tag that needs to match
 * @param starting If the function needs to not write an error
 * @param is_conditional If is a conditional expression
 * @return true: The tag is match |
 * @return false: The tag has not match
 */
bool Parser::match(std::string tag, bool starting = false, bool is_conditional = false)
{
    if (this->tokens_index < this->tokens[this->keys[this->line_index]].size())
    {
        if (strcmp(this->symbol_table[this->tokens[this->keys[this->line_index]][this->tokens_index]].c_str(), tag.c_str()) == 0)
        {
            if (!is_conditional)
            {
                this->advance_token();
            }
            return true;
        }
        else
        {
            if (!starting)
            {
                std::string error = "No se esperaba " + tokens[this->keys[this->line_index]][this->tokens_index];

                write_error(error);
            }
            return false;
        }
    }
    else
    {
        if (!starting)
        {
            std::string error = "Se esperaba " + tag;

            write_error(error);
        }
        // return true; //?original
        return false;
    }
}

/**
 * @brief Match a the current tag with a given tag and writes an error if they does not match
 *
 * @param tags Tags that needs to match
 * @param starting If the function needs to not write an error
 * @param is_conditional If is a conditional expression
 * @return true: The tag is match |
 * @return false: The tag has not match
 */
bool Parser::match(std::vector<std::string> tags, bool starting = false)
{
    if (this->tokens_index < this->tokens[this->keys[this->line_index]].size())
    {
        for (const std::string tag : tags)
        {
            if (strcmp(this->symbol_table[this->tokens[this->keys[this->line_index]][this->tokens_index]].c_str(), tag.c_str()) == 0)
            {
                this->advance_token();
                return true;
            }
        }
        if (!starting)
        {
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

/**
 * @brief Match a next tag and if it does not match it decreases the token index
 *
 * @param tag Tag that has to match
 * @return true: The tag is match |
 * @return false: The tag has not match
 */
bool Parser::match_with_backwards(std::string tag)
{
    if (this->tokens_index < this->tokens[this->keys[this->line_index]].size())
    {
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

/**
 * @brief define the definition of a expression
 *
 * @param is_father define if the function call should have a recursive call
 * @param final_hashtag Define the last hashtag for the expression
 */
void Parser::expresion_parser(bool is_father = true, std::string final_hashtag = "#eol")
{
    unsigned int pre_token_index = this->tokens_index;

    if (this->tokens_index == this->tokens[this->keys[this->line_index]].size())
    {
        return;
    }
    else if (this->match("#group", true))
    {
        this->expresion_parser((this->tokens_index + 2 < this->tokens[this->keys[this->line_index]].size()), "#group");

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

/**
 * @brief Increments the token index and line index if necessary
 *
 */
void Parser::advance_token()
{
    if (this->tokens_index + 1 == this->tokens[this->keys[this->line_index]].size() && this->line_index < this->keys.size())
    {
        this->line_index++;
        this->tokens_index = 0;
    }
    else
    {
        this->tokens_index++;
    }
}

/**
 * @brief Write an error in the error dict and handle collisions
 *
 * @param error string that should be written in the error table
 */
void Parser::write_error(std::string error)
{
    if (this->parser_errors[this->keys[this->line_index]][this->tokens_index].size() > 0)
    {
        this->parser_errors[this->keys[this->line_index]][this->tokens_index + 1] = error;
        return;
    }
    this->parser_errors[this->keys[this->line_index]][this->tokens_index] = error;
}

/**
 * @brief initial function for the analysis
 *
 */
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
            this->advance_token();
        }
    }
}

/**
 * @brief Analysis in sub-routines
 *
 */
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
        else if (this->match("#llavec", true, true))
        {
            break;
        }
        else
        {
            this->advance_token();
        }
    }
}

/**
 * @brief Define the structure of a definition
 *
 */
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

/**
 * @brief Define the structure of a include
 *
 */
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

/**
 * @brief Define the structure of a declaration
 *
 */
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

/**
 * @brief Define the structure of a assignation
 *
 */
void Parser::asignacion_parser()
{
    if (this->match("#assign"))
    {
        this->expresion_parser();

        if (this->match("#eol"))
        {
            return;
        }
    }
}

/**
 * @brief Define the structure of a if statements sequence
 *
 */
void Parser::conditional_parser()
{
    bool is_eif = true;
    if (this->match("#group")) // (
    {
        this->expresion_parser(true, "#group");
        if (this->match("#group")) // )
        {
            if (this->match("#llavea")) //{
            {
                /* MAS CÓDIGO */
                this->sub_analisis_parser();
                if (this->match("#llavec")) //}
                {
                    while (is_eif)
                    {
                        if (this->match("#eif", true)) // EIF
                        {
                            if (this->match("#group")) // (
                            {
                                this->expresion_parser(true, "#group");
                                if (this->match("#group")) //)
                                {
                                    if (this->match("#llavea")) //{
                                    {
                                        /* MAS CÓDIGO */
                                        this->sub_analisis_parser();
                                        if (this->match("#llavec")) //}
                                        {
                                        }
                                    }
                                }
                            }
                        }
                        else
                        {
                            is_eif = false;
                        }
                    }
                    if (this->match("#els", true))
                    {
                        if (this->match("#llavea")) // {
                        {
                            /* MAS CÓDIGO */
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

/**
 * @brief Define the structure of a loop statement
 *
 */
void Parser::loop_parser()
{
    if (this->match("#group")) //(
    {
        if (this->match("#dtype", true))
        {
            if (this->match("#id"))
            {
                this->asignacion_parser();

                this->expresion_parser();

                if (this->match("#eol"))
                {
                    if (this->match("#id"))
                    {
                        this->asignacion_parser();
                    }
                }
            }
        }
        else
        {
            this->expresion_parser(true, "#group");
        }

        if (this->match("#group")) // )
        {
            if (this->match("#llavea")) //{
            {
                /* MAS CÓDIGO */
                this->sub_analisis_parser();
                if (this->match("#llavec")) //}
                {
                    return;
                }
            }
        }
    }
}