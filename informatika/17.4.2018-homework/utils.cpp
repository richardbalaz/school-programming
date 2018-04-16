#include "utils.h"

/*
 * Add integer to the end of the list
 */
void append(list<int> &l, int value)
{
	l.push_back(value);
}

/*
 * Add integer to the beggining of the list
 */
void prepend(list<int> &l, int value)
{
	l.push_front(value);
}

/*
 * Insert integer to the specified position in the list
 */
void insert(list<int> &l, int value, int pos)
{
	list<int>::iterator it = next(l.begin(), pos);
	l.insert(it, value);
}

/*
 * Convert list of numbers to single string, each item on each line 
 */
string stringify(const list<int> l)
{
	ostringstream ss;

	for(list<int>::const_iterator it = l.begin(); it != l.end(); it++)
		ss << *it << endl;

	return ss.str();
}

/*
 * Remove item at specified position in list
 */
void remove_position(list<int> &l, int pos)
{
	list<int>::iterator it = next(l.begin(), pos);
	l.erase(it);
}

/*
 * Remove all occurences of value
 */
void remove_numbers(list<int> &l, int value)
{
	l.remove(value);	
}

/*
 * Helper function for remove_even(): return true if even
 */
bool is_even(const int num)
{
	return !(num % 2);
}

/*
 * Remove all even occurencies in list
 */
void remove_even(list<int> &l)
{
	l.remove_if(is_even);
}

/*
 * Sort the list
 */
void sortify(list<int> &l)
{
	l.sort();
}

/*
 * Reverse order the list
 */
void reversify(list<int> &l)
{
	l.reverse();
}

/*
 * Remove all duplicities in the list
 */
void uniquify(list<int> &l)
{
	l.unique();
}