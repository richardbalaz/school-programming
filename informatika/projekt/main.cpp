#include <iostream>

#include "Train.h"
#include "Reservation.h"
#include "Wagon.h"
#include "Client.h"
#include "Wagon/SecondClassWagon.h"
#include "Wagon/FirstClassWagon.h"
#include "Wagon/RestaurationClassWagon.h"
#include "Wagon/ChildClassWagon.h"

using namespace std;

Reservation makeReservation(Train *t)
{
	cout << "Vytvorenie novej registracie na vlak " << t->getName() << ":" << endl;

	cout << "Meno: ";
	string name;
	getline(cin, name);

	cout << "Vek: ";
	int age;
	cin >> age;

	cout << "Cislo OP: ";
	int id;
	cin >> id;

	Client *c = new Client(name, age, id);

	cout << "Trieda [2/1/R/C]: ";
	char gradeChar;
	cin >> gradeChar;

	int grade;

	switch (gradeChar) {
		case '2':
			grade = SECOND_CLASS;
			break;
		case '1':
			grade = FIRST_CLASS;
			break;
		case 'R':
			grade = RESTAURATION_CLASS;
			break;
		case 'C':
			grade = CHILD_CLASS;
			break;
		default:
			grade = SECOND_CLASS;
			break;
	}

	return t->createReservation(c, grade);
}

void stornoReservation(Train *t)
{
	cout << "Stornovanie registracie na vlak " << t->getName() << ":" << endl;

	cout << "Meno: ";
	string name;
	getline(cin, name);

	cout << "Vek: ";
	int age;
	cin >> age;

	cout << "Cislo OP: ";
	int id;
	cin >> id;

	cout << "Vozen: ";
	int wagon;
	cin >> wagon;	

	cout << "Cislo sedacky: ";
	int seat_number;
	cin >> seat_number;

	Client c(name, age, id);

	vector<Reservation> clientReservations = t->findReservation(c);

	vector<Reservation>::iterator it;
	for (it = clientReservations.begin(); it != clientReservations.end(); ++it)
	{
		if (it->getWagonNumber() == wagon
			&& it->getSeatNumber() == seat_number)
		{
			t->cancelReservation(*it);
			cout << "Rezervacia zrusena" << endl;
			return;
		}
	}
	cout << "Rezervacia neexistuje" << endl;
}

void checkReservation(Train *t)
{
	cout << "Overenie registracie na vlak " << t->getName() << ":" << endl;

	cout << "Meno: ";
	string name;
	getline(cin, name);

	cout << "Vek: ";
	int age;
	cin >> age;

	cout << "Cislo OP: ";
	int id;
	cin >> id;

	cout << "Vozen: ";
	int wagon;
	cin >> wagon;	

	cout << "Cislo sedacky: ";
	int seat_number;
	cin >> seat_number;

	Client c(name, age, id);

	vector<Reservation> clientReservations = t->findReservation(c);

	vector<Reservation>::iterator it;
	for (it = clientReservations.begin(); it != clientReservations.end(); ++it)
	{
		if (it->getWagonNumber() == wagon
			&& it->getSeatNumber() == seat_number)
		{
			cout << "Rezervacia je platna" << endl;
			return;
		}
	}
	cout << "Rezervacia neexistuje" << endl;
}

int main(int argc, char const *argv[])
{
	Train tr1("ZSSK", "R 813 Gemeran");
	tr1.addWagon(Wagon("R-VOZ-1", FIRST_CLASS, 46));
	tr1.addWagon(Wagon("R-VOZ-2", RESTAURATION_CLASS, 28));
	tr1.addWagon(Wagon("R-VOZ-3", SECOND_CLASS, 82));
	tr1.addWagon(Wagon("R-VOZ-4", SECOND_CLASS, 82));
	tr1.addWagon(Wagon("R-VOZ-5", SECOND_CLASS, 82));

	Train tr2("ZSSK", "Os 4801");
	tr2.addWagon(Wagon("OS-VOZ-1", SECOND_CLASS, 63));
	tr2.addWagon(Wagon("OS-VOZ-2", SECOND_CLASS, 63));
	tr2.addWagon(Wagon("OS-VOZ-3", SECOND_CLASS, 63));
	tr2.addWagon(Wagon("OS-VOZ-4", SECOND_CLASS, 63));
	
	while (true) {
		Train *selectedTrain;

		cout << "------------------------------------------" << endl;
		cout << "---------Rezervacny system vlakov---------" << endl;
		cout << "------------------------------------------" << endl;

		cout << "Dostupne vlaky: R 813 Gemeran, Os 4801" << endl;
		cout << "Vyber vlak: ";
		
		string trainString;
		getline(cin, trainString);

		if (trainString == "R 813 Gemeran")
			selectedTrain = &tr1;
		else if (trainString == "Os 4801")
			selectedTrain = &tr2;

		cout << "Prave bol vybraty vlak " << selectedTrain->getName() << endl;

		cout << "1) vytvorenie rezervacie vo zvolenej triede" << endl;
		cout << "2) zrušenie rezervacie" << endl;
		cout << "3) overenie rezervacie" << endl;
		cout << "Vyber moznost [1/2/3]: ";

		int option;
		cin >> option;
		cin.ignore();

		switch (option) {
			case 1: {
				Reservation res = makeReservation(selectedTrain);
				cout << "---------------------------------" << endl;
				cout << "Udaje o rezervacii:" << endl;
				cout << "Nazov vlaku: " << res.getTrainName() << endl;
				cout << "Cislo voznu: " << res.getWagonNumber() << endl;
				cout << "Cislo sedacky: " << res.getSeatNumber() << endl;
				cout << "Objednavatel: " << res.getPassenger()->getName() << endl;
				cout << "---------------------------------" << endl;
				break;
			}
			case 2:
				stornoReservation(selectedTrain);
				break;
			case 3:
				checkReservation(selectedTrain);
				break;
			default:
				break;
		}
	}
	return 0;
}
