#ifndef SEMANTIC_ANALYSIS_H
#define SEMANTIC_ANALYSIS_H
// necessary includes -------->
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <map>

// function declaration -------->
std::vector<std::string> semantic_analyzer(const std::map<unsigned,std::vector<std::string>>&, const std::map<std::string,std::string>&);

#endif // !SEMANTIC_ANALYSIS_H
