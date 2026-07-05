#ifndef PRODOTTO_H
#define PRODOTTO_H

#include <iostream>
#include <string>
using namespace std;

class Prodotto{
protected:
    string nome;
    double prezzo;
public:
    Prodotto(string n, float p): nome(n), prezzo(p){}
    virtual ~Prodotto(){}

    virtual void stampa() const=0;
    double getPrezzo() const {return prezzo;}
    string getNome() const {return nome;}
};


#endif