#include <iostream>
#include <ctime>

using namespace std;

class Car
{
	string manufacturer;
	string model;
	int year;
	int mileage;
	int consumption;
public:
	Car(string manufacturer, string model, int consumption) {
		this->manufacturer = manufacturer;
		this->model = model;
		this->consumption = consumption;

		this->mileage = 0;

		time_t currentTime;
		struct tm * currentLocalTime;

		time(&currentTime);

		currentLocalTime = localtime(&currentTime);

		this->year = currentLocalTime->tm_year + 1900;
	}
	~Car() {

	}

	float ride(int miles) {
		this->mileage += miles;

		float consumedFuel = (miles * this->consumption) / 100.0;

		cout << "You have consumed " << consumedFuel << " litres of fuel!" << endl;

		return consumedFuel;
	}

	int get_year() {
		return this->year;
	}

	int get_mileage() {
		return this->mileage;
	}

	int get_consumption() {
		return this->consumption;
	}

	int set_consumption(int consumption) {
		if (consumption < this->consumption && this->manufacturer == "VW") {
			cout << "Nah, you are installing bluemotion?" << endl;
		}

		this->consumption = consumption;
	}

	void set_mileage(int mileage) {
		cout << "Why are you doing this?? It is illegal. I won't do that!" << endl;
	}
};

int main(int argc, char const *argv[])
{
	Car robovGolf = Car("VW", "Golf Mk5", 10);

	// to NZ
	robovGolf.ride(25);

	// malnasi installs bluemotion
	robovGolf.set_consumption(5);

	// back to TnV
	robovGolf.ride(25);

	cout << "Robert has driven " << robovGolf.get_mileage() << " miles today! Congrats" << endl;

	return 0;
}