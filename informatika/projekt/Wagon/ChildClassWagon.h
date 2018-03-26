#ifndef CHILDCLASSWAGON_H
#define CHILDCLASSWAGON_H

#include <iostream>

using namespace std;

#include "../Wagon.h"

class ChildClassWagon: public Wagon
{
public:
	ChildClassWagon(string name, int seats_count);
};

#endif