/*Vogliamo poi implementare una seconda classe, CodaDalParrucchiereAccurata, in cui i
meccanismi di prenotazione restano invariati ma la stima dell’attesa prende in considerazione anche
la velocità media di lavoro del parrucchiere (minuti impiegati per un cliente). A tal fine, il costruttore
di questa nuova classe riceve in input una map<string,unsigned>, dove ogni chiave
rappresenta un parrucchiere e il valore corrispondente indica il numero di minuti con cui il
parrucchiere, in media, processa un singolo cliente. In questa nuova classe terremo in
considerazione questo nuovo dato per stimare i tempi d’attesa con maggiore accuratezza.
Si noti che la scelta delle strutture dati usate per risolvere l’esercizio ne influenza (positivamente o negativamente) la valutazione. 
*/

#ifndef CODA_ACCURATA_H
#define CODA_ACCURATA_H

#include "CodaDalParrucchiere.h"

using namespace std;

class CodaDalParrucchiereAccurata : public CodaDalParrucchiere{
private:
    map<string, unsigned> velocita;

    static vector<string> estraiNomi(const map<string, unsigned>& parruchieri){
        vector<string> nomi;
        for(const auto& [p,t]: parruchieri){
            nomi.push_back(p);
        }
        return nomi;
    }
public:

    CodaDalParrucchiereAccurata(const map<string, unsigned>& parruchieri): CodaDalParrucchiere(estraiNomi(parruchieri)){
        velocita=parruchieri;
    }

    int stimaAttesa (string c)override{
        for(const auto& [p,lista]: code){
            auto it = find (lista.begin(), lista.end(), c);

            if(it != lista.end()){
                int posizione = distance(lista.begin(), it);
                return posizione * velocita[p];
            }
        }
        return -1;
    }
};

#endif