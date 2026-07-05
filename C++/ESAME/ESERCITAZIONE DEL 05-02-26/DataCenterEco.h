/*3. Classe Derivata DataCenterEco Vogliamo una versione che calcola il consumo energetico reale.
Costruttore: Riceve una map<string, double> efficienza.
Chiave: ID Server.
Valore: Fattore di consumo (es. 1.5 Watt per GB).
Nota: Devi usare il trucco dello static per passare i nomi al costruttore padre.
Override calcolaConsumo(string serverId):
Calcola la somma della RAM.
Restituisce: (Somma RAM) * (Fattore efficienza del server).*/

#ifndef DATA_CENTER_ECO_H
#define DATA_CENTER_ECO_H

#include "DataCenter.h"

class DataCenterEco: public DataCenter{
private:
    map<string, double> efficienza;
    static vector<string> estraiServer(map<string, double> e){
        vector<string> server;
        for(const auto& [s, eff] : e){
            server.push_back(s);
        }
        return server;
    }
public:
    DataCenterEco(map<string, double> e) : DataCenter(estraiServer(e)){
        efficienza=e;
    }

    double calcolaConsumo(string serverId)override{
        return (ramOccupata[serverId] * efficienza[serverId]);
    }

    
};



#endif