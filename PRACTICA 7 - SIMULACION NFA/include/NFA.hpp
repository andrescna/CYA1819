
/*! \brief  Implementación de un NFA.
*
*   Esta clase implementa un Autómata Finito No determinista (NFA), que formalmente está formado por
*   un conjunto de estados, un estado inicial, un conjunto de estados finales o de aceptación, un
*   alfabeto y una función de transición.
*   En este caso la implementación se lleva a cabo definiendo un número total de estados, un estado
*   inicial, un conjunto de estados implementado como un std::set y un alfabeto implementado como
*   un std::char.
*
*   Además se definen los métodos necesarios para llevar a cabo las operaciones que se nos piden en
*   los requisitos: leer, mostrar, calcular los estados de muerte, calcular estados importantes, 
*   comprobar si es un DFA y analizar una cadena para ver si el NFA la reconoce.  
*/

#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

#include "state.hpp"


class NFA{

    private:

    int totalStates_;               /*!< Número de estados */
    char initialState_;             /*!< Estado inicial */
    set<state> setStates_;          /*!< Conjunto de estados */
    set<char> alphabet_;            /*!< Alfabeto */

    public:

    NFA();
    ~NFA();
    
    int read_NFA(string filename);
    void show_NFA();
    void calc_death_states();
    void calc_important_states();
    void is_DFA();
    void analyze_word(string word); 

};