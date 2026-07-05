#ifndef GESTIONE_BIBLIOTECA_H
#define GESTIONE_BIBLIOTECA_H

#include<iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>


using namespace std;

struct Libro{
    string ISBN;
    string titolo;
    int copieDisponibili;

    bool operator==(Libro& other){return ISBN==other.ISBN;}
};


class GestioneBiblioteca{
private:
    vector<Libro> libri;
    unordered_map<string, Libro> prestati;
    unordered_map<string, queue<string>> coda;

public:
    GestioneBiblioteca()=default;
    
    bool aggiungiLibro(Libro& l){
        for(Libro& libro : libri){
            if(libro == l){
                return false;
            }
        }
        libri.push_back(l);
        return true;
    }

    bool registraPrestito(string nome, string ISBN){
        for (Libro& l : libri){
            if (l.ISBN == ISBN && l.copieDisponibili>0){
                prestati[nome]=l;
                l.copieDisponibili--;
                return true;
            }
            else if(l.ISBN == ISBN && l.copieDisponibili==0){
                coda[ISBN].push(nome);
                return false;
            }
        }
        return false;
    }

    void restituisciLibro(string nome, string ISBN){
        auto itA= prestati.find(nome);
        if(itA!= prestati.end() && itA->second.ISBN == ISBN){
            prestati.erase(itA);
            for(Libro& l : libri){
                    if(l.ISBN == ISBN){
                        if(!coda[ISBN].empty()){
                            prestati[coda[ISBN].front()]=(l);
                            coda[ISBN].pop();
                            return;
                        }
                        else{
                            l.copieDisponibili++;
                            return;
                        }
                    }
                }
            }
        else{
            cout<<"Utente non presente"<<endl;
            return;
        }
    }

    int personeInCoda(string ISBN){
        return coda[ISBN].size();
    }
};

#endif