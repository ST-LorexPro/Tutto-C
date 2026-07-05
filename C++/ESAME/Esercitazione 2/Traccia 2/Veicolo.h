#ifndef VEICOLO_H
#define VEICOLO_H


#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Veicolo{
protected:
    string targa;
    string marca;
    bool costo;

    static vector <string> targheRegistrate;

public:
    Veicolo(string t, string m, bool c){
        for (size_t i=0; i<targheRegistrate.size(); i++)
            if (targheRegistrate[i]==t){
                cout<<"Errore, la targa: "<<t<<" è gia in uso."<<endl;
                exit(1);
            }
        targheRegistrate.push_back(t);

        this->targa=t;
        this->marca=m;
        this->costo=c;

        cout<<"Veicolo creato con successo."<<endl;
    }

    virtual ~Veicolo(){}

    virtual void stampaDettagli() const=0;

    string getTarga(){return targa;}
    string getMarca(){return marca;}
    bool getCosto(){return costo;}
};


vector<string> Veicolo::targheRegistrate;

#endif 

