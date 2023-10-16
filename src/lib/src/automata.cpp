// necessary includes -------->
#include "../headers/automata.h"

Automata::Automata(){
    //final states
    this->final_states = {
        3: "NUM",
        74: "#id",
        75: "final"
    };

    this->transition_rules = {
        // RESERVED WORDS-----------
        //q0
        {
            // NUM
            transition_struct(std::regex("N"), 1),
            // $DEF | $LIB
            transition_struct(std::regex("$"), 4),
            //LUP
            transition_struct(std::regex("L"), 11),
            //&&
            transition_struct(std::regex("&"), 14),
            //||
            transition_struct(std::regex("|"), 16),
            //<->, <=, <!>
            transition_struct(std::regex("<"), 18),
            //>=
            transition_struct(std::regex(">"), 24),
            //(
            transition_struct(std::regex("("), 26),
            //)
            transition_struct(std::regex(")"), 27),
            //{
            transition_struct(std::regex("{"), 28),
            //}
            transition_struct(std::regex("}"), 29),
            //[
            transition_struct(std::regex("("), 30),
            //]
            transition_struct(std::regex(")"), 31),
            //+
            transition_struct(std::regex("+"), 32),
            //-
            transition_struct(std::regex("-"), 33),
            //*
            transition_struct(std::regex("*"), 34),
            // /
            transition_struct(std::regex("/"), 35),
            //%
            transition_struct(std::regex("%"), 36),
            // 0-9
            transition_struct(std::regex("[0-9]"), 37),
            //RTN
            transition_struct(std::regex("R"), 40),
            //PTR
            transition_struct(std::regex("P"), 43),
            //FUN
            transition_struct(std::regex("F"), 46),
            //IF
            transition_struct(std::regex("I"), 49),
            //OR
            transition_struct(std::regex("O"), 51),
            //ELS | EIF
            transition_struct(std::regex("E"), 53),
            //AND | ARR
            transition_struct(std::regex("A"), 58),
            //CMT
            transition_struct(std::regex("C"), 63),
            //STR | STX
            transition_struct(std::regex("S"), 66),
            //TOF
            transition_struct(std::regex("T"), 70),
            //identificador '_'
            transition_struct(std::regex("_"), 73),
            //identificador
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9]"), 74),
        },
        //q1
        {
            transition_struct(std::regex("U"), 2),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 74)
        },
        //q2
        {
            transition_struct(std::regex("M"), 3),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 74)
        },
        //q3
        {
            transition_struct(std::regex("#NUM"), 75)
        },
        //q4
        {
            transition_struct(std::regex("D"), 5),
            transition_struct(std::regex("L"), 8),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 74)
        },
        //q5
        {
            transition_struct(std::regex("E"), 6),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 74)
        },
        //q6
        {
            transition_struct(std::regex("F"), 7),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 74)
        },
        //q7
        {
            transition_struct(std::regex("#$DEF"), 75)
        },
        //q8
        {
            transition_struct(std::regex("I"), 9),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 74)
        },
        //q9
        {
            transition_struct(std::regex("B"), 10),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 74)
        },
        //q10
        {
            transition_struct(std::regex("#$LIB"), 75)
        },
        //q11
        {
            transition_struct(std::regex("U"), 12),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 74)
        },
        //q12
        {
            transition_struct(std::regex("P"), 13),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 74)
        },
        //q13
        {
            transition_struct(std::regex("#LUP"), 75)
        },
        //q14
        {
            transition_struct(std::regex("&"), 15)
        },
        //q15
        {
            transition_struct(std::regex("#&&"), 75)
        },
        //q16
        {
            transition_struct(std::regex("|"), 17)
        },
        //q17
        {
            transition_struct(std::regex("#||"), 75)
        },
        //q18
        {
            transition_struct(std::regex("-"), 19),
            transition_struct(std::regex("="), 21),
            transition_struct(std::regex("!"), 22)
        },
        //q19
        {
            transition_struct(std::regex(">"), 20)
        },
        //q20
        {
            transition_struct(std::regex("#<->"), 75)
        },
        //q21
        {
            transition_struct(std::regex("#<="), 75)
        },
        //q22
        {
            transition_struct(std::regex(">"), 23)
        },
        //q23
        {
            transition_struct(std::regex("#<!>"), 75)
        },
        //q24
        {
            transition_struct(std::regex("="), 25)
        },
        //q25
        {
            transition_struct(std::regex("#>="), 75)
        },
        //q26
        {
            transition_struct(std::regex("#("), 75)
        },
        //q27
        {
            transition_struct(std::regex("#)"), 75)
        },
        //q28
        {
            transition_struct(std::regex("#{"), 75)
        },
        //q29
        {
            transition_struct(std::regex("#}"), 75)
        },
        //q30
        {
            transition_struct(std::regex("#["), 75)
        },
        //q31
        {
            transition_struct(std::regex("#]"), 75)
        },
        //q32
        {
            transition_struct(std::regex("#+"), 75)
        },
        //q33
        {
            transition_struct(std::regex("#-"), 75)
        },
        //q34
        {
            transition_struct(std::regex("#*"), 75)
        },
        //q35
        {
            transition_struct(std::regex("#/"), 75)
        },
        //q36
        {
            transition_struct(std::regex("#%"), 75)
        },
        //q37
        {
            transition_struct(std::regex("[0-9]"), 37),
            transition_struct(std::regex("."), 38),
            transition_struct(std::regex("#entero"), 75)
        },
        //q38
        {
            transition_struct(std::regex("[0-9]"), 39)
        },
        //q39
        {
            transition_struct(std::regex("[0-9]"), 39),
            transition_struct(std::regex("#decimal"), 75)
        },
        //q40
        {
            transition_struct(std::regex("T"), 41),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 74)
        },
        //q41
        {
            transition_struct(std::regex("N"), 42),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 74)
        },
        //q42
        {
            transition_struct(std::regex("#RTN"), 75)
        },
        //q43
        {
            transition_struct(std::regex("T"), 44),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 74)
        },
        //q44
        {
            transition_struct(std::regex("R"), 45),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 74)
        },
        //q45
        {
            transition_struct(std::regex("#PTR"), 75)
        },
        //q46
        {
            transition_struct(std::regex("U"), 47),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 74)
        },
        //q47
        {
            transition_struct(std::regex("N"), 48),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 74)
        },
        //q48
        {
            transition_struct(std::regex("#FUN"), 75)
        },
        //q49
        {
            transition_struct(std::regex("F"), 50),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 74)
        },
        //q50
        {
            transition_struct(std::regex("#IF"), 75)
        },
        //q51
        {
            transition_struct(std::regex("R"), 52),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 74)
        },
        //q52
        {
            transition_struct(std::regex("#rword"), 75)
        },
        //q53
        {
            transition_struct(std::regex("L"), 54),
            transition_struct(std::regex("I"), 56),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 74)
        },
        //q54
        {
            transition_struct(std::regex("S"), 55),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 74)
        },
        //q55
        {
            transition_struct(std::regex("#rword"), 75)
        },
        //q56
        {
            transition_struct(std::regex("F"), 57),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 74)
        },
        //q57
        {
            transition_struct(std::regex("#rword"), 75)
        },
        //q58
        {
            transition_struct(std::regex("N"), 59),
            transition_struct(std::regex("R"), 61),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 74)
        },
        //q59
        {
            transition_struct(std::regex("D"), 60),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 74)
        },
        //q60
        {
            transition_struct(std::regex("#rword"), 75)
        },
        //q61
        {
            transition_struct(std::regex("R"), 62),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 74)
        },
        //q62
        {
            transition_struct(std::regex("#rword"), 75)
        },
        //q63
        {
            transition_struct(std::regex("M"), 64),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 74)
        },
        //q64
        {
            transition_struct(std::regex("T"), 65),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 74)
        },
        //q65
        {
            transition_struct(std::regex("#rword"), 75)
        },
        //q66
        {
            transition_struct(std::regex("T"), 67),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 74)
        },
        //q67
        {
            transition_struct(std::regex("R"), 68),
            transition_struct(std::regex("X"), 69),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 74)
        },
        //q68
        {
            transition_struct(std::regex("#rword"), 75)
        },
        //q69
        {
            transition_struct(std::regex("#rword"), 75)
        },
        //q70
        {
            transition_struct(std::regex("O"), 71),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 74)
        },
        //q71
        {
            transition_struct(std::regex("F"), 72),
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 74)
        },
        //q72
        {
            transition_struct(std::regex("#rword"), 75)
        },
        //q73
        {
            transition_struct(std::regex("[a-z] | [A-Z]"), 74)
        },
        //q74
        {
            transition_struct(std::regex("[a-z] | [A-Z] | [0-9] | _"), 74),
            transition_struct(std::regex("#id"), 75)
        }
    };

}

Automata::run(){
    char cadena[3] = "NUM";
    int i, j;
    int current_state = 0;
    std::cmatch m;
    bool keep_transitions=false;
    for(i=0; i<3; i++){
        for(j=0; j<this->transition_rules[current_state].size; j++){
            this->transition_rules[current_state][std::regex_match(cadena[i], m, this->transition_rules[current_state][j].transition)];
            if(keep_transitions){
                current_state = this->transition_rules[current_state][j].next_state;
                break;
            }
        }
        if(!keep_transitions){
            std::cout<<"\nERROR\n";
            break;
        }
        keep_transitions = false;
    }
    
}