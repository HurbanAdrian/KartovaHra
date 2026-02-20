#include "Hrac.h"

Hrac::Hrac(string paMeno)
{
	this->meno = paMeno;
	this->karty = new Karta[8];
	this->pocetVyhier = 0;
}

Hrac::~Hrac()
{
	delete[] this->karty;
}

string Hrac::getMeno()
{
	return this->meno;
}

void Hrac::pridajKartu(Karta paKarta, int index)
{
	this->karty[index] = paKarta;
}

Karta Hrac::dajKartu(int index)
{
	return this->karty[index];
}

int Hrac::getPocetVyhier()
{
	return this->pocetVyhier;
}

void Hrac::zvysPocetVyhier()
{
	this->pocetVyhier++;
}

Hrac::Hrac()
{
	this->meno = "";
}

Hrac::Hrac(const Hrac& zdroj)
{
	this->meno = zdroj.meno;
	this->pocetVyhier = zdroj.pocetVyhier;
	this->karty = new Karta[8];
	for (int i = 0; i < 8; i++)
	{
		this->karty[i] = zdroj.karty[i];
	}
}

Hrac& Hrac::operator=(const Hrac& zdroj)
{
	if (this != &zdroj)
	{
		this->meno = zdroj.meno;
		this->pocetVyhier = zdroj.pocetVyhier;
		//delete[] this->karty;
		this->karty = new Karta[8];
		for (int i = 0; i < 8; i++)
		{
			this->karty[i] = zdroj.karty[i];
		}
	}
	return *this;
}
