#pragma once

using namespace std;


class block {

    public:

    block();
    block(int l, int h);
    ~block();

    int get_lenght();

    private:

    int blockLenght;
    int blockHeight;

};