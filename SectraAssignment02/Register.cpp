#include "Register.h"

Register::Register() {
	Initialize("", 0.0);
};

Register::Register(string designation) {
	Initialize(designation, 0.0);
};

Register::Register(string designation, double val) {
	Initialize(designation, val);
};

void Register::Initialize(string input_name, double input_value) {
	name = input_name;
	value = input_value;
};
double Register::fetch_value() {
	return value;
};

void Register::assign_value(double val) {
	value = val;
};

string Register::fetch_name() {
	return name;
};

void Register::print() {
	cout << name << " : " << value << endl;
};

//ostream& operator<<(Register& r) {
////	return this;      //      Returns cout to allow chaining
//}

//Register& Register::operator=(Register& r) {
//	this.In  
//}
