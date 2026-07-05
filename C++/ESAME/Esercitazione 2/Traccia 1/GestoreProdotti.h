#ifndef GESTOREPRODOTTI_H
#define GESTOREPRODOTTI_H

#include <vector>
#include "Prodotto.h"

class GestoreProdotti {
private:
    vector<Prodotto*> prodotti;
public:
    ~GestoreProdotti(){
        for(auto p: prodotti)
            delete p;
    }

    void aggiungi(Prodotto* p){
        prodotti.push_back(p);
    }

    void stampa(){
        for (auto p : prodotti)
            p->stampa();
    }

    Prodotto* cerca(const string &nome){
        for (auto p:prodotti){
            if (p->getNome()==nome)
                return p;
        }
        return nullptr;
    }

    double totale(){
        double somma=0;
        for (auto p : prodotti)
            somma+=p->getPrezzo();
        return somma;
    }
};

#endif