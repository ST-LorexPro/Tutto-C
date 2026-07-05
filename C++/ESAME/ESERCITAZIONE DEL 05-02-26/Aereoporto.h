/*1. Classe Aeroporto Ogni aeroporto è identificato da un codice univoco (es. "MXP", "JFK") e da un nome completo (es. "Malpensa", "John F. Kennedy"). 
Ogni aeroporto possiede una lista di puntatori agli altri aeroporti raggiungibili tramite un volo diretto in partenza da esso.

Nota: Se c'è un volo da Roma a Milano, non è detto che ci sia da Milano a Roma (il grafo è orientato).

2. Classe GestoreVoli Questa classe gestisce l'insieme degli aeroporti. Deve permettere di:

Registrare nuovi aeroporti.

Inserire una nuova tratta (un volo diretto) da un aeroporto di partenza a uno di destinazione.

3. Algoritmo Richiesto All'interno della classe GestoreVoli, implementare il metodo: 
bool esisteVoloConUnoScalo(const Aeroporto* partenza, const Aeroporto* arrivo)

Questo metodo deve restituire true se e solo se non esiste un volo diretto tra i due, ma esiste almeno un aeroporto intermedio X tale che:

Esiste un volo diretto da Partenza a X.

Esiste un volo diretto da X ad Arrivo.

In caso contrario (o se c'è già un volo diretto), restituisce false.*/


#ifndef AEREOPORTO_H
#define AEREOPORTO_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Aereoporto{
private:
    string codice;
    string nome;
    vector<Aereoporto*> destinazioni;
public:
    Aereoporto() = default;
    Aereoporto(string c, string n): codice(c), nome(n){}

    void aggiungiDestinazione(Aereoporto* d){
        bool giaEsiste=false;
        for (size_t i=0; i< destinazioni.size(); i++){
            if (destinazioni[i] == d){
                giaEsiste=true;
            }
        }
        if(!giaEsiste){
            destinazioni.push_back(d);
        }
    }

    const string getCodice() const{return codice;}
    const string getNome()const {return nome;}
    const vector<Aereoporto*>& getDestinazioni() const {return destinazioni;}

    bool operator==(Aereoporto* other){
        return this->codice==other->codice;
    }

    ~Aereoporto(){};
};

#endif