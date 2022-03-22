
#include "Agen_IO.h"
#include "cstdlib"
#include "iostream"

#include "ej1/ej1.cpp"
#include "ej2/ej2.cpp"

using namespace std;

int main() {

    Agen<char> A{};

    /*rellenarAgen(A, '#');

    ofstream os;
    os.open(string(getenv("HOMEDRIVE")) + string (getenv("HOMEPATH")) + "\\Desktop\\a.dat");
    imprimirAgen(os, A, '#');*/

    ifstream is;
    is.open(string(getenv("HOMEDRIVE")) + string (getenv("HOMEPATH")) + "\\Desktop\\A.dat");

    rellenarAgen(is, A);

    cout << "***** Árbol *****" << endl;
    imprimirAgen(A);
    cout << "*****************" << endl;

    //cout << "El grado del árbol es: " << calcularGrado(A) << endl;

    // Nodo f
    typename Agen<char>::nodo f = A.hermDrcho(A.hijoIzqdo(A.hijoIzqdo(A.raiz())));
    typename Agen<char>::nodo c = A.hermDrcho(A.hijoIzqdo(A.raiz()));
    typename Agen<char>::nodo a = A.raiz();

    cout << "La profundidad del nodo \"" << A.elemento(f) << "\" es " << profundidad(A, f) << endl;
    cout << "La profundidad del nodo \"" << A.elemento(c) << "\" es " << profundidad(A, c) << endl;
    cout << "La profundidad del nodo \"" << A.elemento(a) << "\" es " << profundidad(A, a) << endl;

    return 0;
}
