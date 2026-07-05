#include <iostream>
using namespace std;

int main() {
    const int N = 10;
    int arr[N];
    int *p1, *p2;
    bool uguali = true;

    cout << "Inserisci " << N << " numeri:" << endl;
    for (p1 = arr; p1 < arr + N; p1++) {
        cout << "Elemento " << (p1 - arr + 1) << ": ";
        cin >> *p1;
    }

    // Puntatori alle due metà
    p1 = arr;
    p2 = arr + N / 2;

    // Confronto usando l'aritmetica dei puntatori
    for (int i = 0; i < N / 2; i++) {
        if (*(p1 + i) != *(p2 + i)) {
            uguali = false;
            break;
        }
    }

    // Output del risultato
    if (uguali)
        cout << "Le due metà dell'array sono uguali." << endl;
    else
        cout << "Le due metà dell'array NON sono uguali." << endl;

    return 0;
}
