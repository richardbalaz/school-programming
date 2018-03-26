#include "Wagon.h"

Wagon::Wagon(string name, int grade, int seats_count)
{
	this->name = name;
	this->grade = grade;
	this->seats_count = seats_count;

	/* Set all seats to free */
	for (int i = 1; i <= seats_count; ++i) {
		this->seats.insert(pair<int, bool>(i, false));
	}
}

Wagon::~Wagon()
{}

string Wagon::getName()
{
	return this->name;
}

int Wagon::getGrade()
{
	return this->grade;
}

bool Wagon::hasFreeSeat()
{
	for (map<int, bool>::iterator it = this->seats.begin(); it != this->seats.end(); ++it) {
		if (it->second == false) {
			return true;
		}
	}
	return false;
}


int Wagon::reserveSeat()
{
	for (map<int, bool>::iterator it = this->seats.begin(); it != this->seats.end(); ++it) {
		if (it->second == false) {
			it->second = true;

			return it->first;
		}
	}
	return -1;
}

void Wagon::freeSeat(int seat_number)
{
	this->seats[seat_number] = false;
}