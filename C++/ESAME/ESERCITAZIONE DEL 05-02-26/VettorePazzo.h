#ifndef VETTORE_PAZZO_H
#define VETTORE_PAZZO_H

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
class VettorePazzo: public vector<unsigned>{
private:
	unsigned numeroPazzo;
public:
	VettorePazzo():numeroPazzo(6){}

	VettorePazzo(unsigned n){
		if(n==0){
			cout<<"il numero pazzo non puo essere 0"<<endl;
			numeroPazzo=6;
		}
		else{
			numeroPazzo=n;
		}
	}

	void push_back(unsigned n){
		if(n % numeroPazzo==0){
			cout<<"Numero Non Aggiunto"<<endl; // DEBUG
			return;
		}
		vector<unsigned>::push_back(n);
	}

	unsigned operator[](int i){
		unsigned lunghezza=vector<unsigned>::size();
		if (lunghezza % numeroPazzo == 0){
			return 0;
		}

		if(i < 0){
			int indiceReale= -i;
			if(indiceReale >= lunghezza){
				return vector<unsigned>::at(0);
			}
			else if(indiceReale < lunghezza){
				vector<unsigned> copia= *this;
				reverse(copia.begin(), copia.end());
				return copia.at(i);
			}
		}
		else{
			if(i < lunghezza){
				return vector<unsigned>::at(i);
			}
			else if(i>=lunghezza){
				int ultimoIndice= *vector<unsigned>::end();
				return vector<unsigned>::at(ultimoIndice);
			}
		}
	}
	
	bool operator==(VettorePazzo& other){
		return true;
	}

	bool operator<(VettorePazzo& other){
		return numeroPazzo< other.numeroPazzo;
	}

		bool operator>(VettorePazzo& other){
		return numeroPazzo> other.numeroPazzo;
	}

};

#endif 