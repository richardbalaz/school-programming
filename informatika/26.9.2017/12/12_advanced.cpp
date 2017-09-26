#include <fstream>

using namespace std;

#define INPUT_FILE "input.txt"
#define OUTPUT_FILE "output.txt"

int main(int argc, char const *argv[])
{
    ifstream input(INPUT_FILE);
    ofstream output(OUTPUT_FILE);

    /* Check if opening failed */
    if (!input.is_open() || !output.is_open())
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
    output << longest_line;

    return 0;
}