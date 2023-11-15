#include<iostream>
#include<cstring>
#include<map>
#include<vector>

void analisis_sintactico(std::map<int, std::vector<std::string>> tokens, std::map<std::string, std::string> &symbol_table){
    int indice = 0;
    if(strcmp(symbol_table[tokens[0][0]].c_str(), "#macro") == 0){
        indice += 1;
        defSintactico(tokens, symbol_table, indice);
        if(symbol_table.size() == indice){
            std::cout<<"DONE";
        }
    }
    else if(strcmp(symbol_table[tokens[0][0]].c_str(), "#header") == 0){
        headerSintactico();
    }
    else if(strcmp(symbol_table[tokens[0][0]].c_str(), "#rword") == 0){
        asignacionSintactico(tokens, symbol_table, indice);
    }
    else{
        return;
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