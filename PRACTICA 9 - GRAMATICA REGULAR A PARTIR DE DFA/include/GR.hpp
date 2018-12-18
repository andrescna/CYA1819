/*! \brief  Implementación de una gramática regular.
*
*   Esta clase implementa una gramática regular, que formalmente está formada por
*   un conjunto de simbolos terminales, un conjunto de símbolos no terminanes, un
*   símbolo no terminal de arranque y un conjunto de producciones para cada símbolo.
*                     
*   Además se definen los métodos necesarios para llevar a cabo las operaciones que se 
*   nos piden en los requisitos: crearla, mostrarla por pantalla y escribirla a archivo.
*/

#pragma once

#include <set>
#include <string>
#include <iostream>
#include <fstream>

#include "productionSet.hpp"

using namespace std;

class GR {

    private:

    set<char> alphabet_;                /*!< Alfabeto */
    char startSymbol_;                  /*!< Símbolo no terminal de arranque */
    set<productionSet> productions_;    /*!< Conjunto de producciones */

    public:

    GR();
    GR(set<char> alphabet, char startSymbol, set<productionSet> productions);
    ~GR();

    void show_GR();
    void write_to_file(string output);

};