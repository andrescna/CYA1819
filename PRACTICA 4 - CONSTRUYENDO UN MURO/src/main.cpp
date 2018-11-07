//// Andrés Concepción Afonso
//// alu0100600216
//// CyA 2018-2019

//////////////////// The Wall ////////////////////////



#include <vector>
#include <iostream>

#include "wall.hpp"
#include "common.hpp"

using namespace std;

int main(){
    
    int wallLenght, wallHeight;

    // pedir anchura muro
    cout << "Introduzca la anchura del muro:" << endl;
    cin >> wallLenght;
    // pedir altura muro
    cout << "introduzca la altura del muro" << endl;
    cin >> wallHeight;


            cout << "alto-> " << wallHeight << " ancho-> " << wallLenght << endl;


    cout << "holamundo" << endl;

    // creamos los bloques
    block bloque1(2,1);
    block bloque2(3,1);

    cout << bloque1.get_lenght() << endl;




//calculamos las filas posibles con esos bloques

    vector<row> filas = calc_valid_rows(bloque1, bloque2, wallLenght);

    cout << "si esto funciona debería dar " << filas.size() << "filas" << endl;

    for (int i=0; i<5; i++){
        filas[i].write(cout);


    }


    // calcular muros posibles

    //imprimir muro


}