#ifndef AUTOMATA_H
#define AUTOMATA_H

// necessary includes -------->
#include <vector>
#include <map>
#include <regex>
#include <string>
#include <iostream>

// class declaration -------->
class Automata
{
private:
    // basic struct containing the transition and the state that it leads to
    struct transition_struct{
        const std::regex transition;
        const unsigned short next_state;
    };
    // vector of transition_structs representing the transition rules of the automata
    std::vector<std::vector<struct transition_struct>> transition_rules;
    // vector containing the final states of the automata
    std::map<const unsigned short, std::string> final_states;

public:
    Automata(void);
    // start the lexical analysis
    void run(std::string, std::map<std::string, std::string> &, std::vector<unsigned> &);
};

#endif // !AUTOMATA_H
