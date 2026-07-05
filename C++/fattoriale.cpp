#include <iostream>
using namespace std;

int main(){
	int n;
	cout<<"inserisci un numero positivo intero: ";
	cin>>n;
	int risultato=1;
	for (int i=1;i<=n;i++){
	    risultato*=i;
	}
	cout<<"il fattoriale di "<<n<<" è: "<<risultato<<endl;
return 0;
}

