#ifndef PARTITA_H
#define PARTITA_H

#include <iostream>
#include <string>

using namespace std;

class Partita{
private:
	string squadraCasa;
	string squadraOspite;
	int goalCasa;
	int goalOspite;

public:

	Partita(): squadraCasa("Non definita"), squadraOspite("Non definita"), goalCasa(0), goalOspite(0){}
	Partita(const string& sc,const string& so,const int& gc,const int& go): squadraCasa(sc), squadraOspite(so), goalCasa(gc), goalOspite(go){}

	//getter
	const string getSquadraCasa()const {return squadraCasa;}
	const string getSquadraOspite()const {return squadraOspite;}
	const int getGoalCasa()const {return goalCasa;}
	const int getGoalOspite()const {return goalOspite;}

	//setter
	void setSquadraCasa(const string &sc){squadraCasa = sc;}
	void setSquadraOspite(const string &so){squadraOspite = so;}
	void setGoalCasa(const int &gc){goalCasa = gc;}
	void setGoalOspite(const int &go){goalOspite = go;}

	//metodo
	string vincitore(){
		if(goalCasa > goalOspite){
			return squadraCasa;
		}
		else if (goalOspite > goalCasa){
			return squadraOspite;
		}
		return "Pareggio";
	}
};

#endif