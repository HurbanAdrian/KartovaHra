#include "Balicek.h"

Balicek::Balicek()
{
	this->balicek = new Karta[POCET_KARIET];
}

Balicek::~Balicek()
{
	delete[] this->balicek;
}

void Balicek::naplnBalicek()
{
	char pismenoPremenna = 'A';
	int premennaCislo = 1;
	for (int i = 0; i < POCET_KARIET; i++)
	{
		if (i % 8 == 0 && i > 5)
		{
			pismenoPremenna += 1;
		}
		if (premennaCislo % 9 == 0)
		{
			premennaCislo = 1;
		}
		this->balicek[i] = Karta(premennaCislo, pismenoPremenna);
		//this->balicek[i].vypis();
		premennaCislo++;

	}
}

void Balicek::zamiesaj()
{
	srand(time(0));
	int seed = rand();
	shuffle(&this->balicek[0], &this->balicek[POCET_KARIET], default_random_engine(seed));				//musime & aby sme ukazovali na adresu, lebo shuffle vyzaduje priamy pristup

	/*for (int i = 0; i < POCET_KARIET; i++)
	{
		this->balicek[i].vypis();
	}*/
}

Karta Balicek::dajKartu(int index)
{
	return this->balicek[index];
}
