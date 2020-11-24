#pragma once
#include <string>
#include <iostream>

namespace EPAM
{
	struct FullName
	{
		std::string firstName{};
		std::string lastName{};
		std::string middleName{};

		operator std::string()
		{
			return firstName + ' ' + lastName + ' ' + middleName;
		}
	};
	struct Date
	{
		unsigned day{};
		unsigned month{};
		unsigned year{};

		operator std::string()
		{
			return std::to_string(day) + ' ' + std::to_string(month) + ' ' + std::to_string(year);
		}
	};

	class Employer
	{
	private:
		FullName m_fullname{};
		char m_sex{};
		Date m_birthDate{};
	public:
		Employer() = default;
		Employer(const FullName& fname, char sex, const Date& date) : m_fullname{ fname }, m_sex{ sex }, m_birthDate{ date } {}

	public:
		Employer& operator = (const Employer& other) = default;
	public:
		FullName getFullName() const noexcept { return this->m_fullname;  }
		char     getSex()      const noexcept { return this->m_sex;       }
		Date     getBirthday() const noexcept { return this->m_birthDate; }
	public:
		void setData(FullName& fname, char sex, Date& bdate);
	public:
		friend std::ostream& operator << (std::ostream& out, const Employer& emp);
	};
}
