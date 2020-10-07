#include "Rectangle.h"

Figures::Rectangle::Rectangle(const Point& leftUp, const Point& rightDown) noexcept
	: _leftUp{ leftUp }, _rightDown{ rightDown } {}

Figures::Rectangle::Rectangle(const Point&& leftUp, const Point&& rightDown) noexcept
	: _leftUp{ leftUp }, _rightDown{ rightDown } {}

Figures::Rectangle::Rectangle(const Rectangle& other) noexcept
	: _leftUp{ other._leftUp }, _rightDown{ other._rightDown } {}

Figures::Rectangle::Rectangle(const Rectangle&& other) noexcept
	: _leftUp{ other._leftUp }, _rightDown{ other._rightDown } {}


std::tuple<Figures::Point, Figures::Point> Figures::Rectangle::getPos() noexcept
{
	return { _leftUp, _rightDown };
}

void Figures::Rectangle::setPos(const Point&& leftUp) noexcept
{
	this->_leftUp      = leftUp;
	this->_rightDown.x = this->_leftUp.x + this->getLength();
	this->_rightDown.y = leftUp.y        - this->getWidth();
}


int Figures::Rectangle::getLength() noexcept
{
	return _rightDown.x - _leftUp.x;
}

int Figures::Rectangle::getWidth() noexcept
{
	return _leftUp.y - _rightDown.y;
}


bool Figures::Rectangle::areIntersection(Rectangle& first, Rectangle& second)
{
	Point cen1{ first.getLength()  / 2 + first._leftUp.x,  first.getWidth()  / 2 + first._rightDown.y };
	Point cen2{ second.getLength() / 2 + second._leftUp.x, second.getWidth() / 2 + second._rightDown.y };

	//int lenBetweenCensX{ abs(static_cast<int>(cen1.x - cen2.x)) };
	//int lenBetweenCensY{ abs(static_cast<int>(cen1.y - cen2.y)) };

	if (abs(static_cast<int>(cen1.x - cen2.x)) <= first.getLength() / 2 + second.getLength() / 2 &&
		abs(static_cast<int>(cen1.y - cen2.y)) <= first.getWidth()  / 2 + second.getWidth()  / 2)
	{
		return true;
	}

	return false;
}

Figures::Rectangle Figures::Rectangle::outerRectangle(Rectangle& first, Rectangle& second)
{
	return Rectangle(
		{
			std::min(first._leftUp.x, second._leftUp.x),
			std::max(first._leftUp.y, second._leftUp.y)
		},
		{
			std::max(first._rightDown.x, second._rightDown.x),
			std::min(first._rightDown.y, second._rightDown.y)
		}
	);
}