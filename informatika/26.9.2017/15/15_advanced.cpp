#include <fstream>
#include <cctype>

using namespace std;

#define INPUT_FILE "input_plain.txt"
#define OUTPUT_FILE "output_encoded.txt"

int main(int argc, char const *argv[])
{
    ifstream input(INPUT_FILE);
    ofstream output(OUTPUT_FILE);

    /* Check if opening failed */
    if (!input.is_open() || !output.is_open())
        return 1;

    /* Iterate every line in input file and get the longest's length */
    char in;
    while (input.get(in)) {
        /* if is in alphabet */
        if (isalpha(in)) {
            /* Return to start if end of alphabet, else next char */
            if(in == 'z' || in == 'Z')
                in -= 25;
            else
                in += 1;
        }

        /* Write encoded character to output file */
        output << in;   
    }

    return 0;
}