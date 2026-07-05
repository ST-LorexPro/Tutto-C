#ifndef TORNEO_VIDEOGIOCHI_H
#define TORNEO_VIDEOGIOCHI_H

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class TorneoVideogiochi{
private:
    vector<pair<string, int>> giocatori;

public:
    TorneoVideogiochi()=default;
    TorneoVideogiochi(vector<string> partecipanti){
        for(string& p : partecipanti){
            giocatori.push_back({p, 0});
        }
    }

    bool registra_partita(string vincitore, string perdente){
        int trovati=0;
        for(int i =0; i<giocatori.size(); i++){
            if(giocatori[i].first==vincitore){
                trovati++;
            }
            else if(giocatori[i].first==perdente){
                trovati++;
            }
        }
        if(trovati == 2){
            for(int i=0; i<giocatori.size(); i++){
                if(giocatori[i].first == vincitore){
                    giocatori[i].second+=3;
                }
                else if(giocatori[i].first == perdente && giocatori[i].second >0){
                    giocatori[i].second--;

                }
            }
            return true;
        }
        else{return false;}
    }

    vector<string> classifica_top(unsigned k){
        vector<string> risultato;
        vector<pair<string, int>> copiaGiocatori= giocatori;
        sort(copiaGiocatori.begin(), copiaGiocatori.end(), [](const auto& a, const auto& b){
            return a.second > b.second;
        });

        while (copiaGiocatori.size()>k){
            copiaGiocatori.pop_back();
        }

        for(int i=0; i<copiaGiocatori.size(); i++){
            risultato.push_back(copiaGiocatori[i].first);
        }
        return risultato;
        
    }

    bool operator>(const TorneoVideogiochi& other){
        return giocatori.size()>other.giocatori.size();
    }

    ~TorneoVideogiochi(){};
};


#endif