#include "Backpack.h"

void EPAM::Backpack::fill(const std::vector<Object>& objects)
{
	std::vector<std::pair<float, Object>> specific_cost{};
	for (const auto& object : objects)
		specific_cost.push_back(std::make_pair(object.getCost() / object.getWeight(), object));

	std::sort(specific_cost.begin(), specific_cost.end(),
		[](std::pair<float, Object> obj1, std::pair<float, Object> obj2)
		{
			return obj1.first > obj2.first;
		});

	float totalWeight{};
	for (const auto& object : specific_cost)
	{
		if (object.second.getWeight() + totalWeight <= this->m_maxWeight)
		{
			this->m_bestObjects.push_back(object.second);
			this->m_bestCost += object.second.getCost();
			totalWeight += object.second.getWeight();
		}
		else
			continue;
	}
}

void EPAM::Backpack::output()
{
	for (const auto& object : m_bestObjects)
		std::cout << object.getName() 
				  << "\n  " << "Cost: "   << object.getCost() 
		          << "\n  " << "Weight: " << object.getWeight() << '\n';

	std::cout << "\nMax cost: " << this->m_bestCost << '\n';
}