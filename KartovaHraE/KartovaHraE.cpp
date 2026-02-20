#include <iostream>
#include "Balicek.h"
#include "Hra.h"
#include "MemLeak.h"

using namespace std;
class Pole
{
private:
	int pocet = 0;
	int* data = nullptr;
public:
	Pole(int poc)
		: pocet(poc), data(pocet > 0 ? new int[pocet] : nullptr)
	{
		if (pocet > 0)
		{
			for (int i = 0; i < pocet; i++)
				data[i] = 0;
		}
	}
	friend void Vypis(const Pole& p);
	~Pole() { delete[] data; }

	friend void Vypis(const Pole& p)			//doplnit aj friend a aj const &
	{
		for (int i = 0; i < p.pocet; i++)
			cout << p.data[i] << endl;
	}

};

int main()
{
	Pole p(5);
	Vypis(p);

	Balicek balicek;
	balicek.naplnBalicek();
	balicek.zamiesaj();

	Hra hra;


	return 0;
}

