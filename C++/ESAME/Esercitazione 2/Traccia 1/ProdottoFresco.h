#ifndef PRODOTTOFRESCO_H
#define PRODOTTOFRESCO_H

#include "Prodotto.h"
using namespace std;

class ProdottoFresco: public Prodotto{
public:
    ProdottoFresco(string n, float p): Prodotto(n, p){}
    void stampa() const override {
        cout<<"Prodotto Fresco: "<< nome << " | "<< prezzo << "€\n";
    }
};


#endif