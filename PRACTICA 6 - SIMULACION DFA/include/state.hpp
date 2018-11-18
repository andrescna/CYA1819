#pragma once

#include <set>

#include "transition.hpp"

using namespace std;


class state {

    public:

    state();
    state(char id, char isFinalState);

    char get_stateId();
    bool get_isStateFinal();
    set<transition> get_transitionSet();

    // lo mismo no hacen falta (?)
    void set_stateId(char);
    void set_isStateFinal(bool);

    //aquí mete tres más

    int get_transitionNumber(); //return tamaño de state_
    

    // estas no las has usado
    char get_char(int i);       //return caracter en el elemento i
    int get_next_state(int i);  // return nex state en el elemento i

    // a ver cómo las modificas

    void add_transition(char character, char nextState);
    // este es el método que invoca al constructor de la transición

    state& operator=(const state &rhs);
    int operator==(const state &rhs) const;
    int operator<(const state &rhs) const;

    private:

    char stateId_;
    
    //bool initialState; // esto va en el DFA, ¿¿¿creo???
        
    set<transition> transitionSet_; //vector de transiciones
    bool isFinalState_;

    // bool deathState; //esto no

};


// SI USAS SETS LO MISMO HARÁ FALTA METER LOS OPERADORES