#ifndef RESERVATION_H
#define RESERVATION_H

#include <iostream>

using namespace std;

#include "Client.h"

class Reservation
{
	string train_name;
	int wagon_number;
	int seat_number;
	Client *passenger;
public:
	Reservation(string train_name, int wagon_number, int seat_number, Client *passenger);
	Reservation();
	~Reservation();	

	string getTrainName() const;
	int getWagonNumber() const;
	int getSeatNumber() const;
	Client *getPassenger() const;

	void setTrainName(string train_name);
	void setWagonNumber(int wagon_number);
	void setSeatNumber(int seat_number);
	void setPassenger(Client *Passenger);

	bool operator ==(const Reservation &b) const;
};

#endif