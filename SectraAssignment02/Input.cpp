#include "Input.h"
#include <exception>
#include <climits>

Input::Input() {
	reg = "";
	operation = "";
	input_number = 0.0;
};

string Input::Get_Input() {
	try {
		cin >> reg;
		if (reg.compare("quit") == 0) {
			throw 10;
		}
		else if (reg.compare("print") == 0) {
			cin >> operation;
			throw 20;
		}
		else {
			try {
				cin >> operation >> input_number;
				if (cin.fail()) {
					throw 30;
				}
			}
			catch (int e) {
				if (e == 30) {
					while(cin.fail())
					{
						cin.clear(); // clear input buffer to restore cin to a usable state
						cin.ignore(INT_MAX, '\n'); // ignore last input
						cout << "You can only enter numbers.\n";
						cout << "Enter a number.\n";
						cin >> input_number;
					}
				}
			}
		}
	}
	catch(int e){
		if (e == 10) {
			return "quit";
		}
		else if (e == 20) {
			return "print";
		}
	}
	//cin >> input_number;
	//cin >> reg >> operation >> input_number;
	return "Input good";
};

void Input::Check_Input() {
	cout << reg << " " << operation << " " << input_number;
};

string Input::Get_Reg() {
	return reg;
};

string Input::Get_Operation() {
	return operation;
};

double Input::Get_Number() {
	return input_number;
};