#ifndef TRACKER_ABITUDINI_GAMIFICATO_H
#define TRACKER_ABITUDINI_GAMIFICATO_H

#include "TrackerAbitudini.h"

using namespace std;

class TrackerAbitudiniGamificato: public TrackerAbitudini{
private:
    int XP;
public:
    TrackerAbitudiniGamificato()=default;
    TrackerAbitudiniGamificato(const map<string, unsigned>& mappa, const int pe): TrackerAbitudini(mappa){
        if(pe>=0)
            XP=pe;
    }


    void segna_completamento(string nome, bool raggiunto) override{
        for(Abitudine& a: abitudini){
            if(raggiunto==true){
                if(a.getNome()==nome){
                    a.setStreak(a.getStreak()+1);
                    if(a.getStreak()%5==0){
                        XP+=10;
                    }
                return;
                }
            }
            else{
                if(a.getNome()==nome)
                    a.setStreak(0);
            }
        }
    }

    int leggiXp(){return XP;}


};



#endif