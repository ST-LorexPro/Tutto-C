#ifndef WEBSITE_H
#define WEBSITE_H

#include "Webpage.h"
#include <queue>
#include <algorithm>

using namespace std;

class Website{
    private:
        Webpage homepage;

    public:
        Website() = default;
        Website(Webpage w):  homepage(w) {}

        int find_webpage(const Webpage& target) const {
            vector<Webpage> visitati;
            queue<Webpage> daVisitare;
            
            daVisitare.push(homepage);
            visitati.push_back(homepage);

            int level = 0;

            while (!daVisitare.empty()){
                int levelSize = daVisitare.size();

                for(int i=0; i<levelSize; ++i){
                    Webpage curr_page = daVisitare.front();
                    daVisitare.pop();
                    if(curr_page == target)
                        return level;
                    for (Webpage* w : curr_page.getLink()) {
                        if(find(visitati.begin(), visitati.end(), *w) ==visitati.end()){
                            visitati.push_back(*w);
                            daVisitare.push(*w);
                        }
                    }
                }
                level++;
            }
            return -1;
        }
};


#endif