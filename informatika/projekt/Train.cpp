#include "Train.h"

/*
 * Create train owned by company with specified name
 */
Train::Train(string company, string name)
{
	this->company = company;
	this->name = name;
}

Train::~Train()
{}

string Train::getName() const
{
	return this->name;
}

/*
 * Add specified wagon to wagons
 */
void Train::addWagon(Wagon wagon)
{
	this->wagons.push_back(wagon);
}
	
/*
 * Remove specified wagon from wagons by name 
 */
void Train::removeWagon(Wagon wagon)
{
	vector<Wagon>::iterator it;
	for (it = this->wagons.begin(); it != this->wagons.end(); ++it) {
		if (it->getName() == wagon.getName())
			this->wagons.erase(it);
	}
}

/*
 * Create reservation for passenger in specified grade
 */
Reservation Train::createReservation(Client *passenger, int grade)
{
	Reservation res;

	vector<Wagon>::iterator it;
	for (it = this->wagons.begin(); it != this->wagons.end(); ++it) {
		if (it->getGrade() == grade) {
			if (it->hasFreeSeat()) {
				res.setSeatNumber(it->reserveSeat());
				res.setWagonNumber(distance(this->wagons.begin(), it) + 1);
				
				goto seat_found;
			}
		}
	}

	/* TODO: exception */
	cout << "There is no more seat left!\n" << endl;
	return res;

seat_found:
	res.setTrainName(this->name);
	res.setPassenger(passenger);

	this->reservations.push_back(res);

	return res;
}

/*
 * Find reservation of specified client
 * TODO: return vector of reservations 
 */
vector<Reservation> Train::findReservation(Client passenger)
{
	vector<Reservation> foundReservations;

	vector<Reservation>::iterator it;
	for (it = this->reservations.begin(); it != this->reservations.end(); ++it) {
		Client *c = it->getPassenger();

		if (c->getName() == passenger.getName()
			&& c->getAge() == passenger.getAge()
			&& c->getId() == passenger.getId())
			foundReservations.push_back(*it);
	}

	return foundReservations;
}

/*
 * Delete reservation from reservation list
 */
void Train::cancelReservation(Reservation reservation)
{
	vector<Reservation>::iterator it;
	for (it = this->reservations.begin(); it != this->reservations.end(); ++it) {
		if (*it == reservation) {
			this->reservations.erase(it);
			
			Wagon &w = this->wagons.at(reservation.getWagonNumber());
			w.freeSeat(reservation.getSeatNumber());

			return;
		}
	}

	/* TODO: exception */
	cout << "No reservation to delete" << endl;
}
