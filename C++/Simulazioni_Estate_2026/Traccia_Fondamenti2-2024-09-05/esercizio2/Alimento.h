#ifndef ALIMENTO_H
#define ALIMENTO_H

#include <iostream>
#include <string>

using namespace std;

class Alimento{
private:
	string nome;
	string tipo;
	unsigned kcal;
	bool sano;
public:
	Alimento() : nome(""), tipo(""), kcal(0), sano(false) {}
	Alimento(string nome, string tipo, unsigned kcal, bool sano): nome(nome), tipo(tipo), kcal(kcal), sano(sano){}

	string getTipo() const {return tipo;}
	string getNome() const {return nome;}
	unsigned getKcal() const {return kcal;}
	bool getSano() const {return sano;}

	bool operator==(const Alimento& altro) const {
	        return nome == altro.nome && tipo == altro.tipo && kcal == altro.kcal && sano == altro.sano;
	    }
};


#endif
