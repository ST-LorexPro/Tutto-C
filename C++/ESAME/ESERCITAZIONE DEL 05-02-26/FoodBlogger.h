#ifndef FOOD_BLOGGER_H
#define FOOD_BLOGGER_H


#include <iostream>
#include <string>
#include <utility>
#include <unordered_map>
#include <algorithm>
#include <vector>


using namespace std;

struct Ristorante{
    string nome;
    string localita;
    pair<double, double> posizione;
};


class FoodBlogger{
private:
    unordered_map <Ristorante, unordered_map<string, int>> recensioni;
public:
    FoodBlogger()=default;

    void aggiungiRecensione(Ristorante r, unordered_map<string, int> recensione){
        int countOk=0;
        for(const auto& [cat, voto] : recensione){
            if(voto< 1 || voto>5){
                cout<<"Voto non valido"<<endl;
                return;
            }
            if(cat == "prezzo" || cat=="qualità" || cat=="location" || cat=="originalità"){
                countOk++;
            }
        }
        if(countOk==4){
            recensioni[r]=recensione;
        }

        else{
            cout<<"Categorie non valide"<<endl;
            return;
        }
    }

    int getValutazione(Ristorante r, string cat){
        if(cat == "prezzo" || cat=="qualità" || cat=="location" || cat=="originalità"){   
            for(const auto [c, v] : recensioni[r]){
                if(c == cat){
                    return v;
                }
            }
        }
        else{
            cout<<"Categoria non valida";
            return -1;
        }
    }

    vector<Ristorante> trovaEOrdina(int x, const string& categoriaFiltro, const string& categoriaOrdina){
        vector<pair<Ristorante, int>> candidati;
        for(const auto& [rist, mappaVoti]: recensioni){
            auto itA= mappaVoti.find(categoriaFiltro);
            if(itA != mappaVoti.end() && itA->second >= x){
                auto itB=mappaVoti.find(categoriaOrdina);
                int votoB=0;
                if(itB!= mappaVoti.end()){
                    votoB=itB->second;
                }
                candidati.push_back({rist, votoB});
            }
        }

        sort(candidati.begin(), candidati.end(),
        [](pair<Ristorante, int> p1, pair<Ristorante, int> p2){
        return p1.second > p2.second;
        }
        );

        vector<Ristorante> risultato;
        for(const auto& p: candidati){
            risultato.push_back(p.first);
        }

        return risultato;
    }


    ~FoodBlogger(){};
};

#endif