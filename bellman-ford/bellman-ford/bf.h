#pragma once

struct krawedz {
	int wierz;
	double kraw;
};

void wczyt_g(std::string& graf, std::unordered_map<int, int>& wmap, std::vector<int>& wektw, std::vector<std::list<krawedz>>& kraw);

std::string usuwanie_spacji(std::string& slinia);

void spr_plik(std::ifstream& plik);

void spr_plikw(std::ifstream& plik);

void odczyt(int& w1, int& w2, double& d, std::string& linia, bool& rodzaj);

void przy_map(std::unordered_map<int, int>& wmap, std::vector<int>& wektw, int& w1, int& w2, std::vector<std::list<krawedz>>& kraw);

void dodkr(std::vector<std::list<krawedz>>& kraw, int w1, int w2, double d, std::unordered_map<int, int>&wmap);

void tabele(int p[], double b[], int rozmiar);

bool bf(int pocz, int rozmiar, std::vector<std::list<krawedz>>& kraw, int p[], double b[]);

void algorytm(std::string& w, std::string& output, std::vector<int>& wektw, std::unordered_map<int, int>& wmap, std::vector<std::list<krawedz>>& kraw, int& pocz, int& rozmiar);