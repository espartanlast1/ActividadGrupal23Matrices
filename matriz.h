//
// Created by Jorge Castilla on 26/10/22.
//
#include <vector>
#include <iostream>
#include <cstdlib>
#include <random>

using namespace std;

#ifndef ACTIVIDADGRUPAL23_MATRIZ_H
#define ACTIVIDADGRUPAL23_MATRIZ_H


class matriz { //Clase Matriz
private:
    int filas;
    int columnas;
    vector<double> datos;
    int selecionarElemento(int fila, int columna){ //Metodo que devuelve la posicion equivalente en una matriz de un vector plano
        int base;
        base = fila*columnas+columna;
        return base;
    }
public:
    matriz(int filas, int columnas, int modo){ // Constructor de la matriz
        matriz::filas = filas+1;
        matriz::columnas = columnas+1;
        generarmMtrizAleatoria(filas+1, columnas+1); // Se genera una matriz Aleatoria para llenar los huecos
        if (modo==1){ // si se quiere una matriz vacia
            for (int i = 0; i < filas*columnas; ++i) {
                datos.at(i)=0; // se pone todo a 0
            }
        }
    }
    ~matriz(){ // destructor
        cout << "Matriz destruida con exito" << endl;
    }
    void generarmMtrizAleatoria(int filas, int columnas){ // llenar la matriz de numeros aleatorios
        for (int i = 0; i < filas*columnas; ++i) {
            datos.push_back(std::mt19937_64().operator()());
        }
    }
    int getFilas(){ // devuelve el numero de filas
        return filas;
    }
    int getColumnas(){ // devuelve el numero de columnas
        return columnas;
    }
    void imprimirMatriz(){ // imprime la matriz por consola
        int elementoActual = 0;
        for(int i=0; i<filas; i++){
            for (int j = 0; j < columnas; ++j) {
                cout << " " << datos.at(elementoActual) << " ";
                elementoActual++;
            }
            cout << endl;
        }
    }
    void modificarElemento(int fila, int columna, int nuevoElemento){ //permite modificar un elemento de la matriz
        datos.at(selecionarElemento(fila,columna))=nuevoElemento;
    }
    double verElemento(int fila, int columna){ // permite ver un elemento de la matriz
        return datos.at(selecionarElemento(fila,columna));
    }
    void imprimirMatrizSecuencial(int fila, int columna){ //metodo para imprimir la matriz con unos bonitos parentesis al rededor de un numero (NO SE USA)
        int elementoActual = 0;
        for(int i=0; i<filas; i++){
            for (int j = 0; j < columnas; ++j) {
                if (i==fila && j==columna){
                    cout << " (" << datos.at(elementoActual) << ") ";
                }else{
                    cout << " " << datos.at(elementoActual) << " ";
                }
                elementoActual++;
            }
            cout << endl;
        }
    }

};


#endif //ACTIVIDADGRUPAL23_MATRIZ_H
