#include <iostream>

using namespace std;

/*
 * Create all possible r-len combinations of numbers
 * in range of [0,n)
 * Returns pointer to all list of 'c' combinations
 */
int **permutations(int n, int r, int &c)
{
    if (r > n)
        return NULL;

    /* compute number of permutations */
    c = n;
    for (int i = 1; i < r; ++i) {
        c *= n - i;
    }

    /* initializations */
    int *pool = new int[n];
    int *indices = new int[n];
    int **perms = new int*[c];
    int perms_count = 0;

    for (int i = 0; i < n; ++i) {
        pool[i] = i;
        indices[i] = i;
    }

    for (int i = 0; i < c; ++i)
        perms[i] = new int[r];

    int *cycles = new int[r];
    for (int i = 0; i < r; ++i)
        cycles[i] = n - i;

    /* first permutation */
    for (int i = 0; i < r; ++i)
        perms[perms_count][i] = pool[indices[i]];
    perms_count++;

    /* main loop */
    while (n) {
        /* iterate thru all algorhythm cycles */
        for (int i = (r - 1); i >= 0; --i) {
            cycles[i] -= 1;
            if (cycles[i] == 0) {
                int last = indices[i];

                for (int j = i + 1; j < n; ++j)
                    indices[j - 1] = indices[j];

                indices[n - 1] = last;
                cycles[i] = n - i;

                if (i == 0)
                    return perms;
            } else {
                int j = cycles[i];

                /* do some swap */
                int swap_temp = indices[i];

                indices[i] = indices[n - j];
                indices[n - j] = swap_temp;

                /* add permutation to list */
                for (int i = 0; i < r; ++i)
                    perms[perms_count][i] = pool[indices[i]];
                perms_count++;

                break;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    /* get all possible characters */
    string chars;
    getline(cin, chars);

    /* get length of generated words */
    int r;
    cin >> r;

    /* lets do some combinatorics */    
    int count;
    int **combinations = permutations(chars.length(), r, count);
    cout << "count of all possible words: " << count << endl;

    cout << "printing all possible words " << r << " letters wide" << endl;
    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < r; ++j)
            cout << chars[combinations[i][j]];
        cout << endl;
    }

    return 0;
}
