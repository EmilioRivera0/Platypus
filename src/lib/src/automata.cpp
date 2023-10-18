// necessary includes -------->
#include "../headers/automata.h"

Automata::Automata()
{
    // final states
    this->final_states = {
        {3, "#rword"},   // NUM
        {6, "#rword"},   // LUP
        {9, "#rword"},   // RTN
        {12, "#rword"},  // PTR
        {15, "#rword"},  // FUN
        {17, "#rword"},  // IF
        {19, "#rword"},  // OR
        {22, "#rword"},  // ELS
        {24, "#rword"},  // EIF
        {27, "#rword"},  // AND
        {29, "#rword"},  // ARR
        {32, "#rword"},  // CMT
        {35, "#rword"},  // STR
        {36, "#rword"},  // STX
        {39, "#rword"},  // TOF
        {41, "#id"},     // Identifier
        {45, "#macro"},  // $DEF
        {48, "#header"}, // $LIB
        {50, "#logic"},  // &&
        {52, "#logic"},  // ||
        {53, "#logic"},  // <
        {54, "#assign"}, // <-
        {55, "#logic"},  // <->
        {56, "#logic"},  // <=
        {58, "#logic"},  // <!>
        {59, "#logic"},  // >
        {60, "#logic"},  // >=
        {61, "#group"},  // (
        {62, "#group"},  // )
        {63, "#group"},  // {
        {64, "#group"},  // }
        {65, "#group"},  // [
        {66, "#group"},  // ]
        {67, "#math"},   // +
        {68, "#math"},   // -
        {69, "#math"},   // *
        {70, "#math"},   // /
        {71, "#math"},   // %
        {72, "#int"},    // int number
        {74, "#float"},  // float number
        {76, "#string"}, // 'string'
        {78, "#string"}, // "string"
        {79, "#eol"},    // ;
    };

    //? q0
    this->transition_rules.push_back({
        // NUM
        {std::regex("N"), 1},
        // LUP
        {std::regex("L"), 4},
        // RTN
        {std::regex("R"), 7},
        // PTR
        {std::regex("P"), 10},
        // FUN
        {std::regex("F"), 13},
        // IF
        {std::regex("I"), 16},
        // OR
        {std::regex("O"), 18},
        // ELS | EIF
        {std::regex("E"), 20},
        // AND | ARR
        {std::regex("A"), 25},
        // CMT
        {std::regex("C"), 30},
        // STR | STX
        {std::regex("S"), 31},
        // TOF
        {std::regex("T"), 34},
        // identificador '_'
        {std::regex("_"), 40},
        // identificador
        {std::regex("[a-z]|[A-Z]"), 41},
        // $DEF | $LIB
        {std::regex("\\$"), 42},
        //&&
        {std::regex("&"), 49},
        //||
        {std::regex("\\|"), 51},
        //<->, <=, <!>
        {std::regex("<"), 53},
        //>=
        {std::regex(">"), 59},
        //(
        {std::regex("\\("), 61},
        //)
        {std::regex("\\)"), 62},
        //{
        {std::regex("\\{"), 63},
        //}
        {std::regex("\\}"), 64},
        //[
        {std::regex("\\["), 65},
        //]
        {std::regex("\\]"), 66},
        // //+
        {std::regex("\\+"), 67},
        // //-
        {std::regex("-"), 68},
        //*
        {std::regex("\\*"), 69},
        // /
        {std::regex("/"), 70},
        //%
        {std::regex("%"), 71},
        // 0-9
        {std::regex("[0-9]"), 72},
        // '
        {std::regex("\\'"), 75},
        // "
        {std::regex("\u0022"), 77},
        // ;
        {std::regex("\\;"), 79},
    });
    //? q1 | N
    this->transition_rules.push_back({
        {std::regex("U"), 2},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 41},
    });
    //? q2 | NU
    this->transition_rules.push_back({
        {std::regex("M"), 3},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 41},
    });
    //* q3 | NUM
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 41},
    });
    //? q4 | L
    this->transition_rules.push_back({
        {std::regex("U"), 5},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 41},
    });
    //? q5 | LU
    this->transition_rules.push_back({
        {std::regex("P"), 6},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 41},
    });
    //* q6 | LUP
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 41},
    });
    //? q7 | R
    this->transition_rules.push_back({
        {std::regex("T"), 8},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 41},
    });
    //? q8 | RT
    this->transition_rules.push_back({
        {std::regex("N"), 9},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 41},
    });
    //* q9 | RTN
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 41},
    });
    //? q10 | P
    this->transition_rules.push_back({
        {std::regex("T"), 11},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 41},
    });
    //? q11 | PT
    this->transition_rules.push_back({
        {std::regex("R"), 12},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 41},
    });
    //* q12 | PTR
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 41},
    });
    //? q13 | F
    this->transition_rules.push_back({
        {std::regex("U"), 14},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 41},
    });
    //? q14 | FU
    this->transition_rules.push_back({
        {std::regex("N"), 15},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 41},
    });
    //* q15 | FUN
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 41},
    });
    //? q16 | I
    this->transition_rules.push_back({
        {std::regex("F"), 17},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 41},
    });
    //* q17 | IF
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 41},
    });
    //? q18 | O
    this->transition_rules.push_back({
        {std::regex("R"), 19},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 41},
    });
    //* q19 | OR
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 41},
    });
    //? q20 | E
    this->transition_rules.push_back({
        {std::regex("L"), 21},
        {std::regex("I"), 23},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 41},
    });
    //? q21 | EL
    this->transition_rules.push_back({
        {std::regex("S"), 22},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 41},
    });
    //* q22 | ELS
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 41},
    });
    //? q23 | EI
    this->transition_rules.push_back({
        {std::regex("F"), 24},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 41},
    });
    //* q24 | EIF
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 41},
    });
    //? q25 | A
    this->transition_rules.push_back({
        {std::regex("N"), 26},
        {std::regex("R"), 28},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 41},
    });
    //? q26 | AN
    this->transition_rules.push_back({
        {std::regex("D"), 27},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 41},
    });
    //* q27 | AND
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 41},
    });
    //? q28 | AR
    this->transition_rules.push_back({
        {std::regex("R"), 29},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 41},
    });
    //* q29 | ARR
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 41},
    });
    //? q30 | C
    this->transition_rules.push_back({
        {std::regex("M"), 31},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 41},
    });
    //? q31 | CM
    this->transition_rules.push_back({
        {std::regex("T"), 32},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 41},
    });
    //* q32 | CMT
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 41},
    });
    //? q33 | S
    this->transition_rules.push_back({
        {std::regex("T"), 34},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 41},
    });
    //? q34 | ST
    this->transition_rules.push_back({
        {std::regex("R"), 35},
        {std::regex("X"), 36},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 41},
    });
    //* q35 | STR
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 41},
    });
    //* q36 | STX
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 41},
    });
    //? q37 | T
    this->transition_rules.push_back({
        {std::regex("O"), 38},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 41},
    });
    //? q38 | TO
    this->transition_rules.push_back({
        {std::regex("F"), 39},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 41},
    });
    //* q39 | TOF
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 41},
    });
    //? q40 | _
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]"), 41},
    });
    //* q41 | _ o [a-Z]
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 41},
    });
    //? q42 | $
    this->transition_rules.push_back({
        {std::regex("D"), 43},
        {std::regex("L"), 46},
    });
    //? q43 | $D
    this->transition_rules.push_back({
        {std::regex("E"), 44},
    });
    //? 4q4 | $DE
    this->transition_rules.push_back({
        {std::regex("F"), 45},
    });
    //* q45 | $DEF
    this->transition_rules.push_back({});
    //? q46 | $L
    this->transition_rules.push_back({
        {std::regex("I"), 47},
    });
    //? q47 | $LI
    this->transition_rules.push_back({
        {std::regex("B"), 48},
    });
    //* q48 | $LIB
    this->transition_rules.push_back({});
    //? q49 | &
    this->transition_rules.push_back({
        {std::regex("&"), 50},
    });
    //* q50 | &&
    this->transition_rules.push_back({});
    //? q51 | |
    this->transition_rules.push_back({
        {std::regex("\\|"), 52},
    });
    //* q52 | ||
    this->transition_rules.push_back({});
    //* q53 | <
    this->transition_rules.push_back({
        {std::regex("-"), 54},
        {std::regex("="), 56},
        {std::regex("!"), 57},
    });
    //* q54 | <-
    this->transition_rules.push_back({
        {std::regex(">"), 55},
    });
    //* q55 | <->
    this->transition_rules.push_back({});
    //* q56 | <=
    this->transition_rules.push_back({});
    //? q57 | <!
    this->transition_rules.push_back({
        {std::regex(">"), 23},
    });
    //* q58 | <!>
    this->transition_rules.push_back({});
    //* q59 | >
    this->transition_rules.push_back({
        {std::regex("="), 60},
    });
    //* q60 | >=
    this->transition_rules.push_back({});
    //* q61 | (
    this->transition_rules.push_back({});
    //* q62 | )
    this->transition_rules.push_back({});
    //* q63 | {
    this->transition_rules.push_back({});
    //* q64 | }
    this->transition_rules.push_back({});
    //* q65 | [
    this->transition_rules.push_back({});
    //* q66 | ]
    this->transition_rules.push_back({});
    //* q67 | +
    this->transition_rules.push_back({});
    //* q68 | -
    this->transition_rules.push_back({});
    //* q69 | *
    this->transition_rules.push_back({});
    //* q70 | /
    this->transition_rules.push_back({});
    //* q71 | %
    this->transition_rules.push_back({});
    //* q72 | [0-9]
    this->transition_rules.push_back({
        {std::regex("[0-9]"), 72},
        {std::regex("\\."), 73},
    });
    //? q73 | [0-9] .
    this->transition_rules.push_back({
        {std::regex("[0-9]"), 74},
    });
    //* q74 | [0-9] .
    this->transition_rules.push_back({
        {std::regex("[0-9]"), 74},
    });
    //? q75 | '
    this->transition_rules.push_back({
        {std::regex("\\'"), 76},
        {std::regex("."), 75},
    });
    //* q76 | 'lo que sea'
    this->transition_rules.push_back({});
    //? q77 | "
    this->transition_rules.push_back({
        {std::regex("\u0022"), 78},
        {std::regex("."), 77},
    });
    //* q78 | "lo que sea"
    this->transition_rules.push_back({});
    //* q79 | ;
    this->transition_rules.push_back({});
}

void Automata::run(std::string line)
{
    std::cout << line << std::endl;

    unsigned short state_index = 0;
    std::string temp_token = "";

    for (unsigned i = 0; i < line.length(); i++)
    {
        // std::cout << state_index << std::endl;
        // std::cout << line[i] << std::endl;

        std::string char_to_validate(1, line[i]);
        bool has_match = false;

        for (transition_struct state : this->transition_rules[state_index])
        {
            if (std::regex_match(char_to_validate, state.transition))
            {
                state_index = state.next_state;
                has_match = true;
                temp_token += line[i];
                break;
            }
        }

        if (!has_match || i == line.length() - 1)
        {
            if (this->final_states.count(state_index) > 0)
            {
                std::cout << this->final_states[state_index] << std::endl;
                std::cout << temp_token << std::endl;
                temp_token = "";
            }
            else
            {
                std::cout << "Error" << std::endl;
                std::cout << temp_token << std::endl;
            }

            if (!has_match)
            {
                if (!(line[i] == ' ' || line[i] == '\t'))
                {
                    i--;
                }
            }
            state_index = 0;
        }
    }
}