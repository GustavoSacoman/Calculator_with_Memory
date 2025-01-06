#include "Calculator.h"

Calculator::Calculator()
{
}

Calculator::~Calculator()
{
}

void Calculator::Calculate()
{
	if (calculusOperator == '+') result = value1 + value2;
	else if (calculusOperator == '-') result = value1 - value2;
	else if (calculusOperator == '*') result = value1 * value2;
	else if (calculusOperator == '/') result = value1 != 0 ? value1 / value2 : 0;
}

void Calculator::saveMemory() const
{
	std::ofstream file("memory.txt", std::ios::app);
	if (file.is_open()) {
		file << value1 << " " << calculusOperator << " " << value2 << " = " << result << std::endl;
		file.close();
	}
	else {
		std::cout << "unable to open file" << std::endl;
	}
	
}



void Calculator::showMemory()
{
	std::fstream file("memory.txt");
	if (file.is_open())
	{
		std::string line;
		while (std::getline(file, line)) {

			if (line.empty()) break;

			std::cout << line << std::endl;
		}
		file.close();
	}
	else {
		std::cout << "unable to open file" << std::endl;
	}
}

std::istream& operator>>(std::istream& in, Calculator& c)
{
	in >> c.value1 >> c.calculusOperator >> c.value2;
	c.Calculate();
	return in;
}

std::ostream& operator<<(std::ostream& out, const Calculator& c)
{
	out << c.value1 << " " << c.calculusOperator << " " << c.value2 << " = " << c.result;
	c.saveMemory();
	return out;
}
