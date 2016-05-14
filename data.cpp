#define _CRT_SECURE_NO_DEPRECATE	// stop deprecation warnings, needs to be on first line

#include "data.h"
#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

data::data(char const * const name) :
	name(NULL)
{
	this->setName(name);
}

// destructor
data::~data()
{
	if (name)
	{
		delete [] name;
	}
}

// assignment operator overload
data& data::operator=(const data& data2)
{
	if (this == &data2)
	{
		return *this;
	}
	else
	{
		this->setName(data2.getName());
		return *this;
	}
}

char const * const data::getName() const
{
	return (this->name);
}

void data::setName (char const * const name)
{
	this->name = new char[strlen(name)+1];
	strcpy(this->name, name);
}

// return true if d1 is "less than" d2, false otherwise
bool operator< (const data& d1, const data& d2)
{
	if (strcmp(d1.getName(),d2.getName()) < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// return true if d1 is "equal to" d2, false otherwise
bool operator== (const data& d1, const data& d2)
{
	if (strcmp(d1.getName(),d2.getName()) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// print the data instance referred to by outData
ostream& operator<< (ostream& out, const data& outData)
{
	out << outData.name << endl;
	return out;
}