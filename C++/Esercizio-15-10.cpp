#include <iostream>
using namespace std;

void LeggiMatrice(int A[100][100], int n, int m){
	cout<< "Inserisci gli elementi della matrice (" << n << "x" << m << "):"<<endl;
	for (int i=0; i < n; i++)
		for (int j=0; j<m; j++)
			cin >> A[i][j];
}

void CreaQuadrata(int A[100][100], int B[100][100], int n, int m, int x){
	for (int i=0; i<x; i++)
		for (int j=0; j<x; j++)
			B[i][j]= A[i][j];
}

void stampaMatrice(int M[100][100], int righe, int colonne){
	for( int i=0; i< righe; i++)
		for(int j=0; j<colonne; j++)
			cout<< M[i][j]<< " ";
		cout<<endl;
}
int main(){
	int n, m;
	int A[100][100], B[100][100];
	
	cout << "Numero Righe: ";
	cin >> n;
	cout<<"Numero Colonne: ";
	cin >> m;
	
	LeggiMatrice(A, n, m);
	int x;
	if (n<m)
		x=n;
	else
		x=m;
	CreaQuadrata(A,B,n,m,x);
	
	cout<< "\nMatrice Originale:"<<endl;
	stampaMatrice (A,n,m);
	
	cout<<"\nMatrice Quadrata ("<<x<<"x"<<x<<"):"<<endl;
	stampaMatrice(B,x,x);
	
	return 0;
}