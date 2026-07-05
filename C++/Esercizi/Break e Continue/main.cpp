#include <iostream>
#include <vector>

using namespace std;

void numeri_da_1_a_10(){
    for (int i=0; i<=10; i++){
        if(i==5)
            continue;
        cout<<i<<endl;
    }
}


void numeri_pari(){
    for (int i=0; i<=20; i++){
        if (i%2!=0)
            continue;
        cout<<i<<endl;
    }
}

void divisibile(){
    int numero;
    do{
        cout<<"Inserisci un numero: ";
        cin>>numero;

        if (numero%7==0)
            break;
    }while(true);

    cout<<"Il numero è divisibile per 7"<<endl;


}


int main(){
    numeri_pari();

    divisibile();
}
