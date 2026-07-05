/*
tipo_di_ritorno nome_funzione(parametri{
	//corpo funzione
	//istruzioni
	return valore; //opzionale dipende dal tipo di ritorno della funziona
}
*/

#include <iostream>
using namespace std;

//esempio di funzione somma
int somma(int a, int b){
	return a + b;	
}

//esempio di chiamata della funzione
int main(){
	cout<<somma(2, 3);
return 0;
}

/*
In C++ ci sono diversi tipi di funzioni, a seconda del valore di ritorno e dei parametri.

	Tipo di funzione							Descrizione									Esempio
Con ritorno e parametri				Riceve valori e restituisce un risultato		int somma(int a, int b)
Con ritorno ma senza parametri		Non riceve dati, ma restituisce un valore		int leggiNumero()
Senza ritorno ma con parametri		Riceve dati, ma non restituisce nulla			void stampaMessaggio(string nome)
Senza ritorno e senza parametri		Non riceve né restituisce niente				void saluto()
*/


//Il tipo VOID

void saluta() {
	cout << "Ciao!" << endl; // stampa Ciao!
}
//Chiamata funzione
int main(){
	saluta(); // stampa Ciao!
	return 0;
}


//Passaggio dei parametri

//1. Per Valore (Copia)
//Il valore della variabile viene copiato nella funzione.
void cambia(int x) {
    x = 10;
}

int main() {
    int a = 5;
    cambia(a);
    cout << a; // stampa 5, non cambia niente
}

//2. Per riferimento(Modifica Reale)
//La funzione viene modificata direttamente la variabile passata

void cambia(int &x){ // prende l'indiri0
	x = 10;
}

int main(){
	int a =5;
	cout<<cambia(a)<< endl; //stampa 10
}

//funzioni con valori di default
//puoi assegnare valori predefiniti ai parametri:
void saluta(string nome = "Utente") {
    cout << "Ciao " << nome << "!" << endl;
}

int main() {
    saluta();        // usa "Utente"
    saluta("Marco"); // usa "Marco"
}


//Funzioni Ricorsive
//Una funzione ricorsiva è una funzione che chiama se stessa.
//Esempio classico: fattoriale
int fattoriale(int n) {
    if (n == 0) return 1;
    return n * fattoriale(n - 1);
}

int main() {
    cout << fattoriale(5); // stampa 120
}

//Dichiarazione e definizione (prototipi)
//In C++, le funzioni devono essere dichiarate prima di essere usate.
//Se scrivi la definizione dopo il main, serve un prototipo
#include <iostream>
using namespace std;

// dichiarazione (prototipo)
int somma(int a, int b);

int main() {
    cout << somma(4, 6);
    return 0;
}

// definizione
int somma(int a, int b) {
    return a + b;
}
