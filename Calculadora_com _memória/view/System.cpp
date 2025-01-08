#include "../include/Calculator.h"
#include "../include/System.h"

Calculator calculator;
void start() {
	
	int option{};
	do
	{
		options(option);
		verify(option);
		
	} while (option != 0);
	
}
void options(int& option) {

	std::cout << "\n1 - calculate\n";
	std::cout << "2 - Show memory\n";
	std::cout << "3 - Clean memory\n";
	std::cout << "0 - Exit\n";
	std::cout << ">> ";
	std::cin >> option;
}

void verify(int& option) {


	switch (option)
	{
	case 1:
		operation();
		break;
	case 2:
		calculator.showMemory();
		break;
	case 3: 
		calculator.cleanMemory();
		break;
	case 0:
		std::cout << "Goodbye!" << std::endl;
		break;
	default:
		std::cout << "Invalid option, try again!" << std::endl;
		break;
	}

}

void operation() {
	try
	{
	std::cout << "\nSum - Subtract";
	std::cout << "\nMultiply - Divide\n";
	std::cout << "Enter the values and the operator (x + x)\n";
	std::cout << ">> ";
	std::cin >> calculator;
	std::cout << calculator;
	calculator.saveMemory();
	}
	catch (const std::exception&)
	{
		std::cerr << "Invalid values\n";
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		
	}
}
