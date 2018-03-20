#include "Zaznamnik.h"

#include <iostream>

using namespace std;

Zaznamnik::Zaznamnik()
{
	this->maximalnyPocetZnakov = 0;
	this->pocetZnakov = 0;
}

Zaznamnik::~Zaznamnik()
{}
	
std::vector<Zaznam> Zaznamnik::getZaznamy() 
{
	return this->zaznamy;
}

int Zaznamnik::getMaximalnyPocetZnakov()
{
	return this->maximalnyPocetZnakov;
}

int Zaznamnik::getPocetZnakov()
{
	return this->pocetZnakov;
}

void Zaznamnik::setZaznamy(std::vector<Zaznam> zaznamy)
{
	this->zaznamy = zaznamy;
}

void Zaznamnik::setMaximalnyPocetZnakov(int maximalnyPocetZnakov)
{
	this->maximalnyPocetZnakov = maximalnyPocetZnakov;
}

void Zaznamnik::addPocetZnakov(int pocetZnakov)
{
	this->pocetZnakov += pocetZnakov;
}

void Zaznamnik::subtractPocetZnakov(int pocetZnakov)
{
	this->pocetZnakov -= pocetZnakov;
}

void Zaznamnik::pridajZaznam(string name, string text)
{
	if ((text.length() + this->getPocetZnakov()) > this->getMaximalnyPocetZnakov()) {
		/* TODO: Throw exception */
		cout << "Zaznamnik overflow" << endl;
		return;
	}

	Zaznam z(name, text);
	this->zaznamy.push_back(z);

	this->addPocetZnakov(text.length());
}

void Zaznamnik::zobrazZaznam(string name)
{
	for (std::vector<Zaznam>::iterator it = this->zaznamy.begin();
		it != this->zaznamy.end(); ++it) {
		if ((*it).getNazov() == name)
			cout << "Text zaznamu: " << endl << (*it).getText() << endl << endl;
	}
}

void Zaznamnik::vymazZaznam(string name)
{
	for (std::vector<Zaznam>::iterator it = this->zaznamy.begin();
		it != this->zaznamy.end(); ++it) {
		if ((*it).getNazov() == name)
			this->zaznamy.erase(it);
	}
}

void Zaznamnik::zobrazZaznamy()
{
	for (std::vector<Zaznam>::iterator it = this->zaznamy.begin();
		it != this->zaznamy.end(); ++it) {
		cout << "Nazov zaznamu: " << (*it).getNazov() << endl;
		cout << "Text zaznamu: " << endl << (*it).getText() << endl << endl;
	}
}

void Zaznamnik::vymazZaznamy()
{
	this->zaznamy.clear();
}