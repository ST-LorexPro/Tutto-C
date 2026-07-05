/*Traccia: Centro Riparazioni Smartphone
Un grande centro assistenza ripara smartphone e tablet. Il centro è diviso in vari banchi di lavoro, ognuno identificato da un codice ID (stringa, es: "BancoA", "BancoB").

1. Classe CentroRiparazioni Deve gestire le code di dispositivi in attesa per ogni banco.
Costruttore: Riceve un vector<string> con gli ID dei banchi disponibili e inizializza le code vuote.

-Metodo accettaDispositivo(string dispositivo, string idBanco):
Il cliente chiede di mettere il dispositivo su un banco specifico.
Ogni banco ha una capienza massima di 5 dispositivi in attesa.
Se il banco scelto ha spazio (< 5), aggiungi il dispositivo e restituisci true.
Se il banco scelto è pieno, cerca automaticamente il banco con meno dispositivi in assoluto tra quelli disponibili. Se trovi un banco con spazio, aggiungi lì il dispositivo e restituisci true.
Se tutti i banchi sono pieni, rifiuta il dispositivo e restituisci false.


-Metodo ritiraDispositivo(string dispositivo):
Permette a un cliente di riprendersi il dispositivo senza ripararlo, ma solo se non è già sotto i ferri.
Consideriamo "sotto i ferri" (o in preparazione immediata) i dispositivi nelle prime 2 posizioni della coda (indice 0 e 1).
Se il dispositivo è dalla posizione 2 in poi (indice >= 2), rimuovilo e restituisci true. Altrimenti false.

-Metodo stimaConsegna(string dispositivo):
Restituisce un intero (minuti).
Assume che ogni riparazione richieda standard 45 minuti.
Formula: posizione_in_coda * 45.
Restituisce -1 se il dispositivo non è trovato.*/

#ifndef CENTRO_RIPARAZIONI_H
#define CENTRO_RIPARAZIONI_H

#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <deque>
#include <climits>

using namespace std;

class CentroRiparazioni{
protected:
    map<string, deque<string>> code;
    const int capienza=5;
    const int durata=45;
public:
    CentroRiparazioni(const vector<string>& banchi){
        for (string b : banchi){
            code[b]=deque<string>();
        }
    }
    
    bool accettaDispositivo(const string& dispositivo, const string& idBanco){
        if(code[idBanco].size() < capienza){
            code[idBanco].push_back(dispositivo);
            return true;
        }
        int min=INT_MAX;
        string bancoFinale;
        for(const auto& [b, d] : code){
            if(d.size()<min && d.size() < capienza){
                min=d.size();
                bancoFinale=b;
            }            
        }
        if(min!= INT_MAX){
            code[bancoFinale].push_back(dispositivo);
            return true;
        }
        return false;
    }

    bool ritiraDispositivo(const string& dispositivo){
        for( auto& [b, d] : code){
            for(size_t i=0; i<d.size(); i++){
                if(d[i] == dispositivo){
                    if(i>=2){
                        d.erase(d.begin() + i);
                        return true;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return false;
    }

    virtual int stimaConsegna(string dispositivo){
        for( auto& [b, d] : code){
            for(size_t i=0; i<d.size(); i++){
                if(d[i] == dispositivo){
                    return i*durata;
                }
            }
        }
        return -1;
    }        

    virtual ~CentroRiparazioni(){};
};


#endif