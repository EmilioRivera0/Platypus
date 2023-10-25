#ifndef CONSOLE_OUTPUT_H
#define CONSOLE_OUTPUT_H

// necessary includes -------->
#include <map>
#include <string>
#include <iostream>
#include <iomanip>

// functions declaration -------->
void print_map(std::map<std::string, std::string>);
void print_map(std::map<unsigned, std::map<unsigned, char>>);

#endif // !CONSOLE_OUTPUT_H
