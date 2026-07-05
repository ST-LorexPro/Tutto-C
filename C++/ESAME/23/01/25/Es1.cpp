//Esercizio 1
//Data la seguente porzione di programma rispondere alle domande corrispondenti:
void f(int& a) {if (a%2==0) a++; else a-=2;}
int &g(int& a) {int b=a; return b;}


int main() {
int* matricola = new int[6]{2,6,6,1,3,8};
// 1. Le istruzioni seguenti sono corrette? Se si, cosa viene stampato?
f(g(matricola[2]));                               //le istruzioni sono sintatticamente corrette, l'errore sta nella funzion g che restituisce il riferimento di una variabile locale che al di fuori della funzione non c'è.
cout << matricola[2] << endl; 
// 2. Le istruzioni seguenti sono corrette? Se si, cosa viene stampato?
int* p = matricola + 4;  //puntatore a 3
int* q = matricola + 3;  //puntatore a 1
p = q;  // p(matricola[4])=q(matricola[3]);
q = p;  //q(matricola[3])=q(matricola[3]); puntano entrambi a matricola[3]
*p=0;   //modifica matricola[3] in 0
*q=9;   //modifica matricola[3] in 9
cout << *(matricola+3) << " " << *(matricola+4) << endl;   // stampa 9 3.



// 3. La seguente istruzione è corretta? Se si, cosa viene stampato?

cout << matricola [matricola +2] << endl; //  No. poichè all'interno delle parentesi[ ]è richiesto un intero.


// 4. Selezionare TUTTE le operazioni necessarie per deallocare la memoria allocata nel programma
a. delete[] matricola;
//b. delete p;
// c. for (int i=0; i < 6; i++) {delete matricola[i];}
// d. delete matricola;
//e. delete q;
return 0;
} 
