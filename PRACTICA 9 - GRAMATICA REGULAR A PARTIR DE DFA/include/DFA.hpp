/*! \brief  Implementación de un DFA.
*
*   Esta clase implementa un Autómata Finito Determinista (NFA), que formalmente está formado por
*   un conjunto de estados, un estado inicial, un conjunto de estados finales o de aceptación, un
*   alfabeto y una función de transición.
*   En este caso la implementación se lleva a cabo definiendo un número total de estados, un estado
*   inicial, un conjunto de estados implementado como un std::set de elementos de clase state
*   y un alfabeto implementado como un std::char.
*                  
*   Además se definen los métodos necesarios para llevar a cabo las operaciones que se nos piden en
*   los requisitos: leer, mostrar, calcular los estados de muerte y analizar una cadena para ver si
*   el DFA la reconoce.
*
*   Para la práctica 9 se añade el método para generar una gramática regular a partir del DFA que
*   tengamos cargado en memoria. Esta convierte los símbolos del alfabeto del DFA en símbolos no
*   terminales de la GR, cada uno de los estados en un símbolo no terminal y el conjunto de transiciones
*   pasa a ser un conjunto de producciones. 
*/

#pragma once

#include <string>
#include <fstream>
#include <iostream>

#include "state.hpp"
#include "GR.hpp"


class DFA{

    private:

    int totalStates_;       /*!< Número de estados */
    char initialState_;     /*!< Estado inicial */
    set<state> states_;     /*!< Conjunto de estados */
    set<char> alphabet_;    /*!< Alfabeto */

    public:

    DFA();
    ~DFA();
    
    int read_DFA(string file);
    void show_DFA();
    void calc_death_states();
    int analyze_word(string word); 
    GR convert_to_GR();

};