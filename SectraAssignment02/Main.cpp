#include "Register.h"
#include "Input.h"
#include <iostream>
#include <cstring>
#include <string>
#include <list>

using namespace std;

Input obj;
list<Register> theList;
string chk;

Register* Find_Register(string name) {
	Register* my_pointer = NULL;
	for (list<Register>::iterator it = theList.begin(); it != theList.end(); ++it) {
		if ((*it).fetch_name().compare(name) == 0) {
			my_pointer = &*it;
		}
	}
	return my_pointer;
}

int main() {
	chk.clear();
	theList.clear();
	cout << "Please enter on the form : \n <Register> operation amount \n or \n print <Register> \n to print a register or \n quit \n to exit the program." << endl;
	do {
		chk = obj.Get_Input();
		if (chk.compare("print") == 0) {
			if (Find_Register(obj.Get_Operation())) {
				(*Find_Register(obj.Get_Operation())).print();
			}
			else {
				cout << "There is no register by that name" << endl;
			}
		}
		else if (chk.compare("Input good") == 0) {
			if (!Find_Register(obj.Get_Reg())) {
				theList.push_back(Register(obj.Get_Reg(), obj.Get_Number()));
			}
			//here continues the work!
		}
		//cout << chk << "\n";
	} while (chk.compare("quit") != 0);

	//obj.Check_Input(); //for testing
	return 0;
};