#include "Shapes.h"

namespace EPAM
{
	Circle& Circle::operator = (const Circle& other) noexcept
	{
		if (*this == other)
			return *this;

		this->m_center = other.m_center;
		this->m_radius = other.m_radius;

		return *this;
	}
	Square& Square::operator = (const Square& other) noexcept
	{
		if (*this == other)
			return *this;

		this->m_leftUp = other.m_leftUp;
		this->m_length = other.m_length;

		return *this;
	}
	Rectangle& Rectangle::operator = (const Rectangle& other) noexcept
	{
		if (*this == other)
			return *this;

		this->m_leftUp    = other.m_leftUp;
		this->m_rightDown = other.m_rightDown;

		return *this;
	}

	bool Circle::operator == (const Circle& other) noexcept
	{ 
		return this->m_center == other.m_center && this->m_radius == other.m_radius; 
	}
	bool Square::operator == (const Square& other) noexcept
	{
		return this->m_leftUp == other.m_leftUp && this->m_length == other.m_length;
	}
	bool Rectangle::operator == (const Rectangle& other) noexcept
	{
		return this->m_leftUp == other.m_leftUp && this->m_rightDown == other.m_rightDown;
	}

	float Circle::perimeter() const
	{
		if (this->m_radius <= 0)
			throw std::exception("Radius equal or less than zero!");

		return static_cast<float>(2 * 3.1415 * this->m_radius);
	}
	float Square::perimeter() const
	{
		if (this->m_length == 0)
			throw std::exception("Length of the square equal zero!");

		return static_cast<float>(4 * this->m_length);
	}
	float Rectangle::perimeter() const
	{
		return static_cast<float>(
			   (std::abs(this->m_leftUp.x - this->m_rightDown.x) * 2) +
			   (std::abs(this->m_leftUp.y - this->m_rightDown.y) * 2)
			);
	}

	float Circle::square() const
	{
		if (this->m_radius <= 0)
			throw std::exception("Radius equal or less than zero!");

		return static_cast<float>(3.1415 * this->m_radius);
	}
	float Square::square() const
	{
		if (this->m_length == 0)
			throw std::exception("Length of the square equal zero!");

		return static_cast<float>(this->m_length * this->m_length);
	}
	float Rectangle::square() const
	{
		return static_cast<float>(
				std::abs(this->m_leftUp.x - this->m_rightDown.x) *
			    std::abs(this->m_leftUp.y - this->m_rightDown.y)
			);
	}
}