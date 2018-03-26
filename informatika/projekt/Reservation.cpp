#include "Reservation.h"

Reservation::Reservation(string train_name, int wagon_number, int seat_number, Client *passenger)
{
	this->train_name = train_name;
	this->wagon_number = wagon_number;
	this->seat_number = seat_number;
	this->passenger = passenger;
}

Reservation::Reservation()
{}

Reservation::~Reservation()
{}	

string Reservation::getTrainName() const
{
	return this->train_name;
}

int Reservation::getWagonNumber() const
{
	return this->wagon_number;
}

int Reservation::getSeatNumber() const
{
	return this->seat_number;
}

Client *Reservation::getPassenger() const
{
	return this->passenger;
}

void Reservation::setTrainName(string train_name)
{
	this->train_name = train_name;
}

void Reservation::setWagonNumber(int wagon_number)
{
	this->wagon_number = wagon_number;
}

void Reservation::setSeatNumber(int seat_number)
{
	this->seat_number = seat_number;
}

void Reservation::setPassenger(Client *passenger)
{
	this->passenger = passenger;
}

bool Reservation::operator ==(const Reservation &b) const
{
	if (this->getTrainName() == b.getTrainName()
		&& this->getWagonNumber() == b.getWagonNumber()
		&& this->getSeatNumber() == b.getSeatNumber()
		&& this->getPassenger() == this->getPassenger())
	{
		return true;
	}
	
	return false;
}