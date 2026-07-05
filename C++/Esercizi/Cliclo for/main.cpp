#include <iostream>

using namespace std;

void tabellina(){
    int x;
    cout<<"inserisci un numero: ";
    cin>>x;
    for (int i=0; i<=10; i++){
        cout<<x*i<<endl;
    }
}

int main(){
    tabellina();
}
