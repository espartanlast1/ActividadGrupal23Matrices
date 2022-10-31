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
    int selecionarElemento(int fila, int columna){
        int base;
        base = fila*columnas+columna;
        return base;
    }
public:
    matriz(int filas, int columnas, int modo){
        matriz::filas = filas+1;
        matriz::columnas = columnas+1;
        generarmMtrizAleatoria(filas+1, columnas+1);
        if (modo==1){
            for (int i = 0; i < filas*columnas; ++i) {
                datos.at(i)=0;
            }
        }
    }
    ~matriz(){
        cout << "Matriz destruida con exito" << endl;
    }
    void generarmMtrizAleatoria(int filas, int columnas){
        for (int i = 0; i < filas*columnas; ++i) {
            datos.push_back(std::mt19937_64().operator()());
        }
    }
    int getFilas(){
        return filas;
    }
    int getColumnas(){
        return columnas;
    }
    void imprimirMatriz(){
        int elementoActual = 0;
        for(int i=0; i<filas; i++){
            for (int j = 0; j < columnas; ++j) {
                cout << " " << datos.at(elementoActual) << " ";
                elementoActual++;
            }
            cout << endl;
        }
    }
    void modificarElemento(int fila, int columna, int nuevoElemento){
        datos.at(selecionarElemento(fila,columna))=nuevoElemento;
    }
    double verElemento(int fila, int columna){
        return datos.at(selecionarElemento(fila,columna));
    }
    void imprimirMatrizSecuencial(int fila, int columna){
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
