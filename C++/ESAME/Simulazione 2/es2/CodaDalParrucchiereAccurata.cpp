#include "CodaDalParrucchiereAccurata.h"

CodaDalParrucchiere::estraiNomi(const map<string, unsigned>& dati){
    vector<string> nomi;
    for (const auto& [nome, tempo] : dati){
        nomi.push_back(nome);
    }
    return nomi;
}

CodaDalParrucchiereAccurata::CodaDalParrucchiereAccurata(map<string, unsigned>& dati){
        CodaDalParrucchiere(estraiNomi(dati));
        velocita=dati;
    }

CodaDalParrucchiere::stimaAttesa(string cliente) override{
    for (auto [nomeP, fila]: code){
        int posizione = 0;
        for (const string& c:fila){
            if(cliente==c){
                unsigned tempoPerCliente= velocita[nomeP];
                return posizione*tempoPerCliente;
            }
            posizione++;
        }
    }
    return -1;
}