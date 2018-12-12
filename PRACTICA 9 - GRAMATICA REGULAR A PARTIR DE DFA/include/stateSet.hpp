
/*! \brief  Implementación de un conjunto de estados para minimizar un NFA a DFA
*
*   Esta clase implementa la definición de un subconjunto de estados de un DFA. Consta de un
*   set de estados y un ID que funciona como nuevo identificador del estado a la hora de construir
*   el DFA.
*
*   Además se implementan los métodos para imprimir un conjunto de stateSets por consola y para sub-
*   dividir un stateSet en varios subestados de acuerdo a las transiciones de los estados que lo 
*   conforman. 
*/

#pragma once

#include "state.hpp"

#include <vector>
#include <iostream>


class stateSet{

    private:

    set<state> set_;                /*!< Conjunto de estados de nuestro subestado */
    char setId_;                    /*!< Identificador de estado */

    public:

    stateSet();
    stateSet(set<state> subset);
    stateSet(state newState, char id);
    ~stateSet();

    void insert_state(state);
    set<state> get_states();
    char get_id();
    void set_id(int i);

    int operator==(const stateSet &rhs) const;
};

void show_stateSet(vector<stateSet> PI, int index);
vector<stateSet> create_new_partition(vector<stateSet> PI, set<char> alphabet, int index);