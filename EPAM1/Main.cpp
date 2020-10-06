#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Student
{
	std::string firstname{};
	std::string lastname{};
	unsigned int score[3]{};
};

auto input(std::vector<Student>& vec) -> void
{
	for (auto& st : vec)
	{
		std::cin >> st.firstname >> st.lastname;
		std::cin >> st.score[0] >> st.score[1] >> st.score[2];
	}
}

auto output(const std::vector<Student>& vec) -> void
{
	for (auto& st : vec)
	{
		std::cout << st.firstname << ' ' << st.lastname << ' '
			      << st.score[0] << st.score[1] << st.score[2] << '\n';
	}
}

inline auto sum(unsigned int score[3]) -> int
{
	return score[0] + score[1] + score[2];
}

auto main() -> int
{
	unsigned int size{};
	std::cout << "Number of elems\n";
	std::cin >> size;
	std::vector<Student> vec(size);

	input(vec);	std::cout << '\n';
	output(vec); std::cout << '\n';
	std::sort(vec.begin(), vec.end(), [](Student a1, Student a2)
		{
			return sum(a1.score) > sum(a2.score);
		} 
	); 
	output(vec);

	return 0;
}