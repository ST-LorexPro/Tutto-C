#ifndef GESTIONEDEBITI_H
#define GESTIONEDEBITI_H

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class GestioneDebiti{
public:
    GestioneDebiti( const vector<string>& amici);
    void anticipa(string x, string y, float k);
    float saldo(string x, string y)const;
    void paga(string x, string y, float k);
private:
    unordered_map<string,unsigned> contoAmici;
    vector<vector<float>> contiCompagnia;
};

#endif