//// Andrés Concepción Afonso
//// CyA 2018-19

//////////////////// The Wall ////////////////////////



#include <vector>
#include <iostream>

#include "wall.hpp"
#include "common.hpp"

using namespace std;

int main(){
    
    int wallLength, wallHeight;

    // creamos los bloques predefinidos 
    block bloque1(2,1);
    block bloque2(3,1);

    cout << endl << "————————————————————————————————————————————" << endl;
    cout <<  "CYA 1819 — Práctica 4 - Construyendo un muro" << endl;
    cout <<  "————————————————————————————————————————————" << endl;
    cout << "Este programa calcula muros" << endl << endl;

    // pedir datos muro
    cout << "Por favor introduzca la anchura del muro:" << endl;
    cin >> wallLength;
    cout << "Introduzca la altura del muro:" << endl;
    cin >> wallHeight;

    
    //calculamos las filas posibles con esos bloques
    
    vector<row> filas = calc_valid_rows(bloque1, bloque2, wallLength);

    cout << endl << "Para un muro de dimensiones "<< wallLength << " de ancho y " << wallHeight << " de alto con bloques 2x1 y 3x1 hay:" << endl << endl;
    cout << "_______________________" << endl;
    cout << "|| " << filas.size() << " filas posibles ||" << endl;
    cout << "———————————————————————" << endl << endl;

    cout << "Las filas posibles se muestran a continuación:" << endl << endl;

    for (int i=0; i<filas.size(); i++){
        filas[i].write(cout);

    }

    //calculamos los muros posibles Y VÁLIDOS para los parámetros dados

    vector<wall> muros = calc_valid_walls(filas,wallLength, wallHeight);

    cout << endl << "Usando filas válidas hay un total de:" << endl << endl;
    cout << "______________________________" << endl;
    cout << "|| " << muros.size() << " muros válidos posibles ||" << endl;
    cout << "——————————————————————————————" << endl << endl;
    cout << endl << "¿Desea imprimirlos por pantalla?" << endl;

    char option;
    cin >> option;

    cout << endl;

    switch (option){

        case 'y':
                for (int i=0; i<muros.size(); i++){
                        cout << "Muro " << i+1 << endl;
                        muros[i].write(cout);
                }
        break;


        case 'n':
        cout << "Programa finalizado "<< endl;
        break;


        default:
        cout << "Error. Por defecto no se muestran los muros" << endl;
        break;

    }
}
