#include <random>
#include <functional>

#include "Vector.h"

int main()
{
	EPAM::Vector<int> vec1(10), vec2(10);

	std::random_device rd;
	std::mt19937 random(rd());
	std::uniform_int_distribution<int> dist(1, 40);

	for (auto i{ 0 }; i < 10; i++)
	{
		vec1[i] = dist(random);
		vec2[i] = dist(random);
	}

	vec1.print();
	vec2.print();
	std::cout << '\n';

	std::cout << "vec1 max = " << vec1.max()
		      << "; vec1 min = " << vec1.min()
		      << "; vec1 avarage = " << vec1.avarage() << ".\n";
	std::cout << "vec2 max = " << vec2.max()
		      << "; vec2 min = " << vec2.min() 
		      << "; vec2 avarage = " << vec2.avarage() << ".\n";
	std::cout << '\n';

	std::cout << "Task: \n"
			  << "Vec1 multiply = " << vec1.mult() << '\n'
			  << "Vec2 multiply = " << vec2.mult() << '\n';
	std::cout << '\n';
 
	std::sort(vec1.begin(), vec1.end(), 
		[](int elem1, int elem2) 
		{
			return elem1 > elem2;
		});
	std::sort(vec2.begin(), vec2.end(),
		[](int elem1, int elem2)
		{
			return elem1 > elem2;
		});

	vec1.print();
	vec2.print();
	std::cout << '\n';

	return 0;
}