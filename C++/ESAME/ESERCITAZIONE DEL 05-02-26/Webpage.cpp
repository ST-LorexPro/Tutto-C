#include "Webpage.h"

Webpage::Webpage(): titolo("Null"), testo("Empty"){}

Webpage::Webpage(const string t,const string txt): titolo(t), testo(txt){}

string Webpage::getTitolo(){return titolo;}
string Webpage::getTesto(){return testo;}

const vector<Webpage*>& Webpage::getLink() const {return links;}

void Webpage::addLink(Webpage* l){
    links.push_back(l);
}

bool Webpage::operator==(const Webpage& other){
    return titolo==other.titolo;
}

Webpage::~Webpage(){}