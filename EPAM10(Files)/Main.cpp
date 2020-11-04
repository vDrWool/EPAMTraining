#include <iostream>

#include "CustomDataBase.h"

unsigned selectAnAction()
{
	unsigned choise{};
	std::cout << "1 - Load data from file.\n"
			  << "2 - Enter the data.\n"
		      << "3 - Append the data.\n"
		      << "4 - Sort data by lastname.\n"
		      << "5 - Sort data by age.\n"
			  << "6 - Output by month.\n"
		      << "7 - Output the oldest man.\n"
		      << "8 - Output all employers which lastnames starts with letter.\n"
		      << "0 - Exit.\n";
	std::cin >> choise;

	if (choise < 0 || choise > 8)
		throw std::exception("Incorrect choise!");

	return choise;
}

int main()
{
	try
	{
		std::vector<EPAM::Employer> employers{};

		while (auto choise{ selectAnAction() })
		{
			system("cls");

			switch (choise)
			{
				case 1:
				{
					EPAM::DB::loadData(employers);
				}
				break;
				case 2:
				{
					EPAM::DB::EnterData(employers);
				}
				break;
				case 3:
				{
					bool add{};
					std::cout << "Do you need to reset db?(0 - no, any - yes): ";
					std::cin >> add;

					EPAM::DB::AppendData(employers, add);
				}
				break;
				case 4:
				{
					EPAM::DB::sortByName(employers);
				}
				break;
				case 5:
				{
					EPAM::DB::sortByAge(employers);
				}
				break;
				case 6:
				{
					unsigned month{};
					std::cout << "Enter the month: ";
					std::cin  >> month;

					EPAM::DB::outputByMonth(employers, month);
				}
				break;
				case 7:
				{
					EPAM::DB::outputTheOldestMan(employers);
				}
				break;
				case 8:
				{
					char letter{};
					std::cout << "Enter the letter: ";
					std::cin >> letter;

					EPAM::DB::outputByFirstLetter(employers, letter);
				}
				break;
				case 0:
				default:
					break;
			}
		}
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	return 0;
}