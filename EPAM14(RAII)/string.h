#pragma once
#include <iostream>
#include <algorithm>

namespace EPAM
{
	class string
	{
	public:
		string();
		string(const char* str);
		string(const string& lvalue);
		string(string&& rvalue) noexcept;

		~string();
	public:
		unsigned size() const { return this->m_size; }
	private:
		char* m_str{};
		unsigned m_size{};
	};
}