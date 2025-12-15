#include <iostream>
#include "Matrica.h"

using namespace std;

int main() {
    int n, m;

    cout << "Unesite broj vrsta: ";
    cin >> n;
    cout << "Unesite broj kolona: ";
    cin >> m;

    Matrica A(n, m);
    A.setNaziv("A");

    cout << "Unos elemenata matrice: \n";
    A.unos();

    double sumaKolona = A.sumaKolone(0) + A.sumaKolone(2);
    double sumaRedova = A.sumaReda(1) + A.sumaReda(2);

    cout << "\nSuma 1. i 3. kolone: " << sumaKolona << endl;
    cout << "Suma 2. i 3. reda: " << sumaRedova << endl;

    cout << "\nMatrica A:\n";
    A.prikaz();

    return 0;
}
