#include "Car.h"


EPAM::Car::Car(uint weels, uint mass, uint value, std::string firm, EngineType engine)
	: Vehicle(weels, mass, value, firm), m_engine{ engine } {}

EPAM::Car::Car(const Car& other)
	: Vehicle(other.m_weels, other.m_mass, other.m_value, other.m_firm), m_engine{ other.m_engine } {}

EPAM::Car::Car(const Car&& other)
	: Vehicle(other.m_weels, other.m_mass, other.m_value, other.m_firm), m_engine{ other.m_engine } {}


void EPAM::Car::info()
{
	Vehicle::info();
	switch (this->m_engine)
	{
    case EngineType::electrical:
		std::cout << "EngineType: electrical\n";
		break;
	case EngineType::fuel:
		std::cout << "EngineType: fuel\n";
		break;
	}
}

EPAM::uint EPAM::Car::avarageSum()
{
	return 32000u;
}


EPAM::Car::~Car() {}