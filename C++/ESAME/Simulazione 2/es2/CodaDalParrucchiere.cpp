#include "CodaDalParrucchiere.h"
#include <climits>
#include <algorithm>

CodaDalParrucchiere::CodaDalParrucchiere(const vector<string> parrucchieri){
    for (const string& p : parrucchieri){
        code[p] = list<string>();
    }
}

virtual CodaDalParrucchiere::~CodaDalParrucchiere(){
}

bool CodaDalParrucchiere::aggiungiPrenotazione(string cliente, string parrucchiereScelto){
    if(code.find(parrucchiereScelto)==code.end()){
        cout<<"Errore..."<<endl;
        return false;
    }
    
    string parrucchiereFinale = parrucchiereScelto;

    if (code[parrucchiereScelto].size() > SOGLIA_AFFOLLAMENTO){
        size_t minSize= ULONG_MAX;
        string bestCandidate= "";

        for (auto const& [nome, fila]: code){
            if(fila.size() < minSize){
                minSize = fila.size();
                bestCandidate = nome;
            }
        }
        if (minSize > SOGLIA_AFFOLLAMENTO){
            return false;
        }
        parrucchiereFinale = bestCandidate;
    }
    code[parrucchiereFinale].push_back(cliente);
    return true;
}

bool CodaDalParrucchiere::cancellaPrenotazione(string cliente){
    for (auto& [nomeP, fila] : code){
        int posizione = 0;
        auto it = fila.begin();
        bool trovato = false;

        while (it != fila.end()){
            if (*it == cliente){
                trovato = true;
                break;
            }
            posizione++;
            it++;
        }
        if (trovato){
            if (posizione<3){
                return false;
            } 
            else{
                fila.erase(it);
                return true;
            }
        }
    }
    return false;
}

int CodaDalParrucchiere::stimaAttesa(string cliente){
    for(auto& [nomeP, fila]: code){
        int posizione = 0;
        for (const string& c : fila){
            if (c == cliente){
                return posizione * TEMPO_MEDIO_BASE;
            }
            posizione++;
        }
        return -1;
    }
}