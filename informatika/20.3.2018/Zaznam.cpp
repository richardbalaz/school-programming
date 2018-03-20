#include "Zaznam.h"

#include <iostream>
#include <string>

using namespace std;

Zaznam::Zaznam(string nazov, string text)
{
	this->nazov = nazov;
	this->text = text;
}

Zaznam::~Zaznam()
{}

string Zaznam::getNazov()
{
	return this->nazov;
}

string Zaznam::getText()
{
	return this->text;
}