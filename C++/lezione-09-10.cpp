#include <iostream>
using namespace std;
/*
int main()
{
	int A[3][3]={{1,2,3}{1,2,3}{1,2,3}};
	
	for(unsigned i=0; i<3
}
*/
/*
int main()
{
	
	//creazione di una matrice
	int ** M= new int*[3];
	for(unsigned i=0; i<3; i++)
		M[i]= new int[3];
	
	//riempio la matrice con 0
	for(unsigned i=0; i<3; i++)
		for(usigned j=0; j<3; j++)
			M[i][j]=0;
		
	//stampiamo la matrice
	for(unsigned i=0; i<3; i++)
		for(usigned j=0; j<3; j++)
			cout<<M[i][j]<<" ";
		cout<<endl;
		
	//deallochiamo tutti gli array che compongono la matrice
	for(unsigned i=0;i<3;i++)
		delete [] M[i];
	delete[] M;
	
	
}
*/
/*
int main()
{
	//
	char a='a';
	++a; //stampa b perche va avanti
	cout<<a;
	//
	char a='a';//a= int perche vale 97
	cout<<a+1; // stampa 98 perche a vale 97 quindi 97+1=98 per via del codice ASCII
}
 */
/*
 void stampaRettangolo(int a, int b) // funzione, va sopra il main, senno quando la chiamo non la vede.(void perchè non c'è un valore di ritorno)
 {
	for(int i=0; i<a; i++)
	{
		for(int j=0;j<b;j++)
			 cout<<"*";
		cout<<endl;
	}
 }
 
 
 int main(){
	 stampaRettangolo(2,7);
 }
 */

//possono esistere 2 funzioni con lo stesso nome a patto che abbiano lista di parametri diversa, di tipo o di quantità
/*
void scambia(const int & , int &);

int main() {
	int a=2, b=3;
	int *x =&a, *y=&b;
	
}
*/

/*
#include<iostream>
using namespace std;
void scambia(int &, int &);
int main(){	
	int a=2, b=3;
	int *x =&a, *y=&b;
	cout <<* x << " " <<* y << a << " " << b << endl;
	scambia(x,y);
	cout <<* x << " " <<* y << a << " " << b << endl;
}
void scambia(int*& x, int* &y){
	int* temp=x;
	x=y;
	y=temp;
}
*/

void raddoppia(int *, int);
void incrementa(int[], int]

int main(){
	int dim=10,x ,i=0;
	int * a =new int [dim];
	cin>>x;
	while(x!=0){
		if (i==dim)
			raddoppia(a, dim);
		a[i++]=x;
		cin>>x;
	}
	int a[5]={1,2,3,4,5}
	incrementa(a,5);
}

void raddoppia(int *a, int dim){
	int *temp= new int[dim*2];
	for (unsigned i=0; i<dim; i++){
		temp[i]=a[i]
	}
	delete[]a;
	a=temp
	dim*=2;
}


void incrementa(int[], int){
	for unsigned
}