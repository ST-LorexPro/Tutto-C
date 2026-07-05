#include<iostream>
using namespace std;

int main()
{
	cout<<"introduci un numero, 0 per iniziare"<<endl;
	int x;
	cin>>x;
	while(x!=0)
	   {
	     if(x%2==0)
	        cout<<x<<" è pari"<<endl;
	     else
	        cout<<x<<" é dispari"<<endl;
	     cin>>x;
	   }
return 0;

}
