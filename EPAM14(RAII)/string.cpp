#include "string.h"

namespace EPAM
{
	string::string()
	{
		std::cout << "string()\n";
	}
	string::string(const char* str)
	{
		auto len{ strlen(str) };
		this->m_size = len;
		this->m_str = new char[len];
		std::copy(str, str + len, this->m_str);
	
		std::cout << "string(const char*)\n";
	}
	string::string(const string& lvalue) : m_size{ lvalue.size() }
	{
		this->m_str = new char[this->m_size];
		std::copy(lvalue.m_str, lvalue.m_str + lvalue.m_size, this->m_str);

		std::cout << "string(const string&)\n";
	}
	string::string(string&& rvalue) noexcept : m_size{ rvalue.size() }
	{
		this->m_str = rvalue.m_str;

		rvalue.m_str = nullptr;
		rvalue.m_size = 0;

		std::cout << "string(string&&)\n";
	}

	string& string::operator = (const string& lvalue)
	{
		std::cout << "operator = (&)\n";

		if (this->m_str == lvalue.m_str)
			return *this;

		delete[] this->m_str;
		this->m_str = new char[lvalue.size()];

		this->m_size = lvalue.m_size;
		std::copy(lvalue.m_str, lvalue.m_str + lvalue.m_size, this->m_str);

		return *this;
	}
	string& string::operator = (string&& rvalue) noexcept
	{
		std::cout << "operator = (&&)\n";

		if (this->m_str == rvalue.m_str)
			return *this;

		this->m_size = rvalue.m_size;
		this->m_str  = rvalue.m_str;

		rvalue.m_str = nullptr;
		rvalue.m_size = 0;

		return *this;
	}

	string::~string()
	{
		delete[] this->m_str;

		std::cout << "~string()\n";
	}
}