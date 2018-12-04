
/*! \brief  Implementación de una transición.
*
*   Esta clase implementa una transición de un estado de un Autómata Finito (sea DFA o NFA). Para 
*   ello consta de una dupla de elementos: el caracter de la cadena que lee el automata y el 
*   siguiente estado para ese caracter.
*
*   Además se definen los getters para acceder al caracter y al siguiente estado, además de los
*   los métodos de sobrecarga de operadores necesarios al usar un set de transiciones en la 
*   clase state.  
*/

#pragma once

class transition{

    private:

    char character_;            /*!< Caracter leído por el automata */
    char nextState_;            /*!< Siguiente estado */
    
    public:

    transition();
    transition(char character, char nextState);
    ~transition();

    char get_character();
    char get_next_state();

    transition& operator=(const transition &rhs);
    int operator==(const transition &rhs) const;
    int operator<(const transition &rhs) const;

};
