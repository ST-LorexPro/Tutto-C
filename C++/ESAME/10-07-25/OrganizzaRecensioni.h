#ifndef ORGANIZZARECENSIONI_H
#define ORGANIZZARECENSIONI_H

#include "Ristorante.h"
#include <map>
#include <vector>
#include <algorithm>

class OrganizzaRecensioni{
protected:
    map<pair<string , string>, Ristorante> database;
public:
    void aggiungiRecensione(string nome, string localita, pair<double, double> coords, Recensione rec) {
        Ristorante r(nome, localita, coords, rec);
        // In una map, l'operatore [] sovrascrive se la chiave esiste già, 
        // oppure crea una nuova entry se non esiste.
        database[{nome, localita}] = r;
    }

    int getValutazione(string nome, string localita, string categoria) {
        pair<string, string> chiave = {nome, localita};
        
        // Controlliamo se il ristorante esiste
        if (database.find(chiave) != database.end()) {
            return database[chiave].getRecensione().getVotoPerCategoria(categoria);
        } else {
            cout << "Errore: Ristorante non trovato." << endl;
            return -1; 
        }
    }

    // 3. Filtra per categoria A (>= x) e ordina per categoria B (decrescente)
    vector<Ristorante> filtraEOrdina(int x, string catA, string catB) {
    vector<Ristorante> risultati;

        // Fase 1: Filtro
        for (auto const& [chiave, ristorante] : database) {
            if (ristorante.getRecensione().getVotoPerCategoria(catA) >= x) {
                risultati.push_back(ristorante);
            }
        }

        // Fase 2: Ordinamento
        // Usiamo una lambda function per definire come comparare due ristoranti
        sort(risultati.begin(), risultati.end(), 
            [&](const Ristorante& a, const Ristorante& b) {
                return a.getRecensione().getVotoPerCategoria(catB) > 
                        b.getRecensione().getVotoPerCategoria(catB);
            });

        return risultati;
    }
};


#endif