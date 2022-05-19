/**
*\file
*/
#pragma once
#include"ruchy.h"
/**
*@brief Klasa reprezentujaca ruchy sortowania przez wybieranie.
* 
* Klasa dziedziczaca po klasie Ruch. Posiada zoptymalizowana pod sortowanie przez wybieranie metode opis().
*/
class RuchW : public Ruch {
public:
	/**
	* Zmienna przechowujaca informacje o operacji wykonanej przez algorytm. Dla przejrezystosci opisu zastosowano typ wyliczeniowy, zoptymalizowany dla sortowania przez 
	* wybieranie.
	*/
	enum rodzaj : int { Zamiana=1, Minimum_wlasciwe=2, Minimum=3} nr_operacji;
	//rodzaj nr_operacji;
	/**
	*@brief Metoda opis() w wersji dla sortowanie przez wybieranie.
	* 
	*Metoda dostosowana do specyfiki ruchow sortowania przez wybieranie.
	*Moze ona zwrocic 3 rodzaje komunikatow: o zamianie 2 elementow, o znalezieniu minimum nieposortowanej czesci tablicy
	* oraz zasygnalizowac sytuacje, gdy znalezione minimum bylo juz na wlasciwej pozycji.
	* W celu uproszczenia komunikatu dla osob nieinformatycznych do pierwotnych indeksow elementow dodaje 1, aby
	* sztucznie indeksowac od 1, a nie od 0.
	*/
	virtual std::string opis() {
		std::string s;
		if (this->nr_operacji == Zamiana) {
			s = "Zamieniono element o indeksie  z elementem o indeksie ";
			s.insert(54, std::to_string(this->element2 + 1));
			s.insert(30, std::to_string(this->element1 + 1));
		}
		else if (this->nr_operacji == Minimum_wlasciwe) {
			s = "Znalezione minimum znajdowalo sie na wlasciwym miejscu, zamiana elementow nie byla potrzeba";
		}
		else if (this->nr_operacji == Minimum) {
			s = "Znaleziono minimum nieposortowanej czesci tablicy. Jest nim element spod indeksu ";
			s.insert(81, std::to_string(this->element1 + 1));
		}
		return s;
	}
};