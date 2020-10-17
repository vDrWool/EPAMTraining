#include <iostream>
#include <random>
#include <chrono>

#include "Roubles.h"


int main()
{
	// Task 1.
	{	
		std::vector<std::string>                      allTypesOfCards{ "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "V", "Q", "K" };
		std::vector<std::pair<std::string, unsigned>> cards_map{};
		std::vector<std::string>                      players[4]{};

		for (const auto& elem : allTypesOfCards)
			cards_map.push_back(std::make_pair(elem, 4));

		for (auto& player : players)
		{
			while (player.size() != 13)
			{
				std::shuffle(cards_map.begin(), cards_map.end(),
					std::default_random_engine{ static_cast<unsigned>(std::chrono::high_resolution_clock::now().time_since_epoch().count()) });

				if (cards_map.begin()->second > 0)
				{
					player.push_back(cards_map.begin()->first);
					cards_map.begin()->second--;

					if (cards_map.begin()->second == 0)
						cards_map.erase(cards_map.begin());
				}
			}
		}

		for (auto player_number{ 0 }; player_number < 4; player_number++)
		{
			std::cout << "Player #" << player_number + 1 << ": ";
			for (auto elem{ 0 }; elem < players[player_number].size(); elem++)
				std::cout << players[player_number].at(elem) << ' ';
		
			std::cout << '\n';
		}

		std::cout << std::string(50, '=') << '\n';
	}
	// Task 2.
	{
		using namespace EPAM::currency;

		EPAM::Roubles dl1{}, dl2{};
		dl1 = 32425.1_RUB;
		dl2 = 27435.511_RUB;

		std::cout << dl1 + dl2 << '\n';
		std::cout << dl1 - dl2 << '\n';
		std::cout << dl1 * dl2 << '\n';
		std::cout << dl1 / dl2 << '\n';
	}

	return 0;
}