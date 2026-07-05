#ifndef LOCALE_H
#define LOCALE_H

#include <string>
#include <iostream>
#include <utility>
#include <map>


using namespace std;

class Locale{
private:
	string nome;
	string localita;
	pair<double, double> coordinate;
	
public:
	Locale() : nome("null"), localita("null"), coordinate(0,0){}
	Locale(string n, string l, pair<double,double> c): nome(n), localita(l), coordinate(c){}
	
	string getNome() const {return nome;}
	string getLocalita() const {return localita;}
	pair<double, double> getCoordinate() const {return coordinate;}
	
	bool operator==(Locale& other) const{
		return (this->nome==other.nome && this->localita==other.localita);
	}
	
	bool operator<(const Locale& altro) const {
    if (nome != altro.nome) {
        return nome < altro.nome;
    }
    return localita < altro.localita;
	}
	
};

#endif