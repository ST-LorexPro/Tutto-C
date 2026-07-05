#include <iostream>
#include <string>

using namespace std;

int main(){
    /*
    double voti_storia[5]= {8,9,8,10,7.5};

    voti_storia[0]=10;

    cout<<voti_storia[0]<<endl;

    for (double voto : voti_storia){ // alternativa al solito ciclo for (for({tipo di dato} nome variabile(voto) :(in) array(voti_storia)))
        cout<< voto << endl;         // stampa ogni elemento voto in voti_storia
    }


    cout<<sizeof (voti_storia) <<endl; //restituisce 40 poichè ogni double ha una grandezza di 8 byte

    // per ricevere la lungezza dell'array dobbiamo fare cosi:

    for (int i=0; i<sizeof(voti_storia)/sizeof(double); i++){
        cout<< voti_storia[i]<< endl;
    }
    */
    

    //Array di stringhe
    string celle[2][4] = {
        {"A1","B1","C1","D1"}, 
        {"A2","B2","C2","D2"}
    };

    
    for (int i=0; i<2; i++){
        for (int j=0; j<4; j++){
            cout<<celle[i][j]<<endl;
        }
    }

    cout<< celle[1][2]<<endl;

    return 0;
}