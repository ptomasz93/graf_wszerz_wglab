/*
 * komiwojazer.cpp
 *
 *  Created on: 25-05-2014
 *      Author: tomek
 */

#include "komiwojazer.hh"
droga_komi::droga_komi(graf * obslugiwany)
:dlugosc(0)
{
	droga=new element_komi [obslugiwany->rozmiar];
	graf1=obslugiwany;
}

/**
 * \brief funckja tworzy petle hamiltona w zadanym grafie
 * \details alfgorytm laczy wierzcholek z nastepnym najblizej polaczonym
 * az wszystkie wierzcholki zostana polaczone w petle.
 * @param obslugiwany
 */
void droga_komi::trasa_najblizsze(int start)
{
	int v,v1=start;
	polaczenie pomocniczy;
	for(int i=0;i<graf1->rozmiar;i++)
	{
		v=v1;
		droga[v].stan=1;
		pomocniczy=najblizszy(v, start);
		v1=pomocniczy.wierzcholek;
		droga[v].nastepny=v1;
		droga[v].waga=pomocniczy.waga;
		dlugosc+=pomocniczy.waga;
	}
	dlugosc-=pomocniczy.waga;
	czytaj_droge(start);
}
/**
 * \brief funkcja wyznacza wierzcholek najblizej polozony
 * @param start
 */

polaczenie droga_komi::najblizszy(int v, int start)
{
vector <polaczenie> polaczenia;///lista polaczen wierzcholka
polaczenia=graf1->tablica[v].polaczenia;
sort(polaczenia.begin(), polaczenia.end(),porownanie2);
	for(int i=0;i<polaczenia.size();i++)
	{
		if(droga[polaczenia[i].wierzcholek].stan==0)
		{
			return polaczenia[i];
		}
	}
	for(int i=0;i<polaczenia.size();i++)
	{
		if(polaczenia[i].wierzcholek==start)
		{
			return polaczenia[i];
		}
	}

}
void droga_komi::czytaj_droge(int v1)
{
	int v2=droga[v1].nastepny;
	cout<<graf1->tablica[v1].wartosc<<endl;
	cout<<droga[v1].waga<<endl;
	while(v2!=v1)
	{
		cout<<graf1->tablica[v2].wartosc<<endl;
		cout<<droga[v2].waga<<endl;
		v2=droga[v2].nastepny;
	}
	cout<<graf1->tablica[v1].wartosc<<endl;
	cout<<"dlugosc trasy:"<<endl;
	cout<<dlugosc<<endl;
}

