// necessary includes -------->
#include <vector>
#include <map>
#include <string>
#include <iostream>

class Sintactico
{
    private:
        std::map<int, std::vector<std::string>> tokens;
        std::map<std::string, std::string> symbol_table;
        int tokens_index;
        int line_index;
    public:
        Sintactico(void);
        void analisis_sintactico();


};