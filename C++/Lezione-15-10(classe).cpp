#include <iostream>
using namespace std;

class Cerchio
{
//private:       		// specificatore di accesso in questo caso Privato.
//public:				// tramite questo specificatore di accesso è pubblico ma cosi puo essere modificato.
private:				//lo teniamo privato cosi non puo essere modificato 
	float x,y; 		    // centro del cerchio
	float raggio;
public:
	float getRaggio(){  // utiliziamo questa funzione per avere il raggio, si chiama Metodo getter.
		return raggio;
	}
	float getX(){  		//metodo getter
		return x;
	}
	float getY(){  		//metodo getter
		return y;
	}
	void setRaggio(float h){  //Metodo setter
		if (h<0){
			return;
			cout<<"nuovo valore negativo, modifica non apportata";
		}
		raggio = h;
	}
};

int main()
{
	Cerchio C;
//	cout<<C.raggio  //serve a conoscere il dato che c'è in C (raggio)
// di default tutto quello che c'è in una classe è privato e quindi viene nascosto fuori dalla classe, bisogna modificare lo specificatore di accesso per utilizzarlo. Infatti da errore il comando sopra.
	cout<<C.getRaggio(); // su C esegui il metodo getRaggio
}