#pragma once
#include <iostream>
#include <fstream>
#include <string>
class Calculator
{
private:
	int id;
	int value1, value2;
	char calculusOperator;
	double result;

public:

	Calculator();
	~Calculator();
	void Calculate();
	void saveMemory() const;
	void showMemory();
	void cleanMemory();

public:
	friend std::istream& operator>>(std::istream& in, Calculator& c); 
	friend std::ostream& operator<<(std::ostream& out, const Calculator& c);
	
};

