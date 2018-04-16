#include <iostream>
#include <list>

#include "utils.h"

using namespace std;

void display_menu();

list<int> l;

int main(int argc, char const *argv[])
{

	int c;

	while(true)
	{
		display_menu();

		cout << "Vyber moznost: ";

		cin.clear();
		cin >> c;

		int value, pos;

		switch(c)
		{
			case 1:
				cout << "Cislo? ";
				cin.clear();
				cin >> value;
				append(l, value);
				break;
			case 2:
				cout << "Cislo? ";
				cin.clear();
				cin >> value;
				prepend(l, value);
				break;	
			case 3:
				cout << "Cislo? ";
				cin.clear();
				cin >> value;
				cout << "Pozicia? ";
				cin.clear();
				cin >> pos;
				insert(l, value, pos);
				break;		
			case 4:
				cout << stringify(l);
				break;
			case 5:
				cout << "Pozicia? ";
				cin.clear();
				cin >> pos;
				remove_position(l, pos);
				break;	
			case 6:
				cout << "Cislo? ";
				cin.clear();
				cin >> value;
				remove_numbers(l, value);
				break;
			case 7:
				remove_even(l);
				break;
			case 8:
				sortify(l);
				break;	
			case 9:
				reversify(l);
				break;	
			case 10:
				uniquify(l);
				break;											
		}

		cout << "Hotovo!" << endl;
	}

	return 0;
}

void display_menu()
{
	cout << "-------- MENU --------" << endl;
	cout << "[1] Pridaj na koniec" << endl;
	cout << "[2] Pridaj na zaciatok" << endl;
	cout << "[3] Pridaj na poziciu" << endl;
	cout << "[4] Zobraz zoznam" << endl;
	cout << "[5] Odober z pozicie" << endl;
	cout << "[6] Odober cislo" << endl;
	cout << "[7] Odober parne" << endl;
	cout << "[8] Zotried" << endl;
	cout << "[9] Otoc poradie" << endl;
	cout << "[10] Odstran duplicity" << endl;
}