// necessary includes -------->
#include <vector>
#include <map>
#include <regex>
#include <string>
#include <iostream>

class Automata
{
private:
    struct transition_struct
    {
        const std::regex transition;
        const unsigned short next_state;
    };

    std::vector<std::vector<struct transition_struct>> transition_rules;

    std::map<const unsigned short, std::string> final_states;

public:
    Automata(void);
    void run(std::string, std::map<std::string, std::string> &, std::vector<unsigned> &);
};