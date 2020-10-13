#include <iostream>
#include <chrono>
#include <random>

#include "Matrix.h"

int main()
{
	EPAM::Matrix<int> matrix(5, 5);
	auto [row, column] = matrix.size();

	std::default_random_engine gen{ 
		static_cast<unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()) 
	};
	std::uniform_int_distribution<int> dist{ -25, 99 };
	for (auto i{ 0 }; i < static_cast<int>(row); i++)
	{
		for (auto j{ 0 }; j < static_cast<int>(column); j++)
		{
			matrix[i][j] = dist(gen);
		}
	}
	
	std::cout << matrix;

	EPAM::Task(matrix);

	return 0;
}