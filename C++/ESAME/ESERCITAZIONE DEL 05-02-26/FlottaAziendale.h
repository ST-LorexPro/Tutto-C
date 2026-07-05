#ifndef FLOTTA_AZIENDALE_H
#define FLOTTA_AZIENDALE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Veicolo{
private:
    string targa;
    string modello;
    int chilometraggio;
public:
    Veicolo(string t, string m, int km){
        targa=t;
        modello=m;
        chilometraggio=km;
    }
    string getTarga()const {return targa;}
    int getChilometraggio()const {return chilometraggio;}
    bool operator==(const Veicolo& other)const {return targa==other.targa;}

    void setChilometraggio(int km){
        chilometraggio=km;
    }
};

class FlottaAziendale{
protected:
    vector<Veicolo> veicoli;
public:
    FlottaAziendale()=default;

    bool aggiungiVeicolo(const Veicolo& newVeicolo){
        for(Veicolo& v:veicoli){
            if(v==newVeicolo){
                return false;
            }
        }
        veicoli.push_back(newVeicolo);
        return true;
    }

    bool aggiornaChilometraggio(const string& targa, const int newKm){
        for(Veicolo& v: veicoli){
            if(v.getTarga()==targa){
                if(newKm >= v.getChilometraggio()){
                    v.setChilometraggio(newKm);
                    return true;
                }
                else{
                    cout<<"Chilometraggio non valido"<<endl;
                    return false;
                }
            }
        }
        return false;
    }

    vector<string> veicoliDaRevisionare(const int& k) const {
        vector<string> res;
        for(const Veicolo& v : veicoli){
            if(v.getChilometraggio()>k){
                res.push_back(v.getTarga());
            }
        }
        return res;
    }


    ~FlottaAziendale(){};
};





#endif