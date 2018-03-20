#ifndef _ZAZNAM_H_
#define _ZAZNAM_H_

#include <iostream>
#include <string>

using namespace std;

class Zaznam
{
	string nazov;
	string text;	
public:
	Zaznam(string nazov, string text);
	~Zaznam();
	string getNazov();
	string getText();
};

#endif