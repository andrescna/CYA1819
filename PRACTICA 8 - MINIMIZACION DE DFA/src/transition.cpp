#include "transition.hpp"

//! Constructor por defecto
transition::transition(){} 

//! Destructor
transition::~transition(){}

//! Constructor
transition::transition(char character, char nextState){
    character_ = character;
    nextState_ = nextState;   
}

///////////////////////////////////////  METODOS DE CLASE TRANSITION ////////////////////////////////////////

///////////////////////////// GETTERS /////////////////////

//! Devuelve caracter leído por automata
char transition::get_character(){
   return character_;
}

//! Devuelve siguiente estado
char transition::get_next_state(){
   return nextState_;
}


///////////////////////////// OPERATOR OVERLOAD //////////////////////////

//! Sobrecarga operador =
transition& transition::operator=(const transition &rhs){
   this->character_ = rhs.character_;
   this->nextState_ = rhs.nextState_;
   return *this;
}

//! Sobrecarga operador ==
int transition::operator==(const transition &rhs) const{
   if( this->character_ != rhs.character_) return 0;
   if( this->nextState_ != rhs.nextState_) return 0;
   return 1;
}

// This function is required for built-in STL list functions like sort
// o para containers de tipo ordinal como <set>

//! Sobrecarga operador <
int transition::operator<(const transition &rhs) const{
   if( this->character_== rhs.character_ && this->nextState_ < rhs.nextState_) return 1;
   if( this->character_ < rhs.character_ ) return 1;
   return 0;
}
