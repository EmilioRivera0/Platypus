// necessary includes -------->
#include "../headers/parser.h"

// functions definition -------->

void Parser::analisis_parser(){
    while(this->line_index < this->keys.size() && this->tokens_index < this->tokens[this->keys[this-line_index]].size()){

        if(this->match("#macro")){
            this->def_parser();
        }
        else if(this->match("#header")){
            this->lib_parser();
        }
        else if(this->match("#rword")){
            this->asignacion_parser();
        }
        else{
            
        }
    }

}

void defSintactico(std::map<int, std::vector<std::string>> tokens, std::map<std::string, std::string> &symbol_table, int indice){
    if(strcmp(symbol_table[tokens[indice][0]].c_str(), "#id") == 0){
        indice += 1;

        if(strcmp(symbol_table[tokens[indice][0]].c_str(), "#int") == 0 || strcmp(symbol_table[tokens[indice][0]].c_str(), "#float") == 0 || strcmp(symbol_table[tokens[indice][0]].c_str(), "#string") == 0){
            indice += 1;

            if(strcmp(symbol_table[tokens[indice][0]].c_str(), "#eol") == 0){
                indice += 1;

                // analisis_sintactico();
            }
        }
    }
    else{

    }

}

void headerSintactico(){

}

void asignacionSintactico(std::map<int, std::vector<std::string>> token, std::map<std::string, std::string> &symbol_table, int indice){
    while(strcmp(symbol_table[token[indice][0]].c_str(), "#eol") == 0){
        // match();
    }
}

bool identificador(std::string token){
    if(strcmp(token.c_str(), "identificador") == 0) {
        return true;
    }else{
        return false;
    }
}

void asignacion(std::string tokens[]){
    int indice = 0;
    if(identificador(tokens[indice])){
        ;
    }
}