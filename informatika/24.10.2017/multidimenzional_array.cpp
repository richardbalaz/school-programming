/*
b) Inicializujte pole tak, aby na diagonále boli 1 a ostatné prvku boli 0. Vypíšte pole na 	obrazovku.
*/

#include <iostream>
using namespace std;



int main(int argc, char const *argv[])
{
	int x = 15;
	int y = 15;

	int **matrix = new int*[x];

	for (int i = 0; i < y; ++i)
		matrix[i] = new int[y];

	int beg = 0;
	int end = (y - 1);

	bool mid = false;

	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j)	{
			if(beg == j || end == j)
				matrix[i][j] = 1;
			else
				matrix[i][j] = 0;
		}

		if(mid) {
			beg--;
			end++;
		} else {
			end--;
			beg++;
		}

		if(beg == ((y - 1) / 2)) {
			mid = true;
		}
	}

	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j)	{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}


	return 0;
}