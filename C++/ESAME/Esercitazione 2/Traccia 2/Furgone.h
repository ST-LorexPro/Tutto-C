#ifndef FURGONE_H
#define FURGONE_H

#include "Veicolo.h"

class Furgone : public Veicolo{
private:
    int capacità;
public:
    Furgone(string t, string m,bool costo, int c ): Veicolo(t,m,costo), capacità(c){}
    void stampaDettagli() const override{
        cout<<"Targa: "<<targa<<endl<<"Marca: "<<marca<<endl<<"Prezzo: "<<costo<<endl<<"Capacità: "<<capacità<<" L"<<endl;
    }

    int getCapacita(){return capacità;}
};

#endif