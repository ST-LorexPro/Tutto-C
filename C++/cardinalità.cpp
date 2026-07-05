#include <iostream>
#include <limits.h>
using namespace std;

int main(){
    int n, card_fam=0, card_max=0, card_ins=0;
    cout<<"Inserisci un numero (-1 per terminare): ";
    cin>>n;
    while(n!=-1){
  	if (n!=0){
	  card_ins++;
	} else {
	    card_fam++;
	    if(card_ins>card_max){
	      card_max=card_ins;
	    }
	    card_ins=0;
	  }
	cout<<"Inserisci un numero (-1 per terminare): ";
	cin>>n;
    }
    cout<<"La cardinalità massima è: "<<card_max<<endl;
    cout<<"la cardinalità famiglia è: "<<card_fam<<endl;

return 0;
}
