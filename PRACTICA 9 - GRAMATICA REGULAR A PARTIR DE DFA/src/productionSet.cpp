#include "productionSet.hpp"

//! Constructor por defecto
productionSet::productionSet(){}

//! Constructor 
productionSet::productionSet(char nonTerminal, set<string> productions){
    nonTerminal_ = nonTerminal;
    productions_ = productions;
}

///////////////////////////////////////  METODOS DE CLASE STATE ////////////////////////////////////////

//////// SETTERS Y GETTERS

//! Devuelve identificador del estado
char productionSet::get_nonTerminal(){
     return nonTerminal_;
}

void productionSet::set_nonTerminal(char id){
    nonTerminal_ = id;
}

//! Devuelve el conjunto de transiciones
set<string> productionSet::get_productions(){
    return productions_;
}

//! Añadir transición al estado.
void productionSet::add_production(string production) {
    productions_.insert(production);
}

/////////////// OPERATOR OVERLOAD //////////////////////////

//! Sobrecarga operador =
productionSet& productionSet::operator=(const productionSet &rhs){
   this->nonTerminal_ = rhs.nonTerminal_;
   this->productions_ = rhs.productions_;
   return *this;
}

//! Sobrecarga operador ==
int productionSet::operator==(const productionSet &rhs) const{
   if( this->nonTerminal_ != rhs.nonTerminal_) return 0;
   if( this->productions_ != rhs.productions_) return 0;

   return 1;
}

// This function is required for built-in STL list functions like sort
// o para containers de tipo ordinal como <set>

//! Sobrecarga operador <
int productionSet::operator<(const productionSet &rhs) const{
   if( this->nonTerminal_ < rhs.nonTerminal_ ) return 1;
   return 0;
}
