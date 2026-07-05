#include <iostream>
#include <string>

using namespace std;

void funzione(int& x){ // con le referenze si puo modificare anche se fuori dallo scope
    x = 10; 
}
int &comparazione(int &x, int &y){
    return (x>y) ? x:y;
        
}

int main(){
    
    // int prova = 5;

    // // int &referenza_prova= prova; //non può essere null

    // cout<< prova <<endl;
    // // cout<< referenza_prova <<endl;
    // funzione(prova);

    // cout<<prova<<endl;
    // // prova = 10;
    // // cout<< prova <<endl;
    // // cout<< referenza_prova <<endl;
    
    // // referenza_prova = 50;
    // // cout<< prova <<endl;
    // // cout<< referenza_prova <<endl;
    // /*
    // int x=5;
    // int y = 50;

    // int maggiore= (x > y) ? x : y ;  //se la stessa operazione viene eseguita almeno 2 volte serve fare una funzione
    // */
    
    
    int x=5;
    int y = 50;
    int &maggiore = comparazione(x,y);
    cout<<maggiore<<endl;
    maggiore = 100;
    cout<<maggiore;

    return 0;
}