#include <iostream>
using namespace std;

int main(){
	int n =10;
	int numeri[n];
	cout<<"inserisci "<<n <<" numeri interi:"<<endl;

	for (int i = 0; i < n; i++) {
	cout<<"Numero "<< i + 1 <<": ";
	cin >> numeri[i];
	}

	int massimo= numeri[0];
	int submassimo= numeri[0];

	for (int i=1; i<n;i++) {
	     if (numeri[i]>massimo){
	        submassimo=massimo;
		massimo=numeri[i];
	     }
	     else if (numeri[i]>submassimo && numeri[i] != massimo){
		submassimo=numeri[i];
	     }
	}

	cout <<"Il numero massimo è: "<<massimo<<endl;
	cout <<"Il numero submassimo è: "<<submassimo<<endl;
return 0;
}
