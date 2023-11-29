// necessary includes -------->
#include "../headers/semantic_analysis.h"

// function declaration -------->
std::vector<std::string> semantic_analyzer(const std::map<unsigned,std::vector<std::string>> &file_tokens, const std::map<std::string,std::string> &symbols_table){
  // local variables
  short start_index{0};
  std::string type{};
  std::string temp{};
  // errors vector
  std::vector<std::string> semantic_errors{};
  // data types map
  std::map<std::string, std::string> data_types_table{};
  // data types & identifiers
  std::regex data_type("(NUM|ST(X|R)|TOF|PTR)");
  std::regex identifier("([_])?([a-z]|[A-Z])([_]|[a-z]|[A-Z]|[0-9])*");
  // literal values
  std::regex str("((\\'.*\\')|(\u0022.*\u0022))");
  std::regex num("([-])?([0-9])+([.]([0-9])+)?");
  // operators
  std::regex skip("(([|][|])|(&&)|(<!>)|(<->)|(<|>)(=)?|\\!|NOT|AND|OR|[*]|[+]|/|-|%|\\;|<-)");

  // iterate each line of code
  for (const auto it : file_tokens){
    // check if line starts with data type reserved keyword or with an identifier either store a new variable or search for it
    if (std::regex_match(it.second[0], data_type)) {
      // store new variable and its data type
      data_types_table.insert(std::pair(it.second[1], it.second[0]));
      type = it.second[0];
      start_index = 3;
    }
    else if (std::regex_match(it.second[0], identifier)) {
      // check if variable was defined previously
      if (data_types_table.find(it.second[0]) == data_types_table.end()) {
        temp = "Line " + std::to_string(it.first) + ": \"" + it.second[0] + "\" is not declared.";
        semantic_errors.push_back(temp);
        continue;
      }
      // update the type and index of the token to start the semantic analysis
      type = data_types_table[it.second[0]];
      start_index = 0;
    }
    else{
      continue;
    }
    // check if the variables data types involved in the operation are the same
    for (short token_index = start_index; token_index < it.second.size(); token_index++){
      // skip operators
      if (std::regex_match(it.second[token_index], skip)) {
        continue;
      }
      // continue operations since data types are correctly used
      else if (type == "NUM" && std::regex_match(it.second[token_index], num)){
        continue;
      }
      // continue operations since data types are correctly used
      else if ((type == "STR" || type == "STX") && std::regex_match(it.second[token_index], str)){
        continue;
      }
      // continue operations since data types are correctly used
      else if (type == data_types_table[it.second[token_index]]) {
        continue;
      }
      // data types do not match
      else{
        temp = "Line " + std::to_string(it.first) + ": \"" + it.second[token_index] + "\" operated with incompatible data type variables of " + type + " type.";
        semantic_errors.push_back(temp);
      }
    }
  }
  return semantic_errors;
}
