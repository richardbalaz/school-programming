#ifndef SECONDCLASSWAGON_H
#define SECONDCLASSWAGON_H

#include <iostream>

using namespace std;

#include "../Wagon.h"

class SecondClassWagon: public Wagon
{
public:
	SecondClassWagon(string name, int seats_count);
};

#endif