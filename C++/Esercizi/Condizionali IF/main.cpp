#include <iostream>
using namespace std;

void pari_dispari(){
    int x;
    cout<<"inserisci un numero intero: ";
    cin >> x;
    if (x%2==0)
        cout<< x <<" e' un numero pari."<<endl;
    else
        cout<< x << " e' un numero dispari."<<endl;
}

void pos_neg_zero(){
    int x;
    cout<<"Inserisci un numero: ";
    cin>>x;
    if (x>0)
        cout<<x<<" e' positivo"<<endl;
    else if (x<0)
        cout<<x<<" e' negativo"<<endl;
    else
        cout<<x<<" e' pari a zero"<<endl;
}

void divisibile_3_5(){
    int x;
    cout<< "Inserire un numero: ";
    cin>>x;
    if (x % 5== 0 && x%3==0)
        cout<<x<<" e' divisibile per 3 e per 5"<<endl;
    else
        cout<< x << " non e' divisibile per 3 e per 5"<<endl;
}



int main(){
    pari_dispari();

    pos_neg_zero();
    
    divisibile_3_5();
}