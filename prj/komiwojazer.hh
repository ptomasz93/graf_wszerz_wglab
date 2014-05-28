/*
 * komiwojazer.cpp
 *
 *  Created on: 25-05-2014
 *      Author: tomek
 */

#ifndef KOMIWOJAZER_CPP_
#define KOMIWOJAZER_CPP_

#include "graf.hh"
#include "wierzcholek.hh"
/**
 * \brief klasa modeluje element drogi komiwojazera
 */
struct element_komi
{
	bool stan; //2-start 1 obsluzony, 0 jeszcze nie
	int nastepny;
	int waga;
	element_komi()
	:stan(0){}
};

/**
 * \brief klasa modeluje pojecie drogi komiwojazera.
 */
class droga_komi
{
graf * graf1;
element_komi * droga;
int dlugosc;
public:
droga_komi(graf * obslugiwany);
polaczenie najblizszy(int v, int start);
void trasa_najblizsze(int start);
void czytaj_droge( int v1);

};

#endif /* KOMIWOJAZER_CPP_ */
