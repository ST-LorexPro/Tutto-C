#include "Alimento.h"
#include "Frigorifero.h"
#include "FrigoriferoSalutista.h"

using namespace std;



int main(){
	Alimento pera("pera", "frutta", 34, 1);
	Alimento mela("mela", "frutta", 34, 0);
	Alimento banana("banana", "frutta", 29, 0);
	Alimento pesca("pesca", "frutta", 29, 1);


	FrigoriferoSalutista giancarlo;
	giancarlo.aggiungi(pera);
	giancarlo.aggiungi(mela);
	giancarlo.aggiungi(banana);
	giancarlo.aggiungi(pesca);
	Alimento salutare = giancarlo.estrai("frutta");
	cout<<salutare.getNome()<<endl;

}
