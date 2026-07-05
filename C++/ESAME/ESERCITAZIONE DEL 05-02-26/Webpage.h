#ifndef WEBPAGE_H
#define WEBPAGE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Webpage{
private:
    string titolo;
    string testo;
    vector<Webpage *> links;


public:
    Webpage();
    Webpage(const string t, const string txt);

    string getTitolo();
    string getTesto();
    const vector<Webpage*>& getLink() const;

    void addLink(Webpage* l);

    bool operator==(const Webpage& other);

    ~Webpage();

};


#endif