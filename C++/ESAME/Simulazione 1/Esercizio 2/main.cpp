#include "Website.h"
#include "Webpage.h"


using namespace std;

int main(){
    Webpage Home("homepage", "Benvenuto");
    string t= Home.getTitolo();
    cout<<t<<endl;


    // Creazione Pagine
    Webpage home("Home", "Benvenuti");
    Webpage news("News", "Ultime notizie");
    Webpage sport("Sport", "Calcio");
    Webpage tech("Tech", "Computer");
    Webpage contact("Contatti", "Email");

    // Creazione Link
    home.addLink(&news);      // Distanza 1
    home.addLink(&sport);     // Distanza 1
    news.addLink(&tech);      // Distanza 2 da home
    tech.addLink(&contact);   // Distanza 3 da home
    sport.addLink(&home);     // Ciclo!

    // Creazione Sito
    Website site(&home);

    // Test
    cout << "Cerco Tech (atteso 2): " << site.find_webpage(tech) << endl;
    cout << "Cerco Contatti (atteso 3): " << site.find_webpage(contact) << endl;

    // Test pagina non collegata
    Webpage isolated("Isola", "Nessuno mi linka");
    cout << "Cerco Isola (atteso -1): " << site.find_webpage(isolated) << endl;

    return 0;
}
