#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using std::cout;
using std::ifstream;
using std::ofstream;
using std::string;
using std::map;
using std::set;
using std::vector;
using std::istringstream;
using std::setw;
using std::left;

void URL_nuskaitymas(const string& url_failas, set<string>& URL);

bool URL(const string& segmentas, const set<string>& URL);

bool URL_paieska(string zodis, const set<string>& url);

bool atrenkamos_raides(char c);

void nuskaitomas_failas(const string& failas, map<string, vector<int>>& visi_zodziai, vector<string>& urls, const set<string>& URL);

void zodziu_kiekis_isvestis(const map<string, vector<int>>& visi_zodziai,ofstream& out);

void crossreference_isvestis(const map<string, vector<int>>& visi_zodziai, ofstream& out);

void url_isvestis(const vector<string>& urls, ofstream& out);
