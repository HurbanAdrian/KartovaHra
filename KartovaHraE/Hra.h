#pragma once
#include "Balicek.h"
#include "Hrac.h"

using namespace std;
class Hra
{
private:

	Hrac* hraci;
	Balicek balicek;
public:
	Hra();
	~Hra();

	void rozdajKarty();
	string porovnajKarty(int index);
	void vypis();
};

