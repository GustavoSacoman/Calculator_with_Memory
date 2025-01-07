#pragma once
#include <iostream>
#include "include/Calculator.h"
#include "include/System.h"

int main() {

	std::cout << "Do you wish start the calculator? (y/n): ";

	char* option = new char;

	std::cin >> *option;

	if (*option == 'y') {
		delete option;
		start();
	}
	else
		std::cout << "Goodbye!" << std::endl;

	return 0;
}