#include "GestioneDebiti.h"

GestioneDebiti::GestioneDebiti(const vector<string>& amici){
    for(unsigned i = 0;i<amici.size(); i++){
        contoAmici[amici[i]]=i;
        contiCompagnia.push_back(vector<float>(amici.size(), 0));
    }
}

void GestioneDebiti::anticipa(string x, string y, float k){
    if(k<= 0.0)
        return;
    unsigned contoCreditore = contoAmici[x];
    if(y == "*"){
        float quota=k/contiCompagnia.size();
        for(unsigned i=0; i<contiCompagnia.size(); i++){
            contiCompagnia[i][contoCreditore] += quota;
        }
    }
    else {
        unsigned contoDebitore = contoAmici[y];
        contiCompagnia[contoDebitore][contoCreditore] += k;
    }
}

void GestioneDebiti::saldo(string x, string y) const{
    if(!contoAmici.contains(x) || !contoAmici.contains(y)){
        cout<<"gli amici specificati non sono validi"<<endl;
        return 0;
    }
    unsigned contoDebitore = contoAmici.at(x);
    unsigned contoCreditore = contoAmici.at(y);

    float somma = contiCompagnia[contoDebitore][contoCreditore] - contiCompagnia[contoCreditore][contoDebitore];
    return somma>0.0 ? somma : 0;
}

void GestioneDebiti::paga(string x, string y, float k){
    if(!contoAmici.contains(x) || !contoAmici.contains(y)){
        cout<<"gli amici specificati non sono validi"<<endl;
        return 0;       
    }
    float debito= saldo(x,y)
    unsigned contoDebitore = contoAmici.at(x);
    unsigned contoCreditore = contoAmici.at(y);

    if (debito > 0 && k <= debito){
        contiCompagnia[contoDebitore][contocreditore] = debito - k;
        contiCompagnia[ContoCreditore][contoDebitore] = 0;
    }
    else cout<<"la somma inserita è superiore al debito presente tra "<<x<<" e "<<y<<endl;
    
}