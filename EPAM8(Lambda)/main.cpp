#include <iostream>
#include <algorithm>
#include <regex>
#include <string>
#include <vector>

int main()
{
	// Task 1.1.
	{
		constexpr auto task{
			[](std::vector<int>&& vec)
			{
				for (auto& elem : vec)
					std::cout << elem << ' ';

				std::cout << '\n';
			}
		};

		task({ 5, 1, 7, 8, 6 });
	}
	// Task 1.2.
	{
		unsigned count{};
		std::vector<int> vec{ 7, 5, 1, 8, 6, 1, 2 };

		std::sort(vec.begin(), vec.end(), [&count](int left, int right)
			{
				count++;
				return left < right;
			});

		for (auto& elem : vec)
			std::cout << elem << ' ';
		std::cout << "\nCount = " << count << '\n';
	}
	// Task 1.3.
	{
		using namespace std::literals;

		constexpr auto task{ 
			[](std::string&& str, std::string&& toFind)
			{
				return str.find(toFind);
			}
		};

		std::cout << task("akjfhhas"s, "fhh"s) << '\n';
	}
	// Task 2.1.
	{
		constexpr auto task{
			[](std::vector<int>& vec)
			{
				for (auto i{ 0 }; i < static_cast<int>(vec.size()); i++)
					vec.at(i) = i;
			}
		};

		std::vector<int> vec(10);
		task(vec);

		for (auto elem : vec)
			std::cout << elem << ' ';
		std::cout << '\n';
	}
	// Task 2.2.
	{
		std::vector<int> vec{ 0, 1, 2, 3, 4, 5, 6, 7, 8 };
		constexpr unsigned k{ 4 };

		constexpr auto task{
			[k](std::vector<int>& vec)
			{
				for (auto& elem : vec)
					elem += k;
			}
		};

		task(vec);

		for (auto elem : vec)
			std::cout << elem << ' ';
		std::cout << '\n';
	}

	return 0;
}