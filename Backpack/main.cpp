#include "Backpack.h"

int main()
{
	std::vector<EPAM::Object> objects
	{
		{ "AAA", 2.f,  9.f }, 
		{ "BBB", 1.f,  4.f }, 
		{ "CCC", 3.f, 11.f }, 
		{ "DDD", 2.f,  5.f }, 
		{ "EEE", 5.f, 21.f }, 
		{ "FFF", 5.f, 13.f }, 
		{ "GGG", 2.f,  6.f }  
	};

	std::vector<EPAM::Object> objects2
	{
		{ "AAA", 3.f,  1.f },
		{ "BBB", 4.f,  2.f },
		{ "CCC", 2.f, 12.f },
		{ "DDD", 4.f,  5.f },
		{ "EEE", 2.f, 15.f },
		{ "FFF", 4.f,  8.f },
		{ "GGG", 1.f,  3.f }
	};

	std::vector<EPAM::Object> objects3
	{
		{ "AAA", 1.f,  1.f },
		{ "BBB", 5.f,  4.f },
		{ "CCC", 2.f,  2.f },
		{ "DDD", 4.f, 12.f },
		{ "EEE", 2.f,  6.f },
		{ "FFF", 6.f,  9.f },
		{ "GGG", 3.f, 12.f }
	};

	EPAM::Backpack backpack(10);
	backpack.fill(objects);
	backpack.output();

	return 0;
}