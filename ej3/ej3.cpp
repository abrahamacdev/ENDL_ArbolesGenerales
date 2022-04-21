//
// Created by abrah on 19/04/2022.
//

#include <iostream>
#include "ej3.h"


template <typename T>
int altura(Agen<T>& A, typename Agen<T>::nodo n){
    if (n == Agen<T>::NODO_NULO) return 0;
    else {

        int max = -1;

        typename Agen<T>::nodo temp = A.hijoIzqdo(n);
        while (temp != Agen<T>::NODO_NULO){

            // Actualizamos el valor de la altura
            max = std::max(altura(A, temp), max);

            // Pasamos al siguiente hermano
            temp = A.hermDrcho(temp);
        }

        return 1 + max;
    }
}

template <typename T>
int desequilibrio(Agen<T>& A, typename Agen<T>::nodo n){
    // n es nulo o hoja
    if(n == Agen<T>::NODO_NULO || A.hijoIzqdo(n) == Agen<T>::NODO_NULO) return 0;
    else {

        // El desequilibrio es "la máxima diferencia entre las alturas de los subárboles más bajo y más alto de cada nivel".
        typename Agen<T>::nodo temp = A.hijoIzqdo(n);

        // Contendrán la máxima y mínima altura de los subárboles del nivel actual
        int min = altura(A, temp);
        int max = altura(A, temp);

        // Pila en la que iremos metiendo los nodos para luego hacer las llamadas recursivas
        std::stack<typename Agen<T>::nodo> pila;

        // Actualizamos ya al siguiente nodo (evitamos bugs por usar la funcion min)
        temp = A.hermDrcho(temp);
        while (temp != Agen<T>::NODO_NULO){
            pila.push(temp);

            min = std::min(min, altura(A, temp));
            max = std::max(max, altura(A, temp));

            temp = A.hermDrcho(temp);
        }

        // Guardamos la diferencia que existe en los subárboles más bajos y altos del nivel actual
        int diferenciaActual = std::abs(max - min);

        int maxDiferenciaHijos = -1;
        while (!pila.empty()){

            // Actualizamos la máxima diferencia de los nodos hijos
            maxDiferenciaHijos = std::max(maxDiferenciaHijos, desequilibrio(A, pila.top()));

            // Quitamos el elemento que está en la cima de la pila
            pila.pop();
        }

        return std::max(diferenciaActual, maxDiferenciaHijos);
    }
}


template <typename T>
int desequilibrio(Agen<T>& A){
    return desequilibrio(A, A.raiz());
}