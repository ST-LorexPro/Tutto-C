#ifndef GESTIONE_DEBITI_H
#define GESTIONE_DEBITI_H

#include<vector>
#include<iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class GestioneDebiti{
private:
	unordered_map<string, unsigned> contoAmici;
	vector<vector<float>> contiCompagnia;
public:
	GestioneDebiti(const vector<string>& amici){
		for(unsigned i=0; i<amici.size(); i++){
			contoAmici[amici[i]]=i;
			contiCompagnia.push_back(vector<float>(amici.size(), 0));
		}
	}
	
	void anticipa(string x, string y, float k){
		if(k<=0.0){
			return;
		}
		unsigned codiceCreditore= contoAmici[x];
		if(y=="*"){
			float quota=k/contiCompagnia.size();
			for(size_t i=0; i<contiCompagnia.size(); i++){
				contiCompagnia[i][codiceCreditore]=quota;
			}
			contiCompagnia[codiceCreditore][codiceCreditore]=0;
		}
		
		else{
			unsigned codiceDebitore=contoAmici[y];
			contiCompagnia[codiceDebitore][codiceCreditore]=k;
		}
	}
	
	float saldo(string x, string y) const{
		if(!contoAmici.contains(x) || !contoAmici.contains(y)){
			cout<<"Gli amici non sono in lista"<<endl;
			return 0;
		}
		unsigned codiceDebitore= contoAmici.at(x);
		unsigned codiceCreditore= contoAmici.at(y);
		float saldo=0;
		if(contiCompagnia[codiceCreditore][codiceDebitore] > 0){
			saldo = contiCompagnia[codiceDebitore][codiceCreditore] - contiCompagnia[codiceCreditore][codiceDebitore];
		}
		else{
			saldo = contiCompagnia[codiceDebitore][codiceCreditore];
		}
		if(saldo <=0){
			return 0;
		}
		else{
			return saldo;
		}
	}
	
	void paga(string x, string y, float k){
		unsigned codiceDebitore=contoAmici[x];
		unsigned codiceCreditore=contoAmici[y];
		float s=saldo(x,y);
		if(s <=0 || k > s){
			return;
		}
		else{
			s-=k;
			contiCompagnia[codiceDebitore][codiceCreditore]=s;
			contiCompagnia[codiceCreditore][codiceDebitore]=0;
		}
	}
	
	virtual ~GestioneDebiti(){};
	
};


#endif
