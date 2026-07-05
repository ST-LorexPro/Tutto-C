#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Persona
{
    string nome;
    string cognome;
    int eta;
};

int main(){

    Persona persona1 = {"luca", "Rossi", 25}; //se sai gia i dati da inserire

    //Se ancora non sai i dati
    Persona persona2;

    persona2.nome="marco";
    persona2.cognome="rossi";
    persona2.eta=30;


    cout<<persona2.nome<<endl;

    return 0;
}
