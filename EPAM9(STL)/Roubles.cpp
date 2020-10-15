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
        out << value.m_count;
        return out;
    }
    std::istream& operator>>(std::istream& in, Roubles& value)
    {
        in >> value.m_count;
        return in;
    }
}