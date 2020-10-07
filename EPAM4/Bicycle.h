#pragma once
#include "Vehicle.h"

namespace EPAM
{
	class Bicycle : public Vehicle
	{
	public:
		Bicycle() = delete;
	public:
		Bicycle(uint weels, uint mass, uint value, std::string firm, bool isDiskBrake);
		Bicycle(const Bicycle & other);
		Bicycle(const Bicycle && other);

		void info() override;
		uint avarageSum() override;

		~Bicycle();
	private:
		bool m_isDiskBrake{};
	};
}

