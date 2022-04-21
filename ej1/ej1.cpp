//
// Created by abrah on 20/03/2022.
//

#include "ej1.h"
#include "vector"

using namespace std;

template <typename T>
int numeroHijos(Agen<T> &A, typename Agen<T>::nodo n){
    int hijos = 0;

    typename Agen<T>::nodo temp = n->hIzdo;

    while (temp != Agen<T>::NODO_NULO){
        hijos++;
        temp = temp->herDer;
    }

    return hijos;
}

template <typename T>
int calcularGrado_Rec(Agen<T> &A, typename Agen<T>::nodo n){

    if(n == Agen<T>::NODO_NULO) return 0;
    else {

        int gradoN = numeroHijos(A, n);

        if (n->hIzdo){
            typename Agen<T>::nodo tempN = n->hIzdo;

            while (tempN != Agen<T>::NODO_NULO){

                // Comprobamos si el grado de alguno de los hijos es mayor
                int tempGrado = numeroHijos(A, tempN);
                gradoN = max(gradoN, tempGrado);

                tempN = tempN->herDer;
            }
        }

        return gradoN;
    }
}

template <typename T>
int calcularGrado(Agen<T> &A){
    return calcularGrado_Rec(A, A.raiz());
}