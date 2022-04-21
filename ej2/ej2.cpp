//
// Created by abrah on 22/03/2022.
//

#include "ej2.h"

template <typename T>
void profundidad_rec(typename Agen<T>::nodo actual, int profundidadActual, Agen<T>& A, int* profundidadBuscado, typename Agen<T>::nodo buscado){

    // El nodo actual es nulo o el buscado
    if (actual == Agen<T>::NODO_NULO);
    else if (actual == buscado) {
        *profundidadBuscado = profundidadActual;
    }
    else {

        typename Agen<T>::nodo temp = A.hijoIzqdo(actual);
        while (temp != Agen<T>::NODO_NULO){
            profundidad_rec(temp, profundidadActual + 1, A, profundidadBuscado, buscado);
            temp = A.hermDrcho(temp);
        }
    }
}

template <typename T>
int profundidad(Agen<T>& A, typename Agen<T>::nodo n){
    int p = 0;
    profundidad_rec(A.raiz(), 0, A, &p, n);
    return p;
}
