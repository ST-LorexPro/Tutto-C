#include "Webpage.h"
#include <iostream>
#include <string>

using namespace std;

Webpage::Webpage(string t, string txt): titolo(t), testo(txt){}

string Webpage::getTitolo() const { return titolo; }
string Webpage::getTesto() const { return testo; }

Webpage* Webpage::getLink(int i){
    return links[i];
}

const vector<Webpage*>& Webpage::getLinks() const {
    return links;
}

void Webpage::addLink(Webpage* page){
    if (page != nullptr)
        links.push_back(page);
}

// FONDAMENTALE: const dentro E const fuori
bool Webpage::operator==(const Webpage& other) const {
    return this->titolo == other.titolo;
}
