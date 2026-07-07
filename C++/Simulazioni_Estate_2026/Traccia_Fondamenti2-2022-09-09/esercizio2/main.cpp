#include "GestorePartite.h"
#include <iostream>

using namespace std;

int main() {
    GestorePartite gestore;

    gestore.aggiungiPartita("Juventus", "Milan", 2, 1);
    gestore.aggiungiPartita("Inter", "Roma", 1, 1);
    gestore.aggiungiPartita("Juventus", "Napoli", 2, 0);
    gestore.aggiungiPartita("Milan", "Inter", 0, 2);
    gestore.aggiungiPartita("Juventus", "Inter", 1, 0);

    cout << "Test getSquadraPiuForte():" << endl;
    cout << "Risultato atteso: Juventus" << endl;
    cout << "Risultato ottenuto: " << gestore.getSquadraPiuForte() << endl;
    cout << "-----------------------------------" << endl;

    cout << "Test mediaGoal():" << endl;
    cout << "Goal totali: 10, Partite: 5 -> Media attesa: 2.0" << endl;
    cout << "Media ottenuta: " << gestore.mediaGoal() << endl;

    return 0;
}