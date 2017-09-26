#include <fstream>
#include <iostream>

using namespace std;

#define INPUT_FILE "input.txt"

int main(int argc, char const *argv[])
{
    ifstream input(INPUT_FILE);

    /* Check if opening failed */
    if (!input.is_open())
        return 1;

    /* Iterate every line in input file and get the longest's length */
    int longest_line = 0;
    while (!input.eof()) {
        string line;
        getline(input, line);
        
        if (line.length() > longest_line)
            longest_line = line.length();       
    }

    /* Write result to output file */
    cout << longest_line << endl;

    return 0;
}