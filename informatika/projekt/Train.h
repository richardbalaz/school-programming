#ifndef TRAIN_H
#define TRAIN_H

#include <iostream>
#include <vector>

using namespace std;

#include "Wagon.h"
#include "Reservation.h"
#include "Client.h"

class Train
{
	string company;
	string name;

	vector<Reservation> reservations;

	/* Set of wagons that belong to this train */
	vector<Wagon> wagons;
public:
	Train(string company, string name);
	~Train();

	string getName() const;

	void addWagon(Wagon wagon);
	void removeWagon(Wagon wagon);

	/* High-level API for reservations */
	Reservation createReservation(Client *passenger, int grade);
	vector<Reservation> findReservation(Client passenger);
	void cancelReservation(Reservation reservation);
};

#endif
