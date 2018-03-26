#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
    ifstream input_file("numbers.txt");

    string line;
    int lines = 0;
    while (getline(input_file, line))
        lines++;
    input_file.close();

    cout << "Pocet cisiel: " << lines << endl;

    int *numbers = new int[lines];

    input_file.open("numbers.txt");

    for (size_t i = 0; i < lines; i++) {
        getline(input_file, line);
        numbers[i] = stoi(line);
    }

    input_file.close();

    for (size_t i = 0; i < lines; i++) {
        cout << numbers[i] << endl;
    }

    delete numbers;

    return 0;
}
