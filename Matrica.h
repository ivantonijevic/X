#pragma once

class Matrica {
private:
    double** mat;
    int n;
    int m;
    char* naziv;

public:
    Matrica();
    Matrica(int n, int m);
    ~Matrica();

    inline int getN() const { return n; }
    inline int getM() const { return m; }

    double sumaReda(int r) const;
    double sumaKolone(int k) const;

    Matrica proizvod(const Matrica& druga) const;
    Matrica kroneker(const Matrica& druga) const;

    void unos();
    void prikaz() const;

    inline const char* getNaziv() const {
        return naziv;
    }

    void setNaziv(const char* ime);
};
