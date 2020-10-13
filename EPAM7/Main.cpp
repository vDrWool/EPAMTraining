#include <iostream>
#include "Task.h"

int main()
{
	EPAM::PassengerCar pasCar{ "BMW", 4u, 15000u };
	EPAM::TransportCar traCar{ "AUDI", 6u, 25000u };
	EPAM::Car* cars[2]{
		&pasCar,
		&traCar
	};

	for (auto i{ 0 }; i < 2; i++)
	{
		std::cout << cars[i]->companyName() << '\n';
		std::cout << cars[i]->petrolConsumption() << '\n';
	}

	EPAM::CivilianPlane civPlane{ EPAM::Engine::electricity, 250000u };
	EPAM::MilitaryPlane milPlane{ EPAM::Engine::fuel, 500000u };
	EPAM::Plane* planes[2]{
		&civPlane,
		&milPlane
	};

	for (auto i{ 0 }; i < 2; i++)
	{
		std::cout << planes[i]->getMaxSpeed() << '\n';
		std::cout << planes[i]->costOfFlight() << '\n';
	}

	EPAM::Vehicle* vehicles[2]{
		*cars,
		*planes
	};

	return 0;
}