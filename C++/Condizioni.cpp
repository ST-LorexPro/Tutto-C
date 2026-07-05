#include <iostream>
using namespace std;

int main()
{
	bool a=0;  //può essere true=1 o false=0
	cout<<"inserisci 0 o 1" <<endl; //stampa
	cin>>a;  //input
	if(a!=0)  //condizione
	{
	    cout<< a <<endl;
	}
	else  //altrimenti della condizione
	{
	    cout<<!a <<endl;
	}
return 0;  //restituisce un codice che è 0 di default, serve per indicare qualche errore al sistema se diverso da 0

}
