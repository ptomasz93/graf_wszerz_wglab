/*
 * main.cpp
 *
 *  Created on: 05-05-2014
 *      Author: tomek
 */
#define ROZMIAR 10000

#include <iostream>
//#include <cstdio>
#include <fstream>
#include <string>


#include "graf.hh"
#include "wierzcholek.hh"
#include "generator.hh"
#include "menu.hh"
#include "stoper.hh"

using namespace std;

int main()
{
int v1,v2,waga;
int rozmiar=ROZMIAR;
srand( time( NULL ) );
ifstream polaczenia;
ifstream wierzcholki;
fstream wynik;
czas stoper;
wierzcholek pomocniczy;
graf graf1(rozmiar);
//generuj_wierzcholki(rozmiar);
//generuj_polaczenia(rozmiar);
polaczenia.open("polaczenia");
wierzcholki.open("wierzcholki");
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
	if(v1==rozmiar+999||v2==rozmiar+999||waga==rozmiar+999)break;
	graf1.dodaj_polaczenie(v1,v2,waga);
}
polaczenia.close();
wierzcholki.close();

//*************************************POMIARY CZASU****************************//
double czasy;
wynik.open("wynik.txt");
v1=1;
v2=94;
stoper.start();
for(int i=0;i<10000;i++)
{

	graf1.znajdz_droge_A(v1,v2);

}
stoper.stop();

wynik<<"A* "<<v1<<" do "<<v2<<" czas "<<stoper.time<<endl;
stoper.start();
for(int i=0;i<10000;i++)
{

	graf1.znajdz_droge_bfs(v1,v2);

}
stoper.stop();
stoper.wynik();
wynik<<"bfs z :"<<v1<<" do "<<v2<<" czas "<<stoper.time<<endl;
stoper.start();
stoper.wynik();
for(int i=0;i<10000;i++)
{

	graf1.znajdz_droge_dfs(v1,v2);

}
stoper.stop();
stoper.wynik();
wynik<<"dfs z :"<<v1<<" do "<<v2<<" czas "<<stoper.time<<endl;
wynik.close();




menu(graf1);

}




