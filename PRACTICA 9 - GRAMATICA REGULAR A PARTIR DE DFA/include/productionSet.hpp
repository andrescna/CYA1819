/*! \class productionSet
*   \brief  Implementación de un conjunto de producciones
*

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
    
    //void add_transition(char character, char nextState);

    productionSet& operator=(const productionSet &rhs);
    int operator==(const productionSet &rhs) const;
    int operator<(const productionSet &rhs) const;
};
