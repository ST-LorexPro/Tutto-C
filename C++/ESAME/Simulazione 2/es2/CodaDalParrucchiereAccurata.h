#ifndef CODAPARRUCCHIEREACCURATA_H
#define CODAPARRUCCHIEREACCURATA_H

#include "CodaDalParrucchiere.h"

class CodaDalParrucchiereAccurata: public CodaDalParrucchiere{
protected:
    map<string, unsigned> velocita;

    static vector<string> estraiNomi(const vector<string, unsigned>& dati);

public:
    CodaDalParrucchiereAccurata(vector<string> parrucchieri, map<string, unsigned>& dati);

    int stimaAttesa(string cliente) override;

};


#endif