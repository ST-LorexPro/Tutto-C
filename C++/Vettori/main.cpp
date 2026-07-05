#include <iostream>
#include <string>
#include<vector>

using namespace std;

void stampa(vector<int> x){

    for(int y : x){
        cout<<y<<endl;
    }

}

int main(){
    vector<int> numeri = {10,20,30,40};
    numeri [0]=100;
    
    //numeri.clear(); // svuota il vector
    numeri.pop_back(); // rimuove l'ultimo elemento
    numeri.push_back(50); // aggiunge 50 alla fine del vector
    numeri.insert(numeri.begin(), 0); //Inserisce all'inizio del vector 0;
    numeri.erase(numeri.begin()); //Cancella il primo elemento
    numeri.erase(numeri.begin() +1); //Cancella il secondo elemento

    //cout<<numeri.size()<<endl; // restituisce la dimensione del vettore

    for (int i = 0; i < numeri.size(); i++){
        cout<<numeri[i]<<endl;
    }

    stampa(numeri);

    return 0;
}
