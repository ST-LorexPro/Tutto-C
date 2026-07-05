#ifndef WEBPAGE_H
#define WEBPAGE_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Webpage{
    private:
        string titolo;
        string testo;
        vector<Webpage*> link;
    public:
        Webpage()=default;

        string getTitolo() const {return titolo;}
        string getTesto() const {return testo;}
        const vector<Webpage*> & getLink()const {return link;}

        void aggiungiLink(Webpage* w) {link.push_back(w);}

        bool operator==(const Webpage& other) {
            return titolo == other.getTitolo();
        }

};

#endif 