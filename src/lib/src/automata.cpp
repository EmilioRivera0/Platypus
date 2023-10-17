// necessary includes -------->
#include "../headers/automata.h"

Automata::Automata()
{
    // final states
    this->final_states = {
        {3, '#rword'},   // NUM
        {6, '#rword'},   // LUP
        {9, '#rword'},   // RTN
        {12, '#rword'},  // PTR
        {15, '#rword'},  // FUN
        {17, '#rword'},  // IF
        {19, '#rword'},  // OR
        {22, '#rword'},  // ELS
        {24, '#rword'},  // EIF
        {27, '#rword'},  // AND
        {29, '#rword'},  // ARR
        {32, '#rword'},  // CMT
        {35, '#rword'},  // STR
        {36, '#rword'},  // STX
        {39, '#rword'},  // TOF
        {41, '#id'},     // Identifier
        {45, '#macro'},  // $DEF
        {48, '#header'}, // $LIB
        {50, '#logic'},  // &&
        {52, '#logic'},  // ||
        {53, '#logic'},  // <
        {54, '#assign'}, // <-
        {55, '#logic'},  // <->
        {56, '#logic'},  // <=
        {58, '#logic'},  // <!>
        {59, '#logic'},  // >
        {60, '#logic'},  // >=
        {61, '#group'},  // (
        {62, '#group'},  // )
        {63, '#group'},  // {
        {64, '#group'},  // }
        {65, '#group'},  // [
        {66, '#group'},  // ]
        {67, '#math'},   // +
        {68, '#math'},   // -
        {69, '#math'},   // *
        {70, '#math'},   // /
        {71, '#math'},   // %
        {72, '#int'},    // int number
        {74, '#float'},  // float number
    };

    this->transition_rules = {
        {
            //? q0
            // NUM
            transition_struct(std::regex("N"), 1),
            // LUP
            transition_struct(std::regex("L"), 4),
            // RTN
            transition_struct(std::regex("R"), 7),
            // PTR
            transition_struct(std::regex("P"), 10),
            // FUN
            transition_struct(std::regex("F"), 13),
            // IF
            transition_struct(std::regex("I"), 16),
            // OR
            transition_struct(std::regex("O"), 18),
            // ELS | EIF
            transition_struct(std::regex("E"), 20),
            // AND | ARR
            transition_struct(std::regex("A"), 25),
            // CMT
            transition_struct(std::regex("C"), 30),
            // STR | STX
            transition_struct(std::regex("S"), 31),
            // TOF
            transition_struct(std::regex("T"), 34),
            // identificador '_'
            transition_struct(std::regex("_"), 40),
            // identificador
            transition_struct(std::regex("[a-z] | [A-Z]"), 41),
            // $DEF | $LIB
            transition_struct(std::regex("$"), 42),
            //&&
            transition_struct(std::regex("&"), 49),
            //||
            transition_struct(std::regex("|"), 51),
            //<->, <=, <!>
            transition_struct(std::regex("<"), 53),
            //>=
            transition_struct(std::regex(">"), 59),
            //(
            transition_struct(std::regex("("), 61),
            //)
            transition_struct(std::regex(")"), 62),
            //{
            transition_struct(std::regex("{"), 63),
            //}
            transition_struct(std::regex("}"), 64),
            //[
            transition_struct(std::regex("("), 65),
            //]
            transition_struct(std::regex(")"), 66),
            //+
            transition_struct(std::regex("+"), 67),
            //-
            transition_struct(std::regex("-"), 68),
            //*
            transition_struct(std::regex("*"), 69),
            // /
            transition_struct(std::regex("/"), 70),
            //%
            transition_struct(std::regex("%"), 71),
            // 0-9
            transition_struct(std::regex("[0-9]"), 72),
        },
        {
            //? q1 | N
            transition_struct(std::regex("U"), 2),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 41),
        },
        {
            //? q2 | NU
            transition_struct(std::regex("M"), 3),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 41),
        },
        {
            //* q3 | NUM
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 41),
        },
        {
            //? q4 | L
            transition_struct(std::regex("U"), 5),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 41),
        },
        {
            //? q5 | LU
            transition_struct(std::regex("P"), 6),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 41),
        },
        {
            //* q6 | LUP
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 41),
        },
        {
            //? q7 | R
            transition_struct(std::regex("T"), 8),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 41),
        },
        {
            //? q8 | RT
            transition_struct(std::regex("N"), 9),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 41),
        },
        {
            //* q9 | RTN
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 41),
        },
        {
            //? q10 | P
            transition_struct(std::regex("T"), 11),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 41),
        },
        {
            //? q11 | PT
            transition_struct(std::regex("R"), 12),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 41),
        },
        {
            //* q12 | PTR
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 41),
        },
        {
            //? q13 | F
            transition_struct(std::regex("U"), 14),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 41),
        },
        {
            //? q14 | FU
            transition_struct(std::regex("N"), 15),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 41),
        },
        {
            //* q15 | FUN
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 41),
        },
        {
            //? q16 | I
            transition_struct(std::regex("F"), 17),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 41),
        },
        {
            //* q17 | IF
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 41),
        },
        {
            //? q18 | O
            transition_struct(std::regex("R"), 19),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 41),
        },
        {
            //* q19 | OR
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 41),
        },
        {
            //? q20 | E
            transition_struct(std::regex("L"), 21),
            transition_struct(std::regex("I"), 23),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 41),
        },
        {
            //? q21 | EL
            transition_struct(std::regex("S"), 22),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 41),
        },
        {
            //* q22 | ELS
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 41),
        },
        {
            //? q23 | EI
            transition_struct(std::regex("F"), 24),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 41),
        },
        {
            //* q24 | EIF
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 41),
        },
        {
            //? q25 | A
            transition_struct(std::regex("N"), 26),
            transition_struct(std::regex("R"), 28),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 41),
        },
        {
            //? q26 | AN
            transition_struct(std::regex("D"), 27),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 41),
        },
        {
            //* q27 | AND
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 41),
        },
        {
            //? q28 | AR
            transition_struct(std::regex("R"), 29),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 41),
        },
        {
            //* q29 | ARR
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 41),
        },
        {
            //? q30 | C
            transition_struct(std::regex("M"), 31),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 41),
        },
        {
            //? q31 | CM
            transition_struct(std::regex("T"), 32),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 41),
        },
        {
            //* q32 | CMT
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 41),
        },
        {
            //? q33 | S
            transition_struct(std::regex("T"), 34),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 41),
        },
        {
            //? q34 | ST
            transition_struct(std::regex("R"), 35),
            transition_struct(std::regex("X"), 36),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 41),
        },
        {
            //* q35 | STR
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 41),
        },
        {
            //* q36 | STX
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 41),
        },
        {
            //? q37 | T
            transition_struct(std::regex("O"), 38),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 41),
        },
        {
            //? q38 | TO
            transition_struct(std::regex("F"), 39),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 41),
        },
        {
            //* q39 | TOF
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 41),
        },
        {
            //? q40 | _
            transition_struct(std::regex("[a-z] | [A-Z]"), 41),
        },
        {
            //* q41 | _ o [a-Z]
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 41),
        },
        {
            //? q42 | $
            transition_struct(std::regex("D"), 43),
            transition_struct(std::regex("L"), 46),
        },
        {
            //? q43 | $D
            transition_struct(std::regex("E"), 44),
        },
        {
            //? 44 | $DE
            transition_struct(std::regex("F"), 45),
        },
        {
            //* q45 | $DEF
        },
        {
            //? q46 | $L
            transition_struct(std::regex("I"), 47),
        },
        {
            //? q47 | $LI
            transition_struct(std::regex("B"), 48),
        },
        {
            //* q48 | $LIB
        },
        {
            //? q49 | &
            transition_struct(std::regex("&"), 50),
        },
        {
            //* q50 | &&
        },
        {
            //? q51 | |
            transition_struct(std::regex("|"), 52),
        },
        {
            //* q52 | ||
        },
        {
            //* q53 | <
            transition_struct(std::regex("-"), 54),
            transition_struct(std::regex("="), 56),
            transition_struct(std::regex("!"), 57),
        },
        {
            //* q54 | <-
            transition_struct(std::regex(">"), 55),
        },
        {
            //* q55 | <->
        },
        {
            //* q56 | <=
        },
        {
            //? q57 | <!
            transition_struct(std::regex(">"), 23),
        },
        {
            //* q58 | <!>
        },
        {
            //* q59 | >
            transition_struct(std::regex("="), 60),
        },
        {
            //* q60 | >=
        },
        {
            //* q61 | (
        },
        {
            //* q62 | )
        },
        {
            //* q63 | {
        },
        {
            //* q64 | }
        },
        {
            //* q65 | [
        },
        {
            //* q66 | ]
        },
        {
            //* q67 | +
        },
        {
            //* q68 | -
        },
        {
            //* q69 | *
        },
        {
            //* q70 | /
        },
        {
            //* q71 | %
        },
        {
            //* q72 | [0-9]
            transition_struct(std::regex("[0-9]"), 72),
            transition_struct(std::regex("."), 73),
        },
        {
            //? q73 | [0-9] .
            transition_struct(std::regex("[0-9]"), 74),
        },
        {
            //* q74 | [0-9] .
            transition_struct(std::regex("[0-9]"), 74),
        },
    };
}

Automata::run()
{
    char cadena[3] = "NUM";
    int i, j;
    int current_state = 0;
    std::cmatch m;
    bool keep_transitions = false;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < this->transition_rules[current_state].size; j++)
        {
            this->transition_rules[current_state][std::regex_match(cadena[i], m, this->transition_rules[current_state][j].transition)];
            if (keep_transitions)
            {
                current_state = this->transition_rules[current_state][j].next_state;
                break;
            }
        }
        if (!keep_transitions)
        {
            std::cout << "\nERROR\n";
            break;
        }
        keep_transitions = false;
    }
}