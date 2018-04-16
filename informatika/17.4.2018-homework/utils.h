#ifndef LIST_UTILS

#include <iostream>
#include <list>
#include <sstream>

using namespace std;

void append(list<int> &l, int value);
void prepend(list<int> &l, int value);
void insert(list<int> &l, int value, int pos);
string stringify(const list<int> l);
void remove_position(list<int> &l, int pos);
void remove_numbers(list<int> &l, int value);
bool is_even(const int num);
void remove_even(list<int> &l);
void sortify(list<int> &l);
void reversify(list<int> &l);
void uniquify(list<int> &l);


#define LIST_UTILS
#endif
