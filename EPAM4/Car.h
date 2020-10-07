#pragma once
#include "Vehicle.h"

namespace EPAM
{
	class Car : public Vehicle
	{
	public:
		Car() = delete;
	public:
		Car(uint weels, uint mass, uint value, std::string firm, EngineType engine);
		Car(const Car& other);
		Car(const Car&& other);

		void info() override;
		uint avarageSum() override;

		~Car();
	private:
		EngineType m_engine{};
	};
}

