#include "Data.h"
#include <iostream>
#include <cassert>

using namespace std;


Data::Data(int g, int m, int a): giorno(g), mese(m), anno(a){}

Data::Data(): giorno(0), mese(0), anno(0){}

int Data::getGiorno()const{
    return giorno;
}

void Data::setGiorno(int giorno){
    this->giorno=giorno;
}

int Data::getMese()const {
    return mese;
}
void Data::setMese(int mese){
    this->mese=mese;
}

int Data::getAnno()const{
    return anno;
}

void Data::setAnno(int anno){
    this->anno=anno;
}

Data& Data::operator=(const Data& oData){
    if(this == &oData)
        return *this;
    setGiorno(oData.giorno);
    setMese(oData.mese);
    setAnno(oData.anno);
    return *this;
}
bool Data::operator<(const Data& data) const{
    if (this->anno < data.anno) return true;
    if (this->anno == data.anno){
        if (this->mese < data.mese){
            return true;
        } else if (this->mese == data.mese && this-> giorno < data.giorno) return true;
    }
    return false;
}
ostream& operator<<(ostream& out, const Data& s){
    out << s.giorno << "/" << s.mese << "/" << s.giorno << endl;
    return out;
}
istream& operator>>(istream& in, Data& s){
    cout<<"Inserisci il giorno"<<endl;
    in >> s.giorno;
    cout<<"Inserisci il mese"<<endl;
    in >> s.mese;
    cout<<"Inserisci l'anno"<<endl;
    in >> s.anno;
    return in;
}


