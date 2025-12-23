#include "funkcijos.h"

int main() {
    set<string> URL;
    map<string, vector<int>> visi_zodziai;
    vector<string> urls;

    URL_nuskaitymas("url_galunes.txt", URL);
    nuskaitomas_failas("input.txt", visi_zodziai, urls, URL);

    ofstream daznis("zodziu_daznis.txt");
    ofstream cr("cross_reference.txt");
    ofstream url("url_sarasas.txt");

    zodziu_kiekis_isvestis(visi_zodziai, daznis);
    cout << "zodziai ir ju pasikartojimo daznio lentele issaugota 'zodziu_daznis.txt'\n";

    crossreference_isvestis(visi_zodziai, cr);
    cout << "cross-reference lentele issaugota 'cross_reference.txt'\n";

    url_isvestis(urls, url);
    cout << "URL sarasas issaugotas 'url_sarasas.txt'\n";

    cout << "Programa sekmingai ivykdyta.\n";
    return 0;
}