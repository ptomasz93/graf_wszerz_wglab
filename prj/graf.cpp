/*
 * graf.cpp
 *
 *  Created on: 24-04-2014
 *      Author: tomek
 */

#include "graf.hh"
/**
 * \brief przeladowanie operatora wyjscia
 * @param wyjscie strumien wyjscia
 * @param dane wysylane dane
 */

ostream & operator <<(ostream & wyjscie, graf & dane)
{
	cout<<"graf zawiera "<<dane.ilosc<<" wierzcholkow"<<endl;

	for(int i=0;i<dane.rozmiar;i++)
	{
		if(dane.tablica[i].zajety!=NULL)cout<<dane.tablica[i];
	}
}


/**
 * \brief konstruktor klasy graf
 * @param il wielkosc tworzonego grafu
 */
graf::graf(int il)
{
rozmiar=il;
tablica = new wierzcholek[rozmiar];
tablica_dfs=new element_dfs[rozmiar];
ilosc=0;
time=0;
}

/**
 * \brief destruktor grafu
 */
graf::~graf()
{
	delete tablica;
	delete tablica_dfs;
}

/**
 * \brief funkcja sluzy do dodawania wierzcholkow
 * @param nowy wierzcholek ktory ma zostac dodany
 */
void graf::dodaj_wierzcholek(wierzcholek nowy)
{
if(nowy.numer>rozmiar-1)
{
	cout<<"numer wierzcholka za duzy";
	return;
}
nowy.zajety=true;
tablica[nowy.numer]=nowy;
ilosc++;
}

/**
 * \brief funkcja dodaje wierzcholek
 * \details funkcja wymaga wprowadzania danych przez uzytkownika
 */
void graf::dodaj_wierzcholek()
{
	wierzcholek nowy;
	cout<<"podaj numer wierzcholka"<<endl;
	cin>>nowy.numer;
	cout<<"podaj wartosc wiercholka"<<endl;
	cin>>nowy.wartosc;
	nowy.zajety=true;
if(nowy.numer>rozmiar-1)
{
	cout<<"numer wierzcholka za duzy";
	return;
}
tablica[nowy.numer]=nowy;
ilosc++;
}

/**
 * \brief funkcja usuwa wierzcholek o zadanym kluczu
 * @param numer klucz wierzcholka do usuniecia
 */
void graf::usun_wierzcholek(int numer)
{
	while(tablica[numer].polaczenia.size())
		usun_polaczenie(numer,tablica[numer].polaczenia[0]);

	tablica[numer].zajety=NULL;
	ilosc--;

}

/**
 * \brief funkcja zwraca rozmiar grafu
 * @return
 */
int graf::wrozmiar()
{
	return rozmiar;
}

/**
 * \brief funkcja usuwa polaczenie miedzy zadanymi wierzcholkami
 * @param v1 wierzcholki ktorych polaczenie ma byc usuniete
 * @param v2
 */
void graf::usun_polaczenie(int v1, int v2)
{
	for(int i=0;i<tablica[v2].polaczenia.size();i++)
	{
		if(tablica[v2].polaczenia[i]==v1)tablica[v2].polaczenia.erase(tablica[v2].polaczenia.begin()+i);
	}
	for(int i=0;i<tablica[v1].polaczenia.size();i++)
	{
		if(tablica[v1].polaczenia[i]==v2)tablica[v1].polaczenia.erase(tablica[v1].polaczenia.begin()+i);
	}
}

/**
 * \brief funkcja dodaje polaczenie miedzy zadanymi wierzcholkami
 * \details funckcja sprawdza czy zadane wierzcholki zostaly utworzone jesli tak laczy je.
 * @param v1 wierzcholki ktore maja zostac polaczone
 * @param v2
 */

void graf::dodaj_polaczenie(int v1, int v2)
{
	if(tablica[v1].zajety==NULL)cout<<"wierzcholek :"<<v1<<" nie istnieje \n";
	if(tablica[v2].zajety==NULL)cout<<"wierzcholek :"<<v2<<" nie istnieje \n";
	if(tablica[v1].zajety==NULL|tablica[v2].zajety==NULL|sprawdz_polaczenie(v1,v2))return;
	tablica[v1].polaczenia.push_back(v2);
	tablica[v2].polaczenia.push_back(v1);
}

/**
 * \brief funkcja wyswietla sasiadow wierzcholka
 * \details zostaje wyswietlona lista sasiedztwa
 * @param numer
 */
void graf::wyswietl_sasiadow(int numer)
{
	if(tablica[numer].zajety==NULL)cout<<"wierzcholek nie istnieje"<<endl;
	else cout<<tablica[numer]<<endl;
}
/**
 * \brief funkcja sprawdza czy mieszy podanymi wierzchokami istnieje polaczenie
 * \details funckcja sprawdza czy zadane wierzcholki zostaly utworzone nastepnie sprawdza polaczenie.
 * @param v1
 * @param v2
 * @return zwraca informacja logiczna
 */
