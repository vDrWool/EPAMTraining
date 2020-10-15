#include <iostream>

#include "Roubles.h"


int main()
{
	// Task 1.
	{	

	}
	// Task 2.
	{
		using namespace EPAM::currency;

		EPAM::Roubles dl1{}, dl2{};
		dl1 = 3242.1_RUB;
		dl2 = 27.511_RUB;

		std::cout << dl1 + dl2 << '\n';
	}

	return 0;
}