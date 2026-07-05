#ifndef PIANO_STUDI_H
#define PIANO_STUDI_H

#include "Esame.h"

class PianoStudi {
private:
    vector<Esame*> esami;

public:
    PianoStudi() = default;

    void addEsame(Esame* e) {
        bool giaEsiste = false;
        for (size_t i = 0; i < esami.size(); i++) {
            // CORREZIONE: Dereferenzio (*) per usare l'operator== 
            // e controllare se esiste già un esame con quel nome
            if (*esami[i] == *e) {
                giaEsiste = true;
            }
        }
        if (!giaEsiste) {
            esami.push_back(e);
        }
    }

    void impostaPropedeuticita(Esame* prima, Esame* dopo) {
        if (prima != nullptr && dopo != nullptr) {
            prima->addSblocco(dopo);
        }
    }

    // CORREZIONE: Aggiunto const come da traccia
    bool propedeuticitaIndiretta(const Esame* a, const Esame* b) const {
        // Passo 1: Controllo Diretto (A -> B)
        // Uso const reference per non copiare il vettore
        const vector<Esame*>& aSblocchi = a->getSblocca();
        
        for (size_t i = 0; i < aSblocchi.size(); i++) {
            // Qui confronto i puntatori (indirizzi). Se A punta direttamente a B,
            // la traccia dice di ritornare FALSE (vogliamo solo indiretti).
            if (aSblocchi[i] == b) {
                return false;
            }
        }

        // Passo 2: Controllo Indiretto (A -> X -> B)
        for (size_t i = 0; i < aSblocchi.size(); i++) {
            Esame* intermedio = aSblocchi[i];
            
            // Prendo gli sblocchi dell'intermedio X
            const vector<Esame*>& sblocchiIntermedio = intermedio->getSblocca();
            
            for (size_t j = 0; j < sblocchiIntermedio.size(); j++) {
                if (sblocchiIntermedio[j] == b) {
                    return true; // Trovato percorso A -> X -> B
                }
            }
        }

        return false;
    }

    ~PianoStudi() {};
};

#endif