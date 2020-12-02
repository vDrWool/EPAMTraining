#include <iostream>

#include "string.h"
#include "RAIIFiles.h"


int main()
{
	{
		EPAM::string str0{                 };
		EPAM::string str2{ "aasd"          };
		EPAM::string str3{ str2            };
		EPAM::string str4{ std::move(str2) };
		str0 = str3;
		str4 = EPAM::string("fff");
	}
	{
		EPAM::RAIIFiles file{ "text.txt" };
		file->eof();
	}

	return 0;
}