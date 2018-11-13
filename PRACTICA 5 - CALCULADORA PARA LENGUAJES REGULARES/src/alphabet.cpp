#include "alphabet.hpp"


alphabet::alphabet(){

    set<word> symbols_;

}


alphabet::alphabet(const word symbol){

}



set<word> alphabet::get_symbols(){
    return this->symbols_;
}


void alphabet::insert_symbol(word symbol){
    
   symbols_.insert(symbol);
}

bool alphabet::is_symbol_in_alphabet(word symbol){

    if (symbols_.find(symbol) != symbols_.end()){
        return true;
    }
        return false;
}







// lo mismo hay que poner un setter




/*
void alphabet::parse_alphabet(){

}
*/

alphabet::~alphabet(){


}