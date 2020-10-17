#include "Roubles.h"

EPAM::Roubles& EPAM::Roubles::operator=(Roubles& other)
{
    if (other == *this)
        return *this;

    this->m_count = other.m_count;
    return *this;
}

EPAM::Roubles& EPAM::Roubles::operator=(Roubles&& other) noexcept
{
    if (other == *this)
        return *this;

    this->m_count = other.m_count;
    return *this;
}

namespace EPAM
{
    std::ostream& operator<<(std::ostream& out, const Roubles& value)
    {
        // Example:
        // strValue = 12345678.21
        std::string strValue{ std::to_string(value.m_count) }, decimalPart{}, newValue{};

        // decimalPart = .21
        decimalPart.append(strValue.begin() + strValue.find('.'), strValue.end());
        decimalPart.erase(decimalPart.begin() + decimalPart.find_last_not_of('0') + 1, decimalPart.end());

        // strValue = 12345678
        strValue.erase(strValue.begin() + strValue.find('.'), strValue.end());

        unsigned first_comma{ strValue.length() % 3 };
        if (first_comma != 0)
            newValue.append(strValue.begin(), strValue.begin() + first_comma);
        else
            newValue.append(strValue.begin(), strValue.begin() + 3);

        if (strValue.length() > 3) newValue.append(",");
        // newValue = 12,

        for (size_t i{ first_comma }, j{ 0 }; i < strValue.length(); i++, j++)
        {
            if (j % 3 == 0 && j != 0) 
                newValue += ',';

            newValue += strValue[i];
        }
        // newValue = 12,345,678

        out << newValue << decimalPart <<  "RUB";
        // newValue = 12,345,678RUB
        return out;
    }
    std::istream& operator>>(std::istream& in, Roubles& value)
    {
        in >> value.m_count;
        return in;
    }
}