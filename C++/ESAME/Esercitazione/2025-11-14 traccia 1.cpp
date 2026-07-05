#include <iostream>
#include <string>

using namespace std;

class Pubblicazione{
private:
    static int contatoreUnivoco; //Numero statico tiene traccia nel numero successivo disponibile
    const int codice; //variabile unica per ogni oggetto (Const perche non deve variare dopo essere stata creata)
    string titolo;
    string nomeAutore;

protected:
    void setTitoloBase(string t){
        titolo=t;
    }

    void setAutoreBase(string n){
        nomeAutore=n;
    }

public:
    Pubblicazione() : titolo("null"), nomeAutore("null"), codice(contatoreUnivoco){
        contatoreUnivoco++;
    }

    Pubblicazione(string t, string n) : titolo(t), nomeAutore(n), codice(contatoreUnivoco){
        contatoreUnivoco++;
    }

    int getCodice(){return codice;}
    string getTitolo(){return titolo;}
    string getAutore(){return nomeAutore;}
};

int Pubblicazione::contatoreUnivoco = 0;

class Libro : public Pubblicazione{
private:
    int pagine;

public:
    Libro() : Pubblicazione(), pagine(0){}
    Libro(string t, string n, int p) : Pubblicazione(t, n), pagine(p){}

    void setTitolo(string t){
        if (t!= "")
            setTitoloBase(t);
        else
            cout << "Errore: Il titolo non puo' essere vuoto." << endl;
        
    }

    void setAutore(string a){
        setAutoreBase(a);
    }
    
    void setPagine(int p){
        pagine=p;
    }
    
    void mostraDettagli(){
        cout<<getCodice()<<endl<<getTitolo()<<endl<<getAutore()<<endl<<pagine<<endl;
    }
};

class Rivista : protected Pubblicazione{
private: 
    int numeroEdizione;
public:
    Rivista() : Pubblicazione(), numeroEdizione(0){}
    Rivista(string t, string n, int e) : Pubblicazione(t, n), numeroEdizione(e){}

    void setEdizione(int e){
        numeroEdizione=e;
    }

    void setTitolo(string t){
        if (t!= "")
            setTitoloBase(t);
        else
            cout << "Errore: Il titolo non puo' essere vuoto." << endl;
        
    }

    void setAutore(string a){
        setAutoreBase(a);
    }

    void mostraDettagli(){
        cout<<getCodice()<<endl<<getTitolo()<<endl<<getAutore()<<endl<<numeroEdizione<<endl;
    }
};

class DocumentoRiservato : private Pubblicazione{
private: 
    int codiceAccesso;
public:
    DocumentoRiservato() : Pubblicazione(), codiceAccesso(1234){}
    DocumentoRiservato(string t, string n, int c) : Pubblicazione(t, n), codiceAccesso(c){}

    void setTitolo(string t, int codice){
        if (codice == codiceAccesso){
            setTitoloBase(t);
        }
        else
            cout<<"Accesso negato."<<endl;
    }

    void setAutore(string a, int codice){
        if (codice == codiceAccesso){
            setAutoreBase(a);
        }
        else
            cout<<"Accesso negato."<<endl;
    }

    void mostraDettagli(int c){
        if (c==codiceAccesso){
            cout<<"Codice Univoco: "<<getCodice()<<endl<<"Titolo :"<<getTitolo()<<endl<<"Autore: "<<getAutore()<<endl;
        }
        else
            cout<<"Accesso negato."<<endl;
    }

};


int main(){
    Libro libro1;

    libro1.setPagine(2);

    DocumentoRiservato documento1;

    documento1.setTitolo("Harry Potter", 1234);
    documento1.setAutore("Pippo", 1234);

    documento1.mostraDettagli(1234);

    return 0;
}