/**
*\file
*/
#pragma once
#include"ruchy.h"
/**
*@brief Klasa reprezentujaca ruchy sortowania babelkowego.
* 
* Klasa dziedziczaca po klasie Ruch. Posiada zoptymalizowana pod sortowanie babelkowe metode opis().
*/
class RuchB : public Ruch {
public:
	/**
	* Zmienna przechowujaca informacje o operacji wykonanej przez algorytm. Dla przejrezystosci opisu zastosowano typ wyliczeniowy, zoptymalizowany dla sortowania babelkowego.
	*/
	enum rodzaj : int {Zamiana=1} nr_operacji;
	/**
	*@brief Metoda opis() w wersji dla sortowania babelkowego.
	* 
	* Metoda dostosowana do specyfiki sortowania babelkowego.
	* Zwraca ona komunikat sygnalizujacy zamiane 2 elementow.
	* W celu uproszczenia komunikatu dla osob nieinformatycznych do pierwotnych indeksow elementow dodaje 1, aby
	* sztucznie indeksowac od 1, a nie od 0.
	*/
	virtual std::string opis() {
		std::string s = "Zamieniono element o indeksie  z elementem o indeksie ";
		s.insert(54, std::to_string(this->element2 + 1));
		s.insert(30, std::to_string(this->element1 + 1));
		return s;
	}
};