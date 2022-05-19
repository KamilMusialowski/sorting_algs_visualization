/**
* \file
*/
#include"program.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
/**
* @brief Glowna funkcja programu.
* 
* Funkcja main() pyta uzytkownika o rodzaj danych, jakich chce uzyc przy sortowaniu, a nastepnie tworzy obiekt klasy Program 
* podajac jako parametr szablonowy wybrany typ. Nastepnie wywolywana jest na rzecz tego obiektu metoda run(). Po 
* jej wykonaniu program konczy prace, zwracajac kod 0.
*/
int main() {
	int rodzaj = 0;
	std::cout << "Jesli chcesz sortowac liczby calkowite, wprowadz 1. Jesli zmiennoprzecinkowe, wprowadz 2." << std::endl;
	std::cout << "W przypadku liczb zmiennoprzecinkowych zastosuj zapis z . , np.: 5.5" << std::endl;
	std::cin >> rodzaj;
	if (rodzaj == 1) {
		Program<int> p;
		p.run();
	}
	else if (rodzaj == 2) {
		Program<double>p;
		p.run();
	}
	return 0;
	_CrtDumpMemoryLeaks();
}