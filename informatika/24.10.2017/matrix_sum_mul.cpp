#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int m1[3][3] = {
		{4, 6, 9},
		{2, 3, 0},
		{1, 0, 8}
	};

	int m2[3][3] = {
		{4, 6, 9},
		{2, 3, 0},
		{1, 0, 8}
	};

	int result_sum[3][3];
	int result_mul[3][3];

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			result_sum[i][j] = m1[i][j] + m2[i][j];
			result_mul[i][j] = m1[i][j] * m2[i][j];
		}
	}

	cout << "Vysledok scitania dvoch matic: " << endl;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j)	{
			cout << result_sum[i][j] << " ";
		}
		cout << endl;
	}

	cout << "Vysledok vynasobenia dvoch matic: " << endl;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j)	{
			cout << result_mul[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}