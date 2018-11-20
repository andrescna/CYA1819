#include "transition.hpp"


transition::transition(){} 

transition::~transition(){}

transition::transition(char character, char nextState){
    character_ = character;
    nextState_ = nextState;   
}

//////// GETTERS

char transition::get_character(){
   return character_;
}

char transition::get_next_state(){
   return nextState_;
}


////// OPERATOR OVERLOAD

transition& transition::operator=(const transition &rhs){
   this->character_ = rhs.character_;
   this->nextState_ = rhs.nextState_;
   return *this;
}

int transition::operator==(const transition &rhs) const{
   if( this->character_ != rhs.character_) return 0;
   if( this->nextState_ != rhs.nextState_) return 0;
   return 1;
}

// This function is required for built-in STL list functions like sort
// o para containers de tipo ordinal como <set>

int transition::operator<(const transition &rhs) const{
   if( this->character_== rhs.character_ && this->nextState_ < rhs.nextState_) return 1;
   if( this->character_ < rhs.character_ ) return 1;
   return 0;
}
