#include <iostream>
using namespace std;

int main()
{
	unsigned int n;
	cout<<"inserisci un numero"<<endl;
	cin>>n;
	int x=1;
	int somma=0;
	while(somma<n)
	  {
		somma+=x;
		++x;
	  }
	  if (somma==n)
	     cout<<"SI"<<endl;
	  else
	     cout<<"NO"<<endl;
return 0;
}
