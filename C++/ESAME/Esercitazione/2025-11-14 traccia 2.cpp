#include <iostream>
#include <string>

using namespace std;

class Strumento{
private:
    static int contatoreUnivoco;
    const int codice;
    string nome;
    string produttore;

protected:
    void setNome(string n){
        nome=n;
    }

    void setProduttore(string p){
        produttore=p;
    }

public:
    Strumento(): nome("null"), produttore("null"), codice(contatoreUnivoco){
        contatoreUnivoco++;
    }

    Strumento(string n, string p): nome(n), produttore(p), codice(contatoreUnivoco){
        contatoreUnivoco++;
    }

    int getCodice(){return codice;}
    string getNome(){return nome;}
    string getProduttore(){return produttore};
};

int Strumento::contatoreUnivoco = 0;

class Chitarra : public Strumento{
private:
    int numeroCorde;
public:
    Chitarra(): Strumento(), numeroCorde(0){}
    Chitarra(string n, string p, int c): Strumento(n,p), numeroCorde(c){}

    void mostraDettagli(){
        cout<<"Codice: "<<getCodice()<<endl<<"Nome: "<<getNome()<<endl<<"Produttore: "<<getProduttore()<<endl<<"Numero Corde: "<<numeroCorde<<endl;
    }
};

class Pianoforte : protected Strumento{
private:
    int numeroTasti;
public:
    Pianoforte(): Strumento(), numeroTasti(0){}
    Pianoforte(string n, string p, int t) : Strumento(n,p), numeroTasti(t){}

    void mostraDettagli(){
        cout<<"Codice: "<<getCodice()<<endl<<"Nome: "<<getNome()<<endl<<"Produttore: "<<getProduttore()<<endl<<"Numero Corde: "<<numeroTasti<<endl;
    }
};

class Batteria : private Strumento{
private:
    int numeroTamburi;
public:
    Batteria(): Strumento(), numeroTamburi(0){}
    Batteria(string n, string p, int t) : Strumento(n, p), numeroTamburi(t){}

    void mostraDettagli(){
        cout<<"Codice: "<<getCodice()<<endl<<"Nome: "<<getNome()<<endl<<"Produttore: "<<getProduttore()<<endl<<"Numero Corde: "<<numeroTamburi<<endl;
    }

};
int main(){

    Batteria batteria1("Martina", "Aloi", 4);
    batteria1.mostraDettagli();
    return 0;
}