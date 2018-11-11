/// Class word, for storing language strings. Using "word" to avoid confusion with std::string

#pragma once

#include "alphabet.hpp"

class word {

    public:

    word(string);
    ~word();

    private:

    string word_;

};

