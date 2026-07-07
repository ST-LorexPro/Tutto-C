#ifndef FRIGORIFERO_H
#define FRIGORIFERO_H


#include "Alimento.h"
#include <vector>
#include <unordered_map>

using namespace std;


class Frigorifero{
protected:
	unordered_map<string, vector<Alimento>> ripiani;

public:
	Frigorifero(){}


	void aggiungi(const Alimento& a){
		string tipo = a.getTipo();
		ripiani[tipo].push_back(a);
	}

	virtual Alimento estrai(string ripiano) = 0;

	virtual ~Frigorifero(){}
};


#endif
