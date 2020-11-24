#include <iostream>

#include "Task1.h"
#include "Task2.h"

int main()
{
	{
		std::cout << "Task1.1: " << EPAM::task({ 1, 4, 5, 2, 1 }).value() << '\n';
		std::cout << "Task1.2: " << EPAM::taskS(std::string("aa"), std::string("ba")) << '\n';
	}
	{
		EPAM::Array<int> arr1{ 5, 1, 4, 6, 7, 2, 3 };
		EPAM::Array<char> arr2{ 'a', 't', 'w' ,'Q' };

		std::cout << "Task2.1: " << arr1.max() << '\n';
		std::cout << "Task2.2: " << static_cast<char>(arr2.max()) << '\n';
	}
}