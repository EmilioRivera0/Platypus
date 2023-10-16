// necessary includes -------->
#include <vector>
#include <map>
#include <regex>
#include <string>

class Automata {

private:
    struct transition_struct {
        const std::regex transition;
        const unsigned short next_state;
    };

    std::string currentState;

    std::vector<std::vector<struct transition_struct>> transition_rules;

    std::map<const unsigned short, std::string> final_states;

public:
    Automata (void);
    void run(void);
}