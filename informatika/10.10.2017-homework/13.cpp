#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

typedef vector<int> vectordigit;

vectordigit str_to_vectordigit(string str)
{
	vectordigit v;

	for (string::reverse_iterator it = str.rbegin(); it != str.rend(); ++it) {
		char c = *it;
		v.push_back(atoi(&c));
	}

	return v;
}

string vectordigit_to_str(vectordigit x)
{
	string str;

	for (vectordigit::reverse_iterator it = x.rbegin(); it != x.rend(); ++it)
		str.append(to_string(*it));

	return str;
}

void vectordigit_reduce(vectordigit &x)
{
	string vd_reduced = vectordigit_to_str(x);

	for (string::iterator it = vd_reduced.begin(); it != vd_reduced.end(); ++it) {
		cout << *it << endl;
		/*if(*it == '0') {
			cout << "found 0" << endl;
			vd_reduced.erase(it);
		}
		else {
			cout << "found sometng else 0" << endl;
			return;
		}*/
	}

	x = str_to_vectordigit(vd_reduced); 
}

void vectordigit_align(vectordigit &x, vectordigit &y)
{
	int x_size = x.size();
	int y_size = y.size();

	if (x_size > y_size) {
		for (int i = 0; i < (x_size - y_size); ++i)
			y.push_back(0);
	}
	else if (x_size < y_size) {
		for (int i = 0; i < (y_size - x_size); ++i)
			x.push_back(0);
	}	
}

vectordigit vectordigit_sum(vectordigit x, vectordigit y)
{
	vectordigit_align(x, y);

	vectordigit result;

	bool carry = false;
	for (vectordigit::iterator xt = x.begin(), yt = y.begin(); xt != x.end(); ++xt, ++yt)
	{
		int sum = *xt + *yt;

		if (carry)
			sum++;

		if(sum >= 10) {
			sum -= 10;
			carry = true;
		} else
			carry = false;

		result.push_back(sum);
	}

	if (carry)
		result.push_back(1);
	
	return result;
}

vectordigit vectordigit_dif(vectordigit x, vectordigit y)
{
	vectordigit_align(x, y);

	vectordigit result;

	bool carry = false;
	for (vectordigit::iterator xt = x.begin(), yt = y.begin(); xt != x.end(); ++xt, ++yt)
	{
		if (carry)
			(*yt)++;

		if (*xt < *yt) {
			*xt += 10;
			carry = true;
		} else
			carry = false;

		int dif = *xt - *yt;

		result.push_back(dif);
	}

	return result;
}

/*
vectordigit vectordigit_mul(vectordigit x, vectordigit y)
{

}
*/

int main(int argc, char const *argv[])
{
	string num1 = "123456789";
	string num2 = "111111111";

	vectordigit vd1 = str_to_vectordigit(num1);
	vectordigit vd2 = str_to_vectordigit(num2);

	vectordigit sum = vectordigit_sum(vd1, vd2);
	cout << vectordigit_to_str(sum) << endl;




	/*
	vectordigit dif = vectordigit_dif(vd1, vd2);

	vectordigit_reduce(dif);clear


	string dif_str = vectordigit_to_str(dif);
	cout << dif_str << endl;
	*/

	return 0;
}