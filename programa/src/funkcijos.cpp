#include "funkcijos.h"

void URL_nuskaitymas(const string& url_failas, set<string>& URL) {
    ifstream file(url_failas);
    if (!file) {
        cout << "Nepavyko atidaryti url_galunes.txt\n";
        return;
    }

    string url;
    while (file >> url) {
        std::transform(url.begin(), url.end(), url.begin(), ::toupper);
        URL.insert(url);
    }
}

bool URL(const string& segmentas, const set<string>& URL) {
    return URL.count(segmentas);
}

bool URL_paieska(string zodis, const set<string>& url) {
    std::transform(zodis.begin(), zodis.end(), zodis.begin(), ::toupper);

    if (zodis.find('/') != string::npos) {
        if (!(zodis.rfind("HTTP://", 0) == 0 ||
              zodis.rfind("HTTPS://", 0) == 0)) {
            return false;
              }
    }

    size_t start = zodis.find_first_of("./");
    if (start == string::npos)
        return false;

    start++;
    while (start < zodis.length()) {
        size_t end = zodis.find_first_of("./", start);
        string temp = (end == string::npos)
            ? zodis.substr(start)
            : zodis.substr(start, end - start);

        if (URL(temp, url))
            return true;

        if (end == string::npos)
            break;

        start = end + 1;
    }
    return false;
}

bool atrenkamos_raides(char c) {
    return !ispunct(static_cast<unsigned char>(c)) && !isdigit(static_cast<unsigned char>(c));
}

void nuskaitomas_failas(
    const string& failas,
    map<string, vector<int>>& visi_zodziai,
    vector<string>& urls,
    const set<string>& URL
) {
    ifstream file(failas);
    if (!file) {
        cout << "Nepavyko atidaryti input.txt\n";
        return;
    }

    string eilute;
    int eilutes_sk = 0;

    while (getline(file, eilute)) {
        eilutes_sk++;
        istringstream iss(eilute);
        string token;

        while (iss >> token) {

            if (token.find('.') != string::npos || token.find('/') != string::npos) {
                if (URL_paieska(token, URL)) {
                    if (token.back() == '.' || token.back() == '/')
                        token.pop_back();
                    urls.push_back(token);
                    continue;
                }
            }

            string galutinis_zodis;
            for (char c : token) {
                if (atrenkamos_raides(c))
                    galutinis_zodis += std::tolower(static_cast<unsigned char>(c));
            }

            if (!galutinis_zodis.empty()) {
                visi_zodziai[galutinis_zodis].push_back(eilutes_sk);
            }
        }
    }
}

void zodziu_kiekis_isvestis(
    const map<string, vector<int>>& visi_zodziai,
    ofstream& out)
{
    out << left << setw(25) << "Zodis" << " | Kiekis\n";
    out << string(40, '-') << "\n";

    for (const auto& [zodis, eilute] : visi_zodziai) {
        if (eilute.size() > 1) {
            out << left << setw(25) << zodis << " | " << eilute.size() << "\n";
        }
    }
}

void crossreference_isvestis(
    const map<string, vector<int>>& visi_zodziai,
    ofstream& out)
{
    out << left << setw(25) << "Zodis" << " | Eilutes\n";
    out << string(50, '-') << "\n";

    for (const auto& [zodis, eilute] : visi_zodziai) {
        if (eilute.size() > 1) {
            set<int> unique(eilute.begin(), eilute.end());

            out << left << setw(25) << zodis << " | ";
            for (int ln : unique)
                out << ln << " ";
            out << "\n";
        }
    }
}

void url_isvestis(const vector<string>& urls, ofstream& out) {
    out << "Rastos URL nuorodos:\n";
    for (const auto& u : urls)
        out << u << "\n";
}