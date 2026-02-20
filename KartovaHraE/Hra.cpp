#include "Hra.h"

Hra::Hra()
{
	this->hraci = new Hrac[4];
	this->hraci[0] = Hrac("Peter");
	this->hraci[1] = Hrac("Pavol");
	this->hraci[2] = Hrac("Jozef");
	this->hraci[3] = Hrac("Milan");

	this->balicek.naplnBalicek();
	this->balicek.zamiesaj();

	this->rozdajKarty();
	this->vypis();
}

Hra::~Hra()
{
	delete[] this->hraci;					//tu som skoro zabudol dealokovat objekty, pozor
}

void Hra::rozdajKarty()
{
	int premennaIndex = 0;
	int premennaHrac = 0;
	for (int i = 0; i < POCET_KARIET; i++)
	{
		if (i % 8 == 0 && i > 5)
		{
			premennaHrac++;
		}
		if (premennaIndex % 8 == 0)
		{
			premennaIndex = 0;
		}
		switch (premennaHrac)
		{
		case 0:
			this->hraci[premennaHrac].pridajKartu(this->balicek.dajKartu(i), premennaIndex);
			//cout << "Hrac 1 dostal kartu " << this->balicek.dajKartu(i).getCislo() << this->balicek.dajKartu(i).getPismeno() << " na indexe " << premennaIndex << endl;
			break;
		case 1:
			this->hraci[premennaHrac].pridajKartu(this->balicek.dajKartu(i), premennaIndex);
			//cout << "Hrac 2 dostal kartu " << this->balicek.dajKartu(i).getCislo() << this->balicek.dajKartu(i).getPismeno() << " na indexe " << premennaIndex << endl;
			break;
		case 2:
			this->hraci[premennaHrac].pridajKartu(this->balicek.dajKartu(i), premennaIndex);
			//cout << "Hrac 3 dostal kartu " << this->balicek.dajKartu(i).getCislo() << this->balicek.dajKartu(i).getPismeno() << " na indexe " << premennaIndex << endl;
			break;
		case 3:
			this->hraci[premennaHrac].pridajKartu(this->balicek.dajKartu(i), premennaIndex);
			//cout << "Hrac 4 dostal kartu " << this->balicek.dajKartu(i).getCislo() << this->balicek.dajKartu(i).getPismeno() << " na indexe " << premennaIndex << endl;
			break;
		default:
			break;
		}
		

		premennaIndex++;
	}
}

string Hra::porovnajKarty(int index)
{
	string vypis;
	string menoVitaza;
	int cisloKartyVitaza = 0;
	char znakKartyVitaza = ' ';

	for (int i = 0; i < 4; i++)
	{
		int cisloKarty = this->hraci[i].dajKartu(index).getCislo();
		char pismenoKarty = this->hraci[i].dajKartu(index).getPismeno();
		string menoHraca = this->hraci[i].getMeno();

		if (cisloKarty > cisloKartyVitaza)
		{
			cisloKartyVitaza = cisloKarty;
			znakKartyVitaza = pismenoKarty;
			menoVitaza = menoHraca;
		}
		else if (cisloKarty == cisloKartyVitaza && pismenoKarty < znakKartyVitaza)	//lebo chceme mensie podla abecedy B < C
		{
			cisloKartyVitaza = cisloKarty;
			znakKartyVitaza = pismenoKarty;
			menoVitaza = menoHraca;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		if (menoVitaza.compare(this->hraci[i].getMeno()) == 0)				// ==0 tak vtedy rovne
		{
			this->hraci[i].zvysPocetVyhier();
		}
	}
	return menoVitaza + " " + to_string(cisloKartyVitaza) + znakKartyVitaza;
}

void Hra::vypis()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << this->hraci[j].dajKartu(i).getCislo() << this->hraci[j].dajKartu(i).getPismeno() << " ";
		}
		cout << ": " << this->porovnajKarty(i) << endl;
	}

	cout << "Vysledky:" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << this->hraci[i].getMeno() << ": " << this->hraci[i].getPocetVyhier() << endl;
	}
}
