/*
Traccia dell'Esercizio
Modellare una classe Utente che rappresenti un iscritto al social network. Ogni utente ha un nome (stringa) 
e una lista di puntatori agli altri utenti che sono suoi amici. 
Implementare poi una classe SocialNetwork che gestisce gli utenti. Si richiede di implementare:

Un meccanismo per collegare due utenti (rendendoli amici reciprocamente).

Un metodo int amiciInComune(const Utente* u1, const Utente* u2) che, dati due utenti, restituisca il numero di amici che hanno in comune.
*/

#ifndef SOCIAL_NETWORK_H
#define SOCIAL_NETWORK_H

#include "Utente.h"

class SocialNetwork{
private:
vector<Utente*> utentiRegistrati;

public:

    SocialNetwork() = default;

    void registraUtente(Utente* u){
        utentiRegistrati.push_back(u);
    }

    void stringiAmicizia(Utente* u1, Utente* u2){
        if(u1!=u2){
            u1->aggiungiAmico(u2);
            u2->aggiungiAmico(u1);
        }
    }

    int amiciInComune(const Utente* u1,const Utente* u2){
        int counter=0;

        const vector<Utente*>& AmiciU1=u1->getAmici();
        const vector<Utente*>& AmiciU2=u2->getAmici();

        for (size_t i=0; i< AmiciU1.size(); i++){
            for (size_t j=0;j<AmiciU2.size(); j++){
                if(AmiciU1[i]==AmiciU2[j]){
                    counter++;
                }
            }
        }
        return counter;
    }

};

#endif