/*
 * stoper.hh
 *
 *  Created on: 15-03-2014
 *      Author: root
 */

#ifndef STOPER_HH_
#define STOPER_HH_

#define CLOCKS_PER_SEC 1000000

#include <ctime>

/**
 * \class
 * \brief klasa zawiera zmienne oraz funkcje potrzebne do obliczenia czasu dzialania algorytmu
 */
class czas
{
private:


	clock_t poczatek, koniec;
public:
	double time;
	/**
	 * \brief start pomiaru
	 * zapisuje stan zegara
	 */
	void start()
	{
		poczatek=clock();
	}
	/**
	 * \brief koniec pomiaru
	 * zapisuje stan zegara
	 */
	void stop()
	{
		koniec=clock();
	}
	/**
	 * \brief zwraca wynik pomiaru
	 * @return zwraca czas dzialania
	 */
	void wynik()
	{
		time=(double)(koniec-poczatek)/(double)CLOCKS_PER_SEC;

	}
	/**
	 * \brief zapisuje wynik do pliku
	 * @param wynik pomiaru
	 * @param rozmiar rozmiar problemu
	 */
	void zapisz(fstream &wynik, int rozmiar)
	{
		cout<<rozmiar<<"  "<<time<<"\n";
		wynik<<rozmiar<<"  "<<time<<"\n";
	}

};


#endif /* STOPER_HH_ */
