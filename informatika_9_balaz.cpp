#include <iostream>

using namespace std;

#define NUMBERS_COUNT 15

int main()
{
	int is_zero = 0;
	int more_than_zero = 0;
	int less_then_zero = 0;

	int in;
	for (int i = 0; i < NUMBERS_COUNT; i++)	{
		cin >> in;
		if (in == 0)
			is_zero++;
		else if (in > 0)
			more_than_zero++;
		else if (in < 0)
			less_then_zero++;
	}

	cout << "==0: " << is_zero << " >0: " << more_than_zero << " <0: " << less_then_zero << endl;

	return 0;
}
