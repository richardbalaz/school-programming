#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	ifstream input("input.txt");
	ofstream output("output.txt");

	if (!input.is_open() || !output.is_open()) {
		cout << "Unable to to open input or output file" << "\n";
		return 1;
	}

	string line;
	while (!input.eof()) {
		getline(input, line);
		output << line.length() << "\n";		
	}

	input.close();
	output.close();
	return 0;
}