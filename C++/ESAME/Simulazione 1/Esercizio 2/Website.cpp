#include "Website.h"
#include <queue>
#include <set>
#include <string>

using namespace std;

Website::Website(Webpage* hp): homepage(hp){}
int Website::find_webpage(const Webpage& target) const{
    if(homepage == nullptr) return -1;
    if(*homepage == target) return 0;

    queue<pair<Webpage*, int>> da_visitare;

    set<string> titoli_visitati;

    da_visitare.push({homepage, 0});
    titoli_visitati.insert(homepage->getTitolo());

    while (!da_visitare.empty()){
        pair<Webpage*, int> current = da_visitare.front();
        da_visitare.pop();

        Webpage* currentPage = current.first;
        int currentDist = current.second;

        if(*currentPage == target){
            return currentDist;
        }
        for(Webpage* neighbor : currentPage->getLinks()){
            if(titoli_visitati.find(neighbor->getTitolo())== titoli_visitati.end()){
                titoli_visitati.insert(neighbor->getTitolo());
                da_visitare.push({neighbor, currentDist +1});
            }
        }
    }
    return -1;
}
