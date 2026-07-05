#ifndef AUTO_H
#define AUTO_H

#include "Veicolo.h"

class Auto: public Veicolo{
private:
    int posti;
public:
    Auto(string t, string m,bool c, int p): Veicolo(t,m,c), posti(p){}

    void stampaDettagli() const override{
        cout<<"Targa: "<<targa<<endl<<"Marca: "<<marca<<endl<<"Costo: "<<costo<<endl<<"Posti: "<<posti<<endl;
    }

    int getPosti(){return posti;}
};


#endif