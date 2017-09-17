#include <iostream>

using namespace std;

char marks[8][32] = {
	"Vyborny",
	"Chvalitebny",
	"Dobry",
	"Dostatocny",
	"Nedostatocny"
}; 

int main()
{
	int mark;

	cout << "Zadaj znamku: ";
	cin >> mark;

	cout << marks[mark - 1] << endl;

	return 0;
}