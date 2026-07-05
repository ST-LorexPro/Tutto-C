#include <iostream>
using namespace std;

int main() {
    const int MAX = 100;     // dimensione massima dell'array
    int input[MAX];
    int risultato[MAX * 10]; // per sicurezza, in caso di intervalli grandi
    int n = 0;               // numero di elementi letti
    int r = 0;               // numero di elementi del risultato
    int num;

    cout << "Inserisci una sequenza di interi (termina con -1): " << endl;

    // Lettura dei numeri fino a -1
    while (n < MAX) {
        cin >> num;
        if (num == -1)
            break;
        *(input + n) = num; // uso dell’aritmetica dei puntatori
        n++;
    }

    // Controllo
    if (n < 2) {
        cout << "Devi inserire almeno due numeri per formare un intervallo!" << endl;
        return 0;
    }

    // Creazione degli intervalli
    for (int i = 0; i < n - 1; i++) {
        int start = *(input + i);
        int end   = *(input + i + 1);

        if (start <= end) {
            for (int j = start; j <= end; j++) {
                *(risultato + r) = j;
                r++;
            }
        } else {
            for (int j = start; j >= end; j--) {
                *(risultato + r) = j;
                r++;
            }
        }
    }

    // Stampa del risultato
    cout << "Array risultante: [ ";
    for (int i = 0; i < r; i++) {
        cout << *(risultato + i);
        if (i < r - 1)
            cout << ", ";
    }
    cout << " ]" << endl;

    return 0;
}
