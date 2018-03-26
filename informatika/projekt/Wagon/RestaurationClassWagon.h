#ifndef RESTAURATIONCLASSWAGON_H
#define RESTAURATIONCLASSWAGON_H

#include <iostream>

using namespace std;

#include "../Wagon.h"

class RestaurationClassWagon: public Wagon
{
public:
	RestaurationClassWagon(string name, int seats_count);
};

#endif