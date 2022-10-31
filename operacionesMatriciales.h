//
// Created by Jorge Castilla on 27/10/22.
//
#include "matriz.h"

#ifndef ACTIVIDADGRUPAL23_OPERACIONESMATRICIALES_H
#define ACTIVIDADGRUPAL23_OPERACIONESMATRICIALES_H


class operacionesMatriciales {
public:
    ~operacionesMatriciales(){

    };
        matriz * sumarMatrices(matriz * matriz1,matriz * matriz2){
        if (matriz1->getColumnas() != matriz2->getColumnas() || matriz1->getFilas() != matriz2->getFilas()){
            throw std::invalid_argument( "Matrices Incompatibles" );
        }
        matriz * resultado = new matriz(matriz1->getFilas()-1,matriz1->getColumnas()-1, 0);
        for (int i = 0; i < matriz1->getColumnas(); ++i) {
            for (int j = 0; j < matriz1->getFilas(); ++j) {
                resultado->modificarElemento(j,i,matriz1->verElemento(j, i)+ matriz2->verElemento(j, i));
            }
        }
        return resultado;
    }
    matriz * restarMatrices(matriz * matriz1,matriz * matriz2){
        if (matriz1->getColumnas() != matriz2->getColumnas() || matriz1->getFilas() != matriz2->getFilas()){
            throw std::invalid_argument( "Matrices Incompatibles" );
        }
        matriz * resultado = new matriz(matriz1->getFilas()-1,matriz1->getColumnas()-1, 0);
        for (int i = 0; i < matriz1->getColumnas(); ++i) {
            for (int j = 0; j < matriz1->getFilas(); ++j) {
                resultado->modificarElemento(j,i,matriz1->verElemento(j, i)- matriz2->verElemento(j, i));
            }
        }
        return resultado;
    }
    matriz * transponerMatriz(matriz * matriz1){
            matriz * resultado = new matriz(matriz1->getColumnas()-1,matriz1->getFilas()-1, 0);
        for (int i = 0; i < matriz1->getColumnas(); ++i) {
            for (int j = 0; j < matriz1->getFilas(); ++j) {
                resultado->modificarElemento(i,j,matriz1->verElemento(j,i));
            }
        }
        return resultado;
        }
    matriz * multiplicarMatriz(matriz * matriz1, matriz * matriz2){
        if (matriz2->getFilas()!=matriz1->getColumnas()){
            throw std::invalid_argument( "Matrices Incompatibles" );
        }
        matriz * resultado = new matriz(matriz1->getFilas()-1,matriz2->getColumnas()-1, 0);
        resultado = restarMatrices(resultado, resultado);
        for (int i = 0; i < matriz1->getFilas(); ++i) {
            for (int j = 0; j < matriz2->getColumnas(); ++j) {
                int temportal;
                temportal = 0;
                for (int k = 0; k < matriz1->getColumnas(); ++k) {
                    temportal = temportal + matriz1->verElemento(i,k)*matriz2->verElemento(k,j);
                }
                resultado->modificarElemento(i,j,temportal);
            }
        }
        return resultado;
        }
    double determinante(matriz * matriz1){
            double salida = 1;
        if (matriz1->getColumnas()==matriz1->getFilas()){
            switch (matriz1->getColumnas()) {
                case 1: {
                    salida = matriz1->verElemento(0,0);
                    break;
                }
                case 2: {
                    salida = matriz1->verElemento(0,0)*matriz1->verElemento(1,1)-matriz1->verElemento(0,1)*matriz1->verElemento(1,0);
                    break;
                }
                case 3: {
                    double elemento1;
                    double elemento2;
                    double elemento3;
                    double elemento4;
                    double elemento5;
                    double elemento6;
                    elemento1 = matriz1->verElemento(0,0)*matriz1->verElemento(1,1)*matriz1->verElemento(2,2);
                    elemento2 = matriz1->verElemento(0,1)*matriz1->verElemento(1,2)*matriz1->verElemento(2,0);
                    elemento3 = matriz1->verElemento(0,2)*matriz1->verElemento(1,0)*matriz1->verElemento(2,1);
                    elemento4 = matriz1->verElemento(0,2)*matriz1->verElemento(1,1)*matriz1->verElemento(2,0);
                    elemento5 = matriz1->verElemento(0,0)*matriz1->verElemento(1,2)*matriz1->verElemento(2,1);
                    elemento6 = matriz1->verElemento(0,1)*matriz1->verElemento(1,0)*matriz1->verElemento(2,2);
                    salida = elemento1 + elemento2 + elemento3 - elemento4 - elemento5  - elemento6;
                    break;
                }
                default:{
                    cout << "La Matriz debe se ser 1x1 o 2x2 o 3x3" << endl;
                }
            }
        } else{
            cout << "La Matriz debe se ser cuadrada" << endl;
        }
        return salida;
        }
};


#endif //ACTIVIDADGRUPAL23_OPERACIONESMATRICIALES_H
