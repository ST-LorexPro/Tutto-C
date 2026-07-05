#include <iostream>
#include <string>

using namespace std;

void funzione(int *pParametro){

    *pParametro = 50;
}

int main(){
    int prova = 5;
    int *pProva = nullptr;
    
    pProva = &prova;

    cout<< prova <<endl;    //stampa valore puntato(5)
    // cout<< &prova <<endl;   //stampa l'indirizzo
    // cout<< pProva <<endl;   //stampa l'indirizzo
    // cout<< *pProva <<endl;  //stampa valore puntato(5)

    *pProva=200;

    cout<< prova <<endl;    //stampa valore puntato(200)
    // cout<< &prova <<endl;   //stampa l'indirizzo
    // cout<< pProva <<endl;   //stampa l'indirizzo
    // cout<< *pProva <<endl;  //stampa valore puntato(200)

    funzione(&prova);
    cout<< prova <<endl;    //stampa valore modificato dalla funzione (50)

    return 0;
}