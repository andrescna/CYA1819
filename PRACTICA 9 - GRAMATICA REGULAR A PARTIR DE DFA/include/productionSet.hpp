/*! \class productionSet
*   \brief  Implementación de un conjunto de producciones
*
*   Esta clase implementa, de forma análoga a la clase estado para DFAs/NFAs, un conjunto
*   de producciones productions_ para un determinado símbolo no terminal nonTerminal_
*   
*   Implementa métodos para acceder/modificar el no terminal, acceder y añadir producciones
*   y la sobrecarga de operadores necesaria al tener que implementar un set<productionSet>
*   en la clase GR.
*/

#pragma once

#include <set>
#include <string>

using namespace std;

class productionSet {

    private:

    char nonTerminal_;                          /*!< Identificador símbolo no terminal*/
    set<string> productions_;                     /*!< Conjunto de producciones */

    public:

    productionSet();
    productionSet(char nonTerminal, set<string> productions);

    char get_nonTerminal();
    void set_nonTerminal(char id);
    
    set<string> get_productions();
    void add_production(string production);

    productionSet& operator=(const productionSet &rhs);
    int operator==(const productionSet &rhs) const;
    int operator<(const productionSet &rhs) const;
};
