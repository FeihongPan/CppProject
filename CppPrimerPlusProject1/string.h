#pragma once
#pragma once
// string1.h -- fixed and augmentes string class definition

#ifndef STRING1_H_
#define STRING1_H_
#include <iostream>
#include <string.h>
#include <cstring>
#include <QtCore/QCoreApplication>
using namespace std;

class String
{
private:
	char* str; // pointer to string
	int len; // length of string
	static int num_srings; // number of objects
	static const int CINLIN = 80; // cin inout limit
public:
	// constructors and other methods
	String(const char* s); // constructor
	String(); // defalut constructor
	String(const String& st); //copy constructor
	~String(); // destructor
	int length() const { return len; }

	// overloaded operator methods
	String& operator=(const String& st);
	String& operator=(const char*);
	char& operator[](int i);
	const char& operator[](int i) const;

	// overloaded operator friends
	friend bool operator<(const String& st1, const String& st2);
	friend bool operator>(const String& st1, const String& st2);
	friend bool operator==(const String& st1, const String& st2);
	friend ostream& operator<<(ostream& os, const String& st);
	friend ostream& operator<<(istream& is, const String& st);

	// static function
	static int Howmany();
};

#endif // !STRING1_H_
