/**
*\file
*/
#pragma once
#include<vector>
#include<typeinfo>
/**
*@brief Klasa abstrakcyjna bedaca wzorem dla klas reprezentujacych konkretne algorytmy.
* 
* Klasa abstrakcyjna, po ktorej dziedzicza klasy implementujace konkretne algorytmy sortowania.
* W celu uogolnienia programu zastosowano szablonizacje. Posiada 2 metody abstrakcyjne, sortuj() oraz wypis().
*/
template<typename T>
class Algorytm {
public:
	/**
	* Metoda abstrakcyjna, ktora w klasach potomnych bedzie sortowac vector wprowadzonych elementow oraz
	* tworzyc vector ruchow wykonanych przez dany algorytm.
	*/
	virtual void sortuj(std::vector<T>&) = 0;
	/**
	* Metoda abstrakcyjna, ktora w klasach potomnych bedzie wypisywac na ekran przygotowany wczesniej spis
	* ruchow wykonanych przez dany algorytm.
	*/
	virtual void wypis() = 0;
	Algorytm() {}
	~Algorytm() {}
};