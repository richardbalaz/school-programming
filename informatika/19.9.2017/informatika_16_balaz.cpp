#include <iostream>

/* Character representing an outer char */
#define CHAR "*"

using namespace std;

/* Print 'len' times the CHAR, creating a horizontal side */
void print_horizontal_side(int len)
{
	for (int i = 0; i < len; i++)
		cout << CHAR << " ";
	cout << endl;
}

/* Print two times the char with margin of (len - 2) spaces, creating a 2 vertical sides */
void print_vertical_sides(int len)
{
	cout << CHAR;
	for (int i = 0; i < (len - 2); i++)
		cout << "  ";
	cout << " " << CHAR << endl;
}

int main()
{
	/* Load count of all characters */
	int len;

	cout << "Pocet znakov: ";
	cin >> len;

	/* Print top side */
	print_horizontal_side(len);
	
	/* Print all left and right sides */
	for (int i = 0; i < (len - 2); ++i)
		print_vertical_sides(len);
	
	/* Print bottom side */
	print_horizontal_side(len);

	return 0;
}