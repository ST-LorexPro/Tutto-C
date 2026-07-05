/*
2. Classe Base DataCenter Gestisce i server. Ogni server ha un nome univoco (stringa) e una lista di Job assegnati.
Dati: map<string, vector<Job>> servers.
Costruttore: Riceve un vector<string> con i nomi dei server e li inizializza vuoti.

-Metodo deployJob(string serverId, Job j):
Ogni server ha un limite massimo di 100 GB di RAM totale occupata.
Se il server scelto ha spazio sufficiente (Somma RAM attuale + Nuova RAM <= 100), aggiungi il Job e restituisci true.
Se il server scelto è pieno (o sfora i 100), cerca tra gli altri server quello che ha il carico di RAM più basso in assoluto. Se quel server ha spazio, aggiungi lì il Job e restituisci true.
Altrimenti restituisci false.

-Metodo killZombieProcess():
Scorre tutti i server.
Elimina dai vettori tutti i Job che occupano meno di 2GB di RAM (considerati processi inutili/zombie).
Restituisce il numero totale di processi eliminati.

-Metodo calcolaConsumo(string serverId) (Virtuale):
Restituisce un double.
Nella versione base, il consumo è semplicemente la somma totale della RAM usata su quel server.
*/

#ifndef DATA_CENTER_H
#define DATA_CENTER_H

#include "Job.h"
#include <iostream>
#include <vector>
#include <map>
#include <climits>

using namespace std;

class DataCenter{
protected:
    map<string, vector<Job>> servers;
    map<string, int> ramOccupata;
    const int maxRam=100;
public:
    DataCenter(vector<string> nomi){
        for(string n : nomi){
            servers[n]=vector<Job>();
            ramOccupata[n]=0;
        }
    }
/*-Metodo deployJob(string serverId, Job j):
Ogni server ha un limite massimo di 100 GB di RAM totale occupata.
Se il server scelto ha spazio sufficiente (Somma RAM attuale + Nuova RAM <= 100), aggiungi il Job e restituisci true.
Se il server scelto è pieno (o sfora i 100), cerca tra gli altri server quello che ha il carico di RAM più basso in assoluto. Se quel server ha spazio, aggiungi lì il Job e restituisci true.
Altrimenti restituisci false.*/
    bool deployJob(string serverId, Job j){
        if(ramOccupata[serverId]+j.ram <= 100){
            servers[serverId].push_back(j);
            ramOccupata[serverId]+=j.ram;
            return true;
        }
        int min=INT_MAX;
        string serverFinale;
        for(const auto& [s, jobs] : servers){
            if(ramOccupata[s]<min && ramOccupata[s]+j.ram<=maxRam){
                min=ramOccupata[s];
                serverFinale=s;
            }  
        }
        if(min != INT_MAX){
            servers[serverFinale].push_back(j);
            ramOccupata[serverFinale]+=j.ram;
            return true;
        }
        return false;
    }

/*-Metodo killZombieProcess():
Scorre tutti i server.
Elimina dai vettori tutti i Job che occupano meno di 2GB di RAM (considerati processi inutili/zombie).
Restituisce il numero totale di processi eliminati.
Metodo calcolaConsumo(string serverId) (Virtuale):
Restituisce un double.
Nella versione base, il consumo è semplicemente la somma totale della RAM usata su quel server.*/
    double killZombieProcess(){
        double tot=0;
        for(auto& [s, jobs] : servers){
            for(size_t i=0; i<jobs.size();){
                if(jobs[i].ram<2){
                    ramOccupata[s]-=jobs[i].ram;                    
                    jobs.erase(jobs.begin() + i);
                    tot+=1;
                }
                else{
                    i++;
                }
            }
        }
        return tot;
    }


/*-Metodo calcolaConsumo(string serverId) (Virtuale):
Restituisce un double.
Nella versione base, il consumo è semplicemente la somma totale della RAM usata su quel server.*/
    virtual double calcolaConsumo(string serverId){
        return ramOccupata[serverId];
    }

    virtual ~DataCenter(){};
};

#endif