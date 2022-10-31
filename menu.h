//
// Created by Jorge Castilla on 29/10/22.
//
#include <iostream>
#include "matriz.h"
#include "operacionesMatriciales.h"

#ifndef ACTIVIDADGRUPAL23_MENU_H
#define ACTIVIDADGRUPAL23_MENU_H


class menu {
private:
    char seleccion;
    int banderaSalida = 0;
    std::vector<matriz*> * matrices = new std::vector<matriz*>;
public:
    menu(){
        while (banderaSalida == 0){ // se muestra al usuario las operaciones
            cout << "Selecione una opcion: ";
            std::cout << "\n1 Crear Matriz, \n2 Sumar Matrices, \n3 restar matrices, \n4 multiplicar matriz, \n5 matriz traspuesta, \n6 determinante de la matriz(solo en los casos 1x1,2x2 y3x3), \n7 salir" << endl;
            std::cin >> seleccion;
            switch (seleccion) {
                case '1': { // crear matriz
                    cout << "indique las filas " << endl;
                    int filas;
                    cin >> filas;
                    cout << "indique las columnas " << endl;
                    int columnas;
                    cin >> columnas;
                    matriz *matriz1 = new matriz(filas-1, columnas-1, 0);
                    for (int i = 0; i < matriz1->getFilas(); ++i) {
                        for (int j = 0; j < matriz1->getColumnas(); ++j) {
                            cout << "introduzca el elemento: " << i+1 << "x" << j+1 << endl; // se va introduciendo elemento por elemento
                            int elemento;
                            cin >> elemento;
                            matriz1->modificarElemento(i, j, elemento);
                        }
                    }
                    matrices->push_back(matriz1);
                    matriz1->imprimirMatriz();
                    break;
                }

                case '2': { // suma
                    if (matrices->size()>=2){
                        for (int i = 0; i < matrices->size(); ++i) {
                            cout << "Matriz " << i << endl; // se listan las matrices creadas en el vector listas para operar
                            matrices->at(i)->imprimirMatriz();
                        }
                        cout << "indique la matriz a sumar 1 " << endl;
                        int matrizAlpha;
                        cin >> matrizAlpha;
                        cout << "indique la matriz a sumar 2 " << endl;
                        int matrizBravo;
                        cin >> matrizBravo;
                        operacionesMatriciales * op1 = new operacionesMatriciales; // se crea un objeto operacion en el free store
                        matrices->push_back(op1->sumarMatrices(matrices->at(matrizAlpha), matrices->at(matrizBravo))); // se crea la nueva matriz creada al vector
                        delete op1; // se borra el objeto operacion
                        matrices->at(matrices->size()-1)->imprimirMatriz();
                    }else{
                        cout << "Deben de existir al menos dos matrices" << endl;
                    }
                    break;
                }

                case '3': { // resta
                    if (matrices->size()>=2){
                        for (int i = 0; i < matrices->size(); ++i) {
                            cout << "Matriz " << i << endl; // se listan las matrices creadas en el vector listas para operar
                            matrices->at(i)->imprimirMatriz();
                        }
                        cout << "indique la matriz a restar 1 " << endl;
                        int matrizAlpha;
                        cin >> matrizAlpha;
                        cout << "indique la matriz a restar 2 " << endl;
                        int matrizBravo;
                        cin >> matrizBravo;
                        operacionesMatriciales * op1 = new operacionesMatriciales; // se crea objeto operacion en el free store
                        matrices->push_back(op1->restarMatrices(matrices->at(matrizAlpha), matrices->at(matrizBravo))); // se crea la matriz resultado al vector
                        delete op1; // se elimina el objeto del free store
                        matrices->at(matrices->size()-1)->imprimirMatriz();
                    }else{
                        cout << "Deben de existir al menos dos matrices" << endl;
                    }
                    break;
                }

                case '4': { // multiplicar
                    if (matrices->size()>=2){
                        for (int i = 0; i < matrices->size(); ++i) {
                            cout << "Matriz " << i << endl; // se listan las matrices creadas en el vector listas para operar
                            matrices->at(i)->imprimirMatriz();
                        }
                        cout << "indique la matriz a multiplicar 1 " << endl;
                        int matrizAlpha;
                        cin >> matrizAlpha;
                        cout << "indique la matriz a multiplicar 2 " << endl;
                        int matrizBravo;
                        cin >> matrizBravo;
                        operacionesMatriciales * op1 = new operacionesMatriciales; // se crea objeto operacion en el free store
                        matrices->push_back(op1->multiplicarMatriz(matrices->at(matrizAlpha), matrices->at(matrizBravo))); // se crea matriz resultado en el vector
                        delete op1; // se borra objeto del free store
                        matrices->at(matrices->size()-1)->imprimirMatriz();
                    }else{
                        cout << "Deben de existir al menos dos matrices" << endl;
                    }
                    break;
                }

                case '5': { // transposicion
                        for (int i = 0; i < matrices->size(); ++i) {
                            cout << "Matriz " << i << endl; // se listan las matrices creadas en el vector listas para operar
                            matrices->at(i)->imprimirMatriz();
                        }
                        cout << "indique la matriz a trasponer " << endl;
                        int matrizAlpha;
                        cin >> matrizAlpha;
                        operacionesMatriciales * op1 = new operacionesMatriciales; // se crea objeto operacion en el free store
                        matrices->push_back(op1->transponerMatriz(matrices->at(matrizAlpha))); // se crea matriz resultado en el vector
                        delete op1; // se borra objeto del free store
                        matrices->at(matrices->size()-1)->imprimirMatriz();
                    break;
                }
                case '6': { //determinante
                    for (int i = 0; i < matrices->size(); ++i) {
                        cout << "Matriz " << i << endl; // se listan las matrices creadas en el vector listas para operar
                        matrices->at(i)->imprimirMatriz();
                    }
                    cout << "indique la matriz de la que quiere calcular el determinante " << endl;
                    int matrizAlpha;
                    cin >> matrizAlpha;
                    operacionesMatriciales * op1 = new operacionesMatriciales; //se crea objeto operacion en el free store
                    cout << "El determinante es: " << op1->determinante(matrices->at(matrizAlpha)) << endl; // se muestra el determinante por pantalla
                    delete op1; //se borra el objeto del free store
                    break;
                }
                case '7':{  // salida
                    banderaSalida=1;
                    for (int i = 0; i < matrices->size(); ++i) {
                        delete matrices->at(i); // se borran las matrices del freestore
                    }
                    delete matrices; // se borra el vector
                    break;
                }
                default:{
                    cout << "Seleccione una opcion disponible" << endl;
                }


            }
        }
    }

};


#endif //ACTIVIDADGRUPAL23_MENU_H
