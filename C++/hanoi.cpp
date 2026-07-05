#include <iostream>
using namespace std;

void hanoi(int n, char A,char C, char B){
	if (n==1){
		cout<<"Sposta il disco 1 da "<< A << " a "<< C << endl;
		return;
	}
	
	hanoi(n-1, sorgente, appoggio, destinazione);
	
	cout<<"Sposta il disco "<< n << " da "<< A << " a "<< C <<endl;
	
	hanoi(n-1, B, C, A);
	
}

int main(){
	int n;
	cout << "Inserisci il numero di dischi: ";
	cin >> n;
	
	hanoi(n, 'A', 'C', 'B');
	return 0;
}