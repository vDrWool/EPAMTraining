#pragma once
#include <iostream>
#include <string>
#include <regex>
#include <limits>

namespace EPAM
{
	int mult(int a, int b)
	{
		if (a * b >= std::numeric_limits<int>::max())
			throw std::overflow_error("Overflow error!");

		return a * b;
	}

	int devide(int a, int b)
	{
		if (b == 0)
			throw std::runtime_error("Zero devision exception!");

		if (a / b <= std::numeric_limits<int>::min())
			throw std::underflow_error("Underflow error!");

		return a / b;
	}

	class invalid_number : public std::exception
	{
		std::string m_error;
	public:
		invalid_number(const std::string& str) : m_error{ str.c_str() } {}

		const char* what() const noexcept
		{
			return m_error.c_str();
		}
	};

	void numberAnalise(std::string number)
	{
		if (!std::regex_match(number, std::regex(R"(\+7\((\d{3})\)(\d{3})-(\d{2})-(\d{2}))")))
			throw invalid_number("Invalid number");
	}
}