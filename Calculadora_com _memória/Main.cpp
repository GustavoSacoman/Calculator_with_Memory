#pragma once
#include <iostream>
#include "include/Calculator.h"
#include "include/System.h"

int main() {

	char option;
	std::cout << "Do you wish start the calculator? (y/n): ";
	std::cin >> option;

	if (option == 'y') {
		start();
	}
	else
		std::cout << "Goodbye!" << std::endl;

	return 0;
}