/*
Traccia dell'Esercizio
Modellare una classe Utente che rappresenti un iscritto al social network. Ogni utente ha un nome (stringa) 
e una lista di puntatori agli altri utenti che sono suoi amici. 
Implementare poi una classe SocialNetwork che gestisce gli utenti. Si richiede di implementare:

Un meccanismo per collegare due utenti (rendendoli amici reciprocamente).

Un metodo int amiciInComune(const Utente* u1, const Utente* u2) che, dati due utenti, restituisca il numero di amici che hanno in comune.
*/

#ifndef UTENTE_H
#define UTENTE_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Utente{
protected:
    string nome;
    vector<Utente* > amici;
public:
    Utente(string n): nome(n){}

    string getNome()const {return nome;}

    const vector<Utente*>& getAmici()const {return amici;}

    void aggiungiAmico(Utente* a){
        bool giaPresente=false;
        for (size_t i=0; i<amici.size(); i++){
            if (amici[i]==a){
                giaPresente=true;
            }
        }
        if(!giaPresente){
            amici.push_back(a);
        }
    }

    bool operator==(const Utente& other){
        return nome==other.nome;
    }

};

#endif