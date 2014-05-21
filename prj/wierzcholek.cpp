/*
 * wierzcholek.cpp
 *
 *  Created on: 24-04-2014
 *      Author: tomek
 */

#include "wierzcholek.hh"
bool porownanie(polaczenie aaa ,polaczenie bbb)
{
     if(aaa.waga>bbb.waga)
        return true;
     if(aaa.waga<bbb.waga)
        return false;
}

ostream & operator << (ostream &wyjscie, wierzcholek  &wej)
	{
		cout<<"wierzcholek numer: "<<wej.numer<<"\n";
		cout<<"wartosc: "<<wej.wartosc<<endl;
		cout<<"polaczenia z: ";
		for(int i=0;i<wej.polaczenia.size();i++)
		{
			cout<<wej.polaczenia[i].wierzcholek<<" ";
			cout<<"waga: "<<wej.polaczenia[i].waga<<", ";
		}
		cout<<"\n";
		return wyjscie;
	}


istream & operator >> (istream &wejscie, wierzcholek  &wyj)
	{
		wejscie>>wyj.numer;
		wejscie>>wyj.wartosc;

	}
