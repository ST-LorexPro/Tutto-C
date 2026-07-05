/*
#include "Website.h"
#include <iostream>

using namespace std;

int main(){

    Webpage home("Home", "Benvenuto nella homepage");
    Webpage download("Download", "Che cosa vuoi scaricare?");
    Webpage prodotti("Prodotti", "Che cosa vuoi acquistare?");
    Webpage panino("PagliaccioDiUmile", "Sono anche gay");
    Webpage sediaGaming("Sedia Da Gaming", "Fa cacare la vendo per questo");
    Webpage hotdog("HotDog", "caldo caldo");
    Webpage hamburger("hamburger", "freddo");

    home.addLink(&download);
    home.addLink(&prodotti);

    prodotti.addLink(&panino);
    prodotti.addLink(&sediaGaming);

    panino.addLink(&hotdog);
    panino.addLink(&hamburger);

    download.addLink(&hotdog);


    Website umile(home);

    int res= umile.find_webpage(hotdog);

    cout<<res<<endl;

    return 0;



}
*/
/*
#include "SocialNetwork.h"
#include "Utente.h"

int main(){ 

    Utente u1("Umile");
    Utente u2("Lorenzo");
    Utente u3("Manuel");
    Utente u4("Christian");

    SocialNetwork Instagram;

    Instagram.registraUtente(&u1);
    Instagram.registraUtente(&u2);
    Instagram.registraUtente(&u3);
    Instagram.registraUtente(&u4);

    Instagram.stringiAmicizia(&u1, &u3);
    Instagram.stringiAmicizia(&u2, &u3);
    Instagram.stringiAmicizia(&u1, &u4);
    Instagram.stringiAmicizia(&u2, &u4);

    int res=Instagram.amiciInComune(&u1, &u2);

    cout<<res<<endl;

    return 0;
}

*/
/*

#include "Aereoporto.h"
#include "GestoreVoli.h"

int main(){
    Aereoporto brutto("GAY", "Umile");
    Aereoporto bello("LRZ", "Lorenzo");
    Aereoporto carino("ciao", "sono brutto");

    brutto.aggiungiDestinazione(&carino);

    bello.aggiungiDestinazione(&carino);

    carino.aggiungiDestinazione(&bello);
    carino.aggiungiDestinazione(&brutto);

    GestoreVoli TorreControlo;
    TorreControlo.addAereoporto(&bello);
    TorreControlo.addAereoporto(&brutto);
    TorreControlo.addAereoporto(&carino);

    bool res1=TorreControlo.esisteVoloConUnoScalo(&brutto, &bello);
    cout<<res1<<endl; //1

    bool res2=TorreControlo.esisteVoloConUnoScalo(&brutto, &carino);
    cout<<res2<<endl; //0

    return 0;
}
*/
/*
#include "Esame.h"
#include "PianoStudi.h"
//UMILE ROW
int main(){

    Esame f1("Fondamenti 1", 9);
    Esame f2("Fondamenti 2", 12);
    Esame bd("Basi Di Dati", 9);
    Esame ro("Ricerca Operativa", 9);
    Esame fi("Fisica", 6);
    Esame fi2("Fisica2", 12);

    Esame* p=&f1;

    f1.addSblocco(&f2);
    f1.addSblocco(&bd);
    f1.addSblocco(&ro);


    PianoStudi unical;

    unical.addEsame(&f1);
    unical.impostaPropedeuticita(&f1, &fi);
    unical.impostaPropedeuticita(&fi, &fi2);
    
    bool res=unical.propedeuticitaIndiretta(&f1, &fi2);


    return 0;
}
*/
/*
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "CodaDalParrucchiere.h"
#include "CodaDalParrucchiereAccurata.h"

using namespace std;

void testCodaStandard() {
    cout << "--- TEST CODA STANDARD ---" << endl;
    
    vector<string> parrucchieri = {"Mario", "Luigi"};
    CodaDalParrucchiere salone(parrucchieri);

    // 1. Aggiunta Prenotazioni
    cout << "Aggiungo clienti a Mario..." << endl;
    salone.aggiungiPrenotazione("Cliente1", "Mario");
    salone.aggiungiPrenotazione("Cliente2", "Mario");
    salone.aggiungiPrenotazione("Cliente3", "Mario");
    salone.aggiungiPrenotazione("Cliente4", "Mario"); // 4° in coda (3 prima di lui)

    // 2. Test Stima Attesa Standard (15 min * posizione)
    // Cliente 1 è posizione 0 -> 0 min
    // Cliente 2 è posizione 1 -> 15 min
    // Cliente 4 è posizione 3 -> 45 min
    cout << "Stima attesa Cliente1 (Mario): " << salone.stimaAttesa("Cliente1") << " min (Atteso: 0)" << endl;
    cout << "Stima attesa Cliente2 (Mario): " << salone.stimaAttesa("Cliente2") << " min (Atteso: 15)" << endl;
    cout << "Stima attesa Cliente4 (Mario): " << salone.stimaAttesa("Cliente4") << " min (Atteso: 45)" << endl;

    // 3. Test Cancellazione
    // Cliente 2: ha 1 persona davanti. È "imminente" (< 3 davanti). Non si può cancellare.
    bool cancellato2 = salone.cancellaPrenotazione("Cliente2");
    cout << "Cancellazione Cliente2 (Imminente): " << (cancellato2 ? "Riuscita" : "Fallita") << " (Atteso: Fallita)" << endl;

    // Cliente 4: ha 3 persone davanti. NON è imminente. Si può cancellare.
    bool cancellato4 = salone.cancellaPrenotazione("Cliente4");
    cout << "Cancellazione Cliente4 (Non Imminente): " << (cancellato4 ? "Riuscita" : "Fallita") << " (Atteso: Riuscita)" << endl;

    // Verifica che Cliente4 non ci sia più
    cout << "Cerca Cliente4 dopo cancellazione: " << salone.stimaAttesa("Cliente4") << " (Atteso: -1)" << endl;
    cout << endl;
}

void testCodaAccurata() {
    cout << "--- TEST CODA ACCURATA ---" << endl;

    // Mario è veloce (10 min), Luigi è lento (30 min)
    map<string, unsigned> staff = {
        {"Mario", 10},
        {"Luigi", 30}
    };

    CodaDalParrucchiereAccurata saloneVIP(staff);

    // Aggiungo clienti
    saloneVIP.aggiungiPrenotazione("Alice", "Mario"); // Pos 0
    saloneVIP.aggiungiPrenotazione("Bob", "Mario");   // Pos 1 -> 1 * 10 = 10 min

    saloneVIP.aggiungiPrenotazione("Charlie", "Luigi"); // Pos 0
    saloneVIP.aggiungiPrenotazione("Dave", "Luigi");    // Pos 1 -> 1 * 30 = 30 min

    // Test Stima Accurata
    cout << "Stima Bob (Mario, 10min/client): " << saloneVIP.stimaAttesa("Bob") << " min (Atteso: 10)" << endl;
    cout << "Stima Dave (Luigi, 30min/client): " << saloneVIP.stimaAttesa("Dave") << " min (Atteso: 30)" << endl;

    // Test Reindirizzamento (Riempio Mario fino all'orlo)
    // Mario ha già 2 clienti. Max è 10. Ne aggiungo 9 per saturarlo.
    for(int i=0; i<9; i++) {
        saloneVIP.aggiungiPrenotazione("Extra" + to_string(i), "Mario");
    }
    // Ora Mario ha 10 clienti.
    //LUIGI NE HA 3 non 2 perche EXTRA 8 è stata spostata da luigi
    
    saloneVIP.aggiungiPrenotazione("Zoe", "Mario");
    
    // Verifichiamo dove è finita Zoe controllando la stima attesa.
    // Se è da Mario (pieno), attesa > 100 min.
    // Se è da Luigi (aveva 3 clienti, Zoe è la 4^ in pos 3), attesa = 3 * 30 = 90 min.
    int attesaZoe = saloneVIP.stimaAttesa("Zoe");
    cout << "Attesa Zoe (Reindirizzata da Luigi?): " << attesaZoe << " min" << endl;
    
    if (attesaZoe == 90) cout << "-> Zoe correttamante spostata da Luigi!" << endl;
    else cout << "-> Qualcosa non va nel reindirizzamento." << endl;
}

int main() {
    testCodaStandard();
    testCodaAccurata();
    return 0;
}
*/
/*
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "CentroRiparazioni.h"
#include "CentroRiparazioniPro.h"

using namespace std;

void testCentroBase() {
    cout << "\n--- TEST CENTRO BASE ---" << endl;
    
    vector<string> banchi = {"BancoA", "BancoB"};
    CentroRiparazioni centro(banchi);

    // 1. Riempio il BancoA fino all'orlo (Capienza 5)
    cout << "Riempio BancoA con 5 dispositivi..." << endl;
    centro.accettaDispositivo("D1", "BancoA"); // Pos 0 (Sotto i ferri)
    centro.accettaDispositivo("D2", "BancoA"); // Pos 1 (Sotto i ferri)
    centro.accettaDispositivo("D3", "BancoA"); // Pos 2 (Ritirabile)
    centro.accettaDispositivo("D4", "BancoA"); // Pos 3
    centro.accettaDispositivo("D5", "BancoA"); // Pos 4 (Pieno!)

    // 2. Test Reindirizzamento (Load Balancing)
    // Provo a mettere D6 su BancoA (pieno). Dovrebbe finire su BancoB.
    cout << "Aggiungo D6 su BancoA (Pieno). Risultato: " 
         << (centro.accettaDispositivo("D6", "BancoA") ? "Accettato" : "Rifiutato") << endl;

    // Verifico dov'è finito D6 tramite la stima consegna
    // Se è su BancoB (che era vuoto), è in pos 0. Tempo = 0 * 45 = 0.
    int stimaD6 = centro.stimaConsegna("D6");
    cout << "Stima consegna D6 (dovrebbe essere su BancoB pos 0): " << stimaD6 << " min" << endl;

    // 3. Test Ritiro "Sotto i ferri" vs "In Coda"
    cout << "Tento ritiro D1 (Pos 0, sotto i ferri): " 
         << (centro.ritiraDispositivo("D1") ? "Riuscito" : "Fallito (Corretto)") << endl;
         
    cout << "Tento ritiro D3 (Pos 2, in coda): " 
         << (centro.ritiraDispositivo("D3") ? "Riuscito (Corretto)" : "Fallito") << endl;
         
    // Dopo aver ritirato D3, D4 dovrebbe scalare in posizione 2.
    // Stima D4 (nuova pos 2) -> 2 * 45 = 90 min.
    cout << "Nuova stima D4 dopo ritiro D3: " << centro.stimaConsegna("D4") << " min (Atteso: 90)" << endl;
}

void testCentroPro() {
    cout << "\n--- TEST CENTRO PRO (Efficienza Variabile) ---" << endl;

    // BancoFerrari è veloce (20 min), BancoPanda è lento (100 min)
    map<string, unsigned> efficienza = {
        {"BancoFerrari", 20},
        {"BancoPanda", 100}
    };

    CentroRiparazioniPro centroPro(efficienza);

    // Aggiungo dispositivi
    centroPro.accettaDispositivo("Ferrari1", "BancoFerrari"); // Pos 0
    centroPro.accettaDispositivo("Ferrari2", "BancoFerrari"); // Pos 1
    centroPro.accettaDispositivo("Ferrari3", "BancoFerrari"); // Pos 2

    centroPro.accettaDispositivo("Panda1", "BancoPanda");     // Pos 0
    centroPro.accettaDispositivo("Panda2", "BancoPanda");     // Pos 1
    centroPro.accettaDispositivo("Panda3", "BancoPanda");     // Pos 2

    // 4. Test Stima Personalizzata
    // Ferrari3 è in pos 2. Tempo = 2 * 20 = 40 min.
    // Panda3 è in pos 2.   Tempo = 2 * 100 = 200 min.
    
    cout << "Stima Ferrari3 (Pos 2, Veloce): " << centroPro.stimaConsegna("Ferrari3") << " min (Atteso: 40)" << endl;
    cout << "Stima Panda3   (Pos 2, Lento):  " << centroPro.stimaConsegna("Panda3") << " min (Atteso: 200)" << endl;
}

int main() {
    testCentroBase();
    testCentroPro();
    return 0;
}
*/
/*
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "Job.h"
#include "DataCenter.h"   // Include anche Job.h
#include "DataCenterEco.h" // Include DataCenter.h

using namespace std;

// Funzione helper per stampare i risultati dei test in modo pulito
void assertTest(bool condition, string testName) {
    if (condition) {
        cout << "[OK] " << testName << endl;
    } else {
        cout << "[FAIL] " << testName << endl;
    }
}

int main() {
    cout << "=== TEST DATA CENTER ECO ===" << endl;

    // 1. Configurazione Efficienza Server
    // Server_Eco è efficiente (consumo x1.0)
    // Server_Old è vecchio e consuma il doppio (consumo x2.0)
    map<string, double> efficienza = {
        {"Server_Eco", 1.0},
        {"Server_Old", 2.0}
    };

    // Istanzio il Data Center Eco
    DataCenterEco cloud(efficienza);

    // Creazione Job
    // Nota: Tolto const dalla struct Job come suggerito, quindi posso inizializzare così:
    Job j1 = {"WebApp", 40};      // 40 GB
    Job j2 = {"Database", 50};    // 50 GB
    Job j3 = {"BigData", 30};     // 30 GB (Farà traboccare il server)
    Job zombie1 = {"Script1", 1}; // 1 GB (Da eliminare)
    Job zombie2 = {"Script2", 1}; // 1 GB (Da eliminare)

    // --- TEST 1: DEPLOY STANDARD ---
    cout << "\n--- Fase 1: Deploy Standard ---" << endl;
    
    // Riempio Server_Eco con 40 + 50 = 90 GB (Max 100)
    bool res1 = cloud.deployJob("Server_Eco", j1);
    assertTest(res1, "Deploy J1 (40GB) su Server_Eco");

    bool res2 = cloud.deployJob("Server_Eco", j2);
    assertTest(res2, "Deploy J2 (50GB) su Server_Eco");

    // Verifico consumo attuale: 90GB * 1.0 = 90.0
    double consumoEco = cloud.calcolaConsumo("Server_Eco");
    cout << "Consumo attuale Server_Eco: " << consumoEco << " (Atteso: 90.0)" << endl;


    // --- TEST 2: LOAD BALANCING (REINDIRIZZAMENTO) ---
    cout << "\n--- Fase 2: Load Balancing ---" << endl;

    // Provo a mettere J3 (30GB) su Server_Eco.
    // 90 + 30 = 120 > 100. DEVE FALLIRE su Eco e andare su Old (che è vuoto).
    bool res3 = cloud.deployJob("Server_Eco", j3);
    assertTest(res3, "Deploy J3 (30GB) su Server_Eco (Pieno -> Reindirizzato)");

    // Verifica: J3 dovrebbe essere finito su Server_Old.
    // Consumo Old = 30GB * 2.0 (efficienza) = 60.0
    double consumoOld = cloud.calcolaConsumo("Server_Old");
    cout << "Consumo Server_Old (dopo reindirizzamento): " << consumoOld << " (Atteso: 60.0)" << endl;

    if (consumoOld == 60.0) cout << "[OK] Load Balancing riuscito!" << endl;
    else cout << "[FAIL] Load Balancing fallito." << endl;


    // --- TEST 3: GESTIONE ZOMBIE E LIBERAZIONE RAM ---
    cout << "\n--- Fase 3: Zombie Process ---" << endl;

    // Aggiungo zombie a Server_Eco (era a 90, va a 92)
    cloud.deployJob("Server_Eco", zombie1);
    cloud.deployJob("Server_Eco", zombie2);
    
    double consumoPreKill = cloud.calcolaConsumo("Server_Eco");
    cout << "Consumo Server_Eco con Zombie: " << consumoPreKill << " (Atteso: 92.0)" << endl;

    // Uccido i processi zombie (< 2GB)
    cout << "Eseguo killZombieProcess()..." << endl;
    double uccisi = cloud.killZombieProcess();
    
    cout << "Processi uccisi: " << uccisi << " (Atteso: 2)" << endl;

    // Verifica Consumo Post-Kill
    // Dovrebbe essere tornato a 90.0 (92 - 1 - 1)
    double consumoPostKill = cloud.calcolaConsumo("Server_Eco");
    cout << "Consumo Server_Eco pulito: " << consumoPostKill << " (Atteso: 90.0)" << endl;

    assertTest(consumoPostKill == 90.0, "Verifica liberazione RAM corretta");

    return 0;
}
*/
/*
#include "Magazzino.h"
#include "MagazzinoAlimentare.h"

using namespace std;

int main(){
	vector<string> codici={"Computer","Lampada","Scrivania","Sedia"};
	
	Magazzino euronics(codici);
	
	euronics.rifornisci("Computer", 5, 1400);
	euronics.rifornisci("Lampada", 20, 25);
	euronics.rifornisci("Scivania", 30, 110);
	euronics.rifornisci("Sedia", 7, 80);
	
	
	//Expected: Cout Venduto.
	if(euronics.vendi("Computer", 1) == true){
		cout<<"Venduto"<<endl;
	}
	else{
		cout<<"Non Venduto"<<endl;
	}
	
	//Expecte: Cout Non Venduto.
	if(euronics.vendi("Sedia", 10)==true){
		cout<<"Venduto"<<endl;
	}
	else{
		cout<<"Non Venduto"<<endl;
	}
	
	cout<<euronics.valoreTotale()<<endl;
	
	map<string, int> scad;
	scad["Banana"]=20;
	scad["Pasta"]=90;
	scad["Yougurt"]=5;
	scad["Latte"]=-1;
	
	MagazzinoAlimentare putifa(scad);
	putifa.rifornisci("Banana", 8, 1.5);
	putifa.rifornisci("Pasta", 40, 3);
	putifa.rifornisci("Yougurt", 10, 0.9);
	putifa.rifornisci("Latte", 45, 1);
	
	if(putifa.vendi("Latte", 2) == true){
		cout<<"Venduto"<<endl;
	}
	else{
		cout<<"Non Venduto"<<endl;
	}
	
	if(putifa.vendi("Banana", 8) == true){
		cout<<"Venduto"<<endl;
	}
	else{
		cout<<"Non Venduto"<<endl;
	}
	
	cout<<putifa.valoreTotale()<<endl;
	
	cout<<"Prodotti scaduti rimossi "<<putifa.rimuoviScaduti()<<endl;
	
	
	return 0;
}
*/
/*
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> // FONDAMENTALE per usare reverse()

using namespace std;

// --- CLASSE GRAFO (Simulata per far funzionare il test) ---
class Grafo {
    int V;
    vector<vector<int>> adj;
public:
    Grafo(int V) : V(V) { adj.resize(V); }
    
    // Funzione per capire quanti nodi ci sono
    int n() const { return V; }
    
    // Aggiunge un arco
    void aggiungiArco(int u, int v) { adj[u].push_back(v); }
    
    // Operatore () per controllare se esiste arco tra u e v (come nel tuo codice)
    bool operator()(int u, int v) const {
        for(int vicino : adj[u]) {
            if(vicino == v) return true;
        }
        return false;
    }
};

	vector<unsigned> camminoBreve (Grafo g, unsigned start, unsigned end){
		int nodi=g.n();
		
		queue<unsigned> daVisitare;
		daVisitare.push(start);		
		bool trovato=false;		
		vector<int> genitori(nodi, -1);		
		vector<bool> visitato(nodi, false);
		visitato[start]= true;
		
		while(!daVisitare.empty()){
			int u=daVisitare.front();
			daVisitare.pop();
			
			if(u==end){
					trovato=true;
					break;
			}
			
			for(int i=0; i<nodi; ++i){
				if(g(u,i) && visitato[i]==false){
					visitato[i]=true;
					daVisitare.push(i);
					genitori[i]=u;
				}
			}					
		}
		
		if(!trovato){return {};}
			
			vector<unsigned> percorso;
			for(int i=end; i!=-1; i=genitori[i]){
				percorso.push_back((unsigned)i);
			}
			reverse(percorso.begin(), percorso.end());
			return percorso;
	}
	
	vector<unsigned> trovaPercorsoPassandoPerV(Grafo g, unsigned c, unsigned v, unsigned b){
		vector<unsigned> percorso1 = camminoBreve(g,c,v);
		if(percorso1.empty()){return {};}
		
		vector<unsigned> percorso2 = camminoBreve(g,v,b);
		if(percorso2.empty()){return {};}
		
		percorso1.insert(percorso1.end(), percorso2.begin() + 1, percorso2.end());
		return percorso1;
	}

int main(){
	Grafo g(6);
    
    g.aggiungiArco(0, 1);
    g.aggiungiArco(1, 2); // Arriva a V (2)
    g.aggiungiArco(2, 3); // Riparte da V
    g.aggiungiArco(3, 4); // Arriva a B (4)
    g.aggiungiArco(0, 5); // Distrazione
    g.aggiungiArco(5, 4); // Scorciatoia (ma non passa per 2!)

    cout << "Cerco percorso 0 -> 4 passando per 2..." << endl;
    vector<unsigned> ris = trovaPercorsoPassandoPerV(g, 0, 2, 4);

    if(ris.empty()){
        cout << "Nessun percorso trovato!" << endl;
    } else {
        cout << "Percorso trovato: ";
        for(unsigned nodo : ris){
            cout << nodo << " ";
        }
        cout << endl;
    }

    return 0;
}

*/
/*
#include "VettorePazzo.h"

using namespace std;

int main(){
    VettorePazzo vector;

    vector.push_back(3);
    vector.push_back(1);
    vector.push_back(10);


    return 0;
}
*/
/*

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Grafo {
private:
    int numNodi;
    int numArchi;
    // Usiamo una matrice bool: adj[i][j] == true se c'è arco i->j
    vector<vector<bool>> adj;

public:
    // Costruttore
    Grafo(int n) {
        numNodi = n;
        numArchi = 0;
        // Inizializza la matrice NxN tutta a false
        adj.resize(n, vector<bool>(n, false));
    }

    // Metodo g.n() come da specifiche
    int n() const {
        return numNodi;
    }

    // Metodo g.m() come da specifiche
    int m() const {
        return numArchi;
    }

    // Metodo g(i,j) come da specifiche: ritorna true se esiste arco i->j
    bool operator()(int i, int j) const {
        // Controllo limiti per sicurezza (opzionale ma consigliato)
        if (i < 0 || i >= numNodi || j < 0 || j >= numNodi) return false;
        return adj[i][j];
    }

    // Metodo per popolare il grafo (necessario per il test)
    void aggiungiArco(int u, int v) {
        if (u >= 0 && u < numNodi && v >= 0 && v < numNodi) {
            if (!adj[u][v]) { // Se l'arco non c'era già
                adj[u][v] = true;
                numArchi++;
            }
        }
    }
};

vector<pair<unsigned, unsigned>> coppie(Grafo g){
    unsigned nodi= g.n();
    vector<pair<unsigned, unsigned>> result;
    for(int i=0; i<nodi; i++){
        for (int j=i+1; j<nodi; j++){
            bool sonoUguali=true;

            for(int k=0; k<nodi; ++k){
                if(g(i, k) != g(j, k)){
                    sonoUguali=false;
                }
                if(g(k, i)!=g(k, j)){
                    sonoUguali=false;
                }
            }
            if(sonoUguali){
                result.push_back({i, j});
            }
        }
    }
    return result;
}


int main(){
    Grafo g(4); // 4 nodi: 0, 1, 2, 3

    // Costruiamo gli archi
    g.aggiungiArco(0, 1); // Archi entranti in 1 e 2 (da 0)
    g.aggiungiArco(0, 2);

    g.aggiungiArco(1, 3); // Archi uscenti da 1 e 2 (verso 3)
    g.aggiungiArco(2, 3);

    vector<pair<unsigned, unsigned>> uguali = coppie(g);

    for(int i=0; i<uguali.size();i++){
        cout<<"Questo nodo: "<<uguali[i].first<<" e questo: "<<uguali[i].second<<" sono sovrapponibili."<<endl;
    }

    return 0;
}
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Dormitorio{
    vector<string> studenti;
    vector<pair<string, string>> inc;
    vector<pair<unsigned, vector<string>>> stanze;

};

bool esercizio4(Dormitorio d){
    unsigned numeroStudenti = d.studenti.size();
    unordered_map<unsigned, int> capienza;
    int totaleAssegnati=0;
    vector<string> sutdentiConSistemazione;
    for(int i=0; i<d.stanze.size(); i++){
        unsigned idAttuale=d.stanze[i].first;
        capienza[idAttuale]=(idAttuale/6)+1;
    }
    bool ciclo= true;
    do{
        for(int v=0; v<numeroStudenti; v++){
            for(int c=0; c<d.stanze.size(); c++)
                if(d.stanze[c].second.size()==0){  
                    d.stanze[c].second.push_back(d.studenti[v]);
                    
                    break;
                }
            }
        ciclo=false;
    }while(ciclo);

    for(int i=0; i< numeroStudenti; i++){
        string studenteAttuale=d.studenti[i];
        vector<string> blacklist;
        for(int j=0; j<d.inc.size(); j++){
            for(int k=0; k<numeroStudenti; k++){
                string secondoStudente= d.studenti[k];
                if(d.inc[j].first == studenteAttuale){
                    if(d.inc[j].second == secondoStudente){
                        blacklist.push_back(secondoStudente);
                    }
                }
                if(d.inc[j].second == studenteAttuale){
                    if(d.inc[j].first == secondoStudente){
                        blacklist.push_back(secondoStudente);
                    }
                }
            }
        }

        for(int c=0; c<d.stanze.size(); c++){
            unsigned id=d.stanze[c].first;
            vector<string> assegnati= d.stanze[c].second;
            if(d.stanze[c].second.size() < capienza[id]){
            for(int v=0; v<blacklist.size(); v++){
                for(int b=0; b < assegnati.size(); b++){
                    if(blacklist[v] == assegnati[b]){
                        cout<<"non compatibile con:"<<assegnati[b]<<endl;
                        break;
                    }
                    auto it=find(assegnati.begin(), assegnati.end(), d.studenti[i]);
                    if(it==assegnati.end()){
                        totaleAssegnati++;
                        d.stanze[c].second.push_back(studenteAttuale);
                        cout<<"assegnato"<<endl;
                    }
                }
            }
        }
        }
    }
    if(totaleAssegnati==numeroStudenti){
        return true;
    }
    else{return false;}
}


int main(){

    // Dormitorio unical;
    // unical.studenti={"lorenzo", "martina", "umile", "marco", "manuel"};
    
    // unical.inc[0].second="lorenzo";
    // unical.inc[0].first="marco";
    // unical.inc[1].first="martina";
    // unical.inc[1].second="marco";
    // unical.inc[2].first="martina";
    // unical.inc[2].second="umile";
    // unical.inc[3].first="martina";
    // unical.inc[3].second="manuel";

    int* matricola= new int[6] {2,6,6,1,3,8};
    int* p = matricola + 4;

    p[-2]=99;
    cout<<matricola[2]<<endl;


    return 0;

}