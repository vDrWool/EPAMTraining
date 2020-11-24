#include "Employer.h"

void EPAM::Employer::setData(FullName& fname, char sex, Date& bdate)
{
	this->m_fullname  = fname;
	this->m_sex       = sex;
	this->m_birthDate = bdate;
}

namespace EPAM
{
	std::ostream& operator << (std::ostream& out, const Employer& emp)
	{
		out << "Name: " << emp.getFullName().firstName << ' ' << emp.getFullName().lastName << ' ' << emp.getFullName().middleName << '\n';
		out << "Sex: " << emp.getSex() << '\n';
		out << "Birthday: " << emp.getBirthday().day << '.' << emp.getBirthday().month << '.' << emp.getBirthday().year << '\n';

		return out;
	}
}