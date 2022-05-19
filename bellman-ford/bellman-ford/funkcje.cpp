#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<list>
#include<cctype>
#include<memory>
#include"bf.h"

//usuwanie znakow bialych
std::string usuwanie_spacji(std::string& slinia) {
	slinia.erase(std::remove_if(slinia.begin(), slinia.end(), ::isspace), slinia.end());
	return slinia;
}

//wczytywanie grafu
void wczyt_g(std::string& graf, std::unordered_map<int, int>& wmap, std::vector<int>& wektw, std::vector<std::list<krawedz>>& kraw) {
	int w1=0;
	int w2=0;
	int pmys=0;
	int pdw=0; 
	int pstrz=0;//wierzcholek 1, 2, pozycja myslnika, strzalki, dwukropka
	std::ifstream plik(graf);
	bool rodzaj=1;
	std::string pomocniczy, slinia;// linia;//pomocniczy string
	double d=0;//waga krawedzi
	spr_plik(plik);
	while (getline(plik, slinia)) {
		int spr = (slinia).find(":");
		if (spr != std::string::npos) {
			usuwanie_spacji(slinia);
			odczyt(w1, w2, d, slinia, rodzaj);//ok
			przy_map(wmap, wektw, w1, w2, kraw);
			dodkr(kraw, w1, w2, d, wmap);
			if (rodzaj == 0) {
				przy_map(wmap, wektw, w2, w1, kraw);
				dodkr(kraw, w2, w1, d, wmap);
			}
		}
	}
}

// sprawdzenie pliku z grafem
void spr_plik(std::ifstream& plik) {
	if (!plik) {
		std::cerr << "nie udalo sie otworzyc pliku z grafem" << std::endl;
		exit;
	}
}

// sprawdzenie pliku z wierzcholkami startowymi
void spr_plikw(std::ifstream& plik) {
	if (!plik) {
		std::cerr << "nie udalo sie otworzyc pliku z wierzcholkami" << std::endl;
		exit;
	}
}

//odczyt krawedzi
void odczyt(int& w1, int& w2, double& d, std::string& linia, bool& rodzaj) { //1-skierowana 0-nieskierowana//zmiana
	int pmys =linia.find("-");
	int pdw = linia.find(":");
	int pstrz = linia.find(">");
	std::string pomocniczy = linia.substr(0, (pmys));
	w1 = atoi(pomocniczy.c_str());
	if (pstrz != std::string::npos) {
		rodzaj = 1;
		pomocniczy = linia.substr(pstrz + 1, (pdw - 1) - pstrz);
	}
	else {
		rodzaj = 0;
		pomocniczy = linia.substr(pmys + 1, (pdw - 1) - pmys);
	}
	w2 = atoi(pomocniczy.c_str());
	pomocniczy = linia.substr(pdw + 1, sizeof(linia) - pdw);
	d = atof(pomocniczy.c_str());
}

//przyp do mapy
void przy_map(std::unordered_map<int, int>& wmap, std::vector<int>& wektw, int& w1, int& w2, std::vector<std::list<krawedz>>& kraw) {
	auto spr = std::find(wektw.begin(), wektw.end(), w1);
	if (spr == wektw.end()) {
		wektw.push_back(w1);
		wmap.insert({ w1, wmap.size() });
		std::list<krawedz>* k = new std::list<krawedz>;
		kraw.push_back(*k);
		delete k;
	}
	spr = std::find(wektw.begin(), wektw.end(), w2);
	if (spr == wektw.end()) {
		wektw.push_back(w2);
		wmap.insert({ w2, wmap.size() });
		std::list<krawedz>* k = new std::list<krawedz>;
		kraw.push_back(*k);
		delete k;
	}
}

//dodawanie krawedzi
void dodkr(std::vector<std::list<krawedz>>& kraw, int w1, int w2, double d, std::unordered_map<int, int>&wmap) {
	krawedz* e = new krawedz;
	e->wierz = wmap[w2];
	e->kraw = d;
	kraw[wmap[w1]].push_back(*e);
	delete e;
}

//przygotowyanie tabel
void tabele(int p[], double b[], int rozmiar) {
	for (int i = 0; i < rozmiar; ++i) {
		p[i] = -1;
		b[i] = DBL_MAX;
	}
}

//relaksacja
bool bf(int pocz, int rozmiar, std::vector<std::list<krawedz>>& kraw, int p[], double b[]) {
	bool test=0;
	for (int i = 1; i < rozmiar; ++i) {
		test = true;
		for (int x = 0; x < rozmiar; x++) {
			for (auto& it : kraw[x]) {
				if (b[it.wierz] > b[x] + it.kraw)
				{
					test = false;
					b[it.wierz] = b[x] + it.kraw;
					p[it.wierz] = x;
				}
			}
		}
		if (test) return true;
	}
	for (int x = 0; x < rozmiar - 1; x++) {
		for (auto& t : kraw[x]) {
			if (b[t.wierz] > b[x] + t.wierz)
				return false;
			else 
				return true;
		}
	}
}

//bellman-ford z zapisem do pliku
void algorytm(std::string& w, std::string& output, std::vector<int>& wektw, std::unordered_map<int, int>& wmap, std::vector<std::list<krawedz>>& kraw, int& pocz, int& rozmiar) {
	std::ifstream wierzch(w);
	std::ofstream zapis(output);
	spr_plikw(wierzch);
	double* b = new double[rozmiar]; //koszty dojscia
	int* p = new int[rozmiar]; //numery poprzednikow
	while (wierzch >> pocz) {
		if (std::find(wektw.begin(), wektw.end(), pocz) == wektw.end()) {
			zapis << "brak wierzcholka " << pocz << " w grafie" << std::endl;
		}
		else {
			tabele(p, b, rozmiar);
			b[wmap[pocz]] = 0;
			if (bf(wmap[pocz], rozmiar, kraw, p, b)) {
				int* S = new int[rozmiar];
				int sptr = 0;
				zapis << "wierzcholek startowy: " << pocz << std::endl;
				for (int i = 0; i < rozmiar; i++) {
					if (b[i] == 0) {
						continue;
					}
					for (int x = i; x != -1; x = p[x]) {
						S[sptr++] = wektw[x];
					}
					while (sptr) {
						zapis << S[--sptr];
						if (sptr != 0) {
							zapis << "->";
						}
					}
					zapis << " : " << b[i] << std::endl;
				}
				delete[] S;
			}
			else
				zapis << "Cykl ujemny" << std::endl;
		}
	}
	zapis.close();
	delete[]p;
	delete[]b;

}