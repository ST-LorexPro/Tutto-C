#include <bits/stdc++.h>
using namespace std;

// Controlla se un carattere è un operatore
bool isOp(char c) {
    return c=='+' || c=='-' || c=='*' || c=='/' || c=='^';
}

// Priorità operatori
int prec(char op) {
    switch(op) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': return 3;
    }
    return 0;
}

// Applicazione operatore su due operandi
double applyOp(double a, double b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0.0) throw runtime_error("Divisione per zero");
            return a / b;
        case '^': return pow(a,b);
    }
    throw runtime_error("Operatore sconosciuto");
}

// Converte l'espressione infissa in notazione RPN (Reverse Polish Notation)
// e poi valuta la RPN restituendo il risultato.
double evalExpression(const string &expr) {
    // Tokenizzazione minima: numeri (incluso .), operatori, parentesi
    vector<string> outputQueue;
    stack<char> opStack;
    size_t i = 0;
    bool expectUnary = true; // se true, un + o - è considerato unario

    while (i < expr.size()) {
        char c = expr[i];

        if (isspace((unsigned char)c)) { i++; continue; }

        // Numero (supporta decimali)
        if (isdigit((unsigned char)c) || (c=='.')) {
            string num;
            while (i < expr.size() && (isdigit((unsigned char)expr[i]) || expr[i]=='.')) {
                num.push_back(expr[i++]);
            }
            outputQueue.push_back(num);
            expectUnary = false;
            continue;
        }

        // Gestione del meno/unario e più unario
        if ((c=='+' || c=='-') && expectUnary) {
            // Trattiamo come parte del numero successivo: leggiamo segno e numero
            string num;
            num.push_back(c);
            i++;
            // attendiamo numero dopo il segno
            bool foundDigit = false;
            while (i < expr.size() && isspace((unsigned char)expr[i])) i++;
            // accetta parentesi dopo il segno? se c'è '(' lo consideriamo come -1*(...)
            if (i < expr.size() && expr[i] == '(') {
                // inseriamo -1 e * e continuiamo (es: -(...))
                outputQueue.push_back(string(1, (c=='-')?'-':'+' ) + string("1")); // "-1" or "+1"
                // push '*' operator handling via op stack:
                while (!opStack.empty() && ((prec(opStack.top()) > prec('*')) || (prec(opStack.top()) == prec('*') && opStack.top() != '^'))) {
                    outputQueue.push_back(string(1, opStack.top()));
                    opStack.pop();
                }
                opStack.push('*');
                expectUnary = true;
                continue;
            }
            // altrimenti leggiamo numero (potrebbe non esserci -> errore)
            while (i < expr.size() && (isdigit((unsigned char)expr[i]) || expr[i]=='.')) {
                num.push_back(expr[i++]);
                foundDigit = true;
            }
            if (!foundDigit) throw runtime_error("Formato numero non valido dopo segno unario");
            outputQueue.push_back(num);
            expectUnary = false;
            continue;
        }

        if (isOp(c)) {
            // operatore binario normale
            while (!opStack.empty() && isOp(opStack.top())) {
                char top = opStack.top();
                // '^' è right-associative
                if ((prec(top) > prec(c)) || (prec(top) == prec(c) && c != '^')) {
                    outputQueue.push_back(string(1, top));
                    opStack.pop();
                } else break;
            }
            opStack.push(c);
            i++;
            expectUnary = true;
            continue;
        }

        if (c == '(') {
            opStack.push(c);
            i++;
            expectUnary = true;
            continue;
        }

        if (c == ')') {
            bool found = false;
            while (!opStack.empty()) {
                char top = opStack.top(); opStack.pop();
                if (top == '(') { found = true; break; }
                outputQueue.push_back(string(1, top));
            }
            if (!found) throw runtime_error("Parentesi non bilanciate");
            i++;
            expectUnary = false;
            continue;
        }

        // carattere non riconosciuto
        throw runtime_error(string("Carattere non valido: ") + c);
    }

    while (!opStack.empty()) {
        char top = opStack.top(); opStack.pop();
        if (top == '(' || top == ')') throw runtime_error("Parentesi non bilanciate");
        outputQueue.push_back(string(1, top));
    }

    // Ora valutiamo la RPN (outputQueue)
    stack<double> evalStack;
    for (const string &tok : outputQueue) {
        if (tok.empty()) continue;
        // se il token è un operatore singolo carattere
        if (tok.size() == 1 && isOp(tok[0])) {
            if (evalStack.size() < 2) throw runtime_error("Espressione malformata (operand mancante)");
            double b = evalStack.top(); evalStack.pop();
            double a = evalStack.top(); evalStack.pop();
            double res = applyOp(a,b,tok[0]);
            evalStack.push(res);
        } else {
            // deve essere un numero
            char *endptr = nullptr;
            double val = strtod(tok.c_str(), &endptr);
            if (endptr == tok.c_str() || *endptr != '\0') throw runtime_error("Numero non valido: " + tok);
            evalStack.push(val);
        }
    }

    if (evalStack.size() != 1) throw runtime_error("Espressione malformata");
    return evalStack.top();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << "Calcolatrice C++ (inserisci 'exit' o 'quit' per uscire)\n";
    cout << "Supporta operatori: + - * / ^ e parentesi. Esempio: 3 + 4*(2-1)^2 / -5\n";

    string line;
    while (true) {
        cout << "> ";
        if (!std::getline(cin, line)) break;
        // rimuovi spazi iniziali e finali
        auto ltrim = [](string &s){ s.erase(s.begin(), find_if(s.begin(), s.end(), [](int ch){return !isspace(ch);})); };
        auto rtrim = [](string &s){ s.erase(find_if(s.rbegin(), s.rend(), [](int ch){return !isspace(ch);} ).base(), s.end()); };
        ltrim(line); rtrim(line);
        if (line.empty()) continue;
        if (line == "exit" || line == "quit") break;
        try {
            double result = evalExpression(line);
            // stampa in formato compatto: se intero, senza decimali
            if (fabs(result - round(result)) < 1e-12) {
                cout << (long long) llround(result) << "\n";
            } else {
                cout.setf(std::ios::fixed); cout << setprecision(10) << result << "\n";
                cout.unsetf(std::ios::fixed);
            }
        } catch (const exception &e) {
            cout << "Errore: " << e.what() << "\n";
        }
    }

    cout << "Arrivederci!\n";
    return 0;
}
