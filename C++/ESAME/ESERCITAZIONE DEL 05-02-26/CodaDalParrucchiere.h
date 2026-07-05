/*Un salone di parrucchieri, in cui lavorano un numero imprecisato di dipendenti, ha bisogno di un
software per la gestione delle prenotazioni. A tal fine, si richiede di modellare ed implementare una
classe CodaDalParrucchiere che tenga traccia delle prenotazioni assegnate a ciascun
parrucchiere (rappresentato come stringa) ed esponga le seguenti funzionalità:
- Un costruttore che prenda in input i parrucchieri che lavorano nel salone (tramite
vector<string>)
- Aggiungere una prenotazione: il metodo riceve in input un cliente (anch’esso rappresentato
come stringa) e un parrucchiere. Quando un cliente vuole prenotare una prestazione, il
programma deve cercare di accontentarlo assegnandogli il parrucchiere da lui scelto.
Tuttavia, nel caso in cui il parrucchiere desiderato abbia già più di 10 clienti in coda, la
prenotazione sarà assegnata al parrucchiere con meno clienti in coda. Se non ci sono
parrucchieri disponibili ad accoglierla, il sistema deve restituire false (true altrimenti).

- Cancellare una prenotazione: il metodo riceve il nome di un cliente c e rimuove la sua
prenotazione, se e solo se essa non è imminente (consideriamo imminente la prenotazione
di c se prima di c ci sono meno di 3 clienti in fila). Il metodo restituisce true se la
prenotazione è stata correttamente cancellata e false altrimenti.

- Stimare il tempo d’attesa: che restituisca, in minuti, il tempo che dobbiamo attendere prima
di sederci sulla poltrona, considerando che ogni parrucchiere impiega mediamente 15
minuti per ogni cliente.


Vogliamo poi implementare una seconda classe, CodaDalParrucchiereAccurata, in cui i
meccanismi di prenotazione restano invariati ma la stima dell’attesa prende in considerazione anche
la velocità media di lavoro del parrucchiere (minuti impiegati per un cliente). A tal fine, il costruttore
di questa nuova classe riceve in input una map<string,unsigned>, dove ogni chiave
rappresenta un parrucchiere e il valore corrispondente indica il numero di minuti con cui il
parrucchiere, in media, processa un singolo cliente. In questa nuova classe terremo in
considerazione questo nuovo dato per stimare i tempi d’attesa con maggiore accuratezza.
Si noti che la scelta delle strutture dati usate per risolvere l’esercizio ne influenza (positivamente o negativamente) la valutazione. 
*/

#ifndef CODA_PARRUCCHIERE_H
#define CODA_PARRUCCHIERE_H

#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <map>
#include <climits>
#include <algorithm>

using namespace std;

class CodaDalParrucchiere{
protected:
    map<string,deque<string>> code;
    const size_t maxC=10;
    const int media=15;
public:
    CodaDalParrucchiere(const vector<string>& listaParrucchieri){
        for(string p: listaParrucchieri){
            code[p] = deque<string>();
        }
    }
    
    bool aggiungiPrenotazione(string c, string p){
        if(code[p].size()<maxC){
            code[p].push_back(c);
            return true;
        }
        else{
            size_t min = INT_MAX;
            string parrucchiereDefinitivo;
            for (const auto& [p, lista]: code){
                if(lista.size()<min && lista.size()<maxC){
                    min=lista.size();
                    parrucchiereDefinitivo=p;
                }
            }
            if(min<maxC){
                code[parrucchiereDefinitivo].push_back(c);
                return true;
            }
            else{return false;}
        }
    }

/*- Cancellare una prenotazione: il metodo riceve il nome di un cliente c e rimuove la sua
prenotazione, se e solo se essa non è imminente (consideriamo imminente la prenotazione
di c se prima di c ci sono meno di 3 clienti in fila). Il metodo restituisce true se la
prenotazione è stata correttamente cancellata e false altrimenti.*/

    bool cancellaPrenotazione(string c){
        for(auto& [p, lista]: code){
            auto it = find(lista.begin(), lista.end(), c);

            if(it!=lista.end()){
                int posizione = distance(lista.begin(), it);
                if(posizione>=3){
                    lista.erase(it);
                    return true;
                }
                else{return false;}
            }
        }
        return false;
    }

/*- Stimare il tempo d’attesa: che restituisca, in minuti, il tempo che dobbiamo attendere prima
di sederci sulla poltrona, considerando che ogni parrucchiere impiega mediamente 15
minuti per ogni cliente.*/

    virtual int stimaAttesa(string c){
        for(const auto& [p,lista]: code){
            auto it = find (lista.begin(), lista.end(), c);

            if(it != lista.end()){
                int posizione = distance(lista.begin(), it);
                return posizione * 15;
            }
        }
        return -1;
    }

    virtual ~CodaDalParrucchiere(){};
};


#endif