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
        while (banderaSalida == 0){
            cout << "Selecione una opcion: ";
            std::cout << "\n1 Crear Matriz, \n2 Sumar Matrices, \n3 restar matrices, \n4 multiplicar matriz, \n5 matriz traspuesta, \n6 determinante de la matriz(solo en los casos 1x1,2x2 y3x3), \n7 salir" << endl;
            std::cin >> seleccion;
            switch (seleccion) {
                case '1': {
                    cout << "indique las filas " << endl;
                    int filas;
                    cin >> filas;
                    cout << "indique las columnas " << endl;
                    int columnas;
                    cin >> columnas;
                    matriz *matriz1 = new matriz(filas-1, columnas-1, 0);
                    for (int i = 0; i < matriz1->getFilas(); ++i) {
                        for (int j = 0; j < matriz1->getColumnas(); ++j) {
                            cout << "introduzca el elemento: " << i+1 << "x" << j+1 << endl;
                            int elemento;
                            cin >> elemento;
                            matriz1->modificarElemento(i, j, elemento);
                        }
                    }
                    matrices->push_back(matriz1);
                    matriz1->imprimirMatriz();
                    break;
                }

                case '2': {
                    if (matrices->size()>=2){
                        for (int i = 0; i < matrices->size(); ++i) {
                            cout << "Matriz " << i << endl;
                            matrices->at(i)->imprimirMatriz();
                        }
                        cout << "indique la matriz a sumar 1 " << endl;
                        int matrizAlpha;
                        cin >> matrizAlpha;
                        cout << "indique la matriz a sumar 2 " << endl;
                        int matrizBravo;
                        cin >> matrizBravo;
                        operacionesMatriciales * op1 = new operacionesMatriciales;
                        matrices->push_back(op1->sumarMatrices(matrices->at(matrizAlpha), matrices->at(matrizBravo)));
                        delete op1;
                        matrices->at(matrices->size()-1)->imprimirMatriz();
                    }else{
                        cout << "Deben de existir al menos dos matrices" << endl;
                    }
                    break;
                }

                case '3': {
                    if (matrices->size()>=2){
                        for (int i = 0; i < matrices->size(); ++i) {
                            cout << "Matriz " << i << endl;
                            matrices->at(i)->imprimirMatriz();
                        }
                        cout << "indique la matriz a restar 1 " << endl;
                        int matrizAlpha;
                        cin >> matrizAlpha;
                        cout << "indique la matriz a restar 2 " << endl;
                        int matrizBravo;
                        cin >> matrizBravo;
                        operacionesMatriciales * op1 = new operacionesMatriciales;
                        matrices->push_back(op1->restarMatrices(matrices->at(matrizAlpha), matrices->at(matrizBravo)));
                        delete op1;
                        matrices->at(matrices->size()-1)->imprimirMatriz();
                    }else{
                        cout << "Deben de existir al menos dos matrices" << endl;
                    }
                    break;
                }

                case '4': {
                    if (matrices->size()>=2){
                        for (int i = 0; i < matrices->size(); ++i) {
                            cout << "Matriz " << i << endl;
                            matrices->at(i)->imprimirMatriz();
                        }
                        cout << "indique la matriz a multiplicar 1 " << endl;
                        int matrizAlpha;
                        cin >> matrizAlpha;
                        cout << "indique la matriz a multiplicar 2 " << endl;
                        int matrizBravo;
                        cin >> matrizBravo;
                        operacionesMatriciales * op1 = new operacionesMatriciales;
                        matrices->push_back(op1->multiplicarMatriz(matrices->at(matrizAlpha), matrices->at(matrizBravo)));
                        delete op1;
                        matrices->at(matrices->size()-1)->imprimirMatriz();
                    }else{
                        cout << "Deben de existir al menos dos matrices" << endl;
                    }
                    break;
                }

                case '5': {
                        for (int i = 0; i < matrices->size(); ++i) {
                            cout << "Matriz " << i << endl;
                            matrices->at(i)->imprimirMatriz();
                        }
                        cout << "indique la matriz a trasponer " << endl;
                        int matrizAlpha;
                        cin >> matrizAlpha;
                        operacionesMatriciales * op1 = new operacionesMatriciales;
                        matrices->push_back(op1->transponerMatriz(matrices->at(matrizAlpha)));
                        delete op1;
                        matrices->at(matrices->size()-1)->imprimirMatriz();
                    break;
                }
                case '6': {
                    for (int i = 0; i < matrices->size(); ++i) {
                        cout << "Matriz " << i << endl;
                        matrices->at(i)->imprimirMatriz();
                    }
                    cout << "indique la matriz de la que quiere calcular el determinante " << endl;
                    int matrizAlpha;
                    cin >> matrizAlpha;
                    operacionesMatriciales * op1 = new operacionesMatriciales;
                    cout << "El determinante es: " << op1->determinante(matrices->at(matrizAlpha)) << endl;
                    delete op1;
                    break;
                }
                case '7':{
                    banderaSalida=1;
                    for (int i = 0; i < matrices->size(); ++i) {
                        delete matrices->at(i);
                    }
                    delete matrices;
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
