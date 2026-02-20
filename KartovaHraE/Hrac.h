#pragma once
#include <string>
#include "Karta.h"

using namespace std;
class Hrac
{
private:
	string meno;
	Karta* karty;
	int pocetVyhier;
public:
	Hrac(string paMeno);
	~Hrac();
	string getMeno();

	void pridajKartu(Karta paKarta, int index);
	Karta dajKartu(int index);
	int getPocetVyhier();
	void zvysPocetVyhier();

	Hrac();
	Hrac(const Hrac& zdroj);
	Hrac& operator=(const Hrac& zdroj);
};

