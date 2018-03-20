#include <iostream>

#include "Zaznam.h"
#include "Zaznamnik.h"

int main(int argc, char const *argv[])
{
	Zaznamnik zaznamnik1;
	zaznamnik1.setMaximalnyPocetZnakov(100);
	zaznamnik1.pridajZaznam("Zaznam c.1", "lorem ipsum");
	zaznamnik1.pridajZaznam("Zaznam c.2", "lorem ipsum dolom sit amet");
	zaznamnik1.pridajZaznam("Zaznam c.3", "lorem ipsum kajlsd jfdjdfj jkdsf");
	zaznamnik1.zobrazZaznamy();

	Zaznamnik zaznamnik2;
	zaznamnik2.setMaximalnyPocetZnakov(200);
	zaznamnik2.pridajZaznam("Zaznam c.1", "lorem ipsum");
	zaznamnik2.pridajZaznam("Zaznam c.2", "lorem ipsum dolom sit amet");
	zaznamnik2.pridajZaznam("Zaznam c.3", "lorem ipsum kajlsd jfdjdfj jkdsf");
	zaznamnik2.zobrazZaznamy();

	zaznamnik1.vymazZaznam("Zaznam c.1");
	zaznamnik1.zobrazZaznamy();

	zaznamnik2.zobrazZaznam("Zaznam c.3");

	return 0;
}