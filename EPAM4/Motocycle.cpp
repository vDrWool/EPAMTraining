#include "Motocycle.h"

EPAM::Motocycle::Motocycle(uint weels, uint mass, uint value, std::string firm, uint maxSpeed)
	: Vehicle(weels, mass, value, firm), m_maxSpeed{ maxSpeed } {}

EPAM::Motocycle::Motocycle(const Motocycle& other)
	: Vehicle(other.m_weels, other.m_mass, other.m_value, other.m_firm), m_maxSpeed{ other.m_maxSpeed } {}

EPAM::Motocycle::Motocycle(const Motocycle&& other)
	: Vehicle(other.m_weels, other.m_mass, other.m_value, other.m_firm), m_maxSpeed{ other.m_maxSpeed } {}


void EPAM::Motocycle::info()
{
	Vehicle::info();
	std::cout << "MaxSpeed: " << this->m_maxSpeed << '\n';
}

EPAM::uint EPAM::Motocycle::avarageSum()
{
	return 23000u;
}


EPAM::Motocycle::~Motocycle() {}
