//
// Created by abrah on 21/03/2022.
//

#ifndef PRACTICA2EDNL_ABB_H
#define PRACTICA2EDNL_ABB_H

#include "cassert"

/**
 * Un Árbol Binario de Búsquedas es un árbol binario cuyos nodos contendrán elementos de un conjunto. Cualquier nodo
 * izquierdo contiene un elemento < que el elemento del nodo n mientras que el nodo derecho contiene un elemento > que el
 * elemento del nodo n.
 *
 *  Operaciones:
 *
 *          Abb():
 *              Postcondición: Crea un Árbol Binario de Búsquedas vacío.
 *
 *          const Abb& buscar(const T& e) const:
 *              Postcondición: Si e es un elemento del árbol, devuelve el subárbol cuya raíz contiene el elemento buscado,
 *              en caso contrario devuelve un árbol vacío.
 *
 *          void insertar(const T& elto):
 *              Postcondicion: Si el elemento NO pertenece al árbol, se insertar, en caso contrario el árbol no se ve modificado.
 *
 *          void eliminar(const T& elto):
 *              Postcondicion: Elimina el elemento del árbol si existe en este, en caso contrario no modifica el árbol.
 *
 *          bool vacio() const:
 *              Postcondicion: Devuelve true si el árbol está vacío, en caso contrario devuelve false.
 *
 *          const T& elemento() const:
 *              Precondicion: Árbol no vacío
 *              Postcondicion: Devuelve el elemento de la raíz del árbol.
 *
 *          const Abb& izdo() const:
 *              Precondicion: Árbol no vacío
 *              Postcondicion: Devuelve el subárbol izquierdo.
 *
 *          const Abb& drcho() const:
 *              Precondicion: Árbol no vacío
 *              Postcondicion: Devuelve un subárbol derecho
 *
 */

template <typename T>
class Abb {

public:

    Abb();
    Abb(const Abb<T>& A);

    const Abb& buscar(const T& e) const;
    void insertar(const T& e);
    void eliminar(const T& e);

    bool vacio() const;
    const T& elemento() const;
    const Abb<T>& izdo() const;
    const Abb<T>& drcho() const;


    Abb<T>& operator =(const Abb<T>& A);

    ~Abb();

private:

    struct arbol {
        T elto;
        Abb<T> abIzdo, abDer;
        arbol(const T& e, Abb<T>& aIzdo = nullptr, Abb<T>& aDer = nullptr): elto(e), abIzdo(aIzdo), abDer(aDer);
    };

    arbol* r;

    // TODO Vigilar
    T& borraMin();

};

template<typename T>
inline Abb<T>::Abb(): r(nullptr) {}

template <typename T>
inline Abb<T>::Abb(const Abb<T>& A){

    // Copiamos la raíz y descendientes
    if(A.r){
        r = new arbol(*A.r);
    }
}

template<typename T>
const Abb& Abb<T>::buscar(const T &e) const {

    if(r == nullptr){           // Árbol vacío
        return *this;
    }
    else if (e < r->elto){      // Buscamos en el subárbol izquierdo
        return r->abIzdo.buscar(e);
    }
    else if(e > r->elto){       // Buscamos en el subárbol derecho
        return r->abDer.buscar(e);
    }
    else {                      // Tenemos el elemento buscado
        return *this;
    }
}

template <typename T>
void Abb<T>::insertar(const T& e) {
    if(r == nullptr){           // Árbol vacío
        r = new arbol(e);
    }
    else if (e < r->elto){      // Insertaremos en el subárbol izquierdo
        r->abIzdo.insertar(e);
    }
    else {                      // Insertaremos en el subárbol derecho
        r->abDer.insertar(e);
    }
}

template <typename T>
void Abb<T>::eliminar(const T &e) {

    if(r != nullptr){

        // Buscamos el elemento por la izquierda
        if(e < r->elto){
            r->abIzdo.eliminar(e);
        }
        // Buscamos el elemento por la derecha
        else if (e > r->elto){
            r->abDer.eliminar(e);
        }

        // Quitamos la raíz
        else {

            // Es nodo hoja
            if(!r->abIzdo.r && !r->abDer.r){
                delete r;
                r = nullptr;
            }

            // Sólo tiene hijo derecho
            else if(!r->abDer){
                arbol* a = r->abIzdo.r;     // Evitamos eliminar el hijo izquierdo
                r->abIzdo.r = nullptr;
                delete r;
                r = a;
            }

            // Sólo tiene hijo izquierdo
            else if(!r->abIzdo){
                arbol* a = r->abDer.r;      // Evitamos eliminar el hijo derecho
                r->abDer.r = nullptr;
                delete r;
                r = a;
            }

            // Tiene ambos hijos
            // Eliminamos el mínimo del subárbol derecho y sustituimos la raíz por el elemento borrado
            else{
                r->elto = r->abDer.borraMin();
            }
        }
    }
}

template <typename T>
bool Abb<T>::vacio() const {
    return r == nullptr;
}

template <typename T>
const T& Abb<T>::elemento() const {
    assert(r != nullptr);
    return r->elto;
}

template <typename T>
const T& Abb<T>::izdo() const {
    assert(r != nullptr);
    return r->abIzdo;
}

template <typename T>
const T& Abb<T>::drcho() const {
    assert(r != nullptr);
    return r->abDer;
}

/**
 * Elimina el nodo con el menor elemento del árbol. Devuelve el elemento del nodo eliminado.
 */
template <typename T>
T& Abb<T>::borraMin(){

    // Hemos llegado al elemento menor
    if(r->abIzdo.r == nullptr){
        T& e = r->elto;             // Guardamos el elemento para devolverlo después

        arbol* hd = r->abDer.r;     // Guardamos el subárbol derecho

        r->abDer.r = nullptr;       // Eliminamos el subárbol derecho (al dejar de apuntar al sub derecho, evitamos eliminarlo con delete)
        delete r;

        r = hd;                     // "Ahora somos el subárbol derecho"

        return  e;                  // Devolvemos el elemento eliminado
    }

    // Seguimos buscando por la rama izquierda hasta llegar al menor
    return r->abIzdo.borraMin();
}

template <typename T>
Abb<T>::~Abb() {

    if(r != nullptr){
        delete r;       // Eliminamos los árboles descendientes
        r = nullptr;
    }
}

template<typename T>
Abb<T>& Abb<T>::operator=(const Abb<T> &A) {

    // Evitamos autoasignación
    if(this != &A){
        this->~Abb();   // Vaciamos el árbol

        // Copiamos raíz y descendientes
        if(A.r){
            r = new arbol(*A.r);
        }
    }

    return *this;
}

#endif //PRACTICA2EDNL_ABB_H
