/*
 * generator.cpp
 *
 *  Created on: 15-03-2014
 *      Author: root
 */
using namespace std;

#include "generator.hh"

/**
 * \brief generuje plik *.txt o zadanej ilosci danych i nazwie
 * \details W pliku umieszczane sa liczby naturalne od 1 wzwyrz
 * w pierwszym wierszu umieszczana jest liczba mowiaca o ilosci wierszy danych.
 * @param nazwa - utworzonego pliku
 * @param rozmiar - ilosc wierszy sanych
 */

void generuj_polaczenia(int rozmiar)
{

	ofstream test;
	test.open("polaczenia");
	for(int i=0; i<rozmiar*5; i++)
	{
		test<<(rand()%rozmiar)<<"\n";
		test<<(rand()%rozmiar)<<"\n";
	}
	test.close();
}

void generuj_wierzcholki(int rozmiar)
{
	ofstream test;
	test.open("wierzcholki");
	for(int i=0; i<rozmiar; i++)
	{
		test<<i<<"\n";
		test<<i<<"\n";
	}
	test.close();
}

