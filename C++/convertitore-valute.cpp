#include <iostream>
using namespace std;

int main(){
	int euro=0;
	cout<<"inserire l'importo in Euro da convertire: ";
	cin>>euro;
	cout <<"Selezionare in che valuta convertire:" <<endl <<"1.Dollari USA"<<endl <<"2.Yen Giapponesi"<<endl<<"3.Sterline Britanniche"<<endl<<"selezione: ";
	int n=0;
	cin>>n;
	if (n==1){
	cout<<euro<<"€"<<" in Dollari USA sono: "<<euro*1.08<<"$"<<endl;
	}
		else if (n==2){
		cout<<euro<<"€"<<" in Yen Giapponesi sono: "<<"¥"<<euro*168.22<<endl;
		}
		else if (n==3){
		cout<<euro<<"€"<<" in Sterline Britanniche sono: "<<"£"<<euro*0.86<<endl;
		}
		else{
		cout<<"Mi dispiace selezione errata riprovare"<<endl;
		}
}
