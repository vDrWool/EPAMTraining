#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

namespace EPAM
{
	class Object
	{
	public:
		Object() = delete;
		Object(std::string name, float weight, float cost) 
			: m_name{ name }, m_weight{ weight }, m_cost{ cost } {}
	public:
		std::string getName() const { return this->m_name; }
		float getCost()    const { return this->m_cost; }
		float getWeight()  const { return this->m_weight; }
	private:
		std::string m_name{};
		float m_weight{};
		float m_cost{};
	};
}