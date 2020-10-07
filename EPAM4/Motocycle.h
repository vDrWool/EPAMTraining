#pragma once
#include "Vehicle.h"

namespace EPAM
{
	class Motocycle : public Vehicle
	{
	public:
		Motocycle() = delete;
	public:
		Motocycle(uint weels, uint mass, uint value, std::string firm, uint maxSpeed);
		Motocycle(const Motocycle& other);
		Motocycle(const Motocycle&& other);

		void info() override;
		uint avarageSum() override;

		~Motocycle();
	private:
		uint m_maxSpeed{};
	};
}

