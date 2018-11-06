//// Andrés Concepción Afonso
//// alu0100600216
//// CyA 2018-2019

//////////////////// The Wall ////////////////////////



#include <vector>
#include <iostream>

#include "wall.hpp"

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




    // calcular (bloques)
    // calcular filas posibles


    // calcular muros posibles

    //imprimir muro


}