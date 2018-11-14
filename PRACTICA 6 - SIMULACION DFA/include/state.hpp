#pragma once

#include <set>

#include "transition.hpp"

using namespace std;


class state {

    public:

    state();
    state(int id, bool isFinal);

    int get_stateId();
    bool isStateFinal();

    //aquí mete tres más

    int get_transition_number(); //return tamaño de state_
    char get_char(int i);       //return caracter en el elemento i
    int get_next_state(int i);  // return nex state en el elemento i

    // a ver cómo las modificas



    void add_transition(char character, int nextState);
    // este es el método que invoca al constructor de la transición


    private:

    int stateId_;
    
    //bool initialState; // esto va en el DFA, ¿¿¿creo???
        
    set<transition> state_; //vector de transiciones
    bool isFinalState_;

    // bool deathState; //esto no

};


// SI USAS SETS LO MISMO HARÁ FALTA METER LOS OPERADORES