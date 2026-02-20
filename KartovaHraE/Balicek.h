#pragma once
#include "Karta.h"
#include <random>
#include <time.h>

const int POCET_KARIET = 32;
using namespace std;
class Balicek
{
private:
	Karta* balicek;

public:
	Balicek();
	~Balicek();

	void naplnBalicek();
	void zamiesaj();
	Karta dajKartu(int index);
};

