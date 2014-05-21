/*
 * menu.cpp
 *
 *  Created on: 15-05-2014
 *      Author: tomek
 */

#include "menu.hh"

void menu(graf& graf1)
{
	element_bfs *tablica_bfs;
	element_dfs *tablica_dfs;
	element_a* tablica_a;
	int v1,v2,waga;
	int wybor;
	string opcje[13];
	opcje[0]="1. dodaj wierzcholek";
	opcje[1]="2. usun wierzcholek";
	opcje[2]="3. dodaj polaczenie";
	opcje[3]="4. usun poloczenie";
	opcje[4]="5. sprawdz polaczenie";
	opcje[5]="6. wyswietl sasiadow";
	opcje[6]="7. wyswietl graf";
	opcje[7]="8. przejdz graf w szerz";
	opcje[8]="9. znajdz droge w szerz";
	opcje[9]="10. przejdz graf w gląb";
	opcje[10]="11. znajdz droge w glab";
	opcje[11]="12. znajdz droge A*";
	opcje[12]="12. koniec";
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
		cout<<opcje[10]<<endl;
		cout<<opcje[11]<<endl;
		cout<<opcje[12]<<endl;
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
			cout<<"podaj wage polaczenia";
			cin>>waga;
			graf1.dodaj_polaczenie(v1,v2,waga);
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
			delete [] tablica_bfs;
			break;
		case 9:
				cout<<"wybrales: "<<opcje[8]<<endl;
				cout<<"podaj wierzcholek startowy."<<endl;
				cin>>v1;
				cout<<"podaj wierzcholek koncowy"<<endl;
				cin>>v2;
				tablica_bfs=graf1.znajdz_droge_bfs(v1,v2);
				graf1.czytaj_droge_bfs(tablica_bfs,v2);
				delete [] tablica_bfs;
				break;
		case 10:
			cout<<"wybrales: "<<opcje[9]<<endl;
			tablica_dfs=graf1.przejdz_dfs();
			graf1.wyswietl_dfs(tablica_dfs);
			delete [] tablica_dfs;
			break;
		case 11:
			cout<<"wybrales: "<<opcje[10]<<endl;
			cout<<"podaj wierzcholek startowy."<<endl;
			cin>>v1;
			cout<<"podaj wierzcholek koncowy"<<endl;
			cin>>v2;
			tablica_dfs=graf1.znajdz_droge_dfs(v1,v2);
			graf1.czytaj_droge_dfs(tablica_dfs,v2);
			delete [] tablica_dfs;
			break;
		case 12:
			cout<<"wybrales: "<<opcje[11]<<endl;
			cout<<"podaj wierzcholek startowy."<<endl;
			cin>>v1;
			cout<<"podaj wierzcholek koncowy"<<endl;
			cin>>v2;
			tablica_a=graf1.znajdz_droge_A(v1,v2);
			graf1.czytaj_droge_a(tablica_a,v2);
			delete [] tablica_a;
			break;
		case 13:
			cout<<"wybrales: "<<opcje[12]<<endl;
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


