#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<list>
#include<cctype>
#include<memory>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include"bf.h"
int main(int argc, char* argv[]) {
	std::string graf;
	std::string w;
	std::string output;
	std::vector<int> wektw;
	std::vector<std::list<krawedz>> kraw;
	std::unordered_map<int, int> wmap;
	if (argc !=7){
		std::cout << "Program nalezy uruchamiac w sposob nastepujacy: bellman-ford.exe -g nazwa_pliku_z _grafem -w nazwa_pliku_z_wierzcholkami_startowymi ";
		std::cout<<"-o nazwa_pliku_wyjsciowego"<<std::endl<<"Plik wyjsciowy, jesli nie istnieje, zostanie utworzony, a jesli istnieje ZOSTANIE NADPISANY!"<<std::endl;
		return 0;}
	for (int i = 0; i < argc; ++i) {
		std::string a = argv[i];
		if (a == "-g") {
			graf = argv[i + 1];
			i++;}
		if (a == "-w") {
			w = argv[i + 1];
			i++;}
		if (a == "-o") {
			output = argv[i + 1];
			i++;}}
	/*graf = "g.txt";
	w = "w.txt";
	output = "o.txt";*/
	wczyt_g(graf, wmap, wektw, kraw);
	int pocz = 0;
	int rozmiar = (wektw).size();
	algorytm(w, output, wektw, wmap, kraw, pocz, rozmiar);
	_CrtDumpMemoryLeaks();
	return 0;}