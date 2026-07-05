// #include <vector>
// #include <queue>
// #include <vector>

// using namespace std;

// int contaPersoneRaggiungibili(int numNodi, const vector<vector<int>>& adj, int start, int K) {
//     if (K < 0) return 0;

//     // 1. Strutture dati: Coda e Vettore Distanze
//     // Inizializza le distanze a -1 (o infinito)
//     vector<int> dist(numNodi, -1);
//     queue<int> q;

//     // 2. Setup iniziale
//     // ... SCRIVI QUI (Metti start in coda e setta la sua distanza a 0) ...
//     dist[start]=0;
//     q.push(start);

    
//     int contatore = 0;

//     // 3. Ciclo BFS
//     while (!q.empty()) {
//         int u = q.front();
//         q.pop();

//         // Se la distanza di u è esattamente K, non esplorare i suoi vicini
//         // (perché i vicini avrebbero distanza K+1, che è troppo)
//         if (dist[u] >= K) continue;

//         // Esplora i vicini
//         for (int v : adj[u]) {
//             if(dist[v]==-1){
//                 q.push(v);
//                 dist[v]=dist[u]+1;
//                 contatore++;
//             }
//             // ... SCRIVI QUI (Se v non è visitato: aggiorna distanza, metti in coda, aumenta contatore) ...
//         }
//     }

//     return contatore;
// }


#include <vector>
#include <queue>
using namespace std;

// vector<int> bfs_ordine_visita(int nodi, const vector<vector<int>>& adj, int start) {
//     vector<int> ordine;             // Qui salviamo il risultato
//     vector<bool> visitato(nodi, false);
//     queue<int> q;

//     // 1. SETUP
//     // ... (Metti start nella coda e segnalo come visitato) ...
//     q.push(start);
//     visitato[start]=true;

//     while (!q.empty()) {
//         // 2. ESTRAZIONE
//         int u = q.front();
//         q.pop();
//         ordine.push_back(u); // Lo aggiungiamo alla lista dei visitati

//         // 3. ESPLORAZIONE VICINI
//         for (int v : adj[u]) {
//             if(visitato[v]== false){
//                 q.push(v);
//                 visitato[v]=true;
//             }
//             // ... (Se v non è visitato: segnalo visitato e mettilo in coda) ...
//         }
//     }
//     return ordine;
// }



/*Esercizio 1: Distanza Minima nel Grafo (Classico)
Problema:
Hai un grafo orientato. Devi calcolare quanti "salti" (archi) servono per andare dal nodo start al nodo end.

Se start e end sono uguali, la distanza è 0.

Se non esiste un percorso tra i due, restituisci -1.
*/



int calcolaDistanza(int numNodi, const vector<vector<int>>& adj, int start, int end) {
    // SCRIVI QUI IL TUO CODICE DA ZERO
}


