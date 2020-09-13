/*
In this class we handle the input from the user and specify what to do
if the input is flawed and cause the input reading to fail. We also pass on 
relevant information to the main program about the format of the input.
*/

#include "Input.h"
#include <exception>
#include <climits>

Input::Input() {
	reg = "";
	operation = "";
	input_string = ""; //change to string and then remake to int if possible otherwise search in register list and use that value, if no register is found output error message
	input_double = 0.0;
};

void Input::Clear() {
	reg = "";
	operation = "";
	input_string = "";
	input_double = 0.0;
};


/* NOTE: 66 is for bad input, 0 for quit, 1 for print, 2 is for if you input a double, 3 is for if you input a register as a number  */
int Input::Get_Input() {
	char* checkReg; // possibly needs to be set to nullptr
	char* checkIstr;
	try { // take the first part of the input and put it in reg
		cin >> reg;
		if (cin.fail()) {
			throw 0;
		}
		else if (reg.compare("quit") == 0) { // see if we wrote the quit command
			throw 10;
		}
		else if (reg.compare("print") == 0) { // see if we wrote the print command
			throw 20;
		}
		else if (strtod(reg.c_str(), &checkReg) != 0.0) {
			throw 30;
		}
		else {
			try {
				cin >> operation;
				if (cin.fail()) {
					throw 40;
				}
				else {
					try {
						cin >> input_string;
						if (cin.fail()) {
							throw 50;
						}
						else if(input_double = strtod(input_string.c_str(), &checkIstr)) {
							return 2;
						}
						else {
							/*cin >> input_string;
							if (cin.fail()) {
								cin.clear(); // clear input buffer to restore cin to a usable state
								cin.ignore(INT_MAX, '\n'); // ignore last input
								cout << "Invalid value/register input!" << endl;
								return 66;
							}*/
							return 3;
						}
					}
					catch (int e) {
						if (e == 50) {
							/*else if (strtod(input_string.c_str(), &checkIstr) != 0.0) {
							input_double = strtod(reg.c_str(), &checkIstr);
							return 2;
							}
							else {
								return 3;
							}*/
							cin.clear(); // clear input buffer to restore cin to a usable state
							cin.ignore(INT_MAX, '\n'); // ignore last input
							cout << "Invalid operation input!" << endl;
							return 66;
						}
					}
				}
			}
			catch (int e) {
				if (e == 40) {
					cin.clear(); // clear input buffer to restore cin to a usable state
					cin.ignore(INT_MAX, '\n'); // ignore last input
					cout << "Invalid operation input!" << endl;
					return 66;
				}
			}
		}
	}
	catch(int e){
		if (e == 0) {
			cin.clear(); // clear input buffer to restore cin to a usable state
			cin.ignore(INT_MAX, '\n'); // ignore last input
			cout << "Invalid register input!" << endl;
			return 66;
		}
		else if (e == 10) {
			return 0;
		}
		else if (e == 20) {
			try {
				cin >> operation;
				if (cin.fail()) {
					throw 21;
				}
				else {
					return 1;
				}
			}
			catch(int e){
				if (e == 21) {
					cin.clear(); // clear input buffer to restore cin to a usable state
					cin.ignore(INT_MAX, '\n'); // ignore last input
					cout << "Invalid register input!" << endl;
					return 66;
				}
			}
		}
		else if (e == 30) {
			cin.clear(); // clear input buffer to restore cin to a usable state
			cin.ignore(INT_MAX, '\n'); // ignore last input
			cout << "A Register cant be named a number!" << endl;
			return 66;
		}
	}
};

string Input::Get_InputTest() {
	char* pEnd;
	try { //try to read first value 
		cin >> reg;
		if (cin.fail()) {
			throw 0;
		}
		else if (reg.compare("quit") == 0) {
			throw 10;
		}
		else if (reg.compare("print") == 0) {
			cin >> operation;
			throw 20;
		}
		else {
			try {
				cin >> operation; 
				if (cin.fail()) {
					throw 30;
				}
				else {
					try {
						cin >> input_string;
						if (cin.fail()) {
							throw 40;
						}
						else {
							if (strtod(input_string.c_str(), &pEnd) == input_double) { //if the string could be converted to a double the input was a double read as a string
								return "inputted double";
							}
							else {
								return "inputted string";
							}
						}
						//try to convert the string to a double and if it works make a bool true so we know it succeeded
					}
					catch (int e) {
						if (e == 40) {
							while (cin.fail()) {
								cin.clear(); // clear input buffer to restore cin to a usable state
								cin.ignore(INT_MAX, '\n'); // ignore last input
								cout << "Something was wrong with the operation input.\n";
								cout << "Type in operation plus number/register again.\n";
								cin >> operation;
							}
						}
					}
				}
			}
			catch (int e) {
				if (e == 30) { //error check may be uneccesary here
					/*while (cin.fail()) {
						cin.clear(); // clear input buffer to restore cin to a usable state
						cin.ignore(INT_MAX, '\n'); // ignore last input
						cout << "Something went wrong with the input.\n";
						cout << "Type in operation and number or register again.\n";
						cin >> operation;
					}*/
				}
			}
		}
	}
	catch(int e){
		if (e == 0) {
			while (cin.fail()) {
				cin.clear(); // clear input buffer to restore cin to a usable state
				cin.ignore(INT_MAX, '\n'); // ignore last input
				cout << "Something was wrong with the operation input.\n";
				cout << "Type in operation plus number/register again.\n";
				cin >> reg;
			}

		}
		else if (e == 10) {
			return "quit";
		}
		else if (e == 20) {
			return "print";
		}
	}
	return "Input good"; // can be removed i think
};

void Input::Check_Input() {
	cout << reg << " : " << operation << " : " << input_string << " : " << input_double << endl;
};

string Input::Get_Reg() {
	return reg;
};

string Input::Get_Operation() {
	return operation;
};

double Input::Get_Number() {
	return input_double;
};

string Input::Get_Target_Register() {
	return input_string;
};