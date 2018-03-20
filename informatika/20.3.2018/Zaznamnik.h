#ifndef _ZAZNAMNIK_H_
#define _ZAZNAMNIK_H_

#include <iostream>
#include <vector>

#include "Zaznam.h"

class Zaznamnik
{
	std::vector<Zaznam> zaznamy;
	int maximalnyPocetZnakov;
	int pocetZnakov;
public:
	Zaznamnik();
	~Zaznamnik();
	
	std::vector<Zaznam> getZaznamy();
	int getMaximalnyPocetZnakov();
	int getPocetZnakov();

	void setZaznamy(std::vector<Zaznam> zaznamy);
	void setMaximalnyPocetZnakov(int maximalnyPocetZnakov);

	void addPocetZnakov(int pocetZnakov);
	void subtractPocetZnakov(int pocetZnakov);

	void pridajZaznam(string name, string text);
	void zobrazZaznam(string name);
	void vymazZaznam(string name);

	void zobrazZaznamy();
	void vymazZaznamy();
};

#endif