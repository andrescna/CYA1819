#pragma once

using namespace std;

class block {

    public:

    block();
    block(int, int);
    ~block();

    int get_lenght();
    int get_height();

    private:

    int blockLenght;
    int blockHeight;

};