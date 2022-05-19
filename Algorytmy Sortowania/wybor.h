/**
*\file
*/
#pragma once
#include"ruchy_wybor.h"
#include"algorytm.h"
/**
* @brief Klasa reprezentujaca sortowanie przez wybieranie.
*
* Klasa dziedziczaca po klasie Algorytm. Implementuje ona sortowanie przez wybieranie. Posiada 2 metody, sortuj()
*  oraz wypis(). Wykorzystuje obiekty klasy RuchW do przechowywania wykonywanychprzez algorytm operacji.
* Zastosowano szablonizacje.
*/
template<typename T>
class Wybor : public Algorytm<T> {
public:
	/**
	* @brief Metoda wypisujaca ciag ruchow sortowania przez wybieranie.
	*
	* Metoda wypis() informuje uzytkownika o przygotowaniu listy ruchow algorytmu i prosi o wybranie sposobu ich wypisania.
	* Do wyboru dostajemy 2 tryby: wszystkie ruchy moga zostac wypisane od razu lub po kolei z kazdorazowym potwierdzeniem wypisania przez uzytkownika.
	* Wykorzystany zostal przeciazony dla klasy Ruch operator << oraz polimorfizm.
	*/
	std::vector<RuchW> Ww;
	void wypis() {
		bool rodzaj_wypisywania = 0;
		std::cout << "Lista krokow algorytmu jest gotowa. Jesli chcesz, aby program wypisywal po 1 kroku, wcisnij 1. Jesli chcesz, aby od razu wypisano wszystkie kroki, wcisnij 0" << std::endl;
		std::cin >> rodzaj_wypisywania;
		if (rodzaj_wypisywania == 0) {
			for (unsigned int i = 0; i < Ww.size(); i++) {
				std::cout << Ww[i];
			}
		}
		else {
			std::cout << "Aby przechodzic do kolejnych krokow, wprowadzaj 1." << std::endl;
			for (unsigned int i = 0; i < Ww.size(); i++) {
				int kontynuuj = 0;
				std::cout << Ww[i];
				std::cin >> kontynuuj;
			}
		}
		std::cout << "Koniec" << std::endl;
	}
	/**
	*@brief Metoda sortuj() w wersji implementujacej sortowanie przez wybieranie.
	* 
	* Klasyczna implementacja sortowania przez wybieranie. Kazdorazowo po znalezieniu minimum ieposortowanej czesci vectora
	* elementow tworzony jest obiekt klasy RuchW zawierajacy informacje o tej operacji oraz pierwotny indeks tego minimum.
	* Nastepnie rozponane zostaje polozenie tego elementu, tzn.: czy jest on pierwszym elementem czesci nieposortowanej czy nie.
	* Jesli jest to zostaje utworzony obiekt klasy RuchW zawierajacy taka informacje. W przeciwnym razie obiekt ten bedzie opisywal
	*  zamiane 2 elementow - pzrechowane beda ich indeksy oraz nazwa operacji. Dopiero teraz wykonywana jest zamiana.
	* Po zakonczeniu sortowania wywolana zostaje metoda wypis().
	*/
	virtual void sortuj(std::vector<T>& elementy) {
		for (unsigned int i = 0; i < elementy.size() - 1; i++) {
			T min;
			if (typeid(min).name() == typeid(int).name())
				min = INT_MAX;
			else if (typeid(min).name() == typeid(double).name())
				min = DBL_MAX;
			int indmin = 0;
			for (unsigned int j = i; j < elementy.size(); j++) {
				if (elementy[j] < min) {
					min = elementy[j];
					indmin = j;
				}
			}
			RuchW n;
			n.nr_operacji = RuchW::rodzaj::Minimum;
			n.element1 = indmin;
			n.element2 = 0;
			Ww.push_back(n);
			if (indmin != i) {
				RuchW n;
				n.nr_operacji = RuchW::rodzaj::Zamiana;
				n.element1 = i;
				n.element2 = indmin;
				Ww.push_back(n);
				std::swap(elementy[indmin], elementy[i]);
			}
			else {
				RuchW n;
				n.nr_operacji = RuchW::rodzaj::Minimum_wlasciwe;
				n.element1 = i;
				n.element2 = indmin;
				Ww.push_back(n);
			}
		}
		wypis();
	}
	Wybor() {}
	virtual ~Wybor() {}
};