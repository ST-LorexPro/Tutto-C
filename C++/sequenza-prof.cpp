#include <iostream>
#include <limits.h>
using namespace std;

int main(){
	int n;
	int max=INT_MIN, submax=INT_MIN;
	cout<<"Inserisci 10 numeri: "<<endl;
	for (int i=0; i<10; i++){
	    cout<<"Numero: ";
	    cin>>n;
		if (n>max){
		   submax=max;
		   max=n;
		} else if(n>submax){
		   submax=n;
		  }
	}
	cout<<"il numero massimo è: "<<max<<endl;
	cout<<"il numero submassimo è: "<<submax<<endl;

return 0;
}
