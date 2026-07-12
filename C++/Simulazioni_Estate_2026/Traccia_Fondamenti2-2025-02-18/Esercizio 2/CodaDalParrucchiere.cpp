#include <iostream>
#include <list>
#include <map>
#include <unordered_map>
#include <vector>
#include <climits>

using namespace std;

class CodaDalParrucchiere{
protected:
    unordered_map<string, list<string>> prenotazioni;
public:
    CodaDalParrucchiere(){}

    CodaDalParrucchiere(const vector<string>& parrucchieri){
        if(parrucchieri.empty()){
            cout<<"Lista vuota"<<endl;
            return;
        }
        for (string p : parrucchieri){
            if(prenotazioni.find(p) != prenotazioni.end()){
                cout<<"Parrucchiere gia presente"<<endl;
                continue;
            }
            else{
                prenotazioni[p] = {};
            }
        }
    }

    bool aggiungiPrenotazione(const string& cliente, const string& parrucchiere){
        if(prenotazioni.find(parrucchiere) != prenotazioni.end()){
            if(prenotazioni[parrucchiere].size() <= 10){
                prenotazioni[parrucchiere].push_back(cliente);
                return true;
            }
            else{
                size_t minimoCoda = 11;
                string parrucchiereAttuale = "nessuno";
                for(const auto& coppia : prenotazioni){
                    if (coppia.second.size() < minimoCoda){
                        parrucchiereAttuale = coppia.first;
                    }
                }
                if(parrucchiereAttuale != "nessuno"){
                    prenotazioni[parrucchiereAttuale].push_back(cliente);
                    cout<<parrucchiere<<" non ha posti disponibili. "<<cliente << " Messo in coda per: "<<parrucchiereAttuale<<endl;
                    return true;
                }
            }
            return false;
        }
        return false;
    }

    bool cancellaPrenotazione(const string& cliente){
        string parrucchiere;
        int personePrima = 0;
        bool trovato = false;
        for(const auto& coppia : prenotazioni){
            int counter = 0;
            for (const string& c : coppia.second){
                if(c == cliente){
                    parrucchiere = coppia.first;
                    personePrima = counter;
                    trovato = true;
                    break;
                }
                    counter++;
            }
            if(trovato){
                break;
            }
        }
        if(personePrima >= 3){
            prenotazioni[parrucchiere].remove(cliente);
            return true;
        }
        return false;
    }

    virtual int stima(const string& cliente){
        int stima = 0;
        int personePrima = 0;
        bool trovato = false;
        for(const auto& coppia : prenotazioni){
            int counter = 0;
            for(const string& c : coppia.second){
                if(c==cliente){
                    personePrima = counter;
                    trovato = true;
                    break;
                }
                counter++;
            }
            if(trovato){
                break;
            }
        }
        if(trovato){
            if(personePrima == 0){
                cout<<"Non ci sono persone davanti "<<cliente<<endl;
                return 0;
            }
            stima = personePrima * 15;
            return stima;
        }
        else{
            cout<<"Cliente non presente"<<endl;
            return -1;
        }
    }

    virtual ~CodaDalParrucchiere(){}
};


class CodaDalParrucchiereAccurata : public CodaDalParrucchiere {
private:
    map<string, unsigned> tempoMedio;
public:
    CodaDalParrucchiereAccurata(): CodaDalParrucchiere(){}
    CodaDalParrucchiereAccurata(const vector<string>& parrucchieri, map<string, unsigned> tempoMedio): CodaDalParrucchiere(parrucchieri), tempoMedio(tempoMedio){}

    int stima(const string& cliente)override{
        int stima = 0;
        int personePrima = 0;
        unsigned tempoMedioAttuale = 0;
        bool trovato = false;
        for(const auto& coppia : prenotazioni){
            int counter = 0;
            for(const string& c : coppia.second){
                if(c==cliente){
                    personePrima = counter;
                    trovato = true;
                    break;
                }
                counter++;
            }
            if(trovato){
                tempoMedioAttuale = tempoMedio[coppia.first];
                break;
            }
        }
        if(trovato){
            if(personePrima == 0){
                cout<<"Non ci sono persone davanti "<<cliente<<endl;
                return 0;
            }
            stima = personePrima * tempoMedioAttuale;
            return stima;
        }
        else{
            cout<<"Cliente non presente"<<endl;
            return -1;
        }
    }

};


int main(){

    map<string, unsigned> tempo;
    tempo["Lorenzo"] = 23;
    tempo["Peppe"] = 10;
    tempo["Christian"] = 9;
    tempo["Mattia"] = 6;

    CodaDalParrucchiereAccurata prova({"Lorenzo", "Peppe", "Christian", "Mattia"}, tempo);

    if(prova.aggiungiPrenotazione("Martina", "Lorenzo")){
        cout<<"Riuscito"<<endl;
    }
    if(prova.aggiungiPrenotazione("Loll", "Lorenzo")){
        cout<<"Riuscito"<<endl;
    }
    if(prova.aggiungiPrenotazione("Marco", "Lorenzo")){
        cout<<"Riuscito"<<endl;
    }
    if(prova.aggiungiPrenotazione("Maratea", "Lorenzo")){
        cout<<"Riuscito"<<endl;
    }
    if(prova.aggiungiPrenotazione("Dodaro", "Lorenzo")){
        cout<<"Riuscito"<<endl;
    }
    if(prova.aggiungiPrenotazione("Nino", "Lorenzo")){
        cout<<"Riuscito"<<endl;
    }
    if(prova.aggiungiPrenotazione("Vita", "Lorenzo")){
        cout<<"Riuscito"<<endl;
    }
    if(prova.aggiungiPrenotazione("Laura", "Lorenzo")){
        cout<<"Riuscito"<<endl;
    }
    if(prova.aggiungiPrenotazione("Lilia", "Lorenzo")){
        cout<<"Riuscito"<<endl;
    }
    if(prova.aggiungiPrenotazione("Paolo", "Lorenzo")){
        cout<<"Riuscito"<<endl;
    }
    if(prova.aggiungiPrenotazione("Cecilia", "Lorenzo")){
        cout<<"Riuscito"<<endl;
    }
    if(prova.aggiungiPrenotazione("Giovanni", "Lorenzo")){
        cout<<"Riuscito"<<endl;
    }
     if(prova.aggiungiPrenotazione("Manuel", "Lorenzo")){
        cout<<"Riuscito"<<endl;
    }
    for (int i = 0 ; i<9;i++){
        prova.aggiungiPrenotazione("Manuel", "Peppe");
    }

    for (int i = 0 ; i<6;i++){
        prova.aggiungiPrenotazione("Manuel", "Mattia");
    }


    if(prova.aggiungiPrenotazione("Giuseppe", "Lorenzo")){
        cout<<"Riuscito!!"<<endl;
    }

    if(prova.cancellaPrenotazione("Marco")){
        cout<<"Rimosso"<<endl;
    }
    else{
        cout<<"Non rimosso"<<endl;
    }

    cout<<prova.stima("Giovanni")<<endl;
    
    return 0;
}