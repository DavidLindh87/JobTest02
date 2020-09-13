#pragma once
#include <iostream>
#include <string>

using namespace std;

class Input
{

private:

	string reg;
	string operation;
	string input_string;
	double input_double;

public:

	Input();

	void Clear();

	int Get_Input();

	string Get_InputTest(); // for saving old code

	void Check_Input();

	string Get_Reg();

	string Get_Operation();

	double Get_Number();

	string Get_Target_Register();

};

