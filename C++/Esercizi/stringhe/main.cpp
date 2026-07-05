#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void lunghezza(){
    string stringa;
    cout<<"Inserisci una parola:";
    cin>>stringa;
    cout<<stringa.length()<<endl;
}

void concatena(){
    string str1= "ciao";
    string str2= "mondo";
    string str3= str1+str2;
    cout<<str3<<endl;
}

void maiuscolo(){
    string str="hello word";
    for (int i=0; i < str.length();i++){
        str[i] = toupper(str[i]);
    }
    cout<<str<<endl;
}

void find(string str){
    string stringa = "ciao mondo bello";
    if (stringa.find(str) != std::string::npos)
        cout<<"Esiste la sottostringa"<<endl;
    else
        cout<<"Non esiste la sottostringa"<<endl;

}

int main(){
    // lunghezza();
    // concatena();
    // maiuscolo();
    // find("ciao");
}