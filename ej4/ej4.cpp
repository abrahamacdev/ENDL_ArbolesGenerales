//
// Created by abrah on 23/03/2022.
//

#include "ej4.h"

void eliminar_Rec(Agen<int>& A, Agen<int>::nodo n){
    if(n != Agen<int>::NODO_NULO){

        // Comprobamos que tenga hijos
        if(A.hijoIzqdo(n) != Agen<int>::NODO_NULO){

            // Tiene nietos, seguimos bajando
            if(A.hijoIzqdo(A.hijoIzqdo(n)) != Agen<int>::NODO_NULO){
                Agen<int>::nodo temp = A.hijoIzqdo(n);

                while (temp != Agen<int>::NODO_NULO){
                    eliminar_Rec(A, temp);
                    temp = A.hermDrcho(temp);
                }
            }

            // Eliminamos los hijos
            else {
                Agen<int>::nodo temp = A.hijoIzqdo(n);

                while (temp != Agen<int>::NODO_NULO){
                    A.eliminarHijoIzqdo(n);
                    temp = A.hijoIzqdo(n);
                }
            }
        }
    }
}

void poda_Rec(Agen<int>& A, int e, Agen<int>::nodo n){

    if(n != Agen<int>::NODO_NULO){

        Agen<int>::nodo* anterior = nullptr;
        Agen<int>::nodo temp = A.hijoIzqdo(n);

        while (temp != Agen<int>::NODO_NULO){

            // El nodo temp tiene el elemento e
            if(A.elemento(temp) == e){

                // Eliminamos de forma recursiva sus hijos
                eliminar_Rec(A, n);

                // temp = hijoIzdo(n);
                if(anterior == nullptr){
                    A.eliminarHijoIzqdo(n);
                }

                // temp = hermDerecho(anterior)
                else {
                    A.eliminarHermDrcho(*anterior);
                }

                break;
            }

            // El nodo temp no tiene el elemento e
            else {
                anterior = &temp;
                temp = A.hermDrcho(temp);
            }
        }
    }
}

void poda(Agen<int>& A, int e){

    // No podemos podar la raíz
    assert(A.elemento(A.raiz()) != e);

    poda_Rec(A, e, A.raiz());
}