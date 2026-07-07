#ifndef FRIGORIFERO_SALUTISTA_H
#define	FRIGORIFERO_SALUTISTA_H

#include "Frigorifero.h"

using namespace std;

class FrigoriferoSalutista : public Frigorifero {
public:
	Alimento estrai(string ripiano)override{
		if(ripiani[ripiano].empty()){
			return Alimento();
		}
		vector<Alimento> alimenti;
		unsigned kcal = ripiani[ripiano][0].getKcal();
		Alimento minore = ripiani[ripiano][0];
		int indiceMinore = 0;
		for(int i=0; i<ripiani[ripiano].size(); i++){
			if(ripiani[ripiano][i].getKcal() < kcal){
				kcal=ripiani[ripiano][i].getKcal();
				minore = ripiani[ripiano][i];
				indiceMinore = i;
			}
		}
		bool ControllareSano = false;
		for(int i=0; i<ripiani[ripiano].size(); i++){
			if(ripiani[ripiano][i].getKcal() == kcal){
				alimenti.push_back(ripiani[ripiano][i]);
				ControllareSano=true;
			}
		}
		if(ControllareSano){
			for(int i=0; i<alimenti.size(); i++){
				if(alimenti[i].getSano()){
					minore=alimenti[i];
					for(int j=0; j<ripiani[ripiano].size(); j++){
						if(ripiani[ripiano][j] == minore){
							ripiani[ripiano].erase(ripiani[ripiano].begin() + j);
						}
					}
					return minore;
				}
			}
		}
		ripiani[ripiano].erase(ripiani[ripiano].begin() + indiceMinore);
		return minore;
	}
};


#endif
