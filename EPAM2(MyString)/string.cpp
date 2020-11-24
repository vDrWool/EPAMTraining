#include "string.h"

string::string(char* str)
{
	_size = strlen(str);
	_string = new char[this->_size + 1];
	std::copy_n(str, _size, _string);
	_string[_size] = '\0';
}

string::string(const char* str) : string(const_cast<char*>(str)) {}


unsigned int string::changeA()
{
	unsigned int count{};
	unsigned int lastIndex{ 1 };
	
	//if (std::find(_string, _string + _size, 'a') == (_size - 1))

	while (_string[_size - lastIndex] == 'a' || _string[_size - lastIndex] == 'A')
	{
		lastIndex++;
	}
	
	for (auto i{ 0 }; i < _size; i++)
	{
		if (_string[i] == 'a' || _string[i] == 'A')
		{
			_string[i] = _string[_size - lastIndex];
			count++;
		}
	}
	
	return count;
}


string::~string()
{
	delete[] _string;
}


std::ostream& operator << (std::ostream& out, const string& str)
{
	out << str._string;
	return out;
}