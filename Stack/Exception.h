#pragma once
#include <iostream>
#include <string>

class Exception
{
private:
	std::string str;
public:
	Exception(std::string _str) : str(_str) {}
	void Print() { std::cout << "Here comes the Problem!" << std::endl << str << std::endl; }
};

