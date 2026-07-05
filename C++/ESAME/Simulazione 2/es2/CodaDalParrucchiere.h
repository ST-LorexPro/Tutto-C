#ifndef CODAPARRUCCHIERE_H
#define CODAPARRUCCHIERE_H

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>

using namespace std;

class CodaDalParrucchiere{
private:
    map<string, list<string>> code;

    static const size_t SOGLIA_AFFOLLAMENTO = 10;
    static const int TEMPO_MEDIO_BASE = 15;

public:
    CodaDalParrucchiere(const vector<string>& parrucchieri);
    virtual ~CodaDalParrucchiere();

    bool aggiungiPrenotazione(string cliente, string parrucchiereScelto);
    bool cancellaPrenotazione(string cliente);

    virtual int stimaAttesa(string cliente);
    void stampaStato();

};

#endif