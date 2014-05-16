/*
 * wierzcholek.hh
 *
 *  Created on: 24-04-2014
 *      Author: tomek
 */

#ifndef WIERZCHOLEK_HH_
#define WIERZCHOLEK_HH_

#include <string>
#include <vector>
#include <iostream>

using namespace std;
/**
 * \brief clasa modeluje pojecie pojecie poedynczego wierzcholka grafu
 */

struct poloczenie
{
	int wierzcholek;
	int waga;

};

class wierzcholek
{

	int numer;///identyfikator wierzcholka
	string  wartosc;///wartosc przechowywana w wierzcholku
	vector <poloczenie> polaczenia;///lista polaczen wierzcholka
public:
	friend ostream & operator << (ostream &wyjscie, wierzcholek  &wej);
	friend istream & operator >> (istream &wejscie, wierzcholek  &wyj);
	bool zajety;///zmienna okresla czy wierzcholek zostal zdefiniowany
	friend class graf;

	wierzcholek()///konstruktor
	:zajety(NULL), numer(0)
	{
		wartosc.clear();
	}
};

/**
 * \brief struktura definiuje element drzewa przechodzenie w szerz
 */
struct element_bfs
{
	int stan;
	int odleglosc;
	int poprzedni;
	element_bfs()
	:stan(0), odleglosc(0), poprzedni(0){};
	friend ostream & operator <<(ostream & wyjscie, element_bfs & dane)
	{
		if(dane.stan==2)
		wyjscie<<"poprzedni: "<<dane.poprzedni<<endl;
		wyjscie<<"odleglosc: "<<dane.odleglosc<<endl;
		return wyjscie;
	}

};
/**
 * \brief element drzewa przejscia dla przeszukiwania w głąb;
 */
struct element_dfs
{
	int stan;
	int poprzedni;
	///czas wejscia do wierzcholka
	int d;
	///czas wyjscia z wierzcholka
	int f;
	element_dfs()
	:stan(0), poprzedni(0){};
	friend ostream & operator <<(ostream & wyjscie, element_dfs & dane)
	{
		if(dane.stan==2)
		{
			wyjscie<<"poprzedni: "<<dane.poprzedni<<endl;
			wyjscie<<"czas wizyty: "<<dane.d<<endl;
			wyjscie<<"czas wyjscie: "<<dane.f<<endl;
		}
		return wyjscie;
	}

};
#endif /* WIERZCHOLEK_HH_ */
