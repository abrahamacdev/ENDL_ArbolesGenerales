
#include "Agen_IO.h"
#include "cstdlib"
#include "iostream"

#include "ej1/ej1.cpp"

using namespace std;

int main() {

    Agen<char> c{};

    /*rellenarAgen(c, '#');

    ofstream os;
    os.open(string(getenv("HOMEDRIVE")) + string (getenv("HOMEPATH")) + "\\Desktop\\a.dat");
    imprimirAgen(os, c, '#');*/

    ifstream is;
    is.open(string(getenv("HOMEDRIVE")) + string (getenv("HOMEPATH")) + "\\Desktop\\b.dat");

    rellenarAgen(is, c);

    imprimirAgen(c);

    cout << "El grado del árbol es: " << calcularGrado(c) << endl;

    return 0;
}
