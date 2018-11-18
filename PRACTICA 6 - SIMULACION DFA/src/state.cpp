#include "state.hpp"

state::state(){
}


state::state(char id, char isFinalState){
    stateId_ = id;
    if (isFinalState == '1')
        isFinalState_ = true; 
    else
        isFinalState_ = false;
}



//// GETTERS

char state::get_stateId(){
     return stateId_;
}

bool state::get_isStateFinal(){
        return isFinalState_;
}

set<transition> state::get_transitionSet(){
    return transitionSet_;
}

int state::get_transitionNumber(){
    return transitionSet_.size();
}

////// OPERATOR OVERLOAD

state& state::operator=(const state &rhs){
   this->stateId_ = rhs.stateId_;
   this->isFinalState_ = rhs.isFinalState_;
   this->transitionSet_ = rhs.transitionSet_;

   return *this;
}

int state::operator==(const state &rhs) const{
   if( this->stateId_ != rhs.stateId_) return 0;
   if( this->isFinalState_ != rhs.isFinalState_) return 0;
   //aquí lo mismo deberías meter el set de transiciones, pero :shrug:
   return 1;
}

// This function is required for built-in STL list functions like sort
// o para containers de tipo ordinal como <set>

int state::operator<(const state &rhs) const
{
   // esta no debería hacer falta
   //f( this->stateId_== rhs.stateId_ && this->isFinalState_< rhs.isFinalState_) return 1;
   if( this->stateId_ < rhs.stateId_ ) return 1;
   return 0;
   // con esto debería bastar para comparar (?)
}


    int get_transition_number(); //return tamaño de state_
    char get_char(int i);       //return caracter en el elemento i
    int get_next_state(int i);  // return nex state en el elemento i

    // a ver cómo las modificas

void state::add_transition(char character, char nextState) {

    transition temp(character, nextState);
    transitionSet_.insert(temp);

}