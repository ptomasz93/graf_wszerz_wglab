/*
 * main.cpp
 *
 *  Created on: 05-05-2014
 *      Author: tomek
 */
#define ROZMIAR 11

#include <iostream>
#include <cstdio>

#include "graf.hh"
#include "wierzcholek.hh"
#include "generator.hh"
#include "menu.hh"


int main()
{
int v1,v2,waga;
int rozmiar=ROZMIAR;
srand( time( NULL ) );
//generuj_wierzcholki(rozmiar);
//generuj_polaczenia(rozmiar);
ifstream polaczenia;
ifstream wierzcholki;
wierzcholek pomocniczy;
graf graf1(rozmiar);
polaczenia.open("polaczenia");
wierzcholki.open("wierzcholki");
for(int i=0;i<rozmiar;i++)
{
	wierzcholki>>pomocniczy;
	graf1.dodaj_wierzcholek(pomocniczy);
}
for(int i=0;i<rozmiar;i++)
{
	polaczenia>>v1;
	polaczenia>>v2;
	polaczenia>>waga;
	graf1.dodaj_polaczenie(v1,v2,waga);
}
polaczenia.close();
wierzcholki.close();
menu(graf1);
}




