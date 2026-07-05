#ifndef DATA_H 
#define DATA_H

#include <iostream>
using namespace std;

class Data{
private:
    int giorno;
    int mese;
    int anno;
public:
    Data(int g, int m, int a);
    Data();
    Data(const Data& oData);
    int getGiorno() const;
    void setGiorno(int giorno);
    int getMese() const;
    void setMese(int mese);
    int getAnno() const;
    void setAnno(int anno);
    Data& operator=(const Data& oData);
    bool operator<(const Data& data) const;
    friend ostream& operator<<(ostream& out, const Data& s);
    friend istream& operator>>(istream& out, Data& s);
    
};


#endif