#include<iostream>
using namespace std;


//int main()
//{

//	int a=5, b=3;

//	cout<< (float) a/b<<endl; //cosi si cambia il tipo della variabile, si usano le parentesi per indicare che si l'operazione da fare prima è cambiare il tipo e poi l'operazione.
//----------------------------------------------------------------------------------------------------------------

//return 0;

//}

int main()
{

	int a=5;
	int b=a++; //in questo caso b diventa 5 e a=6
	int b=++a; //invece in questo caso, b e a diventano 6

	cout<<b<<" "<<a;

	a++; //postincremento. si usa all'interno di altre espressioni.

	++a; //preincremento, è più efficente.

}
