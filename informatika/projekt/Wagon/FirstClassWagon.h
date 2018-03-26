#ifndef FIRSTCLASSWAGON_H
#define FIRSTCLASSWAGON_H

#include <iostream>

using namespace std;

#include "../Wagon.h"

class FirstClassWagon: public Wagon
{
public:
	FirstClassWagon(string name, int seats_count);
};

#endif