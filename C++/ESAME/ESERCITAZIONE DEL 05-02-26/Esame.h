#ifndef ESAME_H
#define ESAME_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Esame {
private:
    string nome;
    int CFU;
    vector<Esame*> sblocca;

public:
    Esame() = default;
    Esame(string n, int c) : nome(n), CFU(c) {}

    void addSblocco(Esame* s) {
        bool giaEsiste = false;
        for (size_t i = 0; i < sblocca.size(); i++) {
            // Meglio controllare se puntano allo stesso oggetto logico (*s)
            // oppure allo stesso indirizzo (s) a seconda di cosa vuoi.
            // Qui uso l'indirizzo per evitare cicli banali.
            if (sblocca[i] == s) {
                giaEsiste = true;
            }
        }
        if (!giaEsiste && s != this) { // Evito autolink
            sblocca.push_back(s);
        }
    }

    string getNome() const { return nome; }
    int getCFU() const { return CFU; }

    // CORREZIONE IMPORTANTE:
    // 1. Restituisce un const reference (efficienza)
    // 2. È marcato const alla fine (per poter essere chiamato su "const Esame*")
    const vector<Esame*>& getSblocca() const {
        return sblocca;
    }

    // Firma standard corretta: const Esame&
    bool operator==(const Esame& other) const {
        return nome == other.nome;
    }

    // Il distruttore vuoto non serve se non è virtuale, ma ok lasciarlo
    ~Esame() {};
};

#endif