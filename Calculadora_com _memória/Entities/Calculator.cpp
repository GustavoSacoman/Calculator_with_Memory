#include "../include/Calculator.h"

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
	else if (calculusOperator == '/') result = value1 != 0 ? value1 / value2 :
		throw std::invalid_argument("Invalid Operation!\n");
	else
		throw std::invalid_argument("Invalid operator");
}

void Calculator::saveMemory()
{
	std::ofstream file("memory.txt", std::ios::app);
	if (!file.is_open())
		throw std::invalid_argument("Unable to open file!\n");
	else if(quantity_values == 10)
		throw std::invalid_argument("Memory is full!\n");
	
	quantity_values++;
	file << value1 << " " << calculusOperator << " " <<	value2 << " = " << result << std::endl;
	file.close();
}

void Calculator::showMemory()
{
	std::fstream file("memory.txt");

	if (!file.is_open())
		throw std::invalid_argument("Unable to open file!\n");

	std::cout << "\n";
	std::string line;

	if (file.peek() == std::ifstream::traits_type::eof()) {
		std::cout << "Memory is empty!" << std::endl;
		return;
	}

	while (std::getline(file, line)) {
		if (line.empty()) break;
		std::cout << line << std::endl;
		}

	file.close();
}

void Calculator::cleanMemory()
{
	std::ofstream file("memory.txt", std::ios::out | std::ios::trunc);

	if (!file.is_open())
		throw std::invalid_argument("Unable to open file!\n");
		
	std::cout << "Memory cleaned!" << std::endl;
	file.close();
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
	return out;
}
