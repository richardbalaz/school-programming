#include "Client.h"

Client::Client(string name, int age, int id)
{
	this->name = name;
	this->age = age;
	this->id = id;
}

Client::~Client()
{}

string Client::getName()
{
	return this->name;
}

int Client::getAge()
{
	return this->age;
}

int Client::getId()
{
	return this->id;
}

void Client::setName(string name)
{
	this->name = name;
}

void Client::setAge(int age)
{
	this->age = age;
}
