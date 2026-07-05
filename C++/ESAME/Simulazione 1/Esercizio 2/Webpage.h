#ifndef WEBPAGE_H
#define WEBPAGE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Webpage{
private:
    const string titolo;
    const string testo;
    vector<Webpage*> links;

public:
    Webpage(string t, string txt);
    string getTitolo() const;
    string getTesto() const;
    Webpage* getLink(int i);
    const vector<Webpage*>& getLinks() const;
    void addLink(Webpage* page);

    // ERRORE ERA QUI: deve essere (const Webpage& other) const
    bool operator==(const Webpage& other) const;
};

#endif
