// necessary includes -------->
#include "../headers/automata.h"

// functions definition -------->
// constructor that initializes the transition rules and final states of the automata
Automata::Automata()
{
    // final states
    this->final_states = {
        {4, "#dtype"},   // NUM
        {5, "#logic"},   // NOT
        {8, "#lup"},   // LUP
        {11, "#rword"},  // RTN
        {14, "#dtype"},  // PTR
        {17, "#rword"},  // FUN
        {21, "#bool"},   // FALSE
        {23, "#if"},  // IF
        {25, "#logic"},  // OR
        {28, "#els"},  // ELS
        {30, "#eif"},  // EIF
        {33, "#logic"},  // AND
        {35, "#dtype"},  // ARR
        {38, "#rword"},  // CMT
        {41, "#dtype"},  // STR
        {42, "#dtype"},  // STX
        {45, "#dtype"},  // TOF
        {48, "#bool"},   // TRUE
        {50, "#id"},     // Identifier
        {54, "#macro"},  // $DEF
        {57, "#header"}, // $LIB
        {59, "#logic"},  // &&
        {61, "#logic"},  // ||
        {62, "#logic"},  // <
        {63, "#assign"}, // <-
        {64, "#logic"},  // <->
        {65, "#logic"},  // <=
        {67, "#logic"},  // <!>
        {68, "#logic"},  // >
        {69, "#logic"},  // >=
        {70, "#logic"},  // !
        {71, "#group"},  // (
        {72, "#group"},  // )
        {73, "#llavea"},  // {
        {74, "#llavec"},  // }
        {75, "#group"},  // [
        {76, "#group"},  // ]
        {77, "#math"},   // +
        {78, "#math"},   // -
        {79, "#math"},   // *
        {80, "#math"},   // /
        {81, "#math"},   // %
        {82, "#int"},    // int number
        {84, "#float"},  // float number
        {86, "#string"}, // 'string'
        {88, "#string"}, // "string"
        {89, "#eol"}     // ;
    };

    // transition rules
    this->transition_rules.push_back({
        // NUM | NOT
        {std::regex("N"), 1},
        // LUP
        {std::regex("L"), 6},
        // RTN
        {std::regex("R"), 9},
        // PTR
        {std::regex("P"), 12},
        // FUN
        {std::regex("F"), 15},
        // IF
        {std::regex("I"), 22},
        // OR
        {std::regex("O"), 24},
        // ELS | EIF
        {std::regex("E"), 26},
        // AND | ARR
        {std::regex("A"), 31},
        // CMT
        {std::regex("C"), 36},
        // STR | STX
        {std::regex("S"), 39},
        // TOF | TRUE
        {std::regex("T"), 43},
        // identificador '_'
        {std::regex("_"), 49},
        // identificador
        {std::regex("[a-z]|[A-Z]"), 50},
        // $DEF | $LIB
        {std::regex("\\$"), 51},
        // &&
        {std::regex("&"), 58},
        // ||
        {std::regex("\\|"), 60},
        // <->, <=, <!>
        {std::regex("<"), 62},
        // >=
        {std::regex(">"), 68},
        // !
        {std::regex("\\!"), 70},
        // (
        {std::regex("\\("), 71},
        // )
        {std::regex("\\)"), 72},
        // {
        {std::regex("\\{"), 73},
        // }
        {std::regex("\\}"), 74},
        // [
        {std::regex("\\["), 75},
        // ]
        {std::regex("\\]"), 76},
        // +
        {std::regex("\\+"), 77},
        // -
        {std::regex("-"), 78},
        // *
        {std::regex("\\*"), 79},
        // /
        {std::regex("/"), 80},
        // %
        {std::regex("%"), 81},
        // 0-9
        {std::regex("[0-9]"), 82},
        // '
        {std::regex("\\'"), 85},
        // "
        {std::regex("\u0022"), 87},
        // ;
        {std::regex("\\;"), 89},
    });
    //? q1 | N
    this->transition_rules.push_back({
        {std::regex("U"), 2},
        {std::regex("O"), 3},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 50},
    });
    //? q2 | NU
    this->transition_rules.push_back({
        {std::regex("M"), 4},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 50},
    });
    //? q3 | NO
    this->transition_rules.push_back({
        {std::regex("T"), 5},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 50},
    });
    //* q4 | NUM
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 50},
    });
    //* q5 | NOT
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 50},
    });
    //? q6 | L
    this->transition_rules.push_back({
        {std::regex("U"), 7},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 50},
    });
    //? q7 | LU
    this->transition_rules.push_back({
        {std::regex("P"), 8},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 50},
    });
    //* q8 | LUP
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 50},
    });
    //? q9 | R
    this->transition_rules.push_back({
        {std::regex("T"), 10},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 50},
    });
    //? q10 | RT
    this->transition_rules.push_back({
        {std::regex("N"), 11},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 50},
    });
    //* q11 | RTN
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 50},
    });
    //? q12 | P
    this->transition_rules.push_back({
        {std::regex("T"), 13},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 50},
    });
    //? q13 | PT
    this->transition_rules.push_back({
        {std::regex("R"), 14},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 50},
    });
    //* q14 | PTR
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 50},
    });
    //? q15 | F
    this->transition_rules.push_back({
        {std::regex("U"), 16},
        {std::regex("A"), 18},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 50},
    });
    //? q16 | FU
    this->transition_rules.push_back({
        {std::regex("N"), 17},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 50},
    });
    //* q17 | FUN
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 50},
    });
    //? q18 | FA
    this->transition_rules.push_back({
        {std::regex("L"), 19},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 50},
    });
    //? q19 | FAL
    this->transition_rules.push_back({
        {std::regex("S"), 20},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 50},
    });
    //? q20 | FALS
    this->transition_rules.push_back({
        {std::regex("E"), 21},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 50},
    });
    //* q21 | FALSE
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 50},
    });
    //? q22 | I
    this->transition_rules.push_back({
        {std::regex("F"), 23},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 50},
    });
    //* q23 | IF
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 50},
    });
    //? q24 | O
    this->transition_rules.push_back({
        {std::regex("R"), 25},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 50},
    });
    //* q25 | OR
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 50},
    });
    //? q26 | E
    this->transition_rules.push_back({
        {std::regex("L"), 27},
        {std::regex("I"), 29},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 50},
    });
    //? q27 | EL
    this->transition_rules.push_back({
        {std::regex("S"), 28},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 50},
    });
    //* q28 | ELS
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 50},
    });
    //? q29 | EI
    this->transition_rules.push_back({
        {std::regex("F"), 30},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 50},
    });
    //* q30 | EIF
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 50},
    });
    //? q31 | A
    this->transition_rules.push_back({
        {std::regex("N"), 32},
        {std::regex("R"), 34},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 50},
    });
    //? q32 | AN
    this->transition_rules.push_back({
        {std::regex("D"), 33},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 50},
    });
    //* q33 | AND
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 50},
    });
    //? q34 | AR
    this->transition_rules.push_back({
        {std::regex("R"), 35},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 50},
    });
    //* q35 | ARR
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 50},
    });
    //? q36 | C
    this->transition_rules.push_back({
        {std::regex("M"), 37},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 50},
    });
    //? q37 | CM
    this->transition_rules.push_back({
        {std::regex("T"), 38},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 50},
    });
    //* q38 | CMT
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 50},
    });
    //? q39 | S
    this->transition_rules.push_back({
        {std::regex("T"), 40},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 50},
    });
    //? q40 | ST
    this->transition_rules.push_back({
        {std::regex("R"), 41},
        {std::regex("X"), 42},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 50},
    });
    //* q41 | STR
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 50},
    });
    //* q42 | STX
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 50},
    });
    //? q43 | T
    this->transition_rules.push_back({
        {std::regex("O"), 44},
        {std::regex("R"), 46},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 50},
    });
    //? q44 | TO
    this->transition_rules.push_back({
        {std::regex("F"), 45},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 50},
    });
    //* q45 | TOF
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 50},
    });
    //? q46 | TR
    this->transition_rules.push_back({
        {std::regex("U"), 47},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 50},
    });
    //? q47 | TRU
    this->transition_rules.push_back({
        {std::regex("E"), 48},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 50},
    });
    //* q48 | TRUE
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 50},
    });
    //? q49 | _
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]"), 50},
    });
    //* q50 | _ o [a-Z]
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 50},
    });
    //? q51 | $
    this->transition_rules.push_back({
        {std::regex("D"), 52},
        {std::regex("L"), 53},
    });
    //? q52 | $D
    this->transition_rules.push_back({
        {std::regex("E"), 53},
    });
    //? q53 | $DE
    this->transition_rules.push_back({
        {std::regex("F"), 54},
    });
    //* q54 | $DEF
    this->transition_rules.push_back({});
    //? q55 | $L
    this->transition_rules.push_back({
        {std::regex("I"), 56},
    });
    //? q56 | $LI
    this->transition_rules.push_back({
        {std::regex("B"), 57},
    });
    //* q57 | $LIB
    this->transition_rules.push_back({});
    //? q58 | &
    this->transition_rules.push_back({
        {std::regex("&"), 59},
    });
    //* q59 | &&
    this->transition_rules.push_back({});
    //? q60 | |
    this->transition_rules.push_back({
        {std::regex("\\|"), 61},
    });
    //* q61 | ||
    this->transition_rules.push_back({});
    //* q62 | <
    this->transition_rules.push_back({
        {std::regex("-"), 63},
        {std::regex("="), 65},
        {std::regex("!"), 66},
    });
    //* q63 | <-
    this->transition_rules.push_back({
        {std::regex(">"), 64},
    });
    //* q64 | <->
    this->transition_rules.push_back({});
    //* q65 | <=
    this->transition_rules.push_back({});
    //? q66 | <!
    this->transition_rules.push_back({
        {std::regex(">"), 67},
    });
    //* q67 | <!>
    this->transition_rules.push_back({});
    //* q68 | >
    this->transition_rules.push_back({
        {std::regex("="), 67},
    });
    //* q69 | >=
    this->transition_rules.push_back({});
    //* q70 | !
    this->transition_rules.push_back({});
    //* q71 | (
    this->transition_rules.push_back({});
    //* q72 | )
    this->transition_rules.push_back({});
    //* q73 | {
    this->transition_rules.push_back({});
    //* q74 | }
    this->transition_rules.push_back({});
    //* q75 | [
    this->transition_rules.push_back({});
    //* q76 | ]
    this->transition_rules.push_back({});
    //* q77 | +
    this->transition_rules.push_back({});
    //* q78 | -
    this->transition_rules.push_back({
        {std::regex("[0-9]"), 82},
    });
    //* q79 | *
    this->transition_rules.push_back({});
    //* q80 | /
    this->transition_rules.push_back({});
    //* q81 | %
    this->transition_rules.push_back({});
    //* q82 | [0-9]
    this->transition_rules.push_back({
        {std::regex("[0-9]"), 82},
        {std::regex("\\."), 83},
    });
    //? q83 | [0-9] .
    this->transition_rules.push_back({
        {std::regex("[0-9]"), 84},
    });
    //* q84 | [0-9] .
    this->transition_rules.push_back({
        {std::regex("[0-9]"), 84},
    });
    //? q85 | '
    this->transition_rules.push_back({
        {std::regex("\\'"), 86},
        {std::regex("."), 85},
    });
    //* q86 | 'lo que sea'
    this->transition_rules.push_back({});
    //? q87 | "
    this->transition_rules.push_back({
        {std::regex("\u0022"), 88},
        {std::regex("."), 87},
    });
    //* q88 | "lo que sea"
    this->transition_rules.push_back({});
    //* q89 | ;
    this->transition_rules.push_back({});
}

void Automata::run(std::string line, std::map<std::string, std::string> &symbols_table, std::vector<unsigned> &line_errors, std::vector<std::string> &line_tokens)
{
    unsigned short state_index = 0;
    std::string temp_token = "";
    bool has_match{false};

    for (unsigned i = 0; i < line.length(); i++)
    {
        // get character to evaluate
        std::string char_to_validate(1, line[i]);
        has_match = false;
        // check if the current character has a transition available
        for (transition_struct state : this->transition_rules[state_index])
        {
            if (std::regex_match(char_to_validate, state.transition))
            {
                state_index = state.next_state;
                // indicate a match exists
                has_match = true;
                // store the current character in a temporal token
                temp_token += line[i];
                break;
            }
        }

        // no matching transition rule for the character was found
        if (!has_match || i == line.length() - 1)
        {
            if (state_index == 38)
            {
                break;
            }
            // check if state index is contained inside the final states
            else if (this->final_states.count(state_index) > 0)
            {
                // add the temporal token to the symbols table and its type
                symbols_table[temp_token] = this->final_states[state_index];
                line_tokens.push_back(temp_token);
            }
            // save column number where the error/not matching character is found and output it
            else
            {
                if (!(line[i] == ' ' || line[i] == '\t')) 
                {
                    line_errors.push_back(i);
                    std::cout << "\nSymbol Not Recognised: " << line[i] << std::endl;
                }
            }
            // check if current character is not a white space, a tab or it is not accepted by the automata
            if (!has_match)
            {
                if (!(line[i] == ' ' || line[i] == '\t' || state_index == 0))
                {
                    // move back one character to start the analysis again
                    i--;
                }
            }
            // empty temporal token
            temp_token = "";
            state_index = 0;
        }
    }
}
