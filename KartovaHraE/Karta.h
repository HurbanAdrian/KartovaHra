#pragma once
#include <string>
#include <iostream>


using namespace std;
class Karta
{
private:
	int cislo;
	char pismeno;
public:
	Karta(int paCislo, char paPismeno);
	Karta();
	~Karta();

	void setCislo(int paCislo);
	void setPismeno(char paPismeno);
	int getCislo();
	char getPismeno();
	void vypis();
};

