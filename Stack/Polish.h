#pragma once
#include <iostream>
#include "Stack.h"

class Polish {
public:
	void infix_to_postfix(char Formula[], char* Result);
	int precedence(char x);
	int checker(char Formula[]);
	double Calculator(char* Result);
};