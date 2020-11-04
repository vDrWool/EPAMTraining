#include <iostream>
#include <string>
#include <iomanip>

struct Student
{
	char faulty[2]{};
	std::string firstName{};
	std::string lastName{};
	unsigned    group{};
	std::string email{};
};

struct Student2
{
	std::string firstName{};
	std::string lastName{};
	std::string email{};
	char faulty[2]{};
	unsigned    group{};
};

auto main() -> int
{
	Student fixedArrayOfStudents[30]{};
	Student2 fixedArrayOfStudents2[30]{};

	std::cout << "Enter the number of students:";
	unsigned numberOfStudents{};
	std::cin >> numberOfStudents;
	auto dynamicArrayOfStudents = new Student[numberOfStudents]{};

	std::cout << (*dynamicArrayOfStudents).firstName << "\n\n";

	unsigned size{ sizeof(fixedArrayOfStudents) / sizeof(Student) };
	std::cout << size << "\n\n";

	{
		int i{};
		Student* end{ dynamicArrayOfStudents + numberOfStudents };
		for (Student* begin{ dynamicArrayOfStudents }; begin != end; begin++)
		{
			std::cout << std::setw(2)<< ++i << ' ' << (*begin).firstName << ' ';
			std::cout << begin << '\n';
		}
	}
	
	std::cout << "\n\n";

	{
		int i = 0;
		Student2* end{ fixedArrayOfStudents2 + size };
		for (Student2* begin{ fixedArrayOfStudents2 }; begin != end; begin++)
		{
			std::cout << std::setw(2) << ++i << ' ' << (*begin).firstName << ' ';
			std::cout << begin << '\n';
		}
	}

	std::cout << "\n\n";

	std::cout << &dynamicArrayOfStudents << '\n';
	std::cout << &(*dynamicArrayOfStudents).email << '\n';
	std::cout << &(*dynamicArrayOfStudents).firstName << '\n';
	std::cout << &(*dynamicArrayOfStudents).lastName << '\n';
	std::cout << &(*dynamicArrayOfStudents).faulty << '\n';
	std::cout << &(*dynamicArrayOfStudents).group << "\n\n";

	std::cout << sizeof(Student) << '\n';
	std::cout << sizeof(Student2) << "\n\n";
	return 0;
}