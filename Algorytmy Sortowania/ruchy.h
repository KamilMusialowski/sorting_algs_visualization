/**
*\file
*/
#pragma once
#include<string>
#include<iostream>
/**
* @brief Klasa abstrakcyjna Ruch, reprezentujaca krok algorytmu.
* 
* Klasa Ruch reprezentuje jeden wydzielony krok danego algorytmu.
* Zawiera zmienne przechowujace indeksy elementow, na ktorych wykonana zostala operacja algorytmu, tzn.: jeden jego krok. Klasy dziedziczace po Ruch dodadza
* odpowiednia zmienna przechowujaca informacje o tej operacji.
* Posiada tez metode zwracajaca odpowiedni opis slowny danej operacji.
* 
*/
class Ruch {
public:
	/**
	* Zmienna przechowujaca indeks pierwszego elementu, na ktorym wykonano operacje.
	*/
	int element1 = 0;
	/**
	*Zmienna przechowujaca indeks drugiego elementu, na ktorym wykonano operacje.
	*/
	int element2 = 0;
	/**
	*Metoda abstrakcyjna, ktora w klasach potomnych bedzie zwracac slowny opis operacji przeprowadzonej przez algorytm.
	*/
	virtual std::string opis() = 0;
};


std::ostream& operator<<(std::ostream& i, Ruch& r) {
	i << r.opis() << std::endl;
	return i;
}