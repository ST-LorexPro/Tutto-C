#ifndef GESTORE_PARTITE_H
#define GESTORE_PARTITE_H

#include "Partita.h"
#include <iostream>
#include <list>
#include <string>
#include <unordered_map>

using namespace std;

class GestorePartite{
private:
	list<Partita*> partite;
public:

	GestorePartite(){}

	void aggiungiPartita(const string& squadraCasa,const string& squadraOspite,const int& goalCasa,const int& goalOspite){
		Partita* partita= new Partita(squadraCasa, squadraOspite, goalCasa, goalOspite);
		partite.push_back(partita);
	}

	string getSquadraPiuForte(){
		unordered_map<string, int>  vincitori;
		for (Partita* p : partite){
			string vincitore = p->vincitore();
			if(vincitore == "Pareggio"){
				continue;
			}
			vincitori[vincitore] ++;
		}

		int maxVincite = -1;
		string squadraPiuForte;

		for(const auto& coppia : vincitori){
			if(coppia.second > maxVincite){
				maxVincite = coppia.second;
				squadraPiuForte = coppia.first;
			}
		}
		return squadraPiuForte;
	}

	double mediaGoal() const{
		double media = 0;
		int nPartite = partite.size();
		for(const Partita* p : partite){
			media += p->getGoalCasa();
			media += p->getGoalOspite();
		}

		media = media / nPartite;
		return media;
	}

	~GestorePartite() {
		for(Partita* p : partite) {
			delete p; 
		}
	}	
};

#endif