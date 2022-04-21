
#include "Agen_IO.h"
#include "cstdlib"
#include "iostream"

#include "ej1/ej1.cpp"
#include "ej2/ej2.cpp"
#include "ej3/ej3.cpp"

using namespace std;

int main() {

    Agen<char> A{};

    /*ofstream os;
    rellenarAgen(A, '#');
    os.open(string(getenv("HOMEDRIVE")) + string (getenv("HOMEPATH")) + "\\Desktop\\Arboles\\Generales\\b.dat");
    imprimirAgen(os, A, '#');*/

    ifstream is;
    is.open(string(getenv("HOMEDRIVE")) + string (getenv("HOMEPATH")) + "\\Desktop\\Arboles\\Generales\\b.dat");

    rellenarAgen(is, A);

    cout << "***** Árbol *****" << endl;
    imprimirAgen(A);
    cout << "*****************" << endl;

    cout << "La altura del árbol es " << altura(A, A.raiz()) << endl;

    return 0;
}
