#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{
	int n = 2000;
	int *array = new int[n];
	
	array[0] = rand() % 10; 

	for (int i = 0; i < n; ++i)
		array[i] = (rand() % 10) + array[i - 1];

	for (int i = 0; i < n; ++i)
		cout << array[i] << endl;

	int x = 4506;
	int min = 0;
	int max = n - 1;
	int mid = (min + max) / 2;

	while (x != array[mid] && min <= max) {
		if (array[mid] > x)
			max = mid - 1;
		else if (x > array[mid])
			min = mid + 1;
		mid = (min + max) / 2;
	}

	if (array[mid] == x)
		cout << "found at " << mid << " position" << endl;
	else
		cout << "not found in array" << endl;

	return 0;
}