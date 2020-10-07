#pragma once
#include <algorithm>
#include <math.h>
#include <tuple>
#include "IPolygon.h"

namespace Figures
{
	class Rectangle : public IPolygon
	{
	public:
		Rectangle() = delete;
	public:
		Rectangle(const Point& leftUp, const Point& rightDown) noexcept;
		Rectangle(const Point&& leftUp, const Point&& rightDown) noexcept;

		Rectangle(const Rectangle& other) noexcept;
		Rectangle(const Rectangle&& other) noexcept;

		std::tuple<Point, Point> getPos() noexcept;
		
		void setPos(const Point&& leftUp) noexcept override;

		int getLength() noexcept;
		int getWidth() noexcept;
		

		static bool areIntersection(Rectangle& first, Rectangle& second);
		[[nodiscard]] static Rectangle outerRectangle(Rectangle& first, Rectangle& second);
	private:
		Point _leftUp{};
		Point _rightDown{};
	};
}