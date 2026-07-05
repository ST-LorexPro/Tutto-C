/*
2. Classe GestoreVoli Questa classe gestisce l'insieme degli aeroporti. Deve permettere di:

Registrare nuovi aeroporti.

Inserire una nuova tratta (un volo diretto) da un aeroporto di partenza a uno di destinazione.

3. Algoritmo Richiesto All'interno della classe GestoreVoli, implementare il metodo: 
bool esisteVoloConUnoScalo(const Aeroporto* partenza, const Aeroporto* arrivo)

Questo metodo deve restituire true se e solo se non esiste un volo diretto tra i due, ma esiste almeno un aeroporto intermedio X tale che:

Esiste un volo diretto da Partenza a X.

Esiste un volo diretto da X ad Arrivo.

In caso contrario (o se c'è già un volo diretto), restituisce false.*/

#ifndef GESTORE_VOLI_H
#define GESTORE_VOLI_H

#include <queue>
#include <algorithm>
#include "Aereoporto.h"

class GestoreVoli{
private:
    vector<Aereoporto*> aereoporti;
public:
    GestoreVoli()=default;

    void addAereoporto(Aereoporto* a){
        bool giaEsiste= false;
        for (size_t i=0; i<aereoporti.size(); i++){
            if (aereoporti[i] == a){
                giaEsiste=true;
            }
        }
        if(!giaEsiste){
            aereoporti.push_back(a);
        }
    }

    void addTratta(Aereoporto* a1, Aereoporto* a2){
        a1->aggiungiDestinazione(a2);
    }

    bool esisteVoloConUnoScalo(Aereoporto* partenza, Aereoporto* arrivo){
        vector<Aereoporto*> direttiDaPartenza = partenza->getDestinazioni();

        for (size_t i=0; i<direttiDaPartenza.size(); i++){
            if (direttiDaPartenza[i]==arrivo){
                return false; //Esiste un volo diretto quindi non c'è lo scalo
            }
        }

        for (size_t i=0; i<direttiDaPartenza.size(); i++){
            Aereoporto* current= direttiDaPartenza[i];
            vector<Aereoporto*> destinazioniCurrent = current->getDestinazioni();
            for (size_t j=0; j<destinazioniCurrent.size(); j++){
                if (destinazioniCurrent[j]==arrivo){
                    return true;
                }
            }
        }
        return false;
    }
};

#endif