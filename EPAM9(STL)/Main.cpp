#include <iostream>
#include <random>
#include <chrono>
#include <iomanip>
#include <vector>
#include <list>

#include "Roubles.h"
 

int main()
{
	// Task 1.
	{	
		std::vector<std::string>                      allTypesOfCards{ "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "V", "Q", "K" };
		std::vector<std::pair<std::string, unsigned>> cards{};
		std::vector<std::string>                      players[4]{};

		for (const auto& elem : allTypesOfCards)
			cards.push_back(std::make_pair(elem, 4));

		for (auto& player : players)
		{
			while (player.size() != 13)
			{
				std::shuffle(cards.begin(), cards.end(),
					std::default_random_engine{ static_cast<unsigned>(std::chrono::high_resolution_clock::now().time_since_epoch().count()) });

				if (cards.begin()->second > 0)
				{
					player.push_back(cards.begin()->first);
					cards.begin()->second--;

					if (cards.begin()->second == 0)
						cards.erase(cards.begin());
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
	}
	std::cout << std::string(50, '=') << '\n';
	// Task 2.
	{
		using namespace EPAM::currency;

		EPAM::Roubles dl1{}, dl2{};
		dl1 = 10000000000_RUB;
		dl2 = 10.511_RUB;

		std::cout << dl1 + dl2 << '\n';
		std::cout << dl1 - dl2 << '\n';
		std::cout << dl1 * dl2 << '\n';
		std::cout << dl1 / dl2 << '\n';
	}

	return 0;
}