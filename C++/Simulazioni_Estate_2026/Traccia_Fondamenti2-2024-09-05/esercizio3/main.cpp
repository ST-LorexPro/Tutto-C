#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<vector<int>> popola_campo(unsigned N,vector<pair<int,int>> bombe){
	if(N<=0){
		cout<<"impossibile creare una matrice con questa dimensione"<<endl;
		return vector<vector<int>>();
	}

	if(bombe.empty()){
		cout<<"Non sono presenti bombe"<<endl;
		return vector<vector<int>>();
	}
	vector<vector<int>> campo(N, vector<int>(N, 0));
	bool ciSonoBombe = false;
	for(int i=0;i<bombe.size(); i++){
		int riga = bombe[i].first;
		int colonna = bombe[i].second;
		if(riga >=0 && riga < N && colonna >=0 && colonna < N){
			ciSonoBombe=true;
			campo[riga][colonna] = -1;
		}
	}
	if(!ciSonoBombe){
		cout<<"Non sono presenti bombe valide"<<endl;
		return vector<vector<int>>();
	}

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(campo[i][j] == -1){
				continue;
			}

			int counterBombe = 0;
			for(int r=-1; r<=1; r++){
				for(int c=-1; c<=1; c++){
					if(r == 0 && c == 0) {
						continue;
					}

					int nuovaRiga= i + r;
					int nuovaColonna = j + c;

					if (nuovaRiga >=0 && nuovaRiga < N && nuovaColonna >= 0 && nuovaColonna < N){
						if(campo[nuovaRiga][nuovaColonna] == -1){
							counterBombe++;
						}
					}
				}
			}
			campo[i][j] = counterBombe;
		}
	}

	return campo;
}

int main(){
	
	vector<pair<int,int>> bombe(5);
	for(int i=0; i<bombe.size();i++){
		bombe[i] = {i,i};
	}
	vector<vector<int>> campo = popola_campo(5, bombe);

	for (int i=0; i<campo.size(); i++){
		cout<<"[";
		for (int j=0; j<campo.size(); j++){
			cout<<campo[i][j]<<" ";
		}
		cout<<"]"<<endl;
	}
	return 0;
}	