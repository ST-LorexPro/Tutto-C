#include <iostream>
using namespace std;

int main(){
	unsigned max=1000;
	unsigned *u=new unsigned int[max];
	unsigned v,i=0;
	cin>>v;
	while(v!=0){
		if (i==max){
			unsigned *temp=new unsigned[max*2];
			for(unsigned j=0;j<max;j++){
				temp[j]=u[j];  // equivale a *(temp+j)=*(u+j)
			}
			delete[] u; 
			u=temp;
			max*=2;	
		}
		if(v>50){
			u[i++]=*u;
			cin>>v;
		}	
	}
}
