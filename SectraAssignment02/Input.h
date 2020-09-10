#pragma once
#include <iostream>
#include <string>

using namespace std;

class Input
{

private:

	string reg;
	string operation;
	double input_number;

public:

	Input();

	string Get_Input();

	void Check_Input();

	string Get_Reg();

	string Get_Operation();

	double Get_Number();

};

