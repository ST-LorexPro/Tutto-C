#include <iostream>
#include <limits.h>
using namespace std;

int main(){
    int n, fattn=1;
    cout<<"inserisci un numero positivo intero: ";
    cin>>n;
    if (n==0){
    	cout<<"il fattoriale di "<<n<<" è 1"<<endl;
    }
    int curr_n=n;
    while(curr_n>1){
	fattn*=curr_n;
	curr_n--;
    }
    cout<<"il fattoriale di "<<n<<" è "<<fattn<<endl;

return 0;
}
