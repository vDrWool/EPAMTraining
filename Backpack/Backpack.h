#pragma once
#include "Object.h"

namespace EPAM
{
	class Backpack
	{
	public:
		Backpack() = delete;
		Backpack(float maxWeight)
			: m_maxWeight{ maxWeight } { }
	public:
		void fill(const std::vector<Object>& objects);
		void output();
	private:
		float m_maxWeight{};
		float m_bestCost{};
		std::vector<Object> m_bestObjects{};
	};
}