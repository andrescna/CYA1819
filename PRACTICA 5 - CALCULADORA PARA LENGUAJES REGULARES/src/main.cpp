//// Andrés Concepción Afonso
//// CYA 2018-19

/// PRACTICA 5 - CALCULADORA DE LENGUAJES REGULARES ///
/// Este programa calcula lenguajes regulares y tal ///

#include "language.hpp"

#include <iostream>
#include <set>
#include <string>
using namespace std;


int main(){
    
    cout << endl;
    cout << "——————————————————————————————————————————————————————————" << endl;
    cout << "CYA 1819 — Práctica 5 - Calculadora de lenguajes regulares" << endl;
    cout << "——————————————————————————————————————————————————————————" << endl;
    cout << "Este programa calcula lenguajes regulares" << endl << endl;

    cout << "Por favor defina un lenguaje. El formato es: { símbolos, separados, por, comas }" << endl;
    cout << "Lenguaje 1: ";


    string userInput;

    //cin >> userInput;
    getline(cin, userInput, '\n');

    // LLAMAR AL CONSTRUCTOR DEL LENGUAJE

    bool test = true;

    language L1 = parse_language(userInput,test);


        //*************************************************************************************************************************
        // COSAS QUE NO FUNCIONAN: 
        // el parser funciona, pero no consigo que meta las cosas donde debe
        // el resto debería ser más sencillo, pero es que no puedo dedicarle más tiempo :shrug:
        //*************************************************************************************************************************


    cout << endl;    
    cout << "Por favor defina un segundo lenguaje si quiere hacer operaciones con 2 lenguajes" << endl;
    cout << "Si no quiere definirlo ahora pulse enter" << endl;
    cout << "Lenguaje 2: ";
/*
    getline(cin, userInput, '\n');

    bool L2_created = false;

    if (userInput!=""){
                //language L2(userInput);
                L2_created = true;
    }

    
    //DISEÑAR ESTE PARSER VA A SER DE LEJOS LO PEOR DE LA PRÁCTICA

    ////////////////////////////// MAIN MENU ///////////////////////////////////

    bool end_loop = false;
    bool end_loop2 = false;

    while (end_loop == false) {
        
        cout << endl;
        cout << "—————————————————————————————————————————————" << endl;
        cout << "Por favor seleccione la operación a realizar:" << endl;
        cout << "—————————————————————————————————————————————" << endl << endl;
        cout << "1 - Inversa" << endl << "2 - Concatenación" << endl;
        cout << "3 - Unión" << endl << "4 - Intersección" << endl;
        cout << "5 - Diferencia" << endl << "6 - Sublenguajes" << endl;
        cout << "7 - Igualdad de lenguajes" << endl << "8 - Potencia" << endl;
        cout << "9 - Cierre de Kleene" << endl << "x - Salir del programa" << endl << endl;

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
                        cout << endl << "Gracias por utilizar la calculadora de lenguajes" << endl << endl;
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
                                cout << endl << "Gracias por utilizar la calculadora de lenguajes" << endl << endl;
                                
                                end_loop=true;
                                end_loop2=true;
                        break;

                        default:
                                cout << endl << "Error. Opción no válida." << endl;
                        break;
                }
        }

    }
    
    
    
    
    
    // menu de opciones


            // si se pide operaciones con cadenas -> pedir el otro alfabeto


    //idealmente deberías mostrar el resultado y volver al loop principal.
    // pero para eso necesitas hacer las fórmulas antes

    // lo importante aquí es diseñar bien los objetos

    // que las funciones las tiene el conjunto set





//*/
}