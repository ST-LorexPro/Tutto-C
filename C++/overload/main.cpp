
#include "main.hpp"


using namespace std;

int somma(int x, int y){
    
    return 0;
}

int somma(int x, double y){   // lo fa fare perche la firma è diversa (la firma sono il numero di parametri e il loro tipo)
    
    return 0;
}

int main(){
    somma(5,6);
    somma(5, 6.6);
    
    return 0;
}