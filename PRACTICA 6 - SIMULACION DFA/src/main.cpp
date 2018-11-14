//// Andrés Concepción Afonso
//// CYA 2018-19

/// PRACTICA 6 - SIMULADOR DFA ///
/// Este simula un autómata finito determinista o DFA ///

#include "DFA.hpp"

#include <iostream>
#include <set>
#include <string>
using namespace std;


int main(){
    
    cout << endl;
    cout << "——————————————————————————————————————————————————————————————————————————" << endl;
    cout << "CYA 1819 — Práctica 6 - Simulador de Autómatas Finitos Deterministas (DFA)" << endl;
    cout << "——————————————————————————————————————————————————————————————————————————" << endl;
    cout << "Este programa simula un DFA cargado desde fichero y su comportamiento para " << endl;
    cout << "una cadena introducida por el usuario" << endl;

    ////////////////////////////// MAIN MENU ///////////////////////////////////

    bool end_loop = false;
    bool end_loop2 = false;

    while (end_loop == false) {
        
        cout << endl;
        cout << "—————————————————————————————————————————————" << endl;
        cout << "Por favor seleccione la operación a realizar:" << endl;
        cout << "—————————————————————————————————————————————" << endl << endl;
        cout << "1 - Leer DFA" << endl << "2 - Mostrar DFA" << endl;
        cout << "3 - Identificación de estados de muerte" << endl << "4 - Analizar cadena" << endl;
        cout << "x - Salir del programa" << endl << endl;

        cout << "Introduzca una opción" << endl << ">";

        char option;

        cin >> option;

        switch (option){

                case '1':
                        cout << endl << "Inversa" << endl;
                        break;

                case '2':

                        break;
                

                case 'x':
                        cout << endl << "Gracias por utilizar el simulador de DFAs" << endl << endl;
                        end_loop = true;
                        end_loop2 = true;
                        break;

                default:
                        cout << endl << "Error. Opción no válida." << endl;
                        break;
        }

        // For doing more operatios or exit the program

        while (end_loop2==false){

                cout << "¿Desea realizar otra operación (y/n)?" << endl << ">";

                char option2;
                cin >> option2;

                switch (option2){
                        case 'y':
                                end_loop2=true;
                        break;

                        case 'n':
                                cout << endl << "Gracias por utilizar el simulador de DFAs" << endl << endl;
                                
                                end_loop=true;
                                end_loop2=true;
                        break;

                        default:
                                cout << endl << "Error. Opción no válida." << endl;
                        break;
                }
        }

    }
    
}