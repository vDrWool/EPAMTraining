#include "Bicycle.h"


EPAM::Bicycle::Bicycle(uint weels, uint mass, uint value, std::string firm, bool isDiskBrake)
	: Vehicle(weels, mass, value, firm), m_isDiskBrake{ isDiskBrake } {}

EPAM::Bicycle::Bicycle(const Bicycle& other)
	: Vehicle(other.m_weels, other.m_mass, other.m_value, other.m_firm), m_isDiskBrake{ other.m_isDiskBrake } {}

EPAM::Bicycle::Bicycle(const Bicycle&& other)
	: Vehicle(other.m_weels, other.m_mass, other.m_value, other.m_firm), m_isDiskBrake{ other.m_isDiskBrake } {}


void EPAM::Bicycle::info()
{
	Vehicle::info();
	std::cout << "Is it has disk brake: " << std::boolalpha << this->m_isDiskBrake << '\n';
}

EPAM::uint EPAM::Bicycle::avarageSum()
{
	return 700u;
}


EPAM::Bicycle::~Bicycle() {}

