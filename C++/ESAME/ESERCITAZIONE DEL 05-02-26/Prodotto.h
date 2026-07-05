/*Traccia: Magazzino E-Commerce (Logistica)
Scenario: Devi gestire l'inventario di un grande magazzino online. I prodotti sono identificati da un codice univoco (es. "PROD-01").
1. Struttura Dati (Prodotto) Ogni prodotto ha un Prezzo Unitario (double) e una Quantità Disponibile (int).
2. Obiettivi Classe Base (Magazzino) Devi creare un sistema che gestisca un catalogo di prodotti (mappa codice -> prodotto).
Gestione Scorte: Permettere di aggiungere scorte a un prodotto esistente o crearne uno nuovo.
Vendita: Permettere di vendere una certa quantità di un prodotto.
Se la quantità richiesta è disponibile, decrementala e restituisci true.
Se la quantità richiesta è superiore alla disponibilità (o il prodotto non esiste), l'operazione fallisce (false).
Calcolo Valore Inventario: Calcolare il valore totale della merce in magazzino (prezzo * quantità per tutti i prodotti).
3. Obiettivi Classe Derivata (MagazzinoAlimentare) Questa versione gestisce prodotti deperibili.
Ogni prodotto qui ha anche una proprietà aggiuntiva: Giorni alla Scadenza (int).
Vendita (Override): Non puoi vendere prodotti se sono scaduti (giorni <= 0), anche se ce ne sono in magazzino.
Calcolo Valore (Override): Il valore totale del magazzino non deve includere i prodotti scaduti (che valgono 0 perché vanno buttati).
Operazione di Pulizia: Una funzione che elimina definitivamente dalla mappa tutti i prodotti scaduti.*/

#ifndef PRODOTTO_H
#define PRODOTTO_H

using namespace std;

struct Prodotto{
	double prezzo;
	int qntDisponibile;
	
	Prodotto(double p, int q): prezzo(p), qntDisponibile(q){}
	Prodotto():prezzo(0), qntDisponibile(0){}
		
};

#endif
