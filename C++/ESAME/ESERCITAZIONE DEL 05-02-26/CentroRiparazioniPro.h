/*2. Classe CentroRiparazioniPro (Derivata) Vogliamo una versione evoluta che tenga conto della bravura dei tecnici.

Costruttore: Riceve una map<string, int> efficienza, dove la chiave è l'ID del banco e il valore è il tempo medio (in minuti) 
che quel tecnico impiega per una riparazione.

Override stimaConsegna:
Deve funzionare come quello base, ma invece di usare 45 minuti fissi, deve usare il tempo specifico del banco in cui si trova il dispositivo.

Nota: Per istanziare la classe base, dovrai estrarre le chiavi dalla mappa (i nomi dei banchi) e passarle al costruttore padre 
(proprio come nell'esercizio del parrucchiere).*/

#ifndef CENTRO_RIPARAZIONE_PRO_H
#define CENTRO_RIPARAZIONE_PRO_H

#include "CentroRiparazioni.h"

class CentroRiparazioniPro : public CentroRiparazioni{
private:
    map<string, unsigned> efficienza;
    
    static vector<string> estraiBanchi(map<string, unsigned> efficienza){
        vector<string> banchi;
        for(const auto& [b, t] : efficienza){
            banchi.push_back(b);
        }
        return banchi;
    }
public:
    CentroRiparazioniPro(map<string, unsigned> e): CentroRiparazioni(estraiBanchi(e)){
        efficienza=e;
    }

    int stimaConsegna(string dispositivo) override{
        for(const auto& [b, d] : code){
            for(size_t i=0; i<d.size(); i++){
                if(d[i] == dispositivo){
                    return i*efficienza[b];
                }
            }
        }
        return -1;
    }

};



#endif