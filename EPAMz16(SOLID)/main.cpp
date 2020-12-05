#include <iostream>
#include <vector>
#include <list>
#include <deque>

#include "Shapes.h"
#include "alg.h"


int main()
{
	// Task 1.
	{
		std::vector<std::unique_ptr<EPAM::IShape>> shapes{};
		shapes.push_back(std::make_unique<EPAM::Circle>(EPAM::Point{ 5, 4 }, 5));
		shapes.push_back(std::make_unique<EPAM::Square>(EPAM::Point{ 2, 1 }, 9));
		shapes.push_back(std::make_unique<EPAM::Rectangle>(EPAM::Point{ 2, 5 }, EPAM::Point{ 11, 1 }));

		for (int i{ 0 }; i < 3; ++i)
		{
			std::cout << shapes[i]->perimeter() << '\n';
			std::cout << shapes[i]->square() << '\n';
		}
	}
	// Task 2.
	{
		std::vector<int> vec_from{ 1, 2, 5, 6, 2, 3, 5 };
		std::vector<int> vec_to{};
		
		std::list<int> lst_from{ 2, 5, 2, 6, 7, 3, 3 };
		std::list<int> lst_to{};
		
		std::deque<int> dqu_from{ 7, 6, 9, 4, 2, 6, 2 };
		std::deque<int> dqu_to{ 1, 2, 3 };
		
		EPAM::copy(vec_from, vec_to);
		EPAM::copy(lst_from, lst_to);
		EPAM::copy(dqu_from, dqu_to);

		for (const auto& elemV : vec_to)
			std::cout << elemV << ' ';
		std::cout << std::endl;
		for (const auto& elemL : lst_to)
			std::cout << elemL << ' ';
		std::cout << std::endl;
		for (const auto& elemD : dqu_to)
			std::cout << elemD << ' ';
		std::cout << std::endl;
	}

	return 0;
}