/// Class word, for storing language strings. Using "word" to avoid confusion with std::string

#pragma once

#include <string>
#include <iostream>

using namespace std;

class word {

    friend ostream &operator<<(ostream &, const word &);

    public:

    word();
    word(const char*);
    word(const word &);
    ~word();

    void add_character(word newCharacter);
    void clear_word();

    word& operator=(const word &comp);
    int operator==(const word &comp) const;
    int operator<(const word &comp) const;

    private:

    string word_;

};

