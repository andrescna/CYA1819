/*! \brief  Implementación de un NFA.
*
*   Esta clase implementa un Autómata Finito No determinista (NFA), que formalmente está formado por
*   un conjunto de estados, un estado inicial, un conjunto de estados finales o de aceptación, un
*   alfabeto y una función de transición.
*   En este caso la implementación se lleva a cabo definiendo un número total de estados, un estado
*   inicial, un conjunto de estados implementado como un std::set y un alfabeto implementado como
*   un std::char.
*

                        ARREGLA ESTO



                        
*   Además se definen los métodos necesarios para llevar a cabo las operaciones que se nos piden en
*   los requisitos: leer, mostrar, calcular los estados de muerte, calcular estados importantes, 
*   comprobar si es un DFA y analizar una cadena para ver si el NFA la reconoce.
*
*   Para la práctica 8 se añaden los métodos para minimizar un DFA (puesto que a fin de cuentas un
*   DFA es un caso particular de NFA con las restricciones de una única transición por cada símbolo
*   del alfabeto para cada estado y el no poder tener epsilon-transiciones, por lo que se puede
*   representar con la misma estructura de un NFA), almacenar en memoria el nuevo DFA minimizado
*   sustituyendo los datos del cargado actualmente y un método auxiliar para guardar el NFA/DFA 
*   almacenado en un archivo (que simplemente es el método show_NFA() pero mandando la salida a un
*   fichero y no a cout)  
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