#include <iostream>
#include "Car.h"
#include "Motocycle.h"
#include "Bicycle.h"

// LAB 4 && ABSTRACT classes.

int main()
{
	EPAM::Car car{ 4u, 700u, 10000u, "BMV", EPAM::EngineType::fuel };
	EPAM::Motocycle motocycle{ 2u, 100u, 2000u, "Honda", 200u };
	EPAM::Bicycle bicycle{ 2u, 15u, 200u, "Stels", true };

	EPAM::Vehicle** vehicles = new EPAM::Vehicle*[3]{ &car, &motocycle, &bicycle };

	for (auto i{ 0 }; i < 3; i++)
	{
		vehicles[i]->info();
		std::cout << "AvarageSum: " << vehicles[i]->avarageSum() << "\n\n";
	}

	delete[] vehicles;

	return 0;
}