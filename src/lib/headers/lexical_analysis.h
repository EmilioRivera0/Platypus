#ifndef LEXICAL_ANALYSIS_H
#define LEXICAL_ANALYSIS_H

// necessary imports -------->
#include <fstream>
#include <cstring>
#include <iostream>
#include <vector>
#include <regex>

// macros definition -------->
#define LINE_BUFFER_SIZE 500
#define TOKEN_BUFFER_SIZE 50

// function declaration -------->
void lexical_analysis(std::ifstream &);

#endif // !LEXICAL_ANALYSIS_H
