/*
 * generator.cpp
 *
 *  Created on: 15-03-2014
 *      Author: root
 */
using namespace std;

#include "generator.hh"

/**
 * \brief generuje plik *.txt o zadanej ilosci polaczen.
 * \details polaczenia sa generowane maxymalnie miedzy wierzcholkiem oddalonym o 6.
 * @param nazwa - utworzonego pliku
 * @param rozmiar - ilosc wierszy sanych
 */

void generuj_polaczenia(int rozmiar)
{
	int a;
	ofstream test;
	test.open("polaczenia");
	for(int i=0; i<rozmiar; i++)
	{
		for(int b=0;b<5;b++)
		{
			a=(rand())%6+i;
			if(a<rozmiar)
			{
			test<<i<<"\n";//wierzcholek pierwszy
			test<<a<<"\n";//wierzcholek drugi
			test<<(rand()%15)<<"\n";//waga polaczenia
			}
			else
				test<<rozmiar+999<<endl;//znacznik konca pliku
		}
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

