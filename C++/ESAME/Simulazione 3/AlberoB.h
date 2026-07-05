#ifndef ALBEROB_H
#define ALBEROB_H

#include <assert.h>

enum Direzione {SIN=0, DES=1};

template<class T>
struct SNodo{
    T vinfo;
    SNodo *ppadre, *pfiglio[2];
    SNodo (const T& inf ): vinfo(inf)
    {   ppadre = pfiglio[SIN] = pfiglio[DES] = 0;
    }
    ~SNodo( ) {delete pfiglio[SIN]; delete pfiglio[DES];}

};

template <class T>
class AlberoB{
protected:
    SNodo<T>* pradice;
public:

    AlberoB () : pradice(0) {};
    AlberoB(const T& a){
        pradice = new SNodo<T>(a);
    };

    void insFiglio(Direzione d, AlberoB AC){
        assert (!nullo());
        assert(figlio(d).nullo());
        if(!AC.nullo()){
            pradice->pfiglio[d]=AC.pradice;
            AC.pradice->ppadre=pradice;
        }
    };

    AlberoB<T> estraiFiglio (Direzione d){
        assert(!nullo());
        AlberoB<T> A = figlio (d);
        A.pradice->ppadre=0;
        pradice->pfiglio[d] = 0;
        return A;
    };

    void modRadice (const T& a){
        assert(!nullo());
        pradice->vinfo = a;
    };

    void svuota(){delete pradice; pradice=0;};
    void annulla(){pradice = 0;}

    bool nullo() const{return pradice == 0;};

    AlberoB<T> copia() const{
        if (nullo()) return AlberoB<T>();
        AlberoB<T> AC(radice());
        AlberoB<T> fs = figlio(SIN).copia();
        AlberoB<T> fd = figlio(DES).copia();
        AC.insFiglio(SIN, fs);
        AC.insFiglio(DES, fd);
        return AC;
    };

    const T& radice() const{
        assert(!nullo());
        return pradice->vinfo;
    };

    bool foglia () const {
        return !nullo()&&figlio(SIN).nullo()&& figlio(DES).nullo();
    };

    AlberoB<T> figlio (Direzione d) const{
        assert (!nullo());
        AlberoB<T> AC;
        AC.pradice = pradice-> pfiglio[d];
        return AC;
    };

    AlberoB<T> padre () const{
        assert (!nullo());
        AlberoB<T> AC;
        AC.pradice = pradice->ppadre;
        return AC;
    };
};

#endif
