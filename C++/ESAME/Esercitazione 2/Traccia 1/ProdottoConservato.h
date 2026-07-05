#ifndef PRODOTTOCONSERVATO_H
#define PRODOTTOCONSERVATO_H

#include "Prodotto.h"

class ProdottoConservato: public Prodotto{
private:
    int annoScadenza;
public:
    ProdottoConservato(string n, float p): Prodotto(n, p){}

    void stampa() const override{
        cout<<"Prodotto Conservato: "<< nome << " | "<< prezzo << "€\n";
    }
};


#endif