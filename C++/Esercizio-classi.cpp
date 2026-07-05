#include <iostream>
using namespace std;

class ContoCorrente
{
	private:
		int CodiceConto=0;
		float Saldo=0;
	public:
		int GetCodice(){
			return CodiceConto;
		}
		float GetSaldo(){
			return Saldo;
		}
		void SetCodice(int x){
			CodiceConto=x;
		}
		void Preleva(float p){
			Saldo-=p;
		}
		void Deposita(float d){
			Saldo+=d;
		}
		void Stampa(){
			cout<<"Codice Conto: "<<CodiceConto<<endl;
			cout<<"Saldo: "<<Saldo<<endl;
		}
};

int main(){
	int x=0;
	int y=0;
	ContoCorrente Conto;
	cout<<"Inserire Codice Conto: ";
	cin>>x;
	Conto.SetCodice(x);
	while(y != 4){
		cout << "Operazioni Possibili:" << endl;
		cout << "1. Deposita" << endl;
		cout << "2. Preleva" << endl;
		cout << "3. Stampa" << endl;
		cout << "4. Exit" << endl;
		cout << "Selezionare l'operazione desiderata: ";
		cin >> y;
		
		if (y == 1){
			float d;
			cout << "Inserire l'importo che si vuole depositare: ";
			cin >> d;
			Conto.Deposita(d);
		}
		else if (y == 2){
			float p;
			cout << "Inserire l'importo che si vuole prelevare: ";
			cin >> p;
			Conto.Preleva(p);
		}
		else if (y == 3){
			Conto.Stampa();
		}
		else if (y == 4){
			cout << "Uscita dal programma..." << endl;
		}
		else {
			cout << "Operazione non presente in elenco." << endl;
		}
	}
return 0;
}