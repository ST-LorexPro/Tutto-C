/*3. Classe Derivata MagazzinoAlimentare
Membri Dati:
private map<string, int> scadenze (Associa un codice prodotto ai giorni rimanenti alla scadenza).
Funzionalità Richieste:

-Costruttore
Input: map<string, int> (lista codici prodotti e rispettivi giorni alla scadenza).
Obiettivo: Inizializzare correttamente la classe base e la mappa delle scadenze.
-Metodo vendi (Override)
Input: string codice, int quantitaRichiesta.
Output: bool.
Obiettivo: Eseguire la vendita solo se il prodotto non è scaduto (giorni > 0).
-Metodo valoreTotale (Override)
Input: Nessuno.
Output: double.
Obiettivo: Calcolare il valore totale escludendo dal conteggio i prodotti scaduti (giorni <= 0).
-Metodo rimuoviScaduti
Input: Nessuno.
Output: int.
Obiettivo: Rimuovere dalla gestione scadenze i prodotti scaduti e azzerarne la quantità nel magazzino. Restituire il numero di prodotti rimossi.*/

#ifndef MAGAZZINO_ALIMENTARE_H
#define MAGAZZINO_ALIMENTARE_H

#include "Magazzino.h"

using namespace std;

class MagazzinoAlimentare : public Magazzino{
private:
	map<string, int> scadenze;
	
	static vector<string> estraiCodici(map<string, int> s){
		vector<string> codici;
		for (const auto& [c, scadenza] : s){
			codici.push_back(c);
		}
		return codici;
	}
	
public:
	MagazzinoAlimentare(map<string, int> s): Magazzino(estraiCodici(s)){
		scadenze=s;
	}
/*-Metodo vendi (Override)
Input: string codice, int quantitaRichiesta.
Output: bool.
Obiettivo: Eseguire la vendita solo se il prodotto non è scaduto (giorni > 0).*/
	bool vendi(string c, int qntRichiesta)override{
		if(scorte[c].qntDisponibile >= qntRichiesta && scadenze[c] > 0){
			scorte[c].qntDisponibile -= qntRichiesta;
			return true;
		}
		return false;
	}
	
	
/*-Metodo valoreTotale (Override)
Input: Nessuno.
Output: double.
Obiettivo: Calcolare il valore totale escludendo dal conteggio i prodotti scaduti (giorni <= 0).*/

	double valoreTotale()override{
		double totale=0;
		for(const auto& [c, p] : scorte){
			if(scadenze[c]>0){
				totale+=scorte[c].prezzo*scorte[c].qntDisponibile;
			}
		}
		return totale;
	}

/*-Metodo rimuoviScaduti
Input: Nessuno.
Output: int.
Obiettivo: Rimuovere dalla gestione scadenze i prodotti scaduti e azzerarne la quantità nel magazzino. Restituire il numero di prodotti rimossi.*/

int rimuoviScaduti(){
	int counter=0;
	for(auto& [c, s]:scadenze){
		if(s<=0){
			counter+=scorte[c].qntDisponibile;
			scorte[c].qntDisponibile=0;
			scadenze.erase(c);
		}
	}
	return counter;
}

};	
#endif