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

void menu(graf graf1);

int main()
{
int rozmiar=ROZMIAR;
srand( time( NULL ) );
//generuj_wierzcholki(rozmiar);
//generuj_polaczenia(rozmiar);
ifstream polaczenia;
ifstream wierzcholki;
wierzcholek pomocniczy;
graf graf1(rozmiar);
element_bfs *tablica_bfs;
polaczenia.open("polaczenia");
wierzcholki.open("wierzcholki");
for(int i=0;i<rozmiar;i++)
{
	wierzcholki>>pomocniczy;
	graf1.dodaj_wierzcholek(pomocniczy);
}

int v1,v2;
for(int i=0;i<rozmiar;i++)
{
	polaczenia>>v1;
	polaczenia>>v2;
	graf1.dodaj_polaczenie(v1,v2);
}
polaczenia.close();
wierzcholki.close();
cout<<graf1;


menu(graf1);
}

void menu(graf graf1)
{
	element_bfs *tablica_bfs;
	element_dfs *tablica_dfs;
	int v1,v2;
	int wybor;
	string opcje[10];
	cout<<"Program tworzacy graf";
	opcje[0]="1. dodaj wierzcholek";
	opcje[1]="2. usun wierzcholek";
	opcje[2]="3. dodaj polaczenie";
	opcje[3]="4. usun poloczenie";
	opcje[4]="5. sprawdz polaczenie";
	opcje[5]="6. wyswietl sasiadow";
	opcje[6]="7. wyswietl graf";
	opcje[7]="8. przejdz graf w szerz";
	opcje[8]="9. przejdz graf w gląb";
	opcje[9]="10. koniec";
	bool petla=true;
	while(petla)
	{
		cout<<"Program tworzacy graf"<<endl;
		cout<<opcje[0]<<endl;
		cout<<opcje[1]<<endl;
		cout<<opcje[2]<<endl;
		cout<<opcje[3]<<endl;
		cout<<opcje[4]<<endl;
		cout<<opcje[5]<<endl;
		cout<<opcje[6]<<endl;
		cout<<opcje[7]<<endl;
		cout<<opcje[8]<<endl;
		cout<<opcje[9]<<endl;
		cin>>wybor;

		switch(wybor)
		{
		case 1:
			cout<<"wybrales: "<<opcje[0]<<endl;
			graf1.dodaj_wierzcholek();
			break;
		case 2:
			cout<<"wybrales: "<<opcje[1]<<endl;
			cout<<"podaj numer wiercholka do usuniecia"<<endl;
			cin>>v1;
			graf1.usun_wierzcholek(v1);
			break;
		case 3:
			cout<<"wybrales: "<<opcje[2]<<endl;
			cout<<"podaj nr wiercholkow do polaczenia"<<endl;
			cin>>v1;
			cin>>v2;
			graf1.dodaj_polaczenie(v1,v2);
			break;
		case 4:
			cout<<"wybrales: "<<opcje[3]<<endl;
			cout<<"podaj nr wiercholkow ktorych polaczenie ma byc usuniete"<<endl;
			cin>>v1;
			cin>>v2;
			graf1.usun_polaczenie(v1,v2);
			break;
		case 5:
			cout<<"wybrales: "<<opcje[4]<<endl;
			cout<<"podaj wiercholki ktorych polaczenie ma zostac sprawdzone"<<endl;
			cin>>v1;
			cin>>v2;
			graf1.sprawdz_polaczenie(v1, v2);
			break;
		case 6:
			cout<<"wybrales: "<<opcje[5]<<endl;
			cout<<"podaj wierzcholek do wyswietlenia"<<endl;
			cin>>v1;
			graf1.wyswietl_sasiadow(v1);
			break;
		case 7:
			cout<<"wybrales: "<<opcje[6]<<endl;
			cout<<graf1;
			break;
		case 8:
			cout<<"wybrales: "<<opcje[7]<<endl;
			cout<<"podaj wierzcholek od ktorego zaczac";
			cin>>v1;
			tablica_bfs=graf1.przejdz_bfs(v1);
			for(int i=0;i<graf1.wrozmiar();i++)
				{
					if(tablica_bfs[i].stan==2)
					{
					cout<<"wierzcholek: "<<i<<endl;
					cout<<tablica_bfs[i]<<endl;
					}
				}
			break;

		case 9:
			cout<<"wybrales: "<<opcje[8]<<endl;
			graf1.przejdz_dfs();
			graf1.wyswietl_dfs();
			break;
		case 10:
			cout<<"wybrales: "<<opcje[9]<<endl;
			petla=false;
			break;
		default:
			cout<<"ZLA OPCJA!!!\n Spruboj jeszcze raz";
			break;
		}
		cin.get();
//		  printf("\033[2J"); // Czyści ekran
//		  printf("\033[0;0f"); // Ustawia kursor w lewym, górnym rogu

	}
}



