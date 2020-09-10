#pragma once
#include <string>
#include <iostream>

using namespace std;

class Register
{
private:
	string name;
	double value;

public:

	Register();

	Register(string designation);

	Register(string designation, double val);

	void Initialize(string input_name, double input_value);

	double fetch_value();

	void assign_value(double val);

	string fetch_name();

	void print();

	//ostream& operator<<(ostream& os, Register& r);
};

