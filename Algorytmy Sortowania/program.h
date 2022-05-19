/**
*\file
*/
#pragma once
#include<vector>
#include<memory>
#include<algorithm>
#include<iostream>
#include"algorytm.h"
#include"babelkowe.h"
#include"wybor.h"
/**
* @brief Klasa koordynujaca dzialanie calego programu.
* 
* Klasa ta zawiera metody przygotowujace program do dzialania, zgodnie z wola uzytkownika,
*  a nastepnie wywoluje samo sortowanie i wypisanie efektow.
* Wykorzystano szablonizacje, polimorfizm i wzorzec projektowy strategii.
*/
template<typename T>
class Program {
	/**
	* Inteligentny wskaznik, dzieki ktoremu zaimplementowany zostaje wzorzec strategii. Bedzie on wskazywal na obiekt klasy 
	* reprezentujacej wybrany przez uzytkownika algorytm.
	*/
	std::shared_ptr<Algorytm<T>> alg;
	/**
	* Vector elementow do posortowania. Beda tu przechowywane wprowadzne przez uzytkownika wartosci wybranego przez niego typu.
	*/
	std::vector<T> elementy;
public:
	Program() {}
	~Program() {}
	/**
	* @brief Metoda ustawiajaca wskaznik alg na zadany obiekt.
	* 
	* Metoda przyjmuje const referencje na obiekt klasy dziedziczacej po klasie Algorytm, a nastepnie przypissuje jej 
	* wskaznik. Dzieki temu rozwiazaniu i dzieki polimorfizmowi wywolane zostanie pozadane przez uzytkownika sortowanie.
	*/
	void setAlg(const std::shared_ptr<Algorytm<T>>& algo) {
		this->alg = algo;
	}
/**
* @brief Metoda ustwaiajaca do uzycia wybrany algorytm.
* 
* Metoda zapyta uzytkownika jakiego algorytmu chce uzyc w dalszej czesci programu.
* Po dokonaniu wyboru przez uzytkownika w odpowiedni sposob zostanie wywolana metoda setAlg(), co pozniej spowoduje, dzieki 
* polimorfizmowi, wywolanie pozadanej metody sortuj().
*/
	void wybor_algorytmu() {
		int numer_algorytmu;
		std::cout << "Jakiego algorytmu sortowania chcesz uzyc" << std::endl;
		std::cout << "Babelkowego - wybierz 1." << std::endl;
		std::cout << "Przez proste wybieranie - wybierz 2." << std::endl;
		std::cin >> numer_algorytmu;
		if (numer_algorytmu == 1) {
			this->setAlg(std::make_shared<Babelkowe<T>>());
		}
		else {
			this->setAlg(std::make_shared<Wybor<T>>());
		}
	}
	/**
	* @brief Metoda przygotowujaca elementy do sortowania.
	* 
	* Metoda najpierw zapyta uzytkownika o ilosc elementow, dla ktorych chce uruchomic sortowanie, a nastepnie 
	* poprosi o ich wprowadzenie. Poniewaz ilosc elementow nie jest znana na etapie kompilacji, beda one przechowywane
	* przy pomocy vectora.
	*/
	void przygotowanie_elementow() {
		int ilosc_elementow;
		T nowy_element;
		std::cout << "Podaj ilosc elementow:" << std::endl;
		std::cin >> ilosc_elementow;
		std::cout << "Wprowadz elementy:" << std::endl;
		for (int i = 0; i < ilosc_elementow; i++) {
			std::cin >> nowy_element;
			elementy.push_back(nowy_element);
		}
	}
	/**
	* @brief Metoda sterujaca praca programu.
	* 
	* Metoda po kolei wywoluje kolejne metody potrzebne do pracy programu. W funkcji main() tworzony jest obiekt klasy Program, 
	* a nastepnie wywolywana jest na jego rzecz wlasnie metoda run(). Powoduje to uproszczenie glownej funkcji programu. Po metodach 
	* odpowiedzialnych za wybor algorytmu i przyjecie od uzytkownika elementow do posortowania, wywolana zostaje na ich rzecz metoda 
	* sortuj(elementy). Dzieki zastosowaniu wzorca strategii i polimorfizmu ururhcomiona zostanie instancja tej metody implementujaca 
	* wybrany wczesniej algorytm. Po wykonaniu sie tej metody program konczy prace.
	*/
	void run() {
		wybor_algorytmu();
		przygotowanie_elementow();
		alg->sortuj(elementy);
	}
};