bool graf::sprawdz_polaczenie(int v1, int v2)
{
	if(tablica[v1].zajety==NULL)cout<<"wierzcholek :"<<v1<<" nie istnieje \n";
	if(tablica[v2].zajety==NULL)cout<<"wierzcholek :"<<v2<<" nie istnieje \n";
	bool v1_2=false, v2_1=false;
	for(int i=0;i<tablica[v1].polaczenia.size();i++)
	{
		if(tablica[v1].polaczenia[i]==v2)v1_2=true;
		else v1_2=false;
	}
	for(int i=0;i<tablica[v2].polaczenia.size();i++)
	{
		if(tablica[v2].polaczenia[i]==v1)v2_1=true;
		else v2_1=false;
	}
		if(v2_1&v1_2)
			{
			return true;
			}
		else
		return false;

}

/**
 * \brief implementacja algorytmu przechodzenie wszerz grafu
 * \details funkcja uzywa kolejki dostarczonej w STL. wynikiem dzialania jest drzewo przejscia grafu
 * zawierajace informacje o najkrutszych odleglosciach od korzenia
 * @param v1 korzen przechodzenia
 * @return
 */
element_bfs *graf::przejdz_bfs(int v1)
{
if(tablica[v1].zajety==NULL)
{
	cout<<"wierzcholek nie istnieje"<<endl;
}
element_bfs *tablica_bfs;
tablica_bfs=new element_bfs[rozmiar];
queue <int> kolejka; //kolejka z stl
int v=v1;
///kolorujemy korzen
tablica_bfs[v].stan=2;
tablica_bfs[v].poprzedni=NULL;
tablica_bfs[v].odleglosc=0;
bool pelny=true;
///petla wykonuje sie dopuki jest cis w kolejca
while(pelny)
{
		for (int i = 0; i < tablica[v].polaczenia.size(); i++)
		{
			int a;
			a = tablica[v].polaczenia[i];
			if (tablica_bfs[a].stan == 0)
			{
				kolejka.push(a);
				tablica_bfs[a].stan = 1;
				tablica_bfs[a].odleglosc=tablica_bfs[v].odleglosc+1;
				tablica_bfs[a].poprzedni=v;
			}
		}
		tablica_bfs[v].stan=2;
	if(kolejka.empty())pelny=NULL;
	v=kolejka.front();
	kolejka.pop();

}
return tablica_bfs;
}

//element_dfs *graf::przejdz_dfs(int v1)
//{
//if(tablica[v1].zajety==NULL)
//{
//	cout<<"wierzcholek nie istnieje"<<endl;
//}
//element_dfs *tablica_dfs;
//tablica_dfs=new element_dfs[rozmiar];
//stack <int> kolejka;
//int v=v1;
//int time;
//tablica_dfs[v].stan=2;
//tablica_dfs[v].poprzedni=NULL;
//bool pelny=true;
//while(pelny)
//{
//		for (int i = 0; i < tablica[v].polaczenia.size(); i++)
//		{
//			int a;
//			a = tablica[v].polaczenia[i];
//			if (tablica_dfs[a].stan == 0)
//			{
//				kolejka.push(a);
//				tablica_dfs[a].stan = 1;
//				tablica_dfs[a].poprzedni=v;
//			}
//		}
//		tablica_dfs[v].stan=2;
//	if(kolejka.empty())pelny=NULL;
//	v=kolejka.top();
//	kolejka.pop();
//}
//return tablica_dfs;
//}

/**
 * \brief funkcja wywyołuje przejscie wglab drzewa dla kazdego nie odwiedzonego wierzcholka
 * \powoduje to stworzenie paru drzew przejscia
 * \details na ten moment wszystkie drzewa przechowywyane sa w jednej tablicy
 */
void *graf::przejdz_dfs()
{
time=0;
for(int i=0;i<rozmiar;i++)
{
	if(tablica[i].zajety==true && tablica_dfs[i].stan==0)
		dfs_visit(i);

}

}
/**
 * \brief funkcja przechodzi w głąb graf tworzac drzewo przejscia
 * \details funkcja zaisuje czas odwiedzin oraz czas wyjscia z wierzcholka
 * @param v1
 */

void graf::dfs_visit(int v1)
{
	if(tablica[v1].zajety==NULL)
		{
		cout<<"wierzcholek nie istnieje"<<endl;
		return;
		}
	tablica_dfs[v1].stan=1;
	time+=1;
	tablica_dfs[v1].d=time;
	for (int i = 0; i < tablica[v1].polaczenia.size(); i++)
	{
		int a=tablica[v1].polaczenia[i];
		if(tablica_dfs[a].stan==0)
		{
			tablica_dfs[a].poprzedni=v1;
			dfs_visit(a);
		}
	}
	tablica_dfs[v1].stan=2;
	tablica_dfs[v1].f=time;
	time+=1;
}
/**
 * \brief funkcja wyswietla "las drzew przejsc"
 */
void graf::wyswietl_dfs()
{
	for(int i=0;i<rozmiar;i++)
		{
			if(tablica_dfs[i].stan==2)
			{
			cout<<"wierzcholek: "<<i<<endl;
			cout<<tablica_dfs[i]<<endl;
			}
		}
}
