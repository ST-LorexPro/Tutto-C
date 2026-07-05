#include "Veicolo.h"
#include "Auto.h"
#include "Furgone.h"
#include "GestoreNoleggio.h"

int main(){
    
    
    Auto clio("FJ424BM", "Renault",150, 5);
    Furgone doblo("HS345MN", "Fiat", 500.0, 200);
    doblo.stampaDettagli();

    Auto panda("BD198YT", "Fiat", 75, 4);
    panda.stampaDettagli();

    GestoreNoleggio Siderno;

    Siderno.aggiungi(&clio);
    Siderno.aggiungi(&doblo);
    Siderno.aggiungi(&panda);

    //Siderno.stampaDettagli();

    Veicolo* trovato = Siderno.cerca("HS345MN");
    if (trovato)
        cout << "\nTrovato: " << trovato->getMarca() << "\n";

    Siderno.rimuovi("HS345MN");


    Siderno.stampaDettagli();


}