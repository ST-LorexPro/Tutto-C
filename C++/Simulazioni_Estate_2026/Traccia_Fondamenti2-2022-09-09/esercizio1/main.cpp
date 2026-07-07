// Data la seguente porzione di programma, rispondere alle domande corrispondenti:

int* matricola = new int[6] {2,6,6,1,3,8};


//1. La seguente istruzione è corretta? Se sì, cosa stampa?
cout << *(&matricola[4]);
//stampa 3


//2. La seguente istruzione è corretta? Se sì, cosa stampa?
cout << *(matricola + 3);

//stampa 1



//3. Cosa stampa la seguente porzione di codice?
int& second = matricola[1]; //reference a 6
matricola[1]++; //6 diventa 7
 second ++; //7 diventa 8
 cout << second; // stampa 8




//4. Come andrebbe deallocata la memoria dinamica allocata inizialmente?
A: delete matricola[6];
B: delete[] matricola; //questa è la opzione adeguata
C: delete matricola;
D: Nel main non va deallocata alcuna memoria dinamica.
