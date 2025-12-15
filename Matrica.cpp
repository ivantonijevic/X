#include "Matrica.h"
#include <iostream>
#include <string.h>

using namespace std;

Matrica::Matrica() {
    n = 20;
    m = 20;
    naziv = nullptr;

    mat = new double* [n];
    for (int i = 0; i < n; i++)
        mat[i] = new double[m];
}

Matrica::Matrica(int n, int m) {
    this->n = n;
    this->m = m;
    naziv = nullptr;

    mat = new double* [n];
    for (int i = 0; i < n; i++)
        mat[i] = new double[m];
}

Matrica::~Matrica() {
    for (int i = 0; i < n; i++)
        delete[] mat[i];
    delete[] mat;

    delete[] naziv;
}

void Matrica::setNaziv(const char* ime) {
    delete[] naziv; //OVO OSTAVI AKO JE COPY CONSTRUCTOR

    naziv = new char[strlen(ime) + 1];
    strcpy_s(naziv, strlen(ime) + 1, ime);
}

void Matrica::unos() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cout << "mat[" << i << "][" << j << "] = ";
            cin >> mat[i][j];
        }
}

void Matrica::prikaz() const {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << mat[i][j] << "   ";
        cout << endl;
    }
}

double Matrica::sumaReda(int r) const {
    if (r >= n) {
        cout << "Neispravan indeks reda!" << endl;
        return 0;
    }

    double suma = 0;
    for (int j = 0; j < m; j++)
        suma += mat[r][j];
    return suma;
}


double Matrica::sumaKolone(int k) const {
    if (k >= m) {
        cout << "Neispravan indeks kolone" << endl;
        return 0;
    }

    double suma = 0;
    for (int i = 0; i < n; i++)
        suma += mat[i][k];
    return suma;
}


Matrica Matrica::proizvod(const Matrica& b) const {
    if (m != b.n) {
        cout << "Matrice nisu kompatibilne za mnozenje!" << endl;
        return Matrica(); // prazna 20x20 matrica
    }

    Matrica rez(n, b.m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < b.m; j++) {
            rez.mat[i][j] = 0;
            for (int k = 0; k < m; k++)
                rez.mat[i][j] += mat[i][k] * b.mat[k][j];
        }

    return rez;
}

Matrica Matrica::kroneker(const Matrica& b) const {
    Matrica rez(n * b.n, m * b.m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int x = 0; x < b.n; x++)
                for (int y = 0; y < b.m; y++)
                    rez.mat[i * b.n + x][j * b.m + y] =
                    mat[i][j] * b.mat[x][y];

    return rez;
}
