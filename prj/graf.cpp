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
ilosc=0;
time=0;
}

/**
 * \brief destruktor grafu
 */
graf::~graf()
{
	delete tablica;

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
		usun_polaczenie(numer,tablica[numer].polaczenia[0].wierzcholek);

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
		if(tablica[v2].polaczenia[i].wierzcholek==v1)tablica[v2].polaczenia.erase(tablica[v2].polaczenia.begin()+i);
	}
	for(int i=0;i<tablica[v1].polaczenia.size();i++)
	{
		if(tablica[v1].polaczenia[i].wierzcholek==v2)tablica[v1].polaczenia.erase(tablica[v1].polaczenia.begin()+i);
	}
}

/**
 * \brief funkcja dodaje polaczenie miedzy zadanymi wierzcholkami
 * \details funckcja sprawdza czy zadane wierzcholki zostaly utworzone jesli tak laczy je.
 * @param v1 wierzcholki ktore maja zostac polaczone
 * @param v2
 */

void graf::dodaj_polaczenie(int v1, int v2,int waga)
{
	polaczenie nowev1, nowev2;
	nowev1.waga=nowev2.waga=waga;
	nowev1.wierzcholek=v2;
	nowev2.wierzcholek=v1;
	if(tablica[v1].zajety==NULL)cout<<"wierzcholek :"<<v1<<" nie istnieje \n";
	if(tablica[v2].zajety==NULL)cout<<"wierzcholek :"<<v2<<" nie istnieje \n";
	if(tablica[v1].zajety==NULL|tablica[v2].zajety==NULL|sprawdz_polaczenie(v1,v2))return;
	tablica[v1].polaczenia.push_back(nowev1);
	tablica[v2].polaczenia.push_back(nowev2);
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
		if(tablica[v1].polaczenia[i].wierzcholek==v2)v1_2=true;
		else v1_2=false;
	}
	for(int i=0;i<tablica[v2].polaczenia.size();i++)
	{
		if(tablica[v2].polaczenia[i].wierzcholek==v1)v2_1=true;
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
element_bfs *graf::przejdz_bfs(int v)
{
if(tablica[v].zajety==NULL)
{
	cout<<"wierzcholek nie istnieje"<<endl;
	return NULL;
}
element_bfs *tablica_bfs;
tablica_bfs=new element_bfs[rozmiar];
queue <int> kolejka; //kolejka z stl
///kolorujemy korzen
tablica_bfs[v].stan=2;
tablica_bfs[v].poprzedni=NULL;
tablica_bfs[v].odleglosc=0;
bool pelny=true;
///petla wykonuje sie dopuki jest cos w kolejca
while(pelny)
{
		for (int i = 0; i < tablica[v].polaczenia.size(); i++)
		{
			int a;
			a = tablica[v].polaczenia[i].wierzcholek;
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

/**
 * \brief funkjcja znajduje najkrutsza droge miedzy zadanymi wierzcholkami
 * \details zaimplementowana na kolejce
 * @param korzen
 * @param v
 * @return
 */
element_bfs* graf::znajdz_droge_bfs(int korzen, int v)
{
if(tablica[korzen].zajety==NULL)
{
	cout<<"wierzcholek nie istnieje"<<endl;
	return NULL;
}
element_bfs *tablica_bfs;
tablica_bfs=new element_bfs[rozmiar];
queue <int> kolejka; //kolejka z stl
///kolorujemy korzen
tablica_bfs[korzen].stan=2;
tablica_bfs[korzen].poprzedni=-1;//poniewaz wierzcholki indeksujeemy od 0 dla czytania sciezki potrzebujemy wyjatkowy indeks dla korzenia
tablica_bfs[korzen].odleglosc=0;
bool pelny=true;
///petla wykonuje sie dopuki jest cos w kolejca
while(pelny)
{
		for (int i = 0; i < tablica[korzen].polaczenia.size(); i++)
		{
			int a;
			a = tablica[korzen].polaczenia[i].wierzcholek;
			if (tablica_bfs[a].stan == 0)
			{
				kolejka.push(a);
				tablica_bfs[a].stan = 1;
				tablica_bfs[a].odleglosc=tablica_bfs[korzen].odleglosc+1;
				tablica_bfs[a].poprzedni=korzen;
				if(a==v)
				{
				//w celu pomiarow nie brudzimy pamieci
				//delete[] tablica_bfs;
				//return NULL;
				return tablica_bfs;
				}
			}
		}
		tablica_bfs[korzen].stan=2;
	if(kolejka.empty())pelny=NULL;
	korzen=kolejka.front();
	kolejka.pop();
}
return tablica_bfs;
}

/**
 * \brief funkcja wyswietla zanleziona droge miedzy wierzcholkami
 * @param tablica_bfs
 * @param v1
 */

void graf::czytaj_droge_bfs(element_bfs* tablica_bfs, int v1)
{
	if(tablica_bfs==NULL)return;
while(v1>=0)
{
	cout<<v1<<endl;
	v1=tablica_bfs[v1].poprzedni;
}
}


/**
 * \brief funkcja wywyołuje przejscie wglab drzewa dla kazdego nie odwiedzonego wierzcholka
 * \powoduje to stworzenie paru drzew przejscia
 * \details na ten moment wszystkie drzewa przechowywyane sa w jednej tablicy
 */

element_dfs* graf::przejdz_dfs()
{
time=0;
element_dfs *tablica_dfs;
tablica_dfs=new element_dfs[rozmiar];
for(int i=0;i<rozmiar;i++)
{
	if(tablica[i].zajety==true && tablica_dfs[i].stan==0)
		dfs_visit(tablica_dfs,i);
}
return tablica_dfs;
}

/**
 * \brief funkcja przechodzi w głąb graf tworzac drzewo przejscia oparta na wywolaniu rekurencyjnym
 * \details funkcja zapisuje czas odwiedzin oraz czas wyjscia z wierzcholka
 * @param v1
 */

bool graf::dfs_visit(element_dfs * tablica_dfs,int v1)
{

	if(tablica[v1].zajety==NULL)
		{
		cout<<"wierzcholek nie istnieje"<<endl;
		return false;
		}
	tablica_dfs[v1].stan=1;
	time+=1;
	tablica_dfs[v1].d=time;
	for (int i = 0; i < tablica[v1].polaczenia.size(); i++)
	{
		int a=tablica[v1].polaczenia[i].wierzcholek;
		if(tablica_dfs[a].stan==0)
		{
			tablica_dfs[a].poprzedni=v1;
			dfs_visit(tablica_dfs, a);

		}
	}
	tablica_dfs[v1].stan=2;
	tablica_dfs[v1].f=time;
	time+=1;
	return NULL;
}


/**
* \brief funkcja wyswietla "las drzew przejsc"
*/
void graf::wyswietl_dfs(element_dfs *tablica_dfs)
{
	if(tablica_dfs==NULL)return;
for(int i=0;i<rozmiar;i++)
{
if(tablica_dfs[i].stan==2)
{
cout<<"wierzcholek: "<<i<<endl;
cout<<tablica_dfs[i]<<endl;
}
}
}
/**
 * \brief funkcja znajduje droge miedzy wierzcholkami. W tym przypadku oparta na stosie. A mozna by i na rekurencji
 * \details funkcja jest implementacja algorytmu dfs
 * @param korzen
 * @param v1
 * @return
 */
element_dfs* graf::znajdz_droge_dfs(int korzen, int v1)
{
	{
	if(tablica[korzen].zajety==NULL)
	{
		cout<<"wierzcholek nie istnieje"<<endl;
		return NULL;
	}
	element_dfs *tablica_dfs;
	tablica_dfs=new element_dfs[rozmiar];
	stack <int> stos; //kolejka z stl
	///kolorujemy korzen
	tablica_dfs[korzen].stan=2;
	tablica_dfs[korzen].poprzedni=-1;//poniewaz wierzcholki indeksujeemy od 0 dla czytania sciezki potrzebujemy wyjatkowy indeks dla korzenia
	bool pelny=true;
	///petla wykonuje sie dopuki jest cos w kolejca
	while(pelny)
	{
			for (int i = 0; i < tablica[korzen].polaczenia.size(); i++)
			{
				int a;
				a = tablica[korzen].polaczenia[i].wierzcholek;
				if (tablica_dfs[a].stan == 0)
				{
					stos.push(a);
					tablica_dfs[a].stan = 1;
					tablica_dfs[a].poprzedni=korzen;
					if(a==v1)
						{
						//zeby nie brudzi w pamieci przy pomiarach
						//delete[] tablica_dfs;
						//return NULL;
						return tablica_dfs;
						}
				}
			}
			tablica_dfs[korzen].stan=2;
		if(stos.empty())pelny=NULL;
		korzen=stos.top();
		stos.pop();

	}
	return tablica_dfs;
	}
}

/**
 * \brief funkcja wyswietla zanleziona droge miedzy wierzcholkami
 * @param tablica_bfs
 * @param v1
 */

void graf::czytaj_droge_dfs(element_dfs* tablica_dfs, int v1)
{
	if(tablica_dfs==NULL)return;
while(v1>=0)
{
	cout<<v1<<endl;
	v1=tablica_dfs[v1].poprzedni;
}
}

element_a *graf::znajdz_droge_A(int korzen, int v)
{
	int x,y;
	int a;
	vector <polaczenie> otwarte;
	vector <int> zamkniete;
	element_a * tablica_a;
	tablica_a=new element_a[rozmiar];
	polaczenie pomocniczy, root;
	pomocniczy.waga=0;
	root.wierzcholek=korzen;
	otwarte.push_back(root);
	tablica_a[root.wierzcholek].poprzedni=-1;
	tablica_a[root.wierzcholek].stan=1;
	while(otwarte.size())
	{
		root=otwarte.back();
		otwarte.pop_back();
		a=root.wierzcholek;
		tablica_a[a].stan=2;
		for(int i=0; i<tablica[a].polaczenia.size();i++)
		{

				pomocniczy=(root+tablica[a].polaczenia[i]);
			if(tablica_a[tablica[a].polaczenia[i].wierzcholek].stan!=2)
			{
				x=abs(v/10-pomocniczy.wierzcholek/100);//trzeba dobrac dzielniki do rozmiaru
				y=abs(v%10-pomocniczy.wierzcholek%100);
//				pomocniczy.waga+=5*(x+y);//heurystyka manhatan
				pomocniczy.waga+=5*(sqrt(x*x+y*y));//heurystyka euklidesowa
				if(tablica_a[pomocniczy.wierzcholek].stan==0)
				{
					otwarte.push_back(pomocniczy);
					tablica_a[pomocniczy.wierzcholek].poprzedni=a;
					tablica_a[pomocniczy.wierzcholek].stan=1;
					if(pomocniczy.wierzcholek==v)
					{
						//delete[] tablica_a;//w celu pomiarow zeby nie brudzic pamieci
						//return NULL;
						return tablica_a;
					}
				}
			}

		}

		sort(otwarte.begin(), otwarte.end(),porownanie);

	}
	cout<<"drogi nie ma"<<endl;
	return NULL;
}

void graf::czytaj_droge_a(element_a* tablica_a, int v1)
{
	if(tablica_a==NULL)return;
while(v1>=0)
{
	cout<<v1<<endl;
	v1=tablica_a[v1].poprzedni;
}
}
