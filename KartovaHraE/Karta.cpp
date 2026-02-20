#include "Karta.h"



Karta::Karta(int paCislo, char paPismeno)
{
    this->cislo = paCislo;
    this->pismeno = paPismeno;
}

Karta::Karta()
{
    this->cislo = 0;
    this->pismeno = '0';
}

Karta::~Karta()
{
}

void Karta::setCislo(int paCislo)
{
    this->cislo = paCislo;
}

void Karta::setPismeno(char paPismeno)
{
    this->pismeno = paPismeno;
}

int Karta::getCislo()
{
    return this->cislo;
}

char Karta::getPismeno()
{
    return this->pismeno;
}

void Karta::vypis()
{
    cout << this->cislo << this->pismeno << endl;
}
