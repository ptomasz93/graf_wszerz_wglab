/*
 * main.cpp
 *
 *  Created on: 05-05-2014
 *      Author: tomek
 */
#define ROZMIAR 11

#include <iostream>
//#include <cstdio>
#include <fstream>
#include <string>


#include "graf.hh"
#include "wierzcholek.hh"
#include "generator.hh"
#include "menu.hh"
#include "stoper.hh"
#include "komiwojazer.hh"

using namespace std;

int main()
{
int v1,v2,waga;
int rozmiar=ROZMIAR;
srand( time( NULL ) );
ifstream polaczenia;
ifstream wierzcholki;
ofstream wynik;
czas stoper;
wierzcholek pomocniczy;
graf graf1(rozmiar);

//generuj_wierzcholki(rozmiar);
//generuj_polaczenia(rozmiar);
polaczenia.open("drogi.txt");
wierzcholki.open("miasta.txt");
for(int i=0;i<rozmiar;i++)
{
	wierzcholki>>pomocniczy;
	graf1.dodaj_wierzcholek(pomocniczy);
}



while(1)
{
	polaczenia>>v1;
	polaczenia>>v2;
	polaczenia>>waga;
//	if(v1==rozmiar+999||v2==rozmiar+999||waga==rozmiar+999)break;
	if(v1==999||v2==999||waga==999)
	{
		break;
	}
	graf1.dodaj_polaczenie(v1,v2,waga);
}
polaczenia.close();
wierzcholki.close();

//*************************************POMIARY CZASU****************************//
//wynik.open("wynik_4000.txt");
//cout<<"A*      bfs       dfs"<<endl;
//wynik<<"A*      bfs       dfs"<<endl;
//for(int a=10;a<ROZMIAR;a+=500)
//{
//
//	for(int i=0;i<10000;i++)
//	{
//
//		graf1.znajdz_droge_A(4000,a);
//
//	}
//	stoper.stop();
//
//	wynik<<a<<" "<<stoper.time;
//	cout<<a<<" "<<stoper.time;
//	stoper.start();
//	for(int i=0;i<10000;i++)
//	{
//
//		graf1.znajdz_droge_bfs(4000,a);
//
//	}
//	stoper.stop();
//	stoper.wynik();
//	wynik<<" "<<stoper.time;
//	cout<<" "<<stoper.time;
//	stoper.start();
//	stoper.wynik();
//	for(int i=0;i<10000;i++)
//	{
//
//		graf1.znajdz_droge_dfs(4000,a);
//
//	}
//	stoper.stop();
//	stoper.wynik();
//	wynik<<" "<<stoper.time<<endl;
//	cout<<" "<<stoper.time<<endl;
//	wynik.close();
//
//}

//wynik.close();
droga_komi komi(&graf1);
komi.trasa_najblizsze(5);
menu(graf1);

}




