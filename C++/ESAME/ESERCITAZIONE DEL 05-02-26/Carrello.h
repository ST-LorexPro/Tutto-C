#ifndef CARRELLO_H
#define CARRELLO_H

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>



using namespace std;


class Carrello{
protected:
    vector<pair<string, double>> prodotti;
public:
    Carrello()=default;

    void aggiungiProdotto(string nome, double prezzo){
        for(int i=0; i<prodotti.size(); i++){
            if(prodotti[i].first==nome){
                if(prodotti[i].second>prezzo){
                    prodotti[i].second=prezzo;
                    return;
                }
                else{
                    return;
                }
            }
        }
        prodotti.push_back({nome, prezzo});
    }

    void applicaSconto(float percentuale){
        if(percentuale >100 || percentuale < 0){
            cout<<"Percentuale non valida"<<endl;
            return;
        }
        for(int i=0; i<prodotti.size();i++){
            prodotti[i].second=(prodotti[i].second*(100-percentuale))/100;
        }
    }

    virtual double totale(){
        double tot=0;
        for(int i=0; i< prodotti.size(); i++){
            tot+= prodotti[i].second;
        }
        return tot;
    }



    virtual ~Carrello(){};
};

#endif