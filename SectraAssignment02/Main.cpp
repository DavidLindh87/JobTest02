#include "Register.h"
#include "Input.h"
#include <iostream>
#include <cstring>
#include <string>
#include <list>

using namespace std;

Input obj;
list<Register> registerList;
Register* regObj = nullptr;
Register* useObj = nullptr;
int cases = 0;
list<string> operations = { "add","subtract", "multiply", "divide" };
int operation_number;
//string chk;

Register* Find_Register(string name) {
	Register* my_pointer = nullptr;
	for (list<Register>::iterator it = registerList.begin(); it != registerList.end(); ++it) {
		if ((*it).fetch_name().compare(name) == 0) {
			my_pointer = &*it;
		}
	}
	return my_pointer;
};

int Find_Operation(string name) {
	int index = 1001;
	for (list<string>::iterator it = operations.begin(); it != operations.end(); ++it) {
		if ((*it).compare(name) == 0) {
			index = std::distance(operations.begin(), it);
		}
	}
	return index;
};

int main() {
	obj.Clear();
	registerList.clear();
	cout << "Please input on the form : \n <Register> operation value \n or \n <Register> operation <Register> \n or \n print <Register> \n to print a register or \n quit \n to exit the program." << endl;
	do {
		cases = obj.Get_Input();
		//cout << cases << endl;
		switch (cases) {
			case 66: // if there was an error with the input
				//cout << "case 66 entered" << endl;
				cout << "Try again!" << endl; 
				break;
			case 0 : // if the program was excited by the user
				//cout << "case 0 entered" << endl;
				cout << "Bye!" << endl; 
				break;
			case 1 : // if the print command was entered by the user
				//cout << "case 1 entered" << endl;
				regObj = Find_Register(obj.Get_Operation());
				if (regObj != nullptr) { // if there is no register with the inputted name we need to make one
					regObj->print();
				}
				else {
					cout << "There is no register by that name." << endl;
				}
				break;
			case 2 : // if input by the user uses a double
				//enter code here
				//cout << "case 2 entered" << endl;
				regObj = Find_Register(obj.Get_Reg());
				if (regObj == nullptr) { //there is no previous register by this name
					operation_number = Find_Operation(obj.Get_Operation());
					switch (operation_number) {
						case 1001 :
							cout << "Operation does not exist" << endl;
							break;
						case 0 :
							registerList.push_back(Register(obj.Get_Reg(), obj.Get_Number()));
							break;
						case 1 :
							registerList.push_back(Register(obj.Get_Reg(), -obj.Get_Number()));
							break;
						case 2 :
							registerList.push_back(Register(obj.Get_Reg(), 0));
							break;
						case 3 :
							registerList.push_back(Register(obj.Get_Reg(), 0));
							break;
						default : 
							cout << "Default1, no previous register entered" << endl;
					}
				}
				else { //if there is a previous register by this name
					operation_number = Find_Operation(obj.Get_Operation());
					switch (operation_number) {
						case 1001 :
							cout << "Operation does not exist" << endl;
							break;
						case 0 :
							regObj->assign_value(regObj->fetch_value() + obj.Get_Number());
							break;
						case 1 :
							regObj->assign_value(regObj->fetch_value() - obj.Get_Number());
							break;
						case 2 : 
							regObj->assign_value(regObj->fetch_value() * obj.Get_Number());
							break;
						case 3 : 
							regObj->assign_value(regObj->fetch_value() / obj.Get_Number());
							break;
						default:
							cout << "Default2, previous register entered" << endl;
					}
				}
				break;
			case 3 : // if input used a register instead of double for the value
				//enter code here
				//cout << "case 3 entered" << endl;
				regObj = Find_Register(obj.Get_Reg());
				useObj = Find_Register(obj.Get_Target_Register());
				if (useObj == nullptr) { // if there is no register by the entered name
					cout << "The register you are trying to use as a value doesn't exist" << endl;
				}
				else {
					operation_number = Find_Operation(obj.Get_Operation());
					if (regObj == nullptr) { // if there is no target register either
						switch (operation_number) {
						case 1001:
							cout << "Operation does not exist" << endl;
							break;
						case 0:
							registerList.push_back(Register(obj.Get_Reg(), useObj->fetch_value()));
							break;
						case 1:
							registerList.push_back(Register(obj.Get_Reg(), -useObj->fetch_value()));
							break;
						case 2:
							registerList.push_back(Register(obj.Get_Reg(), 0));
							break;
						case 3:
							registerList.push_back(Register(obj.Get_Reg(), 0));
							break;
						default:
							cout << "Default3, no previous register entered" << endl;
						}
					}
					else {
						switch (operation_number) {
						case 1001:
							cout << "Operation does not exist" << endl;
							break;
						case 0:
							regObj->assign_value(regObj->fetch_value() + useObj->fetch_value());
							break;
						case 1:
							regObj->assign_value(regObj->fetch_value() - useObj->fetch_value());
							break;
						case 2:
							regObj->assign_value(regObj->fetch_value() * useObj->fetch_value());
							break;
						case 3:
							if (useObj->fetch_value() != 0.0) {
								regObj->assign_value(regObj->fetch_value() / useObj->fetch_value());
							}
							else {
								cout << "Division by 0 is not allowed" << endl;
							}
							break;
						default:
							cout << "Default4, previous register entered" << endl;
						}
					}
				}
				break;
			default :
				cout << "Primary switch case default activated" << endl;
		} // END PRIMARY SWITCH CASE
	//reset pointers and values for next loop
		//useObj = nullptr;
		//regObj = nullptr;
		obj.Clear();

	} 
	while (cases != 0);

	//obj.Check_Input(); //for testing
	return 0;
};