#ifndef ORGANIZZA_RECENSIONI_H
#define ORGANIZZA_RECENSIONI_H

#include "Locale.h"
#include <algorithm>
#include <vector>

class OrganizzaRecensioni{
private:
	map<Locale, map <string, int>> recensione;
public:
	OrganizzaRecensioni()=default;
	
	void aggiungiRecensione(const Locale& l, const map<string, int>& r){
		for(const auto& [cat, voto] : r){
			if(voto<1 || voto>5){
				cout<<"Voto non valido"<<endl;
				return;
			}
		}
		recensione[l]=r;
	}
	
	int valutazione(const Locale& l, const string& c){
		auto itLocale= recensione.find(l);
		if(itLocale != recensione.end()){
			auto itCategoria = itLocale->second.find(c);
			if(itCategoria != itLocale->second.end()){
				return itCategoria->second;
			}
		}
		return -1;
	}
	
	vector<Locale> trovaEOrdina(int x, const string& categoriaFiltro, const string& categoriaSort) {
    vector<pair<Locale, int>> candidati;

    for (const auto& [locale, mappaVoti] : recensione) {
        auto itA = mappaVoti.find(categoriaFiltro);
        if (itA != mappaVoti.end() && itA->second >= x) {
            auto itB = mappaVoti.find(categoriaSort);
            int votoB = 0;
			if(itB!=mappaVoti.end()){
				votoB=itB->second;
			}
            candidati.push_back({locale, votoB});
        }
    }

    sort(candidati.begin(), candidati.end(), 
        [](const pair<Locale, int>& p1, const pair<Locale, int>& p2) {
            return p1.second > p2.second; // '>' per Decrescente
        }
    );
    vector<Locale> risultato;

    for (const auto& p : candidati) {
        risultato.push_back(p.first); // Inserisco solo il Locale
    }

    return risultato;
}
};

#endif	