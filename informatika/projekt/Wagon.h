#ifndef WAGON_H
#define WAGON_H

#include <iostream>
#include <map>

using namespace std;

enum grades
{
	FIRST_CLASS,
	SECOND_CLASS,
	RESTAURATION_CLASS,
	CHILD_CLASS
};

class Wagon
{
	string name;
	int grade;
	int seats_count;

	/* List of seats and if they are reserved */
	std::map<int, bool> seats;
public:
	Wagon(string name, int grade, int seats_count);
	~Wagon();

	string getName();
	int getGrade();

	bool hasFreeSeat();
	int reserveSeat();
	void freeSeat(int seat_number);
};

#endif