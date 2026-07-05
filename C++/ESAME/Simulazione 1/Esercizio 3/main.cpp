#include <iostream>
#include <vector>
using namespace std;

bool f(Grafo& g){
    int n=g.n(); //numero di nodi del grafo g

    vector<int> grado_uscente(n,0);
    vector<int> grado_entrante(n,0);

    if(g.m()%2!=0) return false;

    //Calcolo dei gradi
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if(g(i,j)){
                grado_uscente[i]++;
                grado_entrante[j]++;
 
           }
        }
    }

    for (int i=0; i<n;i++){
        if(g(i, i)){
            return false;
        }
    }
    int soglia=0;
    for(int i=0; i<n; i++){
        if(grado_entrante[i]<=1){
            soglia++;
        }
    }

    for (int i=0; i<n; i++){
        if(grado_uscente[i]>=soglia){
            return false;
        }
    }
    return true;
}

int main(){
    return 0;
}