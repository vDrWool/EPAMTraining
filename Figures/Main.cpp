#include <iostream>
#include "Rectangle.h"

int main()
{
	Figures::Rectangle rect1({ 3, 5 }, { 8, 2 });
	Figures::Rectangle rect2({ 7, 7 }, { 10, 4 });

	std::cout << std::boolalpha << Figures::Rectangle::areIntersection(rect1, rect2) << '\n';

	Figures::Rectangle outerRect{ Figures::Rectangle::outerRectangle(rect1, rect2) };

	auto [leftUp1, rightDown1]         = rect1.getPos();
	auto [leftUp2, rightDown2]         = rect2.getPos();
	auto [leftUpOuter, rightDownOuter] = outerRect.getPos();

	std::cout << "Rect1(leftUp): "        << leftUp1.x        << ' ' << leftUp1.y        << '\n'
			  << "Rect1(rigthDown): "     << rightDown1.x     << ' ' << rightDown1.y     << '\n'
			  << "Rect2(leftUp): "        << leftUp2.x        << ' ' << leftUp2.y        << '\n'
			  << "Rect2(rigthDown): "     << rightDown2.x     << ' ' << rightDown2.y     << '\n'
		      << "OuterRect(leftUp): "    << leftUpOuter.x    << ' ' << leftUpOuter.y    << '\n'
		      << "OuterRect(rightDown): " << rightDownOuter.x << ' ' << rightDownOuter.y << '\n';

	return 0;
}