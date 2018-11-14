#pragma once


class transition{


    public:

    transition(); //no debería hacer falta ???
    transition(char character, int nextState);
    ~transition();

    char get_character();
    int get_next_state();


    private:

    //cada transición es un par de elementos: carácter y siguiente estado
    char character_;
    int nextState_;


};




// SI USAS SETS DE CARACTERES VAS A NECESITAR METER LOS OPERADORES, SEGURO