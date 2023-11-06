// necessary includes -------->
#include "../headers/automata.h"

Automata::Automata()
{
    // final states
    this->final_states = {
        {4, "#dtype"},   // NUM
        {5, "#logic"},   // NOT
        {8, "#rword"},   // LUP
        {11, "#rword"},  // RTN
        {14, "#dtype"},  // PTR
        {17, "#rword"},  // FUN
        {19, "#rword"},  // IF
        {21, "#logic"},  // OR
        {24, "#rword"},  // ELS
        {26, "#rword"},  // EIF
        {29, "#logic"},  // AND
        {31, "#dtype"},  // ARR
        {34, "#rword"},  // CMT
        {37, "#dtype"},  // STR
        {38, "#dtype"},  // STX
        {41, "#dtype"},  // TOF
        {43, "#id"},     // Identifier
        {47, "#macro"},  // $DEF
        {50, "#header"}, // $LIB
        {52, "#logic"},  // &&
        {54, "#logic"},  // ||
        {55, "#logic"},  // <
        {56, "#assign"}, // <-
        {57, "#logic"},  // <->
        {58, "#logic"},  // <=
        {60, "#logic"},  // <!>
        {61, "#logic"},  // >
        {62, "#logic"},  // >=
        {63, "#logic"},  // !
        {64, "#group"},  // (
        {65, "#group"},  // )
        {66, "#group"},  // {
        {67, "#group"},  // }
        {68, "#group"},  // [
        {69, "#group"},  // ]
        {70, "#math"},   // +
        {71, "#math"},   // -
        {72, "#math"},   // *
        {73, "#math"},   // /
        {74, "#math"},   // %
        {75, "#int"},    // int number
        {77, "#float"},  // float number
        {79, "#string"}, // 'string'
        {81, "#string"}, // "string"
        {82, "#eol"},    // ;
    };

    //? q0
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
        {std::regex("I"), 18},
        // OR
        {std::regex("O"), 20},
        // ELS | EIF
        {std::regex("E"), 22},
        // AND | ARR
        {std::regex("A"), 27},
        // CMT
        {std::regex("C"), 32},
        // STR | STX
        {std::regex("S"), 35},
        // TOF
        {std::regex("T"), 39},
        // identificador '_'
        {std::regex("_"), 42},
        // identificador
        {std::regex("[a-z]|[A-Z]"), 43},
        // $DEF | $LIB
        {std::regex("\\$"), 44},
        //&&
        {std::regex("&"), 51},
        //||
        {std::regex("\\|"), 53},
        //<->, <=, <!>
        {std::regex("<"), 55},
        //>=
        {std::regex(">"), 61},
        //!
        {std::regex("\\!"), 63},
        //(
        {std::regex("\\("), 64},
        //)
        {std::regex("\\)"), 65},
        //{
        {std::regex("\\{"), 66},
        //}
        {std::regex("\\}"), 67},
        //[
        {std::regex("\\["), 68},
        //]
        {std::regex("\\]"), 69},
        // //+
        {std::regex("\\+"), 70},
        // //-
        {std::regex("-"), 71},
        //*
        {std::regex("\\*"), 72},
        // /
        {std::regex("/"), 73},
        //%
        {std::regex("%"), 74},
        // 0-9
        {std::regex("[0-9]"), 75},
        // '
        {std::regex("\\'"), 78},
        // "
        {std::regex("\u0022"), 80},
        // ;
        {std::regex("\\;"), 82},
    });
    //? q1 | N
    this->transition_rules.push_back({
        {std::regex("U"), 2},
        {std::regex("O"), 3},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 43},
    });
    //? q2 | NU
    this->transition_rules.push_back({
        {std::regex("M"), 4},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 43},
    });
    //? q3 | NO
    this->transition_rules.push_back({
        {std::regex("T"), 5},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 43},
    });
    //* q4 | NUM
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 43},
    });
    //* q5 | NOT
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 43},
    });
    //? q6 | L
    this->transition_rules.push_back({
        {std::regex("U"), 7},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 43},
    });
    //? q7 | LU
    this->transition_rules.push_back({
        {std::regex("P"), 8},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 43},
    });
    //* q8 | LUP
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 43},
    });
    //? q9 | R
    this->transition_rules.push_back({
        {std::regex("T"), 10},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 43},
    });
    //? q10 | RT
    this->transition_rules.push_back({
        {std::regex("N"), 11},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 43},
    });
    //* q11 | RTN
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 43},
    });
    //? q12 | P
    this->transition_rules.push_back({
        {std::regex("T"), 13},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 43},
    });
    //? q13 | PT
    this->transition_rules.push_back({
        {std::regex("R"), 14},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 43},
    });
    //* q14 | PTR
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 43},
    });
    //? q15 | F
    this->transition_rules.push_back({
        {std::regex("U"), 16},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 43},
    });
    //? q16 | FU
    this->transition_rules.push_back({
        {std::regex("N"), 17},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 43},
    });
    //* q17 | FUN
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 43},
    });
    //? q18 | I
    this->transition_rules.push_back({
        {std::regex("F"), 19},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 43},
    });
    //* q19 | IF
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 43},
    });
    //? q20 | O
    this->transition_rules.push_back({
        {std::regex("R"), 21},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 43},
    });
    //* q21 | OR
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 43},
    });
    //? q22 | E
    this->transition_rules.push_back({
        {std::regex("L"), 23},
        {std::regex("I"), 25},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 43},
    });
    //? q23 | EL
    this->transition_rules.push_back({
        {std::regex("S"), 24},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 43},
    });
    //* q24 | ELS
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 43},
    });
    //? q25 | EI
    this->transition_rules.push_back({
        {std::regex("F"), 26},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 43},
    });
    //* q26 | EIF
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 43},
    });
    //? q27 | A
    this->transition_rules.push_back({
        {std::regex("N"), 28},
        {std::regex("R"), 30},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 43},
    });
    //? q28 | AN
    this->transition_rules.push_back({
        {std::regex("D"), 29},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 43},
    });
    //* q29 | AND
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 43},
    });
    //? q30 | AR
    this->transition_rules.push_back({
        {std::regex("R"), 31},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 43},
    });
    //* q31 | ARR
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 43},
    });
    //? q32 | C
    this->transition_rules.push_back({
        {std::regex("M"), 33},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 43},
    });
    //? q33 | CM
    this->transition_rules.push_back({
        {std::regex("T"), 34},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 43},
    });
    //* q34 | CMT
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 43},
    });
    //? q35 | S
    this->transition_rules.push_back({
        {std::regex("T"), 36},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 43},
    });
    //? q36 | ST
    this->transition_rules.push_back({
        {std::regex("R"), 37},
        {std::regex("X"), 38},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 43},
    });
    //* q37 | STR
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 43},
    });
    //* q38 | STX
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 43},
    });
    //? q39 | T
    this->transition_rules.push_back({
        {std::regex("O"), 40},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 43},
    });
    //? q340 | TO
    this->transition_rules.push_back({
        {std::regex("F"), 41},
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 43},
    });
    //* q41 | TOF
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 43},
    });
    //? q42 | _
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]"), 43},
    });
    //* q43 | _ o [a-Z]
    this->transition_rules.push_back({
        {std::regex("[a-z]|[A-Z]|[0-9]|_"), 43},
    });
    //? q44 | $
    this->transition_rules.push_back({
        {std::regex("D"), 43},
        {std::regex("L"), 46},
    });
    //? q45 | $D
    this->transition_rules.push_back({
        {std::regex("E"), 44},
    });
    //? q46 | $DE
    this->transition_rules.push_back({
        {std::regex("F"), 45},
    });
    //* q47 | $DEF
    this->transition_rules.push_back({});
    //? q48 | $L
    this->transition_rules.push_back({
        {std::regex("I"), 47},
    });
    //? q49 | $LI
    this->transition_rules.push_back({
        {std::regex("B"), 48},
    });
    //* q50 | $LIB
    this->transition_rules.push_back({});
    //? q51 | &
    this->transition_rules.push_back({
        {std::regex("&"), 50},
    });
    //* q52 | &&
    this->transition_rules.push_back({});
    //? q53 | |
    this->transition_rules.push_back({
        {std::regex("\\|"), 54},
    });
    //* q54 | ||
    this->transition_rules.push_back({});
    //* q55 | <
    this->transition_rules.push_back({
        {std::regex("-"), 56},
        {std::regex("="), 58},
        {std::regex("!"), 59},
    });
    //* q56 | <-
    this->transition_rules.push_back({
        {std::regex(">"), 57},
    });
    //* q57 | <->
    this->transition_rules.push_back({});
    //* q58 | <=
    this->transition_rules.push_back({});
    //? q59 | <!
    this->transition_rules.push_back({
        {std::regex(">"), 60},
    });
    //* q60 | <!>
    this->transition_rules.push_back({});
    //* q61 | >
    this->transition_rules.push_back({
        {std::regex("="), 60},
    });
    //* q62 | >=
    this->transition_rules.push_back({});
    //* q63 | !
    this->transition_rules.push_back({});
    //* q64 | (
    this->transition_rules.push_back({});
    //* q65 | )
    this->transition_rules.push_back({});
    //* q66 | {
    this->transition_rules.push_back({});
    //* q67 | }
    this->transition_rules.push_back({});
    //* q68 | [
    this->transition_rules.push_back({});
    //* q69 | ]
    this->transition_rules.push_back({});
    //* q70 | +
    this->transition_rules.push_back({});
    //* q71 | -
    this->transition_rules.push_back({
        {std::regex("[0-9]"), 75},
    });
    //* q72 | *
    this->transition_rules.push_back({});
    //* q73 | /
    this->transition_rules.push_back({});
    //* q74 | %
    this->transition_rules.push_back({});
    //* q75 | [0-9]
    this->transition_rules.push_back({
        {std::regex("[0-9]"), 75},
        {std::regex("\\."), 76},
    });
    //? q76 | [0-9] .
    this->transition_rules.push_back({
        {std::regex("[0-9]"), 77},
    });
    //* q77 | [0-9] .
    this->transition_rules.push_back({
        {std::regex("[0-9]"), 77},
    });
    //? q78 | '
    this->transition_rules.push_back({
        {std::regex("\\'"), 79},
        {std::regex("."), 78},
    });
    //* q79 | 'lo que sea'
    this->transition_rules.push_back({});
    //? q80 | "
    this->transition_rules.push_back({
        {std::regex("\u0022"), 81},
        {std::regex("."), 80},
    });
    //* q81 | "lo que sea"
    this->transition_rules.push_back({});
    //* q82 | ;
    this->transition_rules.push_back({});
}

void Automata::run(std::string line, std::map<std::string, std::string> &symbols_table, std::vector<unsigned> &line_errors, std::vector<std::string> &line_tokens)
{
    unsigned short state_index = 0;
    std::string temp_token = "";

    for (unsigned i = 0; i < line.length(); i++)
    {
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
            if (state_index == 34)
            {
                break;
            }
            else if (this->final_states.count(state_index) > 0)
            {
                symbols_table[temp_token] = this->final_states[state_index];
                line_tokens.push_back(temp_token);
            }
            else
            {
                line_errors.push_back(i);
                std::cout << "\nSimbolo No Reconocido: " << line[i] << std::endl;
            }

            if (!has_match)
            {
                if (!(line[i] == ' ' || line[i] == '\t' || state_index == 0))
                {
                    i--;
                }
            }
            temp_token = "";
            state_index = 0;
        }
    }
}