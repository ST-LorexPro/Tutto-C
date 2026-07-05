#include <iostream>
using namespace std;

int main()
{
	cout<<"introduci un numero, 0 per terminare";
	int x;
	cin>>x;
	do
	  {
	   int x;
	   cin>>x;
	   if(x%2==0)
	      cout<<x<< "è pari";
	   else
	      cout<<x<< "è dispari";
	  }
	while(x!=0);

return 0;
}
