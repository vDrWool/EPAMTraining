#include "Vehicle.h"

EPAM::Vehicle::Vehicle(uint weels, uint mass, uint value, std::string firm)
	: m_weels{ weels }, m_mass{ mass }, m_value{ value }, m_firm{ firm } {}

EPAM::Vehicle::Vehicle(const Vehicle& other) 
	: m_weels{ other.m_weels }, m_mass{ other.m_mass }, m_value{ other.m_value }, m_firm{ other.m_firm } {}

EPAM::Vehicle::Vehicle(const Vehicle&& other) 
	: m_weels{ other.m_weels }, m_mass{ other.m_mass }, m_value{ other.m_value }, m_firm{ other.m_firm } {}


void EPAM::Vehicle::info()
{
	std::cout << "Weels: " << this->m_weels << '\n'
			  << "Mass: " << this->m_mass << '\n'
			  << "Value: " << this->m_value << '\n';
}


EPAM::Vehicle::~Vehicle() {}
