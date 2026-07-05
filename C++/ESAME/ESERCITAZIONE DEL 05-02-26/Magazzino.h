/*2. Classe Base Magazzino
Membri Dati:
protected map<string, Prodotto> scorte (Associa un codice prodotto al suo prezzo/quantità).
Funzionalità Richieste:
Costruttore
Input: vector<string> (lista dei codici prodotto)
Obiettivo: Inizializzare il magazzino con i codici forniti (quantità e prezzo a 0).

-Metodo rifornisci
Input: string codice, int quantita, double prezzo.
Output: bool.
Obiettivo: Aggiornare il prezzo e incrementare la quantità del prodotto specificato. Restituire true se il prodotto esiste, false altrimenti.
-Metodo vendi (Virtual)
Input: string codice, int quantitaRichiesta.
Output: bool.
Obiettivo: Decrementare la giacenza se la quantità richiesta è disponibile.
-Metodo valoreTotale (Virtual)
Input: Nessuno.
Output: double.
Obiettivo: Restituire la somma del valore economico di tutti i prodotti presenti (prezzo * quantita).*/

#ifndef MAGAZZINO_H
#define MAGAZZINO_H

#include "Prodotto.h"
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class Magazzino{
protected:
	map<string, Prodotto> scorte;
public:
	Magazzino(vector<string> codici){
		for(string id : codici){
			scorte[id]=Prodotto();
		}
	}
	
/*-Metodo rifornisci
Input: string codice, int quantita, double prezzo.
Output: bool.
Obiettivo: Aggiornare il prezzo e incrementare la quantità del prodotto specificato. Restituire true se il prodotto esiste, false altrimenti.*/
	
	bool rifornisci(string c, int q, double p){
		for(auto [cod, prod] : scorte){
			if(cod == c){
				scorte[c].qntDisponibile=q;
				scorte[c].prezzo=p;
				return true;
			}
		}
		return false;
	}
	
/*-Metodo vendi (Virtual)
Input: string codice, int quantitaRichiesta.
Output: bool.
Obiettivo: Decrementare la giacenza se la quantità richiesta è disponibile.*/
	
	virtual bool vendi(string c, int qntRichiesta){
		if(scorte[c].qntDisponibile >= qntRichiesta){
			scorte[c].qntDisponibile -= qntRichiesta;
			return true;
		}
		return false;
	}
/*-Metodo valoreTotale (Virtual)
Input: Nessuno.
Output: double.
Obiettivo: Restituire la somma del valore economico di tutti i prodotti presenti (prezzo * quantita).*/
	
	virtual double valoreTotale(){
		double totale=0;
		for(const auto& [c, p] : scorte){
			totale+= p.prezzo*p.qntDisponibile;
		}
		return totale;
	}
	
	
	virtual ~Magazzino(){};
};
#endif