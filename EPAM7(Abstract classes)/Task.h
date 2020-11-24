#pragma once
#include <string>

namespace EPAM
{
	enum class Engine
	{
		electricity,
		fuel
	};

	class Vehicle
	{
	public:
		virtual unsigned getMaxSpeed() const noexcept = 0;
		virtual Engine getEngineType() const noexcept = 0;
	};
	

	class Car : public Vehicle
	{
	public:
		Car() = delete;
	public:
		Car(std::string companyName, unsigned weels, unsigned value)
			: m_companyName{ companyName }, m_weels{ weels }, m_value{ value }{}

		void setValue(unsigned value) { m_value = value; }

		virtual std::string companyName() const noexcept = 0;
		virtual unsigned petrolConsumption() const noexcept = 0;
	protected:
		std::string m_companyName{};
		unsigned m_weels{};
		unsigned m_value{};
		Engine m_engine{};
	};

	class TransportCar : public Car
	{
	public:
		TransportCar() = delete;
	public:
		TransportCar(std::string companyName, unsigned weels, unsigned value)
			: Car(companyName, weels, value) {}

		unsigned getMaxSpeed() const noexcept override
		{
			return 160u;
		}
		unsigned petrolConsumption() const noexcept override
		{
			return 20u;
		}
		Engine getEngineType() const noexcept override
		{
			return this->m_engine;
		}
		std::string companyName() const noexcept override
		{
			return this->m_companyName;
		}
	};

	class PassengerCar : public Car
	{
	public:
		PassengerCar() = delete;
	public:
		PassengerCar(std::string companyName, unsigned weels, unsigned value)
			: Car(companyName, weels, value) {}

		unsigned getMaxSpeed() const noexcept override
		{
			return 250u;
		}
		unsigned petrolConsumption() const noexcept override
		{
			return 5u;
		}
		Engine getEngineType() const noexcept override
		{
			return this->m_engine;
		}
		std::string companyName() const noexcept override
		{
			return this->m_companyName;
		}
	};


	class Plane : public Vehicle
	{
	public:
		Plane() = delete;
	public:
		Plane(Engine engineType, unsigned value)
			: m_engine{ engineType }, m_value{ m_value }{}

		virtual unsigned numberOfSeats() const noexcept = 0;
		virtual unsigned costOfFlight() const noexcept = 0;
	protected:
		unsigned m_value{};
		Engine m_engine{};
	};

	class CivilianPlane : public Plane
	{
	public:
		CivilianPlane() = delete;
	public:
		CivilianPlane(Engine engineType, unsigned value)
			: Plane(engineType, value) {}

		unsigned getMaxSpeed() const noexcept override
		{
			return 500u;
		}
		unsigned costOfFlight() const noexcept override
		{
			return 500u;
		}
		Engine getEngineType() const noexcept override
		{
			return this->m_engine;
		}
		unsigned numberOfSeats() const noexcept override
		{
			return 150u;
		}
	};

	class MilitaryPlane : public Plane
	{
	public:
		MilitaryPlane() = delete;
	public:
		MilitaryPlane(Engine engineType, unsigned value)
			: Plane(engineType, value) {}

		unsigned getMaxSpeed() const noexcept override
		{
			return 1000u;
		}
		unsigned costOfFlight() const noexcept override
		{
			return 25000u;
		}
		Engine getEngineType() const noexcept override
		{
			return this->m_engine;
		}
		unsigned numberOfSeats() const noexcept override
		{
			return 2u;
		}
	};
}