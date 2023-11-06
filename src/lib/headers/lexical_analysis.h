#ifndef LEXICAL_ANALYSIS_H
#define LEXICAL_ANALYSIS_H

// necessary imports -------->
#include <fstream>
#include <iostream>
#include <vector>
#include <regex>
#include <string>
#include "./automata.h"

// macros definition -------->

// function declaration -------->
void lexical_analysis(std::ifstream &, std::map<std::string, std::string> &, std::map<unsigned, std::map<unsigned, char>> &, std::map<unsigned, std::vector<std::string>> &);

#endif // !LEXICAL_ANALYSIS_H
