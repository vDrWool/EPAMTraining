#pragma once
#include <iostream>
#include <algorithm>

class string
{
public:
	string(char* str);
	string(const char* str);

	unsigned int changeA();

	~string();

	friend std::ostream& operator << (std::ostream& out, const string& str);
private:
	char* _string{};
	size_t _size{};
};

