#ifndef CARRELLO_PREMIUM_H
#define CARRELLO_PREMIUM_H

#include "Carrello.h"
#include <algorithm>

using namespace std;

class CarrelloPremium : public Carrello{
private:
    pair<string, double> omaggio={"omaggio", 0};

public:
    CarrelloPremium()=default;

    double totale() override{
        double tot=0;
        for(int i=0; i< prodotti.size(); i++){
            tot+= prodotti[i].second;
        }
        if(tot > 100){
            bool giaPresente=false;
            for(int i=0; i<prodotti.size(); i++){
                if(prodotti[i]==omaggio){
                    giaPresente=true;
                }
            }
            if(!giaPresente){
                prodotti.push_back(omaggio);
                cout<<"Omaggio gratuito aggiunto al carrello"<<endl;
            }
        }
        return tot;
    }
};

#endif