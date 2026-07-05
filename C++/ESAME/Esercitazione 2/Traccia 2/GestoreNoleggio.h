#ifndef GESTORENOLEGGIO_H
#define GESTORENOLEGGIO_H

#include "Veicolo.h"

class GestoreNoleggio {
private: 
    vector<Veicolo*> disponibili;
public:
    ~GestoreNoleggio(){
        for (auto p : disponibili)
            delete p;
    }

    void aggiungi(Veicolo* v){
        disponibili.push_back(v);
        cout<<"Veicolo aggiunto con successo"<<endl;
    }

    void stampaDettagli(){
        int i=1;
        for (auto p : disponibili){
            cout<<"Veicolo "<<i<<endl;
            p->stampaDettagli();
            i++;
        }
    }

    void rimuovi(string targa){
        for (size_t i=0; i<disponibili.size(); i++){
            if (disponibili[i]->getTarga() == targa){
                disponibili.erase(disponibili.begin() + i);
                cout<<"Veicolo rimosso con successo"<<endl;
                return;
            }
        }
        cout<<"Veicolo non presente in lista"<<endl;
    }

    Veicolo* cerca(string targa){
        for (auto p : disponibili){
            if (p->getTarga()==targa)
                return p;
        }
        return nullptr;
    }


};

#endif