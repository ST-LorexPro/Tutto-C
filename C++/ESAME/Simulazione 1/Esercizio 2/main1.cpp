#include <iostream>

using namespace std;

int main(){
    int* matricola= new int[6]{2,6,6,1,3,8};

    int * nuova_matricola = new int[3];

    for (int i=0; i < 6; i+=2) {
        nuova_matricola[i/2] = matricola[i] + matricola[i+1];
    }

    for (int i=0; i<3; i++){
        cout<<nuova_matricola[i]<<endl;
    }

    cout << matricola + 4 << endl;


    return 0;
}