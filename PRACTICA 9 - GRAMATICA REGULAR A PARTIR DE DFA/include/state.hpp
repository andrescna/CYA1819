/*! \class state
*   \brief  Implementación de un estado.
*
*   Esta clase implementa el estado de un Autómata Finito (sea DFA o NFA). Para ello consta de un
*   identificador de estado, un bool que almacena si es estado final o de aceptación y un conjunto
*   de transiciones para dicho estado.
*
*   Además se definen los getters para acceder al identificador de estado, a si es inicial, al nº
*   de transiciones de dicho estado y al conjunto de transiciones.
*
*   También se define un método para añadir transiciones al estado y los métodos de sobrecarga de
*   operadores necesarios al usar un set de estados en la clase NFA.  
*/

#pragma once

#include <set>

#include "transition.hpp"

using namespace std;


class state {

    private:

    char stateId_;                          /*!< Identificador de estado */
    bool isFinalState_;                     /*!< ¿És de aceptación? */

    set<transition> transitionSet_;         /*!< Conjunto de transiciones */

    public:

    state();
    state(char id, char isFinalState);

    char get_stateId();
    void set_stateId(char id);
    bool get_isStateFinal();
    void set_isStateFinal(bool isfinal);
    set<transition> get_transitionSet();
    int get_transitionNumber(); 

    void add_transition(char character, char nextState);

    state& operator=(const state &rhs);
    int operator==(const state &rhs) const;
    int operator<(const state &rhs) const;
};
