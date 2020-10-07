#pragma once
#include <iostream>
#include <string>

namespace EPAM
{
	using uint = unsigned int;

	enum class EngineType
	{
		electrical,
		fuel,
	};

	class Vehicle
	{
	public:
		Vehicle() = default;
	public:
		Vehicle(uint weels, uint mass, uint value, std::string firm);
		Vehicle(const Vehicle& other);
		Vehicle(const Vehicle&& other);

		virtual void info();
		virtual uint avarageSum() = 0;

		~Vehicle();
	protected:
		uint m_weels{};
		uint m_mass{};
		uint m_value{};
		std::string m_firm{};
	};
}

