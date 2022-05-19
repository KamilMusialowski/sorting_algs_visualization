/**
*\file
*/
#pragma once
#include"ruchy_babelkowe.h"
#include"algorytm.h"
/**
* @brief Klasa reprezentujaca sortowanie babelkowe.
* 
* Klasa dziedziczaca po klasie Algorytm. Implementuje ona sortowanie babelkowe. Posiada 2 metody, sortuj()
*  oraz wypis(). Wykorzystuje obiekty klasy RuchB do przechowywania wykonywanychprzez algorytm operacji.
* Zastosowano szablonizacje.
*/
template<typename T>
class Babelkowe : public Algorytm<T> {
	/**
	* Vector obiektow typu RuchB. Przechowywane w nim beda operacje wykonane przez algorytm podczas sortowania.
	*/
	std::vector<RuchB> Wb;
public:
	/**
	* @brief Metoda wypisujaca ciag ruchow sortowania babelkowego.
	* 
	* Metoda wypis() informuje uzytkownika o przygotowaniu listy ruchow algorytmu i prosi o wybranie sposobu ich wypisania.
	* Do wyboru dostajemy 2 tryby: wszystkie ruchy moga zostac wypisane od razu lub po kolei z kazdorazowym potwierdzeniem wypisania przez uzytkownika.
	* Wykorzystany zostal przeciazony dla klasy Ruch operator << oraz polimorfizm.
	*/
	void wypis() {
		bool rodzaj_wypisywania = 0;
		std::cout << "Lista krokow algorytmu jest gotowa. Jesli chcesz, aby program wypisywal po 1 kroku, wcisnij 1. Jesli chcesz, aby od razu wypisano wszystkie kroki, wcisnij 0" << std::endl;
		std::cin >> rodzaj_wypisywania;
		if (rodzaj_wypisywania == 0) {
			for (unsigned int i = 0; i < Wb.size(); i++) {
				std::cout << Wb[i];
			}
		}
		else {
			std::cout << "Aby przechodzic do kolejnych krokow, wprowadzaj 1." << std::endl;
			for (unsigned int i = 0; i < Wb.size(); i++) {
				int kontynuuj = 0;
				std::cout << Wb[i];
				std::cin >> kontynuuj;
			}
		}
	}
	/**
	* @brief Metoda sortuj() w wersji implementujacej sortowanie babelkowe.
	* 
	* Klasyczna implementacja sortowania babelkowego. Kazdorazowo po porownaniu ze soba 2 elementow, w razie potrzeby ich zamienienia,
	* Tworzony jest obiekt typu RuchB, przechowujacy pierwotne indeksy zamienianych elementow, oraz, dla zachowania sponosci w programie,
	* nazwa wykonanej operacji. W tym przypadku zawsze jest to Zamiana. Wykorzystywany jest tu typ enum. Nastepnie
	* utorzony obiekt jest dodawany do vectora Wb. Dopiero wtedy nastepuje zamiana elementow. po zakonczeniu sorotwania wywolywana
	* jest metoda wypis().
	*/
	void sortuj(std::vector<T>& elementy) {
		for (unsigned int i = 0; i < elementy.size() - 1; i++) {
			for (unsigned int j = 0; j < elementy.size() - i - 1; j++) {
				if (elementy[j] > elementy[j + 1]) {
					RuchB n;
					n.nr_operacji = RuchB::rodzaj::Zamiana;
					n.element1 = j;
					n.element2 = j + 1;
					Wb.push_back(n);
					std::swap(elementy[j], elementy[j + 1]);
				}
			}
		}
		wypis();
	}

	Babelkowe() {}
	virtual ~Babelkowe() {}
};