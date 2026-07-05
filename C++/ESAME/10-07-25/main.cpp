#include "OrganizzaRecensioni.h"
#include "Ristorante.h"


using namespace std;


int main(){
    OrganizzaRecensioni app;

    app.aggiungiRecensione("Da Mario", "Roma", {41.9, 12.5}, {3, 5, 4, 2});
    app.aggiungiRecensione("Sushi Zen", "Milano", {45.4, 9.1}, {5, 4, 3, 5});
    app.aggiungiRecensione("Pizza Pazza", "Napoli", {40.8, 14.2}, {2, 5, 3, 3});
    
    app.aggiungiRecensione("Da Mario", "Roma", {41.9, 12.5}, {3, 5, 5, 2});

    cout << "--- Test 1: Lettura Singola ---" << endl;
    cout << "Voto Location di Da Mario (Roma): " << app.getValutazione("Da Mario", "Roma", "location") << endl;

    cout << "\n--- Test 2: Filtra e Ordina ---" << endl;
    cout << "Cerco ristoranti con Qualità >= 4, ordinati per Originalità decrescente:" << endl;

    // Parametri: soglia 4 su "qualità", ordina per "originalità"
    vector<Ristorante> classifica = app.filtraEOrdina(4, "qualità", "originalità");

    for (const auto& r : classifica) {
        r.stampaDettagli();
    }
    return 0;
}