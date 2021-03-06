/*
 * graf.hh
 *
 *  Created on: 24-04-2014
 *      Author: tomek
 */


#ifndef GRAF_HH_
#define GRAF_HH_

#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include "wierzcholek.hh"
#include <queue>
#include <stack>
#include <algorithm>


using namespace std;
/**
 * \brief klasa modeluje graf.
 * \details w klasie przechowywana jest tablica wierzcholkow oraz informacje mozliwej ilosci
 * wierzcholkow i ilosci wierzcholkow wykorzystanych
 */
class graf
{
wierzcholek *tablica;
int rozmiar;
int ilosc;
int time;
public:
graf(int il);
~graf();
int wrozmiar();
void dodaj_wierzcholek(wierzcholek nowy);
void dodaj_wierzcholek();
void dodaj_polaczenie(int v1, int v2, int waga);
void usun_polaczenie(int v1, int v2);
void usun_wierzcholek(int numer);
void wyswietl_sasiadow(int numer);
bool sprawdz_polaczenie(int v1, int v2);
polaczenie zwroc_polaczenie(int v1, int v2);
element_bfs* przejdz_bfs(int v);
element_bfs* znajdz_droge_bfs(int korzen, int v);
void czytaj_droge_bfs(element_bfs *tablica_bfs, int v1);
element_dfs* znajdz_droge_dfs(int korzen, int v1);
void czytaj_droge_dfs(element_dfs* tablica_bfs, int v1);
element_dfs* przejdz_dfs();
element_a* znajdz_droge_A(int korzen, int v);
friend ostream & operator <<(ostream & wyjscie, graf & dane);
friend class bfs;
friend class droga_komi;
bool dfs_visit(element_dfs * tablica_dfs, int v1);
void wyswietl_dfs(element_dfs *tablica_dfs);
void czytaj_droge_a(element_a* tablica_dfs, int v1);
};

#endif /* GRAF_HH_ */{

