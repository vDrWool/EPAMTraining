#include "CustomDataBase.h"

namespace EPAM::DB
{
	void loadData(std::vector<Employer>& employers) 
	{
		employers.clear();
		std::fstream file;

		try
		{
			file.open("db.txt", std::fstream::in);

			FullName emp{};
			char sex{};
			Date date{};

			std::string garbage{};
			while (file >> garbage)
			{
				file >> emp.firstName >> emp.lastName >> emp.middleName;

				file >> garbage;
				file >> sex;

				file >> garbage;
				file >> date.day >> date.month >> date.year;

				employers.push_back( { emp, sex, date } );
			}

			file.close();
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			file.close();
		}
	}
	void EnterData(std::vector<Employer>& employers)
	{
		std::cout << "Enter the data of employer:\nName: ";

		FullName fname{};
		std::cin >> fname.firstName >> fname.lastName >> fname.middleName;
		
		std::cout << "Sex: ";

		char sex{};
		std::cin >> sex;

		std::cout << "Birthday: ";

		Date bdate{};
		std::cin >> bdate.day >> bdate.month >> bdate.year;

		employers.push_back( { fname, sex, bdate } );
	}
	void AppendData(const std::vector<Employer>& employers, bool add = true)
	{
		std::fstream file;

		try
		{
			if (add)
				file.open("db.txt", std::fstream::out | std::fstream::app);
			else
				file.open("db.txt", std::fstream::out);

			for (auto employer : employers)
			{
				file << "Name: "     << static_cast<std::string>(employer.getFullName()) << '\n';
				file << "Sex: "      << employer.getSex() << '\n';
				file << "Birthday: " << static_cast<std::string>(employer.getBirthday()) << '\n';
			}

			file.close();
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			file.close();
		}
	}

	void sortByName(std::vector<Employer>& employers)
	{
		std::sort(employers.begin(), employers.end(), 
			[](Employer emp1, Employer emp2)
			{
				return emp1.getFullName().lastName < emp2.getFullName().lastName;
			}
		);
	}
	void sortByAge(std::vector<Employer>& employers)
	{
		std::sort(employers.begin(), employers.end(),
			[](Employer& emp1, Employer& emp2)
			{
				if (emp1.getBirthday().year == emp2.getBirthday().year)
				{
					if (emp1.getBirthday().month == emp2.getBirthday().month)
						return emp1.getBirthday().day < emp2.getBirthday().day;

					return emp1.getBirthday().month < emp2.getBirthday().month;
				}

				return emp1.getBirthday().year < emp2.getBirthday().year;
			}
		);
	}

	void outputByMonth(const std::vector<Employer>& employers, unsigned month)
	{
		for (const auto& employer : employers)
		{
			if (employer.getBirthday().month == month)
				std::cout << employer;
		}
	}
	void outputTheOldestMan(const std::vector<Employer>& employers)
	{
		Employer oldest{ {}, 'm', { 0, 0, 2500 } };
		for (const auto& employer : employers)
		{
			if (employer.getSex() == 'm')
			{
				if (employer.getBirthday().year == oldest.getBirthday().year)
				{
					if (employer.getBirthday().month == oldest.getBirthday().month)
					{
						if (employer.getBirthday().day == oldest.getBirthday().day)
							continue;
						else
							oldest = employer;
					}

					if (employer.getBirthday().month < oldest.getBirthday().month)
						oldest = employer;
				}
				if (employer.getBirthday().year < oldest.getBirthday().year)
					oldest = employer;
			}
		}

		std::cout << oldest;
	}
	void outputByFirstLetter(const std::vector<Employer>& employers, char letter)
	{
		for (const auto& employer : employers)
		{
			if (employer.getFullName().lastName[0] == letter)
				std::cout << employer;
		}
	}
}