#include <iostream>

#include "string.h"
#include "RAIIFiles.h"

int main()
{
	{
		EPAM::string str0{  };
		EPAM::string str2{ "aasd" };
		EPAM::string str3{ str2 };
		EPAM::string str4{ std::move(str2) };
	}
	{
		EPAM::RAIIFiles file{ "text.txt" };
	}

	return 0;
}