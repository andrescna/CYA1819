#include "word.hpp"


word::word(){

        word_ = "";
}


//CREO
word::word(const char* newWord){
        word_ += newWord;
}


//THISISFINE??????
void word::add_character(word newCharacter){

        word_.append(newCharacter.word_);
        //word_.append(newCharacter);
}

//constructor de copia, porque :shrug:
word::word(const word &copy){
        word_ = copy.word_;
}

void word::clear_word(){
        word_.clear();
}


/// ostream

ostream &operator<<(ostream &output, const word &printedWord){

        output << printedWord.word_ << endl;
        return output;

}

///// sobrecarga de operadores, porque :shrug:

word& word::operator=(const word &comp)
{
        this->word_ = comp.word_;
        return *this;
}

int word::operator==(const word &comp) const
{
        if (this->word_ != comp.word_) return 0;
        return 1;
}

int word::operator<(const word &comp) const{

        if (this->word_ < comp.word_) return 1;
        return 0;
}

word::~word()
{}