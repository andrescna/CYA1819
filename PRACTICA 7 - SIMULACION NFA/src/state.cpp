#include "state.hpp"

//! Constructor por defecto
state::state(){}

//! Constructor 
state::state(char id, char isFinalState){
    stateId_ = id;
    if (isFinalState == '1')
        isFinalState_ = true; 
    else
        isFinalState_ = false;
}

///////////////////////////////////////  METODOS DE CLASE STATE ////////////////////////////////////////

//////// GETTERS

//! Devuelve identificador del estado
char state::get_stateId(){
     return stateId_;
}

//! Devuelve si el estado es final
bool state::get_isStateFinal(){
        return isFinalState_;
}

//! Devuelve el conjunto de transiciones
set<transition> state::get_transitionSet(){
    return transitionSet_;
}
//! Devuelve el número de transiciones de ese estado
int state::get_transitionNumber(){
    return transitionSet_.size();
}

//! Añadir transición al estado.
void state::add_transition(char character, char nextState) {
    transition temp(character, nextState);
    transitionSet_.insert(temp);
}

/////////////// OPERATOR OVERLOAD //////////////////////////

//! Sobrecarga operador =
state& state::operator=(const state &rhs){
   this->stateId_ = rhs.stateId_;
   this->isFinalState_ = rhs.isFinalState_;
   this->transitionSet_ = rhs.transitionSet_;

   return *this;
}

//! Sobrecarga operador ==
int state::operator==(const state &rhs) const{
   if( this->stateId_ != rhs.stateId_) return 0;
   if( this->isFinalState_ != rhs.isFinalState_) return 0;

   return 1;
}

// This function is required for built-in STL list functions like sort
// o para containers de tipo ordinal como <set>

//! Sobrecarga operador <
int state::operator<(const state &rhs) const{
   if( this->stateId_ < rhs.stateId_ ) return 1;
   return 0;
}
