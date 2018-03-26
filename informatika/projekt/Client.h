#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>

using namespace std;

class Client
{
	string name;
	int age;
	int id;
public:
	Client(string name, int age, int id);
	~Client();

	string getName();
	int getAge();
	int getId();

	void setName(string name);
	void setAge(int age);
};

#endif