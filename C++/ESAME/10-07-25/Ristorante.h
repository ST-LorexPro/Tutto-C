#ifndef RISTORANTE_H
#define RISTORANTE_H

#include <iostream>
#include <string>
#include <utility>

using namespace std;

struct Recensione{
    int prezzo;
    int qualita;
    int location;
    int originalita;

    int getVotoPerCategoria(const string& categoria) const {
        if (categoria == "prezzo") return prezzo;
        if (categoria == "qualità" || categoria == "qualita") return qualita;
        if (categoria == "location") return location;
        if (categoria == "originalità" || categoria == "originalita") return originalita;
        return 0; // Categoria non valida
    }
};

class Ristorante{
protected:
    string nome;
    string localita;
    pair<double, double> coordinate;
    Recensione recensione;

public:

    Ristorante(string n, string l, pair<double, double> c, Recensione r): nome(n), localita(l), coordinate(c), recensione(r){}

    Ristorante(){}


    string getNome(){return nome;}
    string getLocalita(){return localita;}
    Recensione getRecensione() const { return recensione; }

    double getCoordinata(char coordinata){
        if (coordinata == 'X')
            return coordinate.first;
        else if (coordinata == 'Y')
            return coordinate.second;
    }

    void stampaDettagli() const {
        cout << "- " << nome << " (" << localita << ") | "
            << "Prezzo: " << recensione.prezzo << ", "
            << "Qualità: " << recensione.qualita << ", "
            << "Location: " << recensione.location << ", "
            << "Originalità: " << recensione.originalita << endl;
    }

    pair<double, double> getCoordinate(){
        return coordinate;
    }

    bool operator<(const Ristorante& other) const{
        return this->nome<other.nome;
    }
};


#endif