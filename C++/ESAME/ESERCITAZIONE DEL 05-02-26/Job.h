/*Traccia: Gestione Data Center (Cloud Computing)
Scenario: Devi gestire un Data Center che assegna processi (Job) a diversi Server.

1. Struttura Dati (Job) Ogni processo è una struct Job con:
string id (es. "ProcessoA").
int ram (quantità di RAM richiesta, es. 4GB, 16GB).

*/

#ifndef JOB_H
#define JOB_H

#include <string>

struct Job{
    std::string id;
    int ram;
};



#endif