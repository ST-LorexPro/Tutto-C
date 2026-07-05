#include <iostream>
#include <algorithm>
using namespace std;
/* Esercizio 1
struct Persona{
    string nome;
    int eta;
};

int main(){
    Persona pers1{"Umile", 20};
    cout<<pers1.nome<<endl;
}
*/

/* Esercizio 2
struct Libro{
    string titolo;
    string autore;
    int anno;
};

int main(){
    Libro libri[2];

    libri[0].titolo="Signore degli anelli";
    libri[0].autore="io";
    libri[0].anno=2025;

    libri[1].titolo="Peter Pan";
    libri[1].autore="fratm ciro";
    libri[1].anno=2006W;

}
*/

/* Esercizio 10
struct Giocatore{
    string nome;
    int punteggio;

};

bool confrontaPunteggio(Giocatore giocatore1, Giocatore giocatore2){
    return giocatore1.punteggio>giocatore2.punteggio;
}

int main(){
    const int NUM_GIOCATORI = 4;
    Giocatore squadra[NUM_GIOCATORI];

    squadra[0].nome="Marco";
    squadra[0].punteggio=120;
    
    squadra[1].nome="Luca";
    squadra[1].punteggio=80;

    squadra[2].nome="Umile";
    squadra[2].punteggio=150;
    
    squadra[3].nome="Paolo";
    squadra[3].punteggio=100;

    sort(squadra, squadra + NUM_GIOCATORI, confrontaPunteggio);

    cout<< "Classifica giocatori:"<<endl;
    for(int i = 0; i < NUM_GIOCATORI; i++) {
        cout<< "Giocatore " << i + 1 << ": " << squadra[i].nome <<", Punteggio: "<< squadra[i].punteggio <<endl;
    }
}
*/