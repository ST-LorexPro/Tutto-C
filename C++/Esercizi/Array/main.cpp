#include <iostream>

using namespace std;

void somma_int_array(){
    int array[]={5,10,20,30,40,50};
    int lunghezza=sizeof(array) / sizeof(array[0]);
    int somma = 0;
    for (int i=0; i<lunghezza; i++){
        somma+=array[i];
    }
    cout<<"la somma è: "<<somma<<endl;
}

void valore_massimo(){
    int array[]={3,4,5,1,3,10,12};
    int lunghezza= sizeof(array) / sizeof(array[0]);
    int valore_massimo=0;
    for (int i=0; i<lunghezza;i++){
        if (array[i]>valore_massimo)
            valore_massimo=array[i];
    }
    cout<<"Il Valore massimo è: "<<valore_massimo<<endl;
}
/*
Esercizio 3
Verifica se un numero è presente in un array di numeri interi:
*/
bool presente(int num){
    int array[]={10,20,30,40,25,50};
    int lunghezza= sizeof(array) / sizeof (array[0]);
    for (int i=0; i<lunghezza; i++){
        if (array[i]==num)
            return true;

    }
    return false;
}


/*
Esercizio 4
Calcola la media dei valori di un array di numeri interi:
*/

double media(int array[]){
    int lunghezza= sizeof(array)/sizeof (array[0]);
    int somma=0;
    for (int i=0; i<lunghezza; i++){
        somma+=array[0];
    }
    double media= somma / lunghezza;
    return media;
}


/*
Esercizio 5
Inverti l'ordine degli elementi in un array di numeri interi:
Esercizio 6
Trova il numero di occorrenze di un elemento in un array di numeri interi:
Esercizio 7
Copia gli elementi di un array in un altro array:
Esercizio 8
Trova la posizione di un elemento in un array di stringhe:
Esercizio 9
Controlla se un array di numeri interi è ordinato in modo crescente:
Esercizio 10
Calcola la somma di due array di numeri interi e salva il risultato in un terzo array:
*/






int main(){
    int array[]={500,20,30,40,50};
    
    somma_int_array();
    valore_massimo();

    if (presente(20)==1)
        cout<<"SI"<<endl;
    else
        cout<<"NO"<<endl;


    double media1 = media(array);

    cout<<media1;
}
