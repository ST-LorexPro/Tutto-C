#ifndef TRACKER_ABITUDINI_H
#define TRACKER_ABITUDINI_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
struct Abitudine{
private:
    const string nome;
    int obiettivoSettimanale;
    int streakAttuale;
public:
    Abitudine(string n): nome(n), obiettivoSettimanale(0), streakAttuale(0){}
    Abitudine(string n, int o, int s): nome(n), obiettivoSettimanale(o), streakAttuale(s){}

    void setObiettivo(int o){
        if(o>0){
            obiettivoSettimanale=o;
        }
    }
    void setStreak(int s){
        if(s>=0){
            streakAttuale=s;
        }
    }

    string getNome()const{return nome;}
    int getObiettivo()const {return obiettivoSettimanale;}
    int getStreak() const {return streakAttuale;}

    bool operator==(Abitudine& other){
        return nome==other.nome;
    }


    ~Abitudine(){};
};

class TrackerAbitudini{
protected:
    vector<Abitudine> abitudini;
public:
    TrackerAbitudini()=default;
    TrackerAbitudini(const map<string, unsigned>& mappa){
        for(const auto& [n, o] : mappa){
                Abitudine i(n, o, 0);
                abitudini.push_back(i);
        }
    }

    void aggiungiAbitudine(Abitudine newA){
        bool trovato=false;
        for(Abitudine& a : abitudini){
            if(a== newA){
                trovato=true;
            }
        }
        if(trovato==false){
            abitudini.push_back(newA);
        }
        else{cout<<"Abitudine Già Presente"<<endl;}
    }

    virtual void segna_completamento(string nome, bool raggiunto){
        for(Abitudine& a: abitudini){
            if(raggiunto==true){
                if(a.getNome()==nome){
                    a.setStreak(a.getStreak()+1);
                    return;
                }
            }
            else{
                if(a.getNome()==nome)
                    a.setStreak(0);
            }
        }
    }


    virtual ~TrackerAbitudini(){};

};




#endif